#ifndef DISPLAYCPU_H
#define DISPLAYCPU_H

#include <QWidget>
#include <QObject>
#include <QVBoxLayout>

class displayCPU
{
public:
    displayCPU();
    ~displayCPU();



private:
    vector<QVBoxLayout *> _boxes;
};

#endif // DISPLAYCPU_H
