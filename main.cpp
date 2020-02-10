#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <iostream>
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
  try
  {
    loader.setFile("/home/vlad/Development/WignerDistribution/1-1000000.txt");
    loader.parse();
  } catch (const std::exception & e)
  {
      std::cerr << e.what() << std::endl;
      return EXIT_FAILURE;
  }

  return app.exec();
}
