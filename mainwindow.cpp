#include "mainwindow.h"
#include "ui_mainwindow.h"
#ifndef Q_OS_WIN
#include "wiringPi.h"
#include "wiringSerial.h"
#endif
#define COMMAND_LEN 8
#define NUM_OF_CHANEL 9
struct txChanel
{
   double freq;
   bool isOn;
   double phase;
   double ampl;
};
unsigned char command[COMMAND_LEN] = {0xff,0x00,0x00,0x00,0x00,0x00,0x00,0xff };
txChanel chanelList[NUM_OF_CHANEL];
QTimer *rxTimer;
QTimer *IOupdateTimer;
int fd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rxTimer = new QTimer(this);
    connect(rxTimer, SIGNAL(timeout()), this, SLOT(onRecvUART()));
    rxTimer->start(10);
    rxTimer = new QTimer(this);
    connect(IOupdateTimer, SIGNAL(timeout()), this, SLOT(ioUpdate()));
    IOupdateTimer->start(20000);
    curChanelIndex = 0;
    updateChanelInfo();
#ifndef Q_OS_WIN
    if (wiringPiSetup () == -1)
    {
        printf ( "Unable to start wiringPi\n") ;
        return ;
    }
    if ((fd = serialOpen ("/dev/ttyS0", 9600)) < 0)
    {
        //printf(ui->lineEdit->text().toStdString().data());
        fflush (stdout) ;
        ui->lineEdit->setText("Not connected") ;
        return ;
    }
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::ioUpdate()
{
    command[1] = 0;
    command[2] = 7;
    command[3] = 0;
    command[4] = 0;
    command[5] = 0;
    command[6] = 0;
    sendCommand();

}
void MainWindow::onRecvUART()
{
    QByteArray rd;
#ifndef Q_OS_WIN
    while(serialDataAvail(fd)>0)
    {

        rd.append(serialGetchar (fd));
        //printf (rd.data());

    }
#endif
    if(rd.size())ui->textEdit_data_log->append(rd.toHex());
    //fflush(stdout);
    //if(rd.size()>0)ui->lineEdit->setText(ui->lineEdit->text() + rd.toHex());
    //ui->lineEdit->

}
void MainWindow::on_pushButton_pressed()
{
//    serialPutchar (fd, 60) ;

//    QByteArray dataFrame = QByteArray::fromHex(QByteArray(ui->lineEdit->text().toStdString().c_str()));
//    for(short i=0;i<dataFrame.size();i++)
//    {
//        serialPutchar (fd, dataFrame.at(i)) ;

//    }
    if(ui->pushButton_num_control_amp->isChecked())
    {
        command[2] = 0x02;
        int value =  (ui->lineEdit->text().toInt());
        if(value<10||value>70)
        {
            ui->pushButton->setText("Over Flow");
        }
        else
        {
            ui->pushButton->setText("Send");
            value = value<<2;
            command[3] = value>>8;
            command[4] = value;
            sendCommand();
        }

    }
    else if(ui->pushButton_num_control_phase->isChecked())
    {
        command[2] = 0x01;
        int value =  (ui->lineEdit->text().toInt());
        if(value<0||value>360)
        {
            ui->pushButton->setText("Over Flow");
        }
        else
        {
            ui->pushButton->setText("Send");
            value = value/360.0*(double)(1<<16);
            command[3] = value>>8;
            command[4] = value;
            sendCommand();
        }


    }

//    while (true)
//    {

      //serialPutchar (fd, 71) ;
      //serialFlush(fd);
      //printf ("-\n);
        //delay(1);
//        printf ("+\n%d", serialGetchar (fd)) ;

//    }

}



//void MainWindow::on_pushButton_num_11_pressed()
//{
//    ui->lineEdit->clear();
//}
void MainWindow::inputText(QString text)
{
    ui->lineEdit->setText( ui->lineEdit->text() + text);

}
void MainWindow::on_pushButton_num_1_pressed()
{
    inputText("1");
}

void MainWindow::on_pushButton_num_2_pressed()
{
    inputText("2");
}

void MainWindow::on_pushButton_num_3_pressed()
{
    inputText("3");
}

void MainWindow::on_pushButton_num_4_pressed()
{
    inputText("4");
}

void MainWindow::on_pushButton_num_5_pressed()
{
    inputText("5");
}

void MainWindow::on_pushButton_num_6_pressed()
{
    inputText("6");
}

void MainWindow::on_pushButton_num_7_pressed()
{
    inputText("7");
}

void MainWindow::on_pushButton_num_8_pressed()
{
    inputText("8");
}

void MainWindow::on_pushButton_num_9_pressed()
{
    inputText("9");
}

void MainWindow::on_pushButton_num_0_pressed()
{
     inputText("0");
}

void MainWindow::on_pushButton_num_back_pressed()
{
    QString str = ui->lineEdit->text();
    str.chop(1);
    ui->lineEdit->setText(str);
}

void MainWindow::selectChanel(unsigned char chanelNum)
{
    if(chanelNum>7)
    {
        //chanelNum = 0xaa;
        command[1] = 0xaa;
        curChanelIndex=8;
    }
    else
    {
        curChanelIndex=chanelNum;
        command[1] = chanelNum;

    }
    updateChanelInfo();
}
void MainWindow::updateChanelInfo()
{
    if(curChanelIndex>7)
    {
        ui->label_chanel_num->setText("All");
    }
    else
    {
        ui->label_chanel_num->setText(QString::number(curChanelIndex+1));
    }
    if(chanelList[curChanelIndex].isOn)
    {
        ui->label_chanel_stat->setText("On");
    }
    else
    {
        ui->label_chanel_stat->setText("Off");
    }
    ui->label_chanel_freq->setText(QString::number(chanelList[curChanelIndex].freq));
    ui->label_chanel_phase->setText(QString::number(chanelList[curChanelIndex].phase));
    ui->label_chanel_amp->setText(QString::number(chanelList[curChanelIndex].ampl));

}
void MainWindow::on_pushButton_kenh_1_pressed()
{
    selectChanel(0);
    //unsigned char byte[8] = {0xff,0x00,0x03,0x00,0x00,0x00,0x00,0xff };
    //command[1] = 0x00;
    //ui->label_chanel_num->setText("1");
//    serialPutchar (fd, byte[0]) ;
//    serialPutchar (fd, byte[1]) ;
//    serialPutchar (fd, byte[2]) ;
//    serialPutchar (fd, byte[3]) ;
//    serialPutchar (fd, byte[4]) ;
//    serialPutchar (fd, byte[5]) ;
//    serialPutchar (fd, byte[6]) ;
//    serialPutchar (fd, byte[7]) ;
}
void MainWindow::on_pushButton_kenh_2_pressed()
{

    selectChanel(1);
}

void MainWindow::on_pushButton_kenh_3_pressed()
{
    selectChanel(2);
}

void MainWindow::on_pushButton_kenh_4_pressed()
{
    selectChanel(3);
}

void MainWindow::on_pushButton_kenh_5_pressed()
{
    selectChanel(4);
}

void MainWindow::on_pushButton_kenh_6_pressed()
{
    selectChanel(5);
}

void MainWindow::on_pushButton_kenh_7_pressed()
{
    selectChanel(6);
}

void MainWindow::on_pushButton_kenh_8_pressed()
{
    selectChanel(7);
}

void MainWindow::on_pushButton_kenh_9_pressed()
{
    selectChanel(8);
}

void MainWindow::on_pushButton_num_10_pressed()
{
    inputText(".");
}

void MainWindow::on_pushButton_kenh_16_pressed()
{
    if(curChanelIndex>7)
    command[1] = 0xAA;
    else
        command[1] = curChanelIndex;
    command[2] = 4;
    command[3] = 0;
    command[4] = 0;
    command[5] = 0;
    command[6] = 0;
    chanelList[curChanelIndex].isOn = true;
    sendCommand();
}
void MainWindow::sendCommand()
{
    for(int i=0;i<COMMAND_LEN;i++)
    {
#ifndef Q_OS_WIN
        serialPutchar (fd, command[i]) ;

#endif
    }
    //delay(1);
    onRecvUART();
    updateChanelInfo();
}
void MainWindow::on_pushButton_kenh_17_pressed()
{
    if(curChanelIndex>7)
    command[1] = 0xAA;
    else
        command[1] = curChanelIndex;
    command[2] = 5;
    command[3] = 0;
    command[4] = 0;
    command[5] = 0;
    command[6] = 0;
    chanelList[curChanelIndex].isOn = false;

    sendCommand();
}

void MainWindow::on_pushButton_num_control_phase_comp_2_pressed()
{
    ioUpdate();
}

void MainWindow::on_pushButton_num_control_amp_pressed()
{
    ui->label_unit->setText("(-1)dBm");
}



void MainWindow::on_pushButton_num_control_afreq_pressed()
{
    ui->label_unit->setText("Mhz");
}

void MainWindow::on_pushButton_num_control_phase_pressed()
{
    ui->label_unit->setText("deg");
}
