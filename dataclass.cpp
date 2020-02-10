#include "dataclass.h"

DataClass::DataClass(QObject *parent) : QObject(parent)
{

}

DataClass::~DataClass()
{

}

DataClass::DataClass(unsigned int iterations, short radius, QObject * parent) : QObject(parent), m_iterations(iterations), m_radius(radius)
{
    m_data.reserve(static_cast<size_t>(iterations));
}

void DataClass::setRadius(short radius)
{
    m_radius = radius;
}

void DataClass::setIterations(unsigned int iterations)
{
    m_iterations = iterations;
    m_data.reserve(static_cast<size_t>(iterations));
}

short DataClass::getRadius() const
{
    return m_radius;
}

unsigned int DataClass::getIterations() const
{
    return m_iterations;
}

void DataClass::setData(std::vector<std::pair<double, double>> & data)
{
    m_data = std::move(data);
}
