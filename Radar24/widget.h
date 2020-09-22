#ifndef WIDGET_H
#define WIDGET_H
#define WINDOW_BUILD
#ifdef WINDOW_BUILD
#include <QSerialPort>
#else
#endif
#include <QWidget>
//#include <QtSerialPort>
#include <QTimer>
#include "qcustomplot/qcustomplot.h"
#include <stdio.h>
//#include "raddsp.h"
#define MAXSUBPLOTS 3
#define MAXLINES 3

namespace Ui {
class Widget;
}


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
private:
    QObject* mythingy;
private slots:
    void on_Initchar_lineEdit_textChanged(const QString &arg1);
    void on_Serialavailable_comboBox_currentIndexChanged(const QString &arg1);
    void on_Serialbaud_comboBox_currentIndexChanged(const QString &arg1);
    void on_Start_pushButton_clicked();
    void on_Stop_pushButton_clicked();
    void on_Save_pushButton_clicked();
    void readData();
    void update_plot();
    void selectionChanged();
    void mousePress();
    void mouseWheel();

    void on_Numbersubplots_spinBox_valueChanged(int arg1);

    void number_of_lines_changed(int val);
    void color_changed(int val);
private slots:
    void deleteObject(QObject* thingy);
private:
    Ui::Widget *ui;
    QString serialportname;
    QString serialbaud;
    QString initchar;
#ifndef WINDOW_BUILD
#else
    QSerialPort serialport;
#endif
    QStringList datalist_console;
    QStringList datalist;
    QString lastdatalistline;
    QString firstdatalistline;
    QTimer* timer;
    int buf_size;
    int databefore;
    QByteArray incomingdata;
    QByteArray data;
    double initialtime;
    double finaltime;
    bool isfirst;
    int cur_data_type ;
// line struct
    struct Line_struct_t{
        QWidget* Line_Groupbox;
        QSpinBox* Xdata_Spinbox;
        QSpinBox* Ydata_Spinbox;
        QComboBox* Color_Combobox;
        QCPGraph* graph;
    };

//    struct Subplot
    struct Subplot_struct_t {
        QCPAxisRect* AxesRect;
        QWidget* Subplot_Groupbox;
        QSpinBox* NofLines_Spinbox;
        Line_struct_t lines[MAXLINES];
    };

    Subplot_struct_t Subplots[MAXSUBPLOTS];

//    QList<QCPAxisRect*> allAxesRect;
//    QCPAxisRect* allAxesRect_[MAXSUBPLOTS];

    void updateconsole(QByteArray incomingdata);

    QColor getcolor(int idx);
    bool setupGPIO();
    bool plot_data();
};

#endif // WIDGET_H
