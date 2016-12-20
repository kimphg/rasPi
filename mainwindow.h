#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <QTimer>
#include <c_config.h>
#include <QTableWidgetItem>
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
    void updateTemp();
    void on_pushButton_kenh_1_clicked();
    int onRecvUART();
    //void on_pushButton_num_11_clicked();

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

    //void on_pushButton_num_control_phase_comp_2_clicked();

    void on_pushButton_num_control_afreq_clicked();

    void on_pushButton_num_control_phase_clicked();

    void on_pushButton_num_control_amp_clicked();
    void ioUpdate();
    void on_pushButton_num_control_ioupdate_clicked();

    //void on_pushButton_clicked();

    void on_pushButton_num_control_up_2_clicked();

    void on_pushButton_commit_clicked();

    void on_pushButton_load_config_table_clicked();

//    void on_pushButton_sort_table_clicked();

    void on_pushButton_commit_2_clicked();

    void on_pushButton_sort_table_2_clicked();

    void on_pushButton_num_control_ioupdate_2_clicked();

    void on_pushButton_send_8bytes_clicked();

    void on_pushButton_set_all_freq_clicked();

    void on_pushButton_num_control_up_clicked();
    void on_pushButton_num_control_down_2_clicked();

    void on_pushButton_num_control_down_3_clicked();

    void on_pushButton_num_control_down_clicked();

    void on_pushButton_num_minus_clicked();


    void on_tableWidget_itemClicked(QTableWidgetItem *item);

protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;

    void selectChanel(unsigned char chanelNum);
    void inputText(QString text);
    void updateChanelInfo();
    void sendCommand(unsigned char *command, short chanel);
    int curChanelIndex ;

    bool setfreq(double value, unsigned int chanel);
    bool setPhaseTrue(double value, unsigned int chanel);
    void loadConfigTable();
    void showStatus(QString str);
    void setPhaseComp(double value, unsigned int chanel);
    void delayms(int msec);
    void setAmp(double value, unsigned int chanel);
    void txOn(int chanel);
    void txOff(int chanel);

    void sendCommand(unsigned char *command);
};

#endif // MAINWINDOW_H
