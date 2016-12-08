#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStatusBar>
#ifndef Q_OS_WIN
#include "wiringPi.h"
#include "wiringSerial.h"
#endif
#define MY_PATLETTE_WAITING QColor(40,100,150)
#define MY_PATLETTE_NORMAL QColor(40,100,150)
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
    this->setPalette(MY_PATLETTE_NORMAL);
    rxTimer = new QTimer(this);
    connect(rxTimer, SIGNAL(timeout()), this, SLOT(onRecvUART()));
    rxTimer->start(20);
    //IOupdateTimer =  new QTimer(this);
    //connect(IOupdateTimer, SIGNAL(timeout()), this, SLOT(ioUpdate()));
    //IOupdateTimer->start(20000);
    curChanelIndex = 0;
    updateChanelInfo();
    loadConfigTable();
#ifndef Q_OS_WIN
    if (wiringPiSetup () == -1)
    {
        printf ( "Unable to start wiringPi\n") ;
        return ;
    }
    if ((fd = serialOpen ("/dev/ttyS0", 9600)) < 0)
    {
        //printf(ui->lineEdit->text().toStdString().data());
        //fflush (stdout) ;
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

int MainWindow::onRecvUART()
{
    QByteArray rd;
#ifndef Q_OS_WIN
    while(serialDataAvail(fd)>0)
    {

        rd.append(serialGetchar (fd));
        //printf (rd.data());

    }
#endif
    if(rd.size())
    {
        if(rd.size()>2)
        {
            if(rd.at(rd.size()-2)==0xff)
            {
                double temp = rd.at(rd.size()-1)/4.0;
                ui->label_temp->setText(QString::number(temp));
            }
        }
        ui->textEdit_data_log->append(rd.toHex());
        return rd.size();
    }
    else
    {
        return 0;
    }
    showStatus("Device ready");
    //fflush(stdout);
    //if(rd.size()>0)ui->lineEdit->setText(ui->lineEdit->text() + rd.toHex());
    //ui->lineEdit->

}
void MainWindow::showStatus(QString str)
{
    statusBar()->showMessage(str,5000);
}
void MainWindow::on_pushButton_pressed()
{
    if(ui->pushButton_num_control_amp->isChecked())
    {
        command[2] = 0x02;
        double value =  (ui->lineEdit->text().toDouble());
        if(value<10||value>70)
        {

            showStatus("Wrong value, amplitude should be from -10 to -70 dBm");

        }
        else
        {

            chanelList[curChanelIndex].ampl = value;
            int a = value*4 + 0.5;
            command[3] = a>>8;
            command[4] = a;
            sendCommand(&command[0],curChanelIndex);

        }

    }
    else if(ui->pushButton_num_control_phase->isChecked())
    {

        double value =  (ui->lineEdit->text().toDouble());

        setPhaseComp(value,curChanelIndex);

    }
    else if(ui->pushButton_num_control_afreq->isChecked())
    {
        double value =  (ui->lineEdit->text().toDouble());
        setfreq(value,curChanelIndex);
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
            ui->pushButton_kenh_1->setPalette(MY_PATLETTE_NORMAL);
            break;
        case 1:
            ui->pushButton_kenh_2->setPalette(MY_PATLETTE_NORMAL);
            break;
        case 2:
            ui->pushButton_kenh_3->setPalette(MY_PATLETTE_NORMAL);
            break;
        case 3:
            ui->pushButton_kenh_4->setPalette(MY_PATLETTE_NORMAL);
            break;
        case 4:
            ui->pushButton_kenh_5->setPalette(MY_PATLETTE_NORMAL);
            break;
        case 5:
            ui->pushButton_kenh_6->setPalette(MY_PATLETTE_NORMAL);
            break;
        case 6:
            ui->pushButton_kenh_7->setPalette(MY_PATLETTE_NORMAL);
            break;
        case 7:
            ui->pushButton_kenh_8->setPalette(MY_PATLETTE_NORMAL);
            break;
        case 8:
            ui->pushButton_kenh_9->setPalette(MY_PATLETTE_NORMAL);
            ui->pushButton_kenh_8->setPalette(MY_PATLETTE_NORMAL);
            ui->pushButton_kenh_7->setPalette(MY_PATLETTE_NORMAL);
            ui->pushButton_kenh_6->setPalette(MY_PATLETTE_NORMAL);
            ui->pushButton_kenh_5->setPalette(MY_PATLETTE_NORMAL);
            ui->pushButton_kenh_4->setPalette(MY_PATLETTE_NORMAL);
            ui->pushButton_kenh_3->setPalette(MY_PATLETTE_NORMAL);
            ui->pushButton_kenh_2->setPalette(MY_PATLETTE_NORMAL);
            ui->pushButton_kenh_1->setPalette(MY_PATLETTE_NORMAL);
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
    //ui->pushButton_num_control_ioupdate->setChecked(false);
    if(chanel<0||chanel>8)
    {
        showStatus("Wrong chanel");

        return;
    }
    else if(chanel==8)
    {

        command[1] = 0x0c;

    }
    else
    {
        command[1] = chanel;

    }
    for(int i=0;i<COMMAND_LEN;i++)
    {
        #ifndef Q_OS_WIN
        serialPutchar (fd, command[i]) ;
        #endif
    }

    //delay(1);
    //onRecvUART();
    showStatus("Device  not ready");
    updateChanelInfo();
    //QApplication::beep();
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
    loadConfigTable();
}
void MainWindow::loadConfigTable()
{
    int curCol = 0;
    for(int i=0;i<config.getItemListSize();i++)
    {
        phase_item item = config.getItem(i);
        QTableWidgetItem *tabitem = new QTableWidgetItem;
        tabitem->setText(QString::number(item.freg));
        ui->tableWidget->setItem(0,curCol,tabitem);
        for(int j=0;j<8;j++)
        {
            tabitem = new QTableWidgetItem;
            tabitem->setText(QString::number(item.phaseChanel[j]));
            ui->tableWidget->setItem(1+j,curCol,tabitem);
        }
        curCol++;
    }
}


void MainWindow::on_pushButton_commit_2_pressed()
{
    /*if(ui->lineEdit_pass->text()=="cndt")*/ui->frame_config_edit->setVisible(true);
}

void MainWindow::on_pushButton_sort_table_2_pressed()//test button
{

    QTableWidgetItem * tabitem =ui->tableWidget->selectedItems().at(0);
    if(tabitem->row()>0)
    {

        //double frequency = ui->tableWidget->item(0,tabitem->column())->text().toDouble();
        if(true)
        {
            //unsigned char command[COMMAND_LEN] = {0xff,0x00,0x00,0x00,0x00,0x00,0x00,0xff };
            int chanel = tabitem->row()-1;
            //command[2] = 0x01;
            double value =  tabitem->text().toDouble();
            if(value>=0&&value<360)
            {
                ui->tableWidget->item(0,tabitem->column())->setText(QString::number(chanelList[8].freq));
                setCursor(Qt::WaitCursor);
                setPhaseTrue(value,chanel);
                #ifndef Q_OS_WIN
                delay(1000);
                #endif
                ioUpdate();
                setCursor(Qt::ArrowCursor);
                tabitem->setBackgroundColor(QColor(120,180,250));

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
    this->setPalette(QPalette(MY_PATLETTE_WAITING));
    ui->tabWidget->hide();
    showStatus("Device restarting");
    update();
    repaint();
#ifndef Q_OS_WIN
    delay(1000);
    serialFlush(fd);
    update();
    repaint();
#endif
    int k=0;
    while (true)
    {
        if(onRecvUART()>7)break;
        #ifndef Q_OS_WIN
            delay(500);
        #endif
        k++;
        if(k>40)
        {
            showStatus("Device not ready");
            break;
        }
    }
    ui->tabWidget->show();
    this->setPalette(QPalette(MY_PATLETTE_NORMAL));
}

void MainWindow::on_pushButton_send_8bytes_pressed()
{
    unsigned char command[8];
    command[0] = ui->lineEdit_cmd_byte_1->text().toInt();
    command[1] = ui->lineEdit_cmd_byte_2->text().toInt();
    command[2] = ui->lineEdit_cmd_byte_3->text().toInt();
    command[3] = ui->lineEdit_cmd_byte_4->text().toInt();
    command[4] = ui->lineEdit_cmd_byte_5->text().toInt();
    command[5] = ui->lineEdit_cmd_byte_6->text().toInt();
    command[6] = ui->lineEdit_cmd_byte_7->text().toInt();
    command[7] = ui->lineEdit_cmd_byte_8->text().toInt();
    for(int i=0;i<COMMAND_LEN;i++)
    {
#ifndef Q_OS_WIN
        serialPutchar (fd, command[i]) ;
#endif
    }
}
void MainWindow::setPhaseComp(double value, int chanel)
{

    if(chanel>7)
    {

        for(int i = 0;i<8;i++)
        {
            showStatus("Sending all chanel, please wait..."+QString::number((8-i)/2.0));
            setPhaseComp(value,i);
            update();
            repaint();
            #ifndef Q_OS_WIN
                delay (500) ;
            #endif
        }
    }
    else
    {
        double phaseComp= config.getValue(chanelList[curChanelIndex].freq,curChanelIndex);
        setPhaseTrue(value+phaseComp,chanel);
    }

}
bool MainWindow::setPhaseTrue(double value, int chanel)
{
    command[2] = 0x01;
    if(value<0)value+=360;
    if(value>=360)value-=360;
    if(value<0||value>360)
    {
        showStatus("Wrong value, chanel phase should be from 0 to 360 degrees");
        return false;
    }
    else
    {
        chanelList[chanel].phase = value;
        value = value*182.0444444444444+0.5;
        int a= value;
        command[3] = a>>8;
        command[4] = a;
        sendCommand(&command[0],chanel);
        return true;
    }
}
bool MainWindow::setfreq(double value,int chanel)
{

    command[2] = 0x00;
    if(value<10||value>700)
    {
        showStatus("Wrong value, frequency should be from 10 to 700Mhz");
        return false;
    }
    else
    {
        chanelList[chanel].freq = value;
        value = value*1720740.1+0.5;
        int a = int(value);
        command[3] = a>>24;
        command[4] = a>>16;
        command[5] = a>>8;
        command[6] = a;
        sendCommand(&command[0],chanel);
        return true;
    }
}
void MainWindow::on_pushButton_set_all_freq_pressed()
{
    double value = ui->lineEdit_pass_freq_set_all->text().toDouble();
    setfreq(value,8);

}
