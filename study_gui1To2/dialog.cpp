#include "dialog.h"
#include "mainwindow.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString str2 = ui->lineEdit_senddata->text();
      emit sendData(str2);


}

void Dialog::getData(QString str1)
{
 ui->lineEdit_getdata->setText(str1);
}
