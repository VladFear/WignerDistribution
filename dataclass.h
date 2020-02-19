#ifndef DATACLASS_H
#define DATACLASS_H

#include <QObject>
#include <vector>
#include <tuple>

class DataClass : public QObject
{
    Q_OBJECT

private:
    unsigned int m_iterations;
    short m_radius;
    std::vector<std::pair<double, double>> m_data;

public:
    explicit DataClass(QObject * parent = nullptr);
    virtual ~DataClass();
    DataClass(unsigned int iterations, short radius, QObject * parent = nullptr);
    void setRadius(short radius);
    void setIterations(unsigned int iterations);
    short getRadius() const;
    unsigned int getIterations() const;
    void setData(std::vector<std::pair<double, double>> & data);

    void operator=(const DataClass & dataClass) = delete;
    DataClass(const DataClass & dataClass) = delete;

signals:

public slots:
};

#endif // DATACLASS_H
