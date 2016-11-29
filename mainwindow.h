#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <QTimer>
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
    void on_pushButton_clicked();

    void on_pushButton_kenh_1_clicked();

    void onRecvUART();
    void on_pushButton_num_11_clicked();

    void on_pushButton_num_1_clicked();

    void on_pushButton_num_2_clicked();

    void on_pushButton_num_3_clicked();

    void on_pushButton_num_4_clicked();

    void on_pushButton_num_5_clicked();

    void on_pushButton_num_6_clicked();

    void on_pushButton_num_7_clicked();

    void on_pushButton_num_8_clicked();

    void on_pushButton_num_9_clicked();

    void on_pushButton_num_0_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
