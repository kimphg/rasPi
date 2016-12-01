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

    void on_pushButton_num_back_clicked();

    void on_pushButton_kenh_2_clicked();

    void on_pushButton_kenh_3_clicked();

    void on_pushButton_kenh_4_clicked();

    void on_pushButton_kenh_5_clicked();

    void on_pushButton_kenh_6_clicked();

    void on_pushButton_kenh_7_clicked();

    void on_pushButton_kenh_8_clicked();

    void on_pushButton_kenh_9_clicked();

    void on_pushButton_num_10_clicked();

    void on_pushButton_kenh_16_clicked();

    void on_pushButton_kenh_17_clicked();

    void on_pushButton_num_control_phase_comp_2_clicked();

    void on_pushButton_num_control_afreq_pressed();

    void on_pushButton_num_control_phase_pressed();

private:
    Ui::MainWindow *ui;
    void selectChanel(unsigned char chanelNum);
    void inputText(QString text);
    void updateChanelInfo();
    void sendCommand();
    int curChanelIndex ;
};

#endif // MAINWINDOW_H
