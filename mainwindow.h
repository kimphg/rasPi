#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <QTimer>
#include <c_config.h>
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
    void on_pushButton_pressed();

    void on_pushButton_kenh_1_pressed();

    void onRecvUART();
    //void on_pushButton_num_11_pressed();

    void on_pushButton_num_1_pressed();

    void on_pushButton_num_2_pressed();

    void on_pushButton_num_3_pressed();

    void on_pushButton_num_4_pressed();

    void on_pushButton_num_5_pressed();

    void on_pushButton_num_6_pressed();

    void on_pushButton_num_7_pressed();

    void on_pushButton_num_8_pressed();

    void on_pushButton_num_9_pressed();

    void on_pushButton_num_0_pressed();

    void on_pushButton_num_back_pressed();

    void on_pushButton_kenh_2_pressed();

    void on_pushButton_kenh_3_pressed();

    void on_pushButton_kenh_4_pressed();

    void on_pushButton_kenh_5_pressed();

    void on_pushButton_kenh_6_pressed();

    void on_pushButton_kenh_7_pressed();

    void on_pushButton_kenh_8_pressed();

    void on_pushButton_kenh_9_pressed();

    void on_pushButton_num_10_pressed();

    void on_pushButton_kenh_16_pressed();

    void on_pushButton_kenh_17_pressed();

    //void on_pushButton_num_control_phase_comp_2_pressed();

    void on_pushButton_num_control_afreq_pressed();

    void on_pushButton_num_control_phase_pressed();

    void on_pushButton_num_control_amp_pressed();
    void ioUpdate();
    void on_pushButton_num_control_ioupdate_pressed();

    void on_pushButton_clicked();

    void on_pushButton_num_control_up_2_pressed();

    void on_pushButton_commit_pressed();

    void on_pushButton_load_config_table_pressed();

//    void on_pushButton_sort_table_pressed();

    void on_pushButton_commit_2_pressed();

    void on_pushButton_sort_table_2_pressed();

    void on_pushButton_num_control_ioupdate_2_pressed();

    void on_pushButton_send_8bytes_pressed();

    void on_pushButton_set_all_freq_pressed();

private:
    Ui::MainWindow *ui;
    void selectChanel(unsigned char chanelNum);
    void inputText(QString text);
    void updateChanelInfo();
    void sendCommand(unsigned char *command, short chanel);
    int curChanelIndex ;

    bool setfreq(double value, int chanel);
    bool setPhase(double value, int chanel);
};

#endif // MAINWINDOW_H
