#include <xmlloader.h>

XMLLoader::XMLLoader(QObject * parent) : QObject(parent)
{

}

XMLLoader::~XMLLoader()
{

}

XMLLoader::XMLLoader(const QString &filename, QObject * parent) : QObject(parent), m_filename(filename)
{

}

void XMLLoader::setFile(const QString &filename)
{
    if (filename.isEmpty())
        throw std::runtime_error("File isn't specified!");

    if (!QFile::exists(filename))
        throw std::runtime_error("File not found!");

    m_filename = filename;
    m_file.setFileName(m_filename);
}

void XMLLoader::parse()
{
    using vector = std::vector<std::pair<double, double>>;

    vector vec;
    std::thread t([&]
    {
        if (!m_file.open(QFile::ReadOnly))
        {
            std::cerr << "Failed while opening file!\n";
            return;
        }

        parser.setDevice(&m_file);

        while (!parser.atEnd())
        {
            if  (parser.isStartElement())
            {
                if (parser.name() == "radius")
                {
                    qDebug() << parser.readElementText();
                }

                if (parser.name() == "iteration")
                {
                    unsigned int size = parser.readElementText().toUInt();
                    vec.reserve(size);
                }
            }

            parser.readNext();
        }
    });
    t.detach();
}
