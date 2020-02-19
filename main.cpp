#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <iostream>
#include <thread>
#include <xmlloader.h>

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QApplication app(argc, argv);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  XMLLoader loader;
  std::thread parsing;
  try
  {
    loader.setFile("/home/vlad/Development/WignerDistribution/1-1000000.txt");
    parsing = std::thread(&XMLLoader::parse, &loader);
  } catch (const std::exception & e)
  {
      std::cerr << e.what() << std::endl;
      return EXIT_FAILURE;
  }

  app.exec();
  parsing.join();
  return EXIT_SUCCESS;
}
