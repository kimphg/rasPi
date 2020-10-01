#include "widget.h"
#include "ui_widget.h"

//#include <QtSerialPort>
#include <QDebug>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QTimer>
#include <QMap>
#ifdef WINDOW_BUILD
#include <QSerialPortInfo>
#else
//for raspi:apt-get install libqt5serialport5(-dev)
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#endif

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->frame_setting->setHidden(true);
    this->showFullScreen();
    plot_type=1;
//     check all the available serial ports
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->Serialavailable_comboBox->addItem(info.portName());
    }
    buf_size = 4096;
    // setup the possible serial baud speed
    QStringList baudlist;
    baudlist << "1200" << "2400" << "4800" << "9600" << "19200" << "38400" << "57600" << "115200";
    ui->Serialbaud_comboBox->addItems(baudlist);
    ui->Serialbaud_comboBox->setCurrentIndex(7);

    // set the default init char
    ui->Initchar_lineEdit->setText("!");
    initchar = ui->Initchar_lineEdit->text();

    // serial data available signal
    connect(&serialport, SIGNAL(readyRead()), this, SLOT(readData()));



    // timer for asincronous plot
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_plot()));

//    ui->frame_setting->setHidden(true);
    lastdatalistline = "";
    isfirst = true;

    // initial qsplitter size
    // Set the initial sizes for QSplitter widgets
    QList<int> sizes;
    sizes << 900 << 10 << 100;
    ui->splitter->setSizes(sizes);

    // plot setup
    ui->Plot->plotLayout()->clear();
    ui->Plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iMultiSelect);
//    ui->Plot->setMultiSelectModifier(Qt::NoModifier);
    // initialize all subplots
    connect(ui->Plot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
    connect(ui->Plot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
    connect(ui->Plot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));


    Subplots[0].Subplot_Groupbox = ui->Subplot_groupBox_1;
    Subplots[1].Subplot_Groupbox = ui->Subplot_groupBox_2;
    Subplots[2].Subplot_Groupbox = ui->Subplot_groupBox_3;
    Subplots[0].NofLines_Spinbox = ui->numberlines_spinBox_1;
    Subplots[1].NofLines_Spinbox = ui->numberlines_spinBox_2;
    Subplots[2].NofLines_Spinbox = ui->numberlines_spinBox_3;
    // lines groupbox
    Subplots[0].lines[0].Line_Groupbox = ui->line_groupBox_1_1;
    Subplots[0].lines[1].Line_Groupbox = ui->line_groupBox_1_2;
    Subplots[0].lines[2].Line_Groupbox = ui->line_groupBox_1_3;
    Subplots[1].lines[0].Line_Groupbox = ui->line_groupBox_2_1;
    Subplots[1].lines[1].Line_Groupbox = ui->line_groupBox_2_2;
    Subplots[1].lines[2].Line_Groupbox = ui->line_groupBox_2_3;
    Subplots[2].lines[0].Line_Groupbox = ui->line_groupBox_3_1;
    Subplots[2].lines[1].Line_Groupbox = ui->line_groupBox_3_2;
    Subplots[2].lines[2].Line_Groupbox = ui->line_groupBox_3_3;
    // x data spinbox
    Subplots[0].lines[0].Xdata_Spinbox = ui->x_spinBox_1_1;
    Subplots[0].lines[1].Xdata_Spinbox = ui->x_spinBox_1_2;
    Subplots[0].lines[2].Xdata_Spinbox = ui->x_spinBox_1_3;
    Subplots[1].lines[0].Xdata_Spinbox = ui->x_spinBox_2_1;
    Subplots[1].lines[1].Xdata_Spinbox = ui->x_spinBox_2_2;
    Subplots[1].lines[2].Xdata_Spinbox = ui->x_spinBox_2_3;
    Subplots[2].lines[0].Xdata_Spinbox = ui->x_spinBox_3_1;
    Subplots[2].lines[1].Xdata_Spinbox = ui->x_spinBox_3_2;
    Subplots[2].lines[2].Xdata_Spinbox = ui->x_spinBox_3_3;
    // y data spinbox
    Subplots[0].lines[0].Ydata_Spinbox = ui->y_spinBox_1_1;
    Subplots[0].lines[1].Ydata_Spinbox = ui->y_spinBox_1_2;
    Subplots[0].lines[2].Ydata_Spinbox = ui->y_spinBox_1_3;
    Subplots[1].lines[0].Ydata_Spinbox = ui->y_spinBox_2_1;
    Subplots[1].lines[1].Ydata_Spinbox = ui->y_spinBox_2_2;
    Subplots[1].lines[2].Ydata_Spinbox = ui->y_spinBox_2_3;
    Subplots[2].lines[0].Ydata_Spinbox = ui->y_spinBox_3_1;
    Subplots[2].lines[1].Ydata_Spinbox = ui->y_spinBox_3_2;
    Subplots[2].lines[2].Ydata_Spinbox = ui->y_spinBox_3_3;
    // color combobox
    Subplots[0].lines[0].Color_Combobox = ui->color_comboBox_1_1;
    Subplots[0].lines[1].Color_Combobox = ui->color_comboBox_1_2;
    Subplots[0].lines[2].Color_Combobox = ui->color_comboBox_1_3;
    Subplots[1].lines[0].Color_Combobox = ui->color_comboBox_2_1;
    Subplots[1].lines[1].Color_Combobox = ui->color_comboBox_2_2;
    Subplots[1].lines[2].Color_Combobox = ui->color_comboBox_2_3;
    Subplots[2].lines[0].Color_Combobox = ui->color_comboBox_3_1;
    Subplots[2].lines[1].Color_Combobox = ui->color_comboBox_3_2;
    Subplots[2].lines[2].Color_Combobox = ui->color_comboBox_3_3;

    for (int i = 0; i < MAXSUBPLOTS; i++) {
        Subplots[i].AxesRect = NULL;
    }

    for (int i = 0; i < MAXSUBPLOTS; i++) {
        Subplots[i].Subplot_Groupbox->hide();
        for(int k = 0; k < MAXLINES; k++) {
            Subplots[i].lines[k].Line_Groupbox->hide();
            Subplots[i].lines[k].graph = NULL;
            connect(Subplots[i].lines[k].Color_Combobox, SIGNAL(currentIndexChanged(int)), this, SLOT(color_changed(int)));
        }
        connect(Subplots[i].NofLines_Spinbox, SIGNAL(valueChanged(int)), this, SLOT(number_of_lines_changed(int)));
        Subplots[i].NofLines_Spinbox->setValue(1);
        Subplots[i].NofLines_Spinbox->setMaximum(MAXLINES);
    }

    ui->Numbersubplots_spinBox->setValue(1);
    ui->Numbersubplots_spinBox->setMaximum(MAXSUBPLOTS);



//    Subplots[0].lines[0].graph = ui->Plot->addGraph(Subplots[0].AxesRect->axis(QCPAxis::atBottom), Subplots[0].AxesRect->axis(QCPAxis::atLeft));

    mythingy = new QObject(this);
//    RadDSP* worker = new RadDSP(mythingy, this);
//    connect(worker, SIGNAL(deleteObject(QObject*)), this, SLOT(deleteObject(QObject*)));
    // plot extremes
    initialtime = -9999.0;
    finaltime   = -9999.0;


}

void Widget::deleteObject(QObject* thingy)
{
    QThread* thisthread = this->thread();
    QThread* mainthread = QCoreApplication::instance()->thread();
    //breakpoint here to check thisthread and mainthread
    delete thingy;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Initchar_lineEdit_textChanged(const QString &arg1)
{
    initchar = arg1;
    qDebug() << "init char: " << initchar;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Widget::on_Serialavailable_comboBox_currentIndexChanged(const QString &arg1)
{
    serialportname = arg1;
    qDebug() << "serial port: " << serialportname;
    QSerialPortInfo serialportinfo(serialportname);

    QString serialinfos = QString("<html><b>Manufacturer:</b>\n%1\n<b>Description:</b>\n%2</html>").arg(serialportinfo.manufacturer(), serialportinfo.description());

    ui->Serialinfo_textBrowser->setText(serialinfos);


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Widget::on_Serialbaud_comboBox_currentIndexChanged(const QString &arg1)
{
    serialbaud = arg1;
    qDebug() << "serial baud: " << serialbaud;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Widget::on_Start_pushButton_clicked()
{
//    RadDSP::StartRead();
    timer->start(200);
//    digitalWrite(22,HIGH);
    serialportname = "ttyS0";
    serialbaud = "115200";
    QSerialPortInfo serialportinfo(serialportname);
    if (serialportinfo.isBusy()) {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","The selected serial port is busy");
        messageBox.setFixedSize(500,200);
        return;
    }
    if (serialportname.isEmpty()) {
        QMessageBox messageBox;
        messageBox.warning(0,"Warning","No serial port selected");
        messageBox.setFixedSize(500,200);
        return;
    }
    isfirst = true;
    serialport.setPortName(serialportname);
    serialport.open(QIODevice::ReadWrite);
    serialport.setBaudRate( serialbaud.toInt() );
    serialport.setDataBits(QSerialPort::Data8);
    serialport.setParity(QSerialPort::NoParity);
    serialport.setStopBits(QSerialPort::OneStop);
    serialport.setFlowControl(QSerialPort::NoFlowControl);

    ui->Serialincomingdata_textBrowser->clear();

//    initialtime = -9999.0;
//    finaltime   = -9999.0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Widget::on_Stop_pushButton_clicked()
{
//        RadDSP::StopRead();
        timer->stop();
//    QElapsedTimer elapsedtimer;
//    elapsedtimer.start();
    serialport.close();

//    ui->Serialincomingdata_textBrowser->setText(datalist_console.join('\n'));
//    ui->Serialincomingdata_textBrowser->append(datalist_console.at(10));
//    ui->Serialincomingdata_textBrowser->clear();
//    QStringList list = data.split("\n");
//    for (int i = 0; i < datalist.length()-1; ++i) {
//        ui->Serialincomingdata_textBrowser->append(datalist.at(i));
//    }

//    qDebug() << list.length() << "samples, " << "elspsed " << elapsedtimer.elapsed() << "ms";
//    data.clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Widget::readData() {
    incomingdata.append(serialport.readAll());
//    updateconsole(incomingdata);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Widget::on_Save_pushButton_clicked()
{
    // check for no data
    if (datalist_console.length() == 0) {
        QMessageBox messageBox;
        messageBox.warning(0,"Warning","No data to save");
        messageBox.setFixedSize(500,200);
        return;
    }
    QFile fOut("output.txt");
    if (fOut.open(QFile::WriteOnly)) {
        QTextStream s(&fOut);
        for (int i = 0; i < datalist_console.size(); ++i) {
                s << datalist_console.at(i);
        }
    } else {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Unable to open file");
        messageBox.setFixedSize(500,200);
        return;
    }
    fOut.close();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Widget::updateconsole(QByteArray incomingdata){
    databefore = datalist_console.length();
    if (incomingdata.at(0) != '\n') {
        datalist_console << incomingdata;
    }
    if (databefore != datalist_console.length()) {
        ui->Serialincomingdata_textBrowser->insertPlainText(datalist_console.last());
        ui->Serialincomingdata_textBrowser->moveCursor(QTextCursor::End);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//double parseddatalist[BUF_SIZE];
void Widget::update_plot() {
    if(incomingdata.contains('!'))
    {
        QList<QByteArray> baList = incomingdata.split('!');
        int ntokens = baList.size();
        for(int i=0;i<ntokens-1;i++)
        {
            data.append(baList[i]);
            plot_data();
            data.clear();
        }

        data.append(baList.at(ntokens-1));
        if(plot_data())data.clear();
        incomingdata.clear();
    }

}
bool Widget::plot_data()
{
    if(data.length()==0)return false;
    QList<QByteArray> datalist =  data.split('\n');
    updateconsole("data len:");
    updateconsole(QString::number(datalist.length()).toUtf8());

    if(datalist.length()>(buf_size)) {
        cur_data_type = QString(datalist[1]).toInt();
        updateconsole("data type:");
        updateconsole(datalist[1]);
        //--------------------------------------/
        /*datalist.clear();
        data.remove("\n");
        data.remove("\r");
        int a =data.length();
        datalist = data.split("#");
//        datalist.append();
        firstdatalistline = datalist.takeFirst();
        if(!isfirst) {
            datalist.insert(0, lastdatalistline + firstdatalistline);
        }
        isfirst = false;
        lastdatalistline = datalist.takeLast();

//        ui->Serialincomingdata_textBrowser->append("<html><b>New set</b></html>");
        QList<QString>::ConstIterator i;
        for (i = datalist.begin(); i != datalist.end(); ++i){
            QStringList chunks = (*i).split("\t");
            if(chunks.at(0) == initchar) {
                chunks.removeFirst();
                QList<double> currentdataset;
                QList<QString>::ConstIterator k;
                for (k = chunks.begin(); k != chunks.end(); ++k){
                    currentdataset.append((*k).toFloat());
                }
                parseddatalist.append(currentdataset);
            }
//            ui->Serialincomingdata_textBrowser->append(*i);
        }*/
        int numberofchunks = 2;
        double freqResolution = 500.0/buf_size;

        if(cur_data_type==plot_type)
        {
            if(plot_type==1)
            {
            Subplots[0].AxesRect->axis(QCPAxis::atBottom, 0)->setRange(0,-20,Qt::AlignRight);
            Subplots[0].AxesRect->axis(QCPAxis::atLeft, 0)->setRange(0,-50,Qt::AlignRight);
            }
            else if(plot_type==0)
            {
                Subplots[0].AxesRect->axis(QCPAxis::atBottom, 0)->setRange(0,-20,Qt::AlignRight);
                Subplots[0].AxesRect->axis(QCPAxis::atLeft, 0)->setRange(0,-1000,Qt::AlignRight);
            }
            Subplots[0].lines[0].graph->clearData();
            double heart_rate=0;
            double max_amp=0;
            double avr = 0;
            for (int i=1;i<datalist.length();i++) {
                double freq  = (i-1)*freqResolution;
                double amp = QString(datalist[i]).toDouble();
                avr += amp;
                if(freq>0&&freq<3)
                {
                    if(amp>max_amp)
                    {
                        max_amp=amp;
                        heart_rate = freq;
                    }
                }
                Subplots[0].lines[0].graph->addData(freq,amp);
                //                                ui->Serialincomingdata_textBrowser->append(QString::number(parseddata.at(Subplots[subplot_i].lines[line_i].Xdata_Spinbox->value()-1 )));
            }
            if(datalist.length()>1)
            {
                avr = avr/(datalist.length()-1);
                if(max_amp>5*avr) ui->label_breath_rate->setText(QString::number(heart_rate*60,'f',1));
                else ui->label_breath_rate->setText("Not detected");
            }

        }
        /*else
        for (int subplot_i = 0; subplot_i < MAXSUBPLOTS; subplot_i++) {
            if (Subplots[subplot_i].Subplot_Groupbox->isVisible()){
                for (int line_i = 0; line_i < MAXLINES; line_i++){
                    if (line_i==0)//Subplots[subplot_i].lines[line_i].Line_Groupbox->isVisible())
                    {
                        if(true)//Subplots[subplot_i].lines[line_i].Xdata_Spinbox->value()<=numberofchunks && Subplots[subplot_i].lines[line_i].Ydata_Spinbox->value()<=numberofchunks)
                        {
                            if(subplot_i==(cur_data_type-1))
                            {
                                qDebug() << "subplot_i : " << subplot_i;
                                if(subplot_i==0)//fft data
                                {
                                    Subplots[subplot_i].AxesRect->axis(QCPAxis::atBottom, 0)->setRange(0,-20,Qt::AlignRight);
                                    Subplots[subplot_i].AxesRect->axis(QCPAxis::atLeft, 0)->setRange(0,-50,Qt::AlignRight);
                                    Subplots[subplot_i].lines[line_i].graph->clearData();
                                    double heart_rate;
                                    double max_amp=0;
                                    double avr = 0;
                                    for (int i=1;i<datalist.length();i++) {
                                        double freq  = (i-1)*freqResolution;
                                        double amp = QString(datalist[i]).toDouble();
                                        avr += amp;
                                        if(freq>0&&freq<3)
                                        {
                                            if(amp>max_amp)
                                            {
                                                max_amp=amp;
                                                heart_rate = freq;
                                            }
                                        }
                                        Subplots[subplot_i].lines[line_i].graph->addData(freq,amp);
                                        //                                ui->Serialincomingdata_textBrowser->append(QString::number(parseddata.at(Subplots[subplot_i].lines[line_i].Xdata_Spinbox->value()-1 )));
                                    }
                                    if(datalist.length()>1)
                                    {
                                        avr = avr/(datalist.length()-1);
                                        if(max_amp>5*avr) ui->label_breath_rate->setText(QString::number(heart_rate*60,'f',1));
                                        else ui->label_breath_rate->setText("Not detected");
                                    }

                                }
                                else if(subplot_i==0)
                                {
                                    Subplots[subplot_i].AxesRect->axis(QCPAxis::atBottom, 0)->setRange(0,-20,Qt::AlignRight);
                                    Subplots[subplot_i].AxesRect->axis(QCPAxis::atLeft, 0)->setRange(0,-1000,Qt::AlignRight);
                                    Subplots[subplot_i].lines[line_i].graph->clearData();
                                    for (int i=1;i<datalist.length();i++) {
                                        Subplots[subplot_i].lines[line_i].graph->addData((i-1)*freqResolution,QString(datalist[i]).toDouble());
                                        //                                ui->Serialincomingdata_textBrowser->append(QString::number(parseddata.at(Subplots[subplot_i].lines[line_i].Xdata_Spinbox->value()-1 )));
                                    }
                                }

                            }
//                            Subplots[subplot_i].AxesRect->axis(QCPAxis::atBottom, 0)->setRange(parseddatalist.last().at(Subplots[subplot_i].lines[line_i].Xdata_Spinbox->value()-1)+1.0,
//                            10.0, Qt::AlignRight);
//                            Subplots[subplot_i].lines[line_i].graph->rescaleValueAxis();
//                            Subplots[subplot_i].lines[line_i].Xdata_Spinbox->setStyleSheet("QSpinBox {color: black}");
//                            Subplots[subplot_i].lines[line_i].Ydata_Spinbox->setStyleSheet("QSpinBox {color: black}");
                        } else {
                            if(Subplots[subplot_i].lines[line_i].Xdata_Spinbox->value()>numberofchunks) {
                              Subplots[subplot_i].lines[line_i].Xdata_Spinbox->setStyleSheet("QSpinBox {color: red; font: bold}");
                            }
                            if(Subplots[subplot_i].lines[line_i].Ydata_Spinbox->value()>numberofchunks) {
                                Subplots[subplot_i].lines[line_i].Ydata_Spinbox->setStyleSheet("QSpinBox {color: red; font: bold}");
                            }
                        }
                    }
                }
            }
        }*/

        ui->Plot->replot();
//        data.clear();
//        parseddatalist.clear();
        return true;

    }

    return false;
//    for (int k = 0; k < datalist.length(); k++) {
//        QStringList chunks = datalist.at(k).split("\t");
//        // if it is a plot line, parse the chuncks into doule
//        if(chunks.at(0) == initchar) {
//            double parseddata[chunks.length()-1];
//            for (int i = 1; i < chunks.length(); i++) {
//                parseddata[i-1] = chunks.at(i).toFloat();
//            }
//            // add data to lines:
//            ui->Plot->graph(0)->addData(parseddata[0], parseddata[2]);
//            ui->Plot->graph(0)->rescaleValueAxis();
//            ui->Plot->xAxis->setRange(parseddata[0]+1.0, 10.0, Qt::AlignRight);

//            if (k==0 && initialtime == -9999.0) {
//                initialtime = parseddata[0];
//                qDebug()<<initialtime;
//            }
//            if (k == datalist.length()-1) {
//                finaltime = parseddata[0];
//            }
//            ui->horizontalScrollBar->setRange(initialtime*100, finaltime*100);
//            ui->horizontalScrollBar->setValue(finaltime*100);
//        }
//    }
//    ui->Plot->replot();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Widget::on_Numbersubplots_spinBox_valueChanged(int arg1)
{
    for(int i = 0; i<arg1; i++) {
        if(Subplots[i].AxesRect == NULL) {
            Subplots[i].AxesRect = new QCPAxisRect(ui->Plot);
            ui->Plot->plotLayout()->addElement(i, 0, Subplots[i].AxesRect);
            ui->Plot->replot();
            Subplots[i].Subplot_Groupbox->show();
            Subplots[i].lines[0].graph = ui->Plot->addGraph(Subplots[i].AxesRect->axis(QCPAxis::atBottom), Subplots[i].AxesRect->axis(QCPAxis::atLeft));
        }
        if(i > 0 && Subplots[i].AxesRect != NULL) {
                connect(Subplots[i].AxesRect->axis(QCPAxis::atBottom, 0), SIGNAL(rangeChanged(QCPRange)), Subplots[i-1].AxesRect->axis(QCPAxis::atBottom, 0), SLOT(setRange(QCPRange)));
                connect(Subplots[i-1].AxesRect->axis(QCPAxis::atBottom, 0), SIGNAL(rangeChanged(QCPRange)), Subplots[i].AxesRect->axis(QCPAxis::atBottom, 0), SLOT(setRange(QCPRange)));
        }
    }

    for(int i = MAXSUBPLOTS-1; i>arg1-1; i--) {
        if(Subplots[i].AxesRect != NULL) {
            ui->Plot->plotLayout()->remove(Subplots[i].AxesRect);
            Subplots[i].AxesRect = NULL;
            ui->Plot->plotLayout()->simplify();
            ui->Plot->replot();
            Subplots[i].Subplot_Groupbox->hide();
        }
    }

}

void Widget::selectionChanged() {
    for(int i = 0; i < ui->Numbersubplots_spinBox->value(); i++) {
        if (Subplots[i].AxesRect->axis(QCPAxis::atBottom, 0)->selectedParts().testFlag(QCPAxis::spAxis) || Subplots[i].AxesRect->axis(QCPAxis::atBottom, 0)->selectedParts().testFlag(QCPAxis::spTickLabels)) {
            Subplots[i].AxesRect->axis(QCPAxis::atBottom, 0)->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        }
        if (Subplots[i].AxesRect->axis(QCPAxis::atLeft, 0)->selectedParts().testFlag(QCPAxis::spAxis) || Subplots[i].AxesRect->axis(QCPAxis::atLeft, 0)->selectedParts().testFlag(QCPAxis::spTickLabels)) {
            Subplots[i].AxesRect->axis(QCPAxis::atLeft, 0)->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        }
    }
}

void Widget::mousePress() {
    for(int i = 0; i < ui->Numbersubplots_spinBox->value(); i++) {
        if (Subplots[i].AxesRect->axis(QCPAxis::atBottom, 0)->selectedParts().testFlag(QCPAxis::spAxis) && !Subplots[i].AxesRect->axis(QCPAxis::atLeft, 0)->selectedParts().testFlag(QCPAxis::spAxis)) {
            Subplots[i].AxesRect->setRangeDrag(Qt::Horizontal);
        } else if (Subplots[i].AxesRect->axis(QCPAxis::atLeft, 0)->selectedParts().testFlag(QCPAxis::spAxis) && !Subplots[i].AxesRect->axis(QCPAxis::atBottom, 0)->selectedParts().testFlag(QCPAxis::spAxis)) {
            Subplots[i].AxesRect->setRangeDrag(Qt::Vertical);
        } else {
            Subplots[i].AxesRect->setRangeDrag(Qt::Horizontal|Qt::Vertical);
        }
    }
}

void Widget::mouseWheel() {
    for(int i = 0; i < ui->Numbersubplots_spinBox->value(); i++) {
        if (Subplots[i].AxesRect->axis(QCPAxis::atBottom, 0)->selectedParts().testFlag(QCPAxis::spAxis) && !Subplots[i].AxesRect->axis(QCPAxis::atLeft, 0)->selectedParts().testFlag(QCPAxis::spAxis)) {
            Subplots[i].AxesRect->setRangeZoom(Qt::Horizontal);
        } else if (Subplots[i].AxesRect->axis(QCPAxis::atLeft, 0)->selectedParts().testFlag(QCPAxis::spAxis) && !Subplots[i].AxesRect->axis(QCPAxis::atBottom, 0)->selectedParts().testFlag(QCPAxis::spAxis)) {
            Subplots[i].AxesRect->setRangeZoom(Qt::Vertical);
        } else {
            Subplots[i].AxesRect->setRangeZoom(Qt::Horizontal|Qt::Vertical);
        }
    }
}

void Widget::number_of_lines_changed(int val){
    QVector<double> xdatatest;
    QVector<double> ydatatest;
    xdatatest << 0.0 << 5.0;

    QSpinBox* numberoflineschanged = qobject_cast<QSpinBox*>(QObject::sender());
    QString subplot_sender_s = numberoflineschanged->objectName().at(numberoflineschanged->objectName().length()-1);
    int subplot_sender_i = subplot_sender_s.toInt() - 1;
    for(int i = 0; i<val; i++) {
        if(Subplots[subplot_sender_i].lines[i].Line_Groupbox->isHidden()){
            Subplots[subplot_sender_i].lines[i].Line_Groupbox->show();
        }
        if(Subplots[subplot_sender_i].lines[i].graph == NULL && Subplots[subplot_sender_i].AxesRect != NULL){
//            qDebug() << subplot_sender_i << ": " << i;
            Subplots[subplot_sender_i].lines[i].graph = ui->Plot->addGraph(Subplots[subplot_sender_i].AxesRect->axis(QCPAxis::atBottom), Subplots[subplot_sender_i].AxesRect->axis(QCPAxis::atLeft));
//            ydatatest.clear();
//            ydatatest << 0 << i+1;
//            Subplots[subplot_sender_i].lines[i].graph->addData(xdatatest, ydatatest);
//            ui->Plot->replot();
        }
    }
    for(int i = MAXLINES-1; i>val-1; i--) {
        if(Subplots[subplot_sender_i].lines[i].Line_Groupbox->isVisible()){
            Subplots[subplot_sender_i].lines[i].Line_Groupbox->hide();
        }
        if(Subplots[subplot_sender_i].lines[i].graph != NULL && Subplots[subplot_sender_i].AxesRect != NULL){
            ui->Plot->removeGraph(Subplots[subplot_sender_i].lines[i].graph);
            Subplots[subplot_sender_i].lines[i].graph = NULL;
            ui->Plot->replot();
        }
    }

}

void Widget::color_changed(int val) {
    QComboBox* colorchanged = qobject_cast<QComboBox*>(QObject::sender());
    QString subplot_sender_s = colorchanged->objectName().at(colorchanged->objectName().length()-3);
    QString line_sender_s = colorchanged->objectName().at(colorchanged->objectName().length()-1);

    int subplot_sender_i = subplot_sender_s.toInt() - 1;
    int line_sender_i = line_sender_s.toInt() - 1;

    Subplots[subplot_sender_i].lines[line_sender_i].graph->setPen(QPen(getcolor(val), 1));

    qDebug() << subplot_sender_s << " : " << line_sender_s << " color: " << val;
}

QColor Widget::getcolor(int idx) {
    switch (idx) {
    case 0:
        return Qt::blue;

    case 1:
        return Qt::red;

    case 2:
        return Qt::black;

    case 3:
        return Qt::green;

    case 4:
        return QColor("#e27f00");

    case 5:
        return Qt::yellow;

    default:
        return Qt::blue;

    }
}

void Widget::on_checkBox_stateChanged(int arg1)
{
    plot_type = arg1;
}
