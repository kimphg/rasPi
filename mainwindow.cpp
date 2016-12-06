#include "mainwindow.h"
#include "ui_mainwindow.h"
#ifndef Q_OS_WIN
#include "wiringPi.h"
#include "wiringSerial.h"
#endif
#define MY_PATLETTE QColor(40,100,150)
#define MY_PATLETTE_HL QColor(255,150,30)
#define COMMAND_LEN 8
#define NUM_OF_CHANEL 9
struct txChanel
{
   double freq;
   bool isOn;
   double phase;
   double ampl;
};
CConfig config;
unsigned char command[COMMAND_LEN] = {0xff,0x00,0x00,0x00,0x00,0x00,0x00,0xff };
txChanel chanelList[NUM_OF_CHANEL];
QTimer *rxTimer;
//QTimer *IOupdateTimer;
int fd;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame_config_edit->setVisible(false);
    this->setPalette(MY_PATLETTE);
    rxTimer = new QTimer(this);
    connect(rxTimer, SIGNAL(timeout()), this, SLOT(onRecvUART()));
    rxTimer->start(20);
    //IOupdateTimer =  new QTimer(this);
    //connect(IOupdateTimer, SIGNAL(timeout()), this, SLOT(ioUpdate()));
    //IOupdateTimer->start(20000);
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
    command[1] = 0x0a;
    command[2] = 0x0a;
    command[3] = 0x0a;
    command[4] = 0x0a;
    command[5] = 0x0a;
    command[6] = 0x0a;
    for(int i=0;i<COMMAND_LEN;i++)
    {
#ifndef Q_OS_WIN
        serialPutchar (fd, command[i]) ;

#endif
    }

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
        double value =  (ui->lineEdit->text().toDouble());
        if(value<10||value>70)
        {
            ui->pushButton->setText("Over Flow");
        }
        else
        {
            ui->pushButton->setText("Send");
            chanelList[curChanelIndex].ampl = value;
            int a = value*4 + 0.5;
            command[3] = a>>8;
            command[4] = a;
            sendCommand(&command[0],curChanelIndex);

        }

    }
    else if(ui->pushButton_num_control_phase->isChecked())
    {
        command[2] = 0x01;
        double value =  (ui->lineEdit->text().toDouble());
        if(value<0||value>360)
        {
            ui->pushButton->setText("Over Flow");
        }
        else
        {
            ui->pushButton->setText("Send");
            chanelList[curChanelIndex].phase = value;
            value = value*182.0444444444444+0.5;
            int a= value;
            command[3] = a>>8;
            command[4] = a;
            sendCommand(&command[0],curChanelIndex);
        }


    }
    else if(ui->pushButton_num_control_afreq->isChecked())
    {
        command[2] = 0x00;
        double value =  (ui->lineEdit->text().toDouble());
        if(value<10||value>700)
        {
            ui->pushButton->setText("Over Flow");
        }
        else
        {
            ui->pushButton->setText("Send");
            chanelList[curChanelIndex].freq = value;
            value = value*1720740.1+0.5;
            int a = int(value);
            command[3] = a>>24;
            command[4] = a>>16;
            command[5] = a>>8;
            command[6] = a;
            sendCommand(&command[0],curChanelIndex);
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

        curChanelIndex=8;
    }
    else
    {
        curChanelIndex=chanelNum;


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
        switch (curChanelIndex) {
        case 0:
            ui->pushButton_kenh_1->setPalette(MY_PATLETTE_HL);
            break;
        case 1:
            ui->pushButton_kenh_2->setPalette(MY_PATLETTE_HL);
            break;
        case 2:
            ui->pushButton_kenh_3->setPalette(MY_PATLETTE_HL);
            break;
        case 3:
            ui->pushButton_kenh_4->setPalette(MY_PATLETTE_HL);
            break;
        case 4:
            ui->pushButton_kenh_5->setPalette(MY_PATLETTE_HL);
            break;
        case 5:
            ui->pushButton_kenh_6->setPalette(MY_PATLETTE_HL);
            break;
        case 6:
            ui->pushButton_kenh_7->setPalette(MY_PATLETTE_HL);
            break;
        case 7:
            ui->pushButton_kenh_8->setPalette(MY_PATLETTE_HL);
            break;
        case 8:
            ui->pushButton_kenh_9->setPalette(MY_PATLETTE_HL);
            ui->pushButton_kenh_8->setPalette(MY_PATLETTE_HL);
            ui->pushButton_kenh_7->setPalette(MY_PATLETTE_HL);
            ui->pushButton_kenh_6->setPalette(MY_PATLETTE_HL);
            ui->pushButton_kenh_5->setPalette(MY_PATLETTE_HL);
            ui->pushButton_kenh_4->setPalette(MY_PATLETTE_HL);
            ui->pushButton_kenh_3->setPalette(MY_PATLETTE_HL);
            ui->pushButton_kenh_2->setPalette(MY_PATLETTE_HL);
            ui->pushButton_kenh_1->setPalette(MY_PATLETTE_HL);
            break;
        default:
            break;
        }
    }
    else
    {
        ui->label_chanel_stat->setText("Off");
        switch (curChanelIndex) {
        case 0:
            ui->pushButton_kenh_1->setPalette(MY_PATLETTE);
            break;
        case 1:
            ui->pushButton_kenh_2->setPalette(MY_PATLETTE);
            break;
        case 2:
            ui->pushButton_kenh_3->setPalette(MY_PATLETTE);
            break;
        case 3:
            ui->pushButton_kenh_4->setPalette(MY_PATLETTE);
            break;
        case 4:
            ui->pushButton_kenh_5->setPalette(MY_PATLETTE);
            break;
        case 5:
            ui->pushButton_kenh_6->setPalette(MY_PATLETTE);
            break;
        case 6:
            ui->pushButton_kenh_7->setPalette(MY_PATLETTE);
            break;
        case 7:
            ui->pushButton_kenh_8->setPalette(MY_PATLETTE);
            break;
        case 8:
            ui->pushButton_kenh_9->setPalette(MY_PATLETTE);
            ui->pushButton_kenh_8->setPalette(MY_PATLETTE);
            ui->pushButton_kenh_7->setPalette(MY_PATLETTE);
            ui->pushButton_kenh_6->setPalette(MY_PATLETTE);
            ui->pushButton_kenh_5->setPalette(MY_PATLETTE);
            ui->pushButton_kenh_4->setPalette(MY_PATLETTE);
            ui->pushButton_kenh_3->setPalette(MY_PATLETTE);
            ui->pushButton_kenh_2->setPalette(MY_PATLETTE);
            ui->pushButton_kenh_1->setPalette(MY_PATLETTE);
            break;
        default:
            break;
        }
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
    sendCommand(&command[0],curChanelIndex);
}
void MainWindow::sendCommand(unsigned char* command,short chanel)
{
    ui->pushButton_num_control_ioupdate->setChecked(false);
    if(chanel==8)
    {

        command[1] = 0x0c;
        for(int i=0;i<COMMAND_LEN;i++)
        {
            #ifndef Q_OS_WIN
            serialPutchar (fd, command[i]) ;
            #endif
        }

    }
    else
    {
        command[1] = chanel;
        for(int i=0;i<COMMAND_LEN;i++)
        {
            #ifndef Q_OS_WIN
            serialPutchar (fd, command[i]) ;
            #endif
        }
    }

    //delay(1);
    //onRecvUART();
    updateChanelInfo();
    QApplication::beep();
}
void MainWindow::on_pushButton_kenh_17_pressed()
{
    if(curChanelIndex>7)
    curChanelIndex = 8;
    command[2] = 5;
    command[3] = 0;
    command[4] = 0;
    command[5] = 0;
    command[6] = 0;
    chanelList[curChanelIndex].isOn = false;
    sendCommand(&command[0],curChanelIndex);
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

void MainWindow::on_pushButton_num_control_ioupdate_pressed()
{
    ioUpdate();
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_num_control_up_2_pressed()
{
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_commit_pressed()
{
    //=  ui->tableWidget->item(1,1);
    config.clearItem();
    for(int i=0;i<1000;i++)
    {
        //int selCol = itemList.at(0)->column();
        phase_item item;
        QTableWidgetItem *itab;
        itab= ui->tableWidget->item(0,i);
        if(itab)item.freg = itab->text().toDouble();
        else continue;
        if(item.freg==0)continue;
        for(int row=1; row < 9;row++)
        {
            itab = ui->tableWidget->item(row,i);
            if(itab)
            {
                item.phaseChanel[row-1] = itab->text().toDouble();
            }
            else
            {
                item.phaseChanel[row-1] = 0;
            }
        }
        config.addItem(&item);
    }
    config.sortItems();
    config.SaveToFile();
        //printf("\n%f",itemList.at(0)->text().toDouble());
}

void MainWindow::on_pushButton_load_config_table_pressed()
{
    int curCol = 0;
    for(int i=0;i<config.getItemListSize();i++)
    {
        phase_item item = config.getItem(i);
        QTableWidgetItem *tabitem = new QTableWidgetItem;
        tabitem->setText(QString::number(item.freg,'f'));
        ui->tableWidget->setItem(0,curCol,tabitem);
        for(int j=0;j<8;j++)
        {
            tabitem = new QTableWidgetItem;
            tabitem->setText(QString::number(item.phaseChanel[j],'f',0));
            ui->tableWidget->setItem(1+j,curCol,tabitem);
        }
        curCol++;
    }
}



void MainWindow::on_pushButton_commit_2_pressed()
{
    if(ui->lineEdit_pass->text()=="cndt")ui->frame_config_edit->setVisible(true);
}

void MainWindow::on_pushButton_sort_table_2_pressed()
{

    QTableWidgetItem * tabitem =ui->tableWidget->selectedItems().at(0);
    if(tabitem->row()>0)
    {

        //double frequency = ui->tableWidget->item(0,tabitem->column())->text().toDouble();
        if(true)
        {
            unsigned char command[COMMAND_LEN] = {0xff,0x00,0x00,0x00,0x00,0x00,0x00,0xff };
            int chanel = tabitem->row()-1;
            command[2] = 0x01;
            double value =  tabitem->text().toDouble();
            if(value>=0&&value<360)
            {
#ifndef Q_OS_WIN
                setCursor(Qt::WaitCursor);
                value = value*182.0444444444444+0.5;
                int a= value;
                command[3] = a>>8;
                command[4] = a;
                sendCommand(&command[0],chanel);
                //
//                delay(100);
//                command[2] = 0x00;
//                value =  frequency;
//                value = value*1720740.1+0.5;
//                a = int(value);
//                command[3] = a>>24;
//                command[4] = a>>16;
//                command[5] = a>>8;
//                command[6] = a;
//                sendCommand(&command[0],chanel);
                delay(500);
                ioUpdate();
                setCursor(Qt::ArrowCursor);
                tabitem->setBackgroundColor(QColor(120,180,250));
#endif
                return;
            }
        }

    }
    tabitem->setBackgroundColor(QColor(250,120,20));
}

void MainWindow::on_pushButton_num_control_ioupdate_2_pressed()
{
    command[1] = 0x0b;
    command[2] = 0x0b;
    command[3] = 0x0b;
    command[4] = 0x0b;
    command[5] = 0x0b;
    command[6] = 0x0b;
    for(int i=0;i<COMMAND_LEN;i++)
    {
#ifndef Q_OS_WIN
        serialPutchar (fd, command[i]) ;
#endif
    }
}
