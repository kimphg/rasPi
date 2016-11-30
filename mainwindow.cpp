#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wiringPi.h"
#include "wiringSerial.h"
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
int fd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rxTimer = new QTimer(this);
    connect(rxTimer, SIGNAL(timeout()), this, SLOT(onRecvUART()));
    rxTimer->start(50);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::onRecvUART()
{
    QByteArray rd;
    while(serialDataAvail(fd)>0)
    {

        rd.append(serialGetchar (fd));
        //printf (rd.data());

    }
    if(rd.size())ui->textEdit_data_log->append(rd.toHex());
    //fflush(stdout);
    //if(rd.size()>0)ui->lineEdit->setText(ui->lineEdit->text() + rd.toHex());
    //ui->lineEdit->

}
void MainWindow::on_pushButton_clicked()
{
//    serialPutchar (fd, 60) ;

//    QByteArray dataFrame = QByteArray::fromHex(QByteArray(ui->lineEdit->text().toStdString().c_str()));
//    for(short i=0;i<dataFrame.size();i++)
//    {
//        serialPutchar (fd, dataFrame.at(i)) ;

//    }

    serialFlush(fd);
//    while (true)
//    {

      //serialPutchar (fd, 71) ;
      //serialFlush(fd);
      //printf ("-\n);
        //delay(1);
//        printf ("+\n%d", serialGetchar (fd)) ;

//    }

}

void MainWindow::on_pushButton_kenh_1_clicked()
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

void MainWindow::on_pushButton_num_11_clicked()
{
    ui->lineEdit->clear();
}
void MainWindow::inputText(QString text)
{
    ui->lineEdit->setText( ui->lineEdit->text() + text);

}
void MainWindow::on_pushButton_num_1_clicked()
{
    inputText("1");
}

void MainWindow::on_pushButton_num_2_clicked()
{
    inputText("2");
}

void MainWindow::on_pushButton_num_3_clicked()
{
    inputText("3");
}

void MainWindow::on_pushButton_num_4_clicked()
{
    inputText("4");
}

void MainWindow::on_pushButton_num_5_clicked()
{
    inputText("5");
}

void MainWindow::on_pushButton_num_6_clicked()
{
    inputText("6");
}

void MainWindow::on_pushButton_num_7_clicked()
{
    inputText("7");
}

void MainWindow::on_pushButton_num_8_clicked()
{
    inputText("8");
}

void MainWindow::on_pushButton_num_9_clicked()
{
    inputText("9");
}

void MainWindow::on_pushButton_num_0_clicked()
{
     inputText("0");
}

void MainWindow::on_pushButton_num_back_clicked()
{
    QString str = ui->lineEdit->text();
    str.chop(1);
    ui->lineEdit->setText(str);
}
int curChanelIndex = 0;
void MainWindow::selectChanel(unsigned char chanelNum)
{
    if(chanelNum>7)
    {
        //chanelNum = 0xaa;
        curChanelIndex=8;
    }
    else
    {
        curChanelIndex=chanelNum;
        //command[1] = chanelNum;

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
void MainWindow::on_pushButton_kenh_2_clicked()
{

    selectChanel(1);
}

void MainWindow::on_pushButton_kenh_3_clicked()
{
    selectChanel(2);
}

void MainWindow::on_pushButton_kenh_4_clicked()
{
    selectChanel(3);
}

void MainWindow::on_pushButton_kenh_5_clicked()
{
    selectChanel(4);
}

void MainWindow::on_pushButton_kenh_6_clicked()
{
    selectChanel(5);
}

void MainWindow::on_pushButton_kenh_7_clicked()
{
    selectChanel(6);
}

void MainWindow::on_pushButton_kenh_8_clicked()
{
    selectChanel(7);
}

void MainWindow::on_pushButton_kenh_9_clicked()
{
    selectChanel(8);
}

void MainWindow::on_pushButton_num_10_clicked()
{
    inputText(".");
}

void MainWindow::on_pushButton_kenh_16_clicked()
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
    sendCommand();
}
void MainWindow::sendCommand()
{
    for(int i=0;i<COMMAND_LEN;i++)
    {
        serialPutchar (fd, command[i]) ;
    }
    serialFlush(fd);
}
void MainWindow::on_pushButton_kenh_17_clicked()
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
    sendCommand();
}
