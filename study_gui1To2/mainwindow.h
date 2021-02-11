#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();
    void getData(QString);
signals:
    void sendData(QString);//发送数据的信号，不需要实体函数，在头文件定义就可以
private:
    Ui::MainWindow *ui;
    Dialog *gui2 = new Dialog();//初始化dialog窗口，实例化对象，可以在mainwindow中调用dialog的函数


};

#endif // MAINWINDOW_H
