#include "mainwindow.h"
#include "dialog.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   connect(gui2,SIGNAL(sendData(QString)),this,SLOT(getData(QString)));
   connect(this,SIGNAL(sendData(QString)),gui2,SLOT(getData(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
     gui2->show();
     QString strss = ui->lineEdit_2->text();
     emit sendData(strss);//发送数据，使用emit
}

void MainWindow::getData(QString str2)
{

  //  ui->lineEdit->text();
    ui->lineEdit->setText(str2);
}
