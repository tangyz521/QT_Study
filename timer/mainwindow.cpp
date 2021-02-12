#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   timer(new QTimer),
   timer1(new QTimer),
   timer2(new QTimer),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer->setInterval(100);
    timer->start();
    timer1->setInterval(100);
    timer1->start();
    timer2->setInterval(1000);
    timer2->start();

    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));
    connect(timer1, SIGNAL(timeout()), this, SLOT(timerSlot1()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(timerSlot2()));

}
void MainWindow::timerSlot()
{  static double test_i=0;
    if (QObject::sender() == timer)
    {
        test_i +=0.1;
        ui->label_10->setText(tr("100ms定时 秒表1:")  +  QString::number(test_i,'.',2));
    }
}
void MainWindow::timerSlot1()//100ms定时
{ static double test_i=0;

    if (QObject::sender() == timer1)
    {
        test_i +=0.1;
        ui->label_11->setText(tr("100ms定时 秒表2:")  +  QString::number(test_i,'.',2));
        qDebug("%.2f",test_i);
    }
}
void MainWindow::timerSlot2() //1000ms定时
{ static int test_i=0;
  static int testFlage=0;
  static int testIntStartTimer=0;
    if (QObject::sender() == timer2)
    {
       // QDateTime time1 = QDateTime::fromString("2018-03-19 16:40:02", "yyyy-MM-dd hh:mm:ss:mmm");
       // QDateTime time2 = QDateTime::fromString("2018-03-19 16:43:02", "yyyy-MM-dd hh:mm:ss:mmm");
       // qDebug() << "time2 - time1=" << time1.secsTo(time2);
      QDateTime QDateStartTime = QDateTime::currentDateTime();
      QDateTime QDateEndtTime = QDateTime::currentDateTime();
      int testIntEndTimer = QDateEndtTime.toTime_t();
          test_i=test_i+1;
       ui->label_12->setText(tr("1s定时 秒表:") + QString::number(test_i,10));
       if(testFlage==0)
       {
        testIntStartTimer= QDateStartTime.toTime_t();
        testFlage=1;
       }
       else
       {
        int DebugTestDate = (testIntEndTimer- testIntStartTimer) + 1;
        ui->label_13->setText(tr("系统时间先减 秒表:") + QString::number(DebugTestDate,10));
       }
     }
}

MainWindow::~MainWindow()
{
    delete ui;
}
