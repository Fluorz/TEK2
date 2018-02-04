/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *TimeLayout;
    QLabel *upTimeValue;
    QFrame *line;
    QLabel *timeValue;
    QFrame *line_2;
    QLabel *batteryValue;
    QLabel *batteryPercent;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *BOX;
    QVBoxLayout *CpuRamLayout;
    QVBoxLayout *CPUMODULE;
    QLabel *CPUModuleLabel;
    QFrame *CpuSep;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLabel *cputemp;
    QVBoxLayout *cpuInsert;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *RAMMODULE;
    QLabel *RAMModuleLabel;
    QFrame *line_3;
    QVBoxLayout *ramInsert_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *maxramlabel_5;
    QLabel *processVal;
    QFrame *line_7;
    QVBoxLayout *ramInsert;
    QHBoxLayout *horizontalLayout;
    QLabel *maxramlabel;
    QLabel *maxramVal;
    QLabel *label;
    QVBoxLayout *ramInsert_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *maxramlabel_2;
    QLabel *usedramVal;
    QLabel *label_2;
    QFrame *line_8;
    QVBoxLayout *ramInsert_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *maxramlabel_3;
    QLabel *maxswapVal;
    QLabel *label_3;
    QVBoxLayout *ramInsert_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *maxramlabel_4;
    QLabel *usedswapVal;
    QLabel *label_4;
    QFrame *line_4;
    QVBoxLayout *DISKNETW;
    QVBoxLayout *CPUMODULE_2;
    QLabel *CPUModuleLabel_2;
    QFrame *CpuSep_2;
    QVBoxLayout *cpuInsert_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLabel *readVal;
    QVBoxLayout *cpuInsert_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *writeVal;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *RAMMODULE_2;
    QLabel *RAMModuleLabel_2;
    QFrame *line_5;
    QVBoxLayout *ramInsert_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLabel *breceivedVal;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLabel *btransmittedVal;
    QLabel *breceivedVal_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLabel *preceivedVal;
    QLabel *breceivedVal_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLabel *ptransmittedVal;
    QLabel *breceivedVal_4;
    QFrame *line_6;
    QVBoxLayout *USERMODULE;
    QLabel *DiskModuleLabel_2;
    QFrame *DiskSep_2;
    QHBoxLayout *userItemLayout;
    QLabel *kernel;
    QLabel *kernelValue;
    QHBoxLayout *rowUserLayout2;
    QLabel *kernel_2;
    QLabel *osversionValue;
    QHBoxLayout *rowUserLayout3;
    QLabel *machine;
    QLabel *machineValue;
    QHBoxLayout *rowLayoutDisk_2;
    QLabel *sysName;
    QLabel *sysNameValue;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(731, 663);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(420, 10, 301, 31));
        TimeLayout = new QHBoxLayout(horizontalLayoutWidget);
        TimeLayout->setSpacing(6);
        TimeLayout->setContentsMargins(11, 11, 11, 11);
        TimeLayout->setObjectName(QStringLiteral("TimeLayout"));
        TimeLayout->setContentsMargins(0, 0, 0, 0);
        upTimeValue = new QLabel(horizontalLayoutWidget);
        upTimeValue->setObjectName(QStringLiteral("upTimeValue"));
        upTimeValue->setAlignment(Qt::AlignCenter);

        TimeLayout->addWidget(upTimeValue);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        TimeLayout->addWidget(line);

        timeValue = new QLabel(horizontalLayoutWidget);
        timeValue->setObjectName(QStringLiteral("timeValue"));
        timeValue->setAlignment(Qt::AlignCenter);

        TimeLayout->addWidget(timeValue);

        line_2 = new QFrame(horizontalLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        TimeLayout->addWidget(line_2);

        batteryValue = new QLabel(horizontalLayoutWidget);
        batteryValue->setObjectName(QStringLiteral("batteryValue"));
        batteryValue->setLineWidth(0);
        batteryValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        TimeLayout->addWidget(batteryValue);

        batteryPercent = new QLabel(horizontalLayoutWidget);
        batteryPercent->setObjectName(QStringLiteral("batteryPercent"));

        TimeLayout->addWidget(batteryPercent);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 110, 711, 334));
        BOX = new QHBoxLayout(horizontalLayoutWidget_2);
        BOX->setSpacing(6);
        BOX->setContentsMargins(11, 11, 11, 11);
        BOX->setObjectName(QStringLiteral("BOX"));
        BOX->setContentsMargins(0, 0, 0, 0);
        CpuRamLayout = new QVBoxLayout();
        CpuRamLayout->setSpacing(6);
        CpuRamLayout->setObjectName(QStringLiteral("CpuRamLayout"));
        CPUMODULE = new QVBoxLayout();
        CPUMODULE->setSpacing(6);
        CPUMODULE->setObjectName(QStringLiteral("CPUMODULE"));
        CPUModuleLabel = new QLabel(horizontalLayoutWidget_2);
        CPUModuleLabel->setObjectName(QStringLiteral("CPUModuleLabel"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        CPUModuleLabel->setFont(font);
        CPUModuleLabel->setAlignment(Qt::AlignCenter);

        CPUMODULE->addWidget(CPUModuleLabel);

        CpuSep = new QFrame(horizontalLayoutWidget_2);
        CpuSep->setObjectName(QStringLiteral("CpuSep"));
        CpuSep->setFrameShape(QFrame::HLine);
        CpuSep->setFrameShadow(QFrame::Sunken);

        CPUMODULE->addWidget(CpuSep);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_11 = new QLabel(horizontalLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_12->addWidget(label_11);

        cputemp = new QLabel(horizontalLayoutWidget_2);
        cputemp->setObjectName(QStringLiteral("cputemp"));

        horizontalLayout_12->addWidget(cputemp);


        CPUMODULE->addLayout(horizontalLayout_12);

        cpuInsert = new QVBoxLayout();
        cpuInsert->setSpacing(6);
        cpuInsert->setObjectName(QStringLiteral("cpuInsert"));

        CPUMODULE->addLayout(cpuInsert);


        CpuRamLayout->addLayout(CPUMODULE);

        verticalSpacer = new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        CpuRamLayout->addItem(verticalSpacer);

        RAMMODULE = new QVBoxLayout();
        RAMMODULE->setSpacing(6);
        RAMMODULE->setObjectName(QStringLiteral("RAMMODULE"));
        RAMModuleLabel = new QLabel(horizontalLayoutWidget_2);
        RAMModuleLabel->setObjectName(QStringLiteral("RAMModuleLabel"));
        RAMModuleLabel->setFont(font);
        RAMModuleLabel->setAlignment(Qt::AlignCenter);

        RAMMODULE->addWidget(RAMModuleLabel);

        line_3 = new QFrame(horizontalLayoutWidget_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        RAMMODULE->addWidget(line_3);

        ramInsert_6 = new QVBoxLayout();
        ramInsert_6->setSpacing(6);
        ramInsert_6->setObjectName(QStringLiteral("ramInsert_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        maxramlabel_5 = new QLabel(horizontalLayoutWidget_2);
        maxramlabel_5->setObjectName(QStringLiteral("maxramlabel_5"));

        horizontalLayout_5->addWidget(maxramlabel_5);

        processVal = new QLabel(horizontalLayoutWidget_2);
        processVal->setObjectName(QStringLiteral("processVal"));

        horizontalLayout_5->addWidget(processVal);


        ramInsert_6->addLayout(horizontalLayout_5);


        RAMMODULE->addLayout(ramInsert_6);

        line_7 = new QFrame(horizontalLayoutWidget_2);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        RAMMODULE->addWidget(line_7);

        ramInsert = new QVBoxLayout();
        ramInsert->setSpacing(6);
        ramInsert->setObjectName(QStringLiteral("ramInsert"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        maxramlabel = new QLabel(horizontalLayoutWidget_2);
        maxramlabel->setObjectName(QStringLiteral("maxramlabel"));

        horizontalLayout->addWidget(maxramlabel);

        maxramVal = new QLabel(horizontalLayoutWidget_2);
        maxramVal->setObjectName(QStringLiteral("maxramVal"));

        horizontalLayout->addWidget(maxramVal);

        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);


        ramInsert->addLayout(horizontalLayout);


        RAMMODULE->addLayout(ramInsert);

        ramInsert_3 = new QVBoxLayout();
        ramInsert_3->setSpacing(6);
        ramInsert_3->setObjectName(QStringLiteral("ramInsert_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        maxramlabel_2 = new QLabel(horizontalLayoutWidget_2);
        maxramlabel_2->setObjectName(QStringLiteral("maxramlabel_2"));

        horizontalLayout_2->addWidget(maxramlabel_2);

        usedramVal = new QLabel(horizontalLayoutWidget_2);
        usedramVal->setObjectName(QStringLiteral("usedramVal"));

        horizontalLayout_2->addWidget(usedramVal);

        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);


        ramInsert_3->addLayout(horizontalLayout_2);


        RAMMODULE->addLayout(ramInsert_3);

        line_8 = new QFrame(horizontalLayoutWidget_2);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        RAMMODULE->addWidget(line_8);

        ramInsert_4 = new QVBoxLayout();
        ramInsert_4->setSpacing(6);
        ramInsert_4->setObjectName(QStringLiteral("ramInsert_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        maxramlabel_3 = new QLabel(horizontalLayoutWidget_2);
        maxramlabel_3->setObjectName(QStringLiteral("maxramlabel_3"));

        horizontalLayout_3->addWidget(maxramlabel_3);

        maxswapVal = new QLabel(horizontalLayoutWidget_2);
        maxswapVal->setObjectName(QStringLiteral("maxswapVal"));

        horizontalLayout_3->addWidget(maxswapVal);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);


        ramInsert_4->addLayout(horizontalLayout_3);


        RAMMODULE->addLayout(ramInsert_4);

        ramInsert_5 = new QVBoxLayout();
        ramInsert_5->setSpacing(6);
        ramInsert_5->setObjectName(QStringLiteral("ramInsert_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        maxramlabel_4 = new QLabel(horizontalLayoutWidget_2);
        maxramlabel_4->setObjectName(QStringLiteral("maxramlabel_4"));

        horizontalLayout_4->addWidget(maxramlabel_4);

        usedswapVal = new QLabel(horizontalLayoutWidget_2);
        usedswapVal->setObjectName(QStringLiteral("usedswapVal"));

        horizontalLayout_4->addWidget(usedswapVal);

        label_4 = new QLabel(horizontalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);


        ramInsert_5->addLayout(horizontalLayout_4);


        RAMMODULE->addLayout(ramInsert_5);


        CpuRamLayout->addLayout(RAMMODULE);


        BOX->addLayout(CpuRamLayout);

        line_4 = new QFrame(horizontalLayoutWidget_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        BOX->addWidget(line_4);

        DISKNETW = new QVBoxLayout();
        DISKNETW->setSpacing(6);
        DISKNETW->setObjectName(QStringLiteral("DISKNETW"));
        CPUMODULE_2 = new QVBoxLayout();
        CPUMODULE_2->setSpacing(6);
        CPUMODULE_2->setObjectName(QStringLiteral("CPUMODULE_2"));
        CPUModuleLabel_2 = new QLabel(horizontalLayoutWidget_2);
        CPUModuleLabel_2->setObjectName(QStringLiteral("CPUModuleLabel_2"));
        CPUModuleLabel_2->setFont(font);
        CPUModuleLabel_2->setAlignment(Qt::AlignCenter);

        CPUMODULE_2->addWidget(CPUModuleLabel_2);

        CpuSep_2 = new QFrame(horizontalLayoutWidget_2);
        CpuSep_2->setObjectName(QStringLiteral("CpuSep_2"));
        CpuSep_2->setFrameShape(QFrame::HLine);
        CpuSep_2->setFrameShadow(QFrame::Sunken);

        CPUMODULE_2->addWidget(CpuSep_2);

        cpuInsert_2 = new QVBoxLayout();
        cpuInsert_2->setSpacing(6);
        cpuInsert_2->setObjectName(QStringLiteral("cpuInsert_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(horizontalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        readVal = new QLabel(horizontalLayoutWidget_2);
        readVal->setObjectName(QStringLiteral("readVal"));

        horizontalLayout_6->addWidget(readVal);


        cpuInsert_2->addLayout(horizontalLayout_6);

        cpuInsert_3 = new QVBoxLayout();
        cpuInsert_3->setSpacing(6);
        cpuInsert_3->setObjectName(QStringLiteral("cpuInsert_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        writeVal = new QLabel(horizontalLayoutWidget_2);
        writeVal->setObjectName(QStringLiteral("writeVal"));

        horizontalLayout_7->addWidget(writeVal);


        cpuInsert_3->addLayout(horizontalLayout_7);


        cpuInsert_2->addLayout(cpuInsert_3);


        CPUMODULE_2->addLayout(cpuInsert_2);


        DISKNETW->addLayout(CPUMODULE_2);

        verticalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        DISKNETW->addItem(verticalSpacer_2);

        RAMMODULE_2 = new QVBoxLayout();
        RAMMODULE_2->setSpacing(6);
        RAMMODULE_2->setObjectName(QStringLiteral("RAMMODULE_2"));
        RAMModuleLabel_2 = new QLabel(horizontalLayoutWidget_2);
        RAMModuleLabel_2->setObjectName(QStringLiteral("RAMModuleLabel_2"));
        RAMModuleLabel_2->setFont(font);
        RAMModuleLabel_2->setAlignment(Qt::AlignCenter);

        RAMMODULE_2->addWidget(RAMModuleLabel_2);

        line_5 = new QFrame(horizontalLayoutWidget_2);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        RAMMODULE_2->addWidget(line_5);

        ramInsert_2 = new QVBoxLayout();
        ramInsert_2->setSpacing(6);
        ramInsert_2->setObjectName(QStringLiteral("ramInsert_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_8->addWidget(label_7);

        breceivedVal = new QLabel(horizontalLayoutWidget_2);
        breceivedVal->setObjectName(QStringLiteral("breceivedVal"));

        horizontalLayout_8->addWidget(breceivedVal);

        label_12 = new QLabel(horizontalLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_8->addWidget(label_12);


        ramInsert_2->addLayout(horizontalLayout_8);


        RAMMODULE_2->addLayout(ramInsert_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_8 = new QLabel(horizontalLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_9->addWidget(label_8);

        btransmittedVal = new QLabel(horizontalLayoutWidget_2);
        btransmittedVal->setObjectName(QStringLiteral("btransmittedVal"));

        horizontalLayout_9->addWidget(btransmittedVal);

        breceivedVal_2 = new QLabel(horizontalLayoutWidget_2);
        breceivedVal_2->setObjectName(QStringLiteral("breceivedVal_2"));

        horizontalLayout_9->addWidget(breceivedVal_2);


        RAMMODULE_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(horizontalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);

        preceivedVal = new QLabel(horizontalLayoutWidget_2);
        preceivedVal->setObjectName(QStringLiteral("preceivedVal"));

        horizontalLayout_10->addWidget(preceivedVal);

        breceivedVal_3 = new QLabel(horizontalLayoutWidget_2);
        breceivedVal_3->setObjectName(QStringLiteral("breceivedVal_3"));

        horizontalLayout_10->addWidget(breceivedVal_3);


        RAMMODULE_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(horizontalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_11->addWidget(label_10);

        ptransmittedVal = new QLabel(horizontalLayoutWidget_2);
        ptransmittedVal->setObjectName(QStringLiteral("ptransmittedVal"));

        horizontalLayout_11->addWidget(ptransmittedVal);

        breceivedVal_4 = new QLabel(horizontalLayoutWidget_2);
        breceivedVal_4->setObjectName(QStringLiteral("breceivedVal_4"));

        horizontalLayout_11->addWidget(breceivedVal_4);


        RAMMODULE_2->addLayout(horizontalLayout_11);


        DISKNETW->addLayout(RAMMODULE_2);


        BOX->addLayout(DISKNETW);

        line_6 = new QFrame(horizontalLayoutWidget_2);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        BOX->addWidget(line_6);

        USERMODULE = new QVBoxLayout();
        USERMODULE->setSpacing(6);
        USERMODULE->setObjectName(QStringLiteral("USERMODULE"));
        DiskModuleLabel_2 = new QLabel(horizontalLayoutWidget_2);
        DiskModuleLabel_2->setObjectName(QStringLiteral("DiskModuleLabel_2"));
        DiskModuleLabel_2->setFont(font);
        DiskModuleLabel_2->setAlignment(Qt::AlignCenter);

        USERMODULE->addWidget(DiskModuleLabel_2);

        DiskSep_2 = new QFrame(horizontalLayoutWidget_2);
        DiskSep_2->setObjectName(QStringLiteral("DiskSep_2"));
        DiskSep_2->setFrameShape(QFrame::HLine);
        DiskSep_2->setFrameShadow(QFrame::Sunken);

        USERMODULE->addWidget(DiskSep_2);

        userItemLayout = new QHBoxLayout();
        userItemLayout->setSpacing(6);
        userItemLayout->setObjectName(QStringLiteral("userItemLayout"));
        kernel = new QLabel(horizontalLayoutWidget_2);
        kernel->setObjectName(QStringLiteral("kernel"));

        userItemLayout->addWidget(kernel);

        kernelValue = new QLabel(horizontalLayoutWidget_2);
        kernelValue->setObjectName(QStringLiteral("kernelValue"));

        userItemLayout->addWidget(kernelValue);


        USERMODULE->addLayout(userItemLayout);

        rowUserLayout2 = new QHBoxLayout();
        rowUserLayout2->setSpacing(6);
        rowUserLayout2->setObjectName(QStringLiteral("rowUserLayout2"));
        kernel_2 = new QLabel(horizontalLayoutWidget_2);
        kernel_2->setObjectName(QStringLiteral("kernel_2"));

        rowUserLayout2->addWidget(kernel_2);

        osversionValue = new QLabel(horizontalLayoutWidget_2);
        osversionValue->setObjectName(QStringLiteral("osversionValue"));
        osversionValue->setMaximumSize(QSize(150, 150));

        rowUserLayout2->addWidget(osversionValue);


        USERMODULE->addLayout(rowUserLayout2);

        rowUserLayout3 = new QHBoxLayout();
        rowUserLayout3->setSpacing(6);
        rowUserLayout3->setObjectName(QStringLiteral("rowUserLayout3"));
        machine = new QLabel(horizontalLayoutWidget_2);
        machine->setObjectName(QStringLiteral("machine"));

        rowUserLayout3->addWidget(machine);

        machineValue = new QLabel(horizontalLayoutWidget_2);
        machineValue->setObjectName(QStringLiteral("machineValue"));

        rowUserLayout3->addWidget(machineValue);


        USERMODULE->addLayout(rowUserLayout3);

        rowLayoutDisk_2 = new QHBoxLayout();
        rowLayoutDisk_2->setSpacing(6);
        rowLayoutDisk_2->setObjectName(QStringLiteral("rowLayoutDisk_2"));
        sysName = new QLabel(horizontalLayoutWidget_2);
        sysName->setObjectName(QStringLiteral("sysName"));

        rowLayoutDisk_2->addWidget(sysName);

        sysNameValue = new QLabel(horizontalLayoutWidget_2);
        sysNameValue->setObjectName(QStringLiteral("sysNameValue"));

        rowLayoutDisk_2->addWidget(sysNameValue);


        USERMODULE->addLayout(rowLayoutDisk_2);


        BOX->addLayout(USERMODULE);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        upTimeValue->setText(QApplication::translate("MainWindow", "uptime", Q_NULLPTR));
        timeValue->setText(QApplication::translate("MainWindow", "time", Q_NULLPTR));
        batteryValue->setText(QApplication::translate("MainWindow", "battery", Q_NULLPTR));
        batteryPercent->setText(QApplication::translate("MainWindow", "%", Q_NULLPTR));
        CPUModuleLabel->setText(QApplication::translate("MainWindow", "CPU", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Temperature", Q_NULLPTR));
        cputemp->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        RAMModuleLabel->setText(QApplication::translate("MainWindow", "RAM", Q_NULLPTR));
        maxramlabel_5->setText(QApplication::translate("MainWindow", "Process", Q_NULLPTR));
        processVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        maxramlabel->setText(QApplication::translate("MainWindow", "Max Ram", Q_NULLPTR));
        maxramVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Go", Q_NULLPTR));
        maxramlabel_2->setText(QApplication::translate("MainWindow", "Used Ram", Q_NULLPTR));
        usedramVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Go", Q_NULLPTR));
        maxramlabel_3->setText(QApplication::translate("MainWindow", "Max Swap", Q_NULLPTR));
        maxswapVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Go", Q_NULLPTR));
        maxramlabel_4->setText(QApplication::translate("MainWindow", "Used Swap", Q_NULLPTR));
        usedswapVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Go", Q_NULLPTR));
        CPUModuleLabel_2->setText(QApplication::translate("MainWindow", "DISK", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Read", Q_NULLPTR));
        readVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Write", Q_NULLPTR));
        writeVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        RAMModuleLabel_2->setText(QApplication::translate("MainWindow", "NETWORK", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Bytes Received", Q_NULLPTR));
        breceivedVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Mo/s", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Bytes Transmitted", Q_NULLPTR));
        btransmittedVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        breceivedVal_2->setText(QApplication::translate("MainWindow", "Mo/s", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Packets Received", Q_NULLPTR));
        preceivedVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        breceivedVal_3->setText(QApplication::translate("MainWindow", "Mo/s", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Packets Transmitted", Q_NULLPTR));
        ptransmittedVal->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        breceivedVal_4->setText(QApplication::translate("MainWindow", "Mo/s", Q_NULLPTR));
        DiskModuleLabel_2->setText(QApplication::translate("MainWindow", "User", Q_NULLPTR));
        kernel->setText(QApplication::translate("MainWindow", "Kernel", Q_NULLPTR));
        kernelValue->setText(QString());
        kernel_2->setText(QApplication::translate("MainWindow", "OS Version", Q_NULLPTR));
        osversionValue->setText(QString());
        machine->setText(QApplication::translate("MainWindow", "Machine", Q_NULLPTR));
        machineValue->setText(QString());
        sysName->setText(QApplication::translate("MainWindow", "System Name", Q_NULLPTR));
        sysNameValue->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
