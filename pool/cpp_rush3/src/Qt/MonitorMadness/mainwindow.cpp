#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modules/BatteryModule/Battery.hpp"
#include "modules/CPUModule/CPUModule.hpp"
#include "modules/DiskModule/Disk.hpp"
#include "modules/MonitorCore/MonitorCore.hpp"
#include "modules/NetworkModule/Network.hpp"
#include "modules/RamModule/Ram.hpp"
#include "modules/TemperatureModule/Temperature.hpp"
#include "modules/UserModule/User.hpp"
#include <QTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    MonitorCore MC = MonitorCore::getInstance();

    {
        QString uptimestr = QString::number(MC.getUser()->getUpTime());
        QTime uptime = QTime::fromString(uptimestr);
            QString uptimetext = uptime.toString("hh:mm");
        ui->upTimeValue->setText(uptimetext);

        QString timestr = QString::number(MC.getUser()->getUpTime());
        QTime time = QTime::fromString(timestr);
            QString timetext = time.toString("hh:mm");
        ui->timeValue->setText(timetext);

        ui->batteryValue->setText(QString::number(MC.getBattery()->getBattery()));
    }

    {
        int nb = MC.getCPU()->getCoreNb();

        ui->cputemp->setText(QString::number(MC.getTemperature()->getTemperature() / 1000));

        for (int i = 0; i < nb; i++) {
            QHBoxLayout *box = new QHBoxLayout;
            QLabel *cpu = new QLabel;
            QLabel *cpuStat = new QLabel;

            cpu->setText(QString("cpu") + (i + 48));
            float a = MC.getCPU()->getCore(i).getUsage();
            cpuStat->setText(QString::number(a));
            box->addWidget(cpu);
            box->addWidget(cpuStat);
            ui->cpuInsert->addLayout(box);
        }
    }

    {
        ui->processVal->setText(QString::number(MC.getRam()->getNbProcess()));
        ui->maxramVal->setText(QString::number(MC.getRam()->getMaxRam() / 1000000000));
        ui->usedramVal->setText(QString::number(MC.getRam()->getUsedRam() / 1000000000));
        ui->maxswapVal->setText(QString::number(MC.getRam()->getMaxSwap() / 1000000000));
        ui->usedswapVal->setText(QString::number(MC.getRam()->getUsedSwap() / 1000000000));
    }

    {
        ui->readVal->setText(QString::number(MC.getDisk()->getDiskRead()));
        ui->writeVal->setText(QString::number(MC.getDisk()->getDiskWrite()));
    }

    {
        ui->breceivedVal->setText(QString::number(MC.getNetwork()->getBytesReceived() / 1000000));
        ui->btransmittedVal->setText(QString::number(MC.getNetwork()->getBytesTransmitted() / 1000000));

        ui->preceivedVal->setText(QString::number(MC.getNetwork()->getPacketsReceived() / 1000000));
        ui->ptransmittedVal->setText(QString::number(MC.getNetwork()->getPacketsTransmitted() / 1000000));
    }

    {
        ui->kernelValue->setText(QString::fromStdString(MC.getUser()->getKernel()));
        ui->osversionValue->setText(QString::fromStdString(MC.getUser()->getOsVersion()));
        ui->machineValue->setText(QString::fromStdString(MC.getUser()->getMachine()));
        ui->sysNameValue->setText(QString::fromStdString(MC.getUser()->getSysName()));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
