#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wiringPi.h"
#include "wiringSerial.h"
#define BYTE_SIZE
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
        ui->pushButton->setText("Fail:"+ui->lineEdit->text()) ;
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
    //fflush(stdout);
    if(rd.size()>0)ui->lineEdit->setText(ui->lineEdit->text() + rd.toHex());

}
void MainWindow::on_pushButton_clicked()
{
    serialPutchar (fd, 60) ;

    QByteArray dataFrame = QByteArray::fromHex(QByteArray(ui->lineEdit->text().toStdString().c_str()));
    for(short i=0;i<dataFrame.size();i++)
    {
        serialPutchar (fd, dataFrame.at(i)) ;

    }
    serialFlush(fd);
//    while (true)
//    {

      //serialPutchar (fd, 71) ;
      //serialFlush(fd);
      //printf ("-\nć);
        //delay(1);
//        printf ("+\n%d", serialGetchar (fd)) ;

//    }

}

void MainWindow::on_pushButton_kenh_1_clicked()
{
    unsigned char byte[8] = {0xff,0x00,0x03,0x00,0x00,0x00,0x00,0xff };
    serialPutchar (fd, byte[0]) ;
    serialPutchar (fd, byte[1]) ;
    serialPutchar (fd, byte[2]) ;
    serialPutchar (fd, byte[3]) ;
    serialPutchar (fd, byte[4]) ;
    serialPutchar (fd, byte[5]) ;
    serialPutchar (fd, byte[6]) ;
    serialPutchar (fd, byte[7]) ;
}

void MainWindow::on_pushButton_num_11_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_num_1_clicked()
{
    ui->lineEdit->text() = ui->lineEdit->text() + "1";
}

void MainWindow::on_pushButton_num_2_clicked()
{
    ui->lineEdit->text() = ui->lineEdit->text() + "2";
}

void MainWindow::on_pushButton_num_3_clicked()
{
    ui->lineEdit->text() = ui->lineEdit->text() + "3";
}

void MainWindow::on_pushButton_num_4_clicked()
{
    ui->lineEdit->text() = ui->lineEdit->text() + "4";
}

void MainWindow::on_pushButton_num_5_clicked()
{
    ui->lineEdit->text() = ui->lineEdit->text() + "5";
}

void MainWindow::on_pushButton_num_6_clicked()
{
    ui->lineEdit->text() = ui->lineEdit->text() + "6";
}

void MainWindow::on_pushButton_num_7_clicked()
{
    ui->lineEdit->text() = ui->lineEdit->text() + "7";
}

void MainWindow::on_pushButton_num_8_clicked()
{
    ui->lineEdit->text() = ui->lineEdit->text() + "8";
}

void MainWindow::on_pushButton_num_9_clicked()
{
    ui->lineEdit->text() = ui->lineEdit->text() + "9";
}

void MainWindow::on_pushButton_num_0_clicked()
{
     ui->lineEdit->text() = ui->lineEdit->text() + "0";
}
