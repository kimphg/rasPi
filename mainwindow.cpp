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
        printf (rd.data());

    }
    fflush(stdout);
    if(rd.size()>0)ui->lineEdit->setText(ui->lineEdit->text() + rd.toHex());

}
void MainWindow::on_pushButton_clicked()
{

    while (true)
    {

      //serialPutchar (fd, 71) ;
      //serialFlush(fd);
      //printf ("-\n");
        //delay(1);
//        printf ("+\n%d", serialGetchar (fd)) ;

    }

}

void MainWindow::on_pushButton_kenh_1_clicked()
{
    //unsigned char byte[];
}
