#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wiringPi.h"
#include "wiringSerial.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (wiringPiSetup () == -1)
    {
        printf ( "Unable to start wiringPi\n") ;
        return ;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int fd;

    if ((fd = serialOpen ("/dev/ttyS0", 9600)) < 0)
    {
        //printf(ui->lineEdit->text().toStdString().data());
        fflush (stdout) ;
        ui->pushButton->setText("Fail:"+ui->lineEdit->text()) ;
        return ;
    }
    while (true)
    {

      //serialPutchar (fd, 71) ;
      //serialFlush(fd);
      //printf ("-\n");
        //delay(1);
//        printf ("+\n%d", serialGetchar (fd)) ;
      if (serialDataAvail (fd)>0)
      {
         // ui->pushButton->setText(QString::fromAscii(serialGetchar (fd)));
        char d =   serialGetchar (fd);
        if(d==-1)continue;
        if(d=='e') return;
        putchar(d) ;
        fflush (stdout) ;
      }
    }

}
