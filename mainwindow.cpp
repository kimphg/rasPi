#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QStatusBar>
#ifndef Q_OS_WIN
#include "wiringPi.h"
#include "wiringSerial.h"
#endif
#define MY_PATLETTE_WAITING QColor(40,100,150)
#define MY_PATLETTE_NORMAL QColor(120,150,180)
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
QTimer *updateTimer;
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
    updateTimer =  new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateTemp()));
    updateTimer->start(10000);
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

        if((rd.at(rd.size()-2)==0xff)&&(rd.size()>2))
        {
            int byte = rd.at(rd.size()-1);
            if(byte!=0xff)
            {
                double temp = byte/4.0;
                ui->label_temp->setText(QString::number(temp));
            }
        }

        ui->textEdit_data_log->append(rd.toHex());
        showStatus("Device ready");
        return rd.size();
    }
    else
    {
        return 0;
    }

    //fflush(stdout);
    //if(rd.size()>0)ui->lineEdit->setText(ui->lineEdit->text() + rd.toHex());
    //ui->lineEdit->

}
void MainWindow::showStatus(QString str)
{
    statusBar()->showMessage(str,5000);
}
void MainWindow::setAmp(double value, unsigned int chanel){

    if(value<10||value>70)
    {
        showStatus("Wrong value, amplitude should be from -10 to -70 dBm");
        return;
    }


    if(chanel>8)return;
    chanelList[curChanelIndex].ampl = value;
    if(chanel>7)
    {
        chanelList[curChanelIndex].ampl = value;
        for(int i = 0;i<8;i++)
        {
            setAmp(value,i);
            delayms (200) ;
        }

    }
    else
    {

        command[2] = 0x02;
        value = value+2*(700.0-chanelList[curChanelIndex].freq)/690.0;
        int a = value*4 + 0.5;
        command[3] = a>>8;
        command[4] = a;
        sendCommand(&command[0],chanel);
    }


}
void MainWindow::on_pushButton_clicked()
{
    if(ui->pushButton_num_control_amp->isChecked())
    {
        if(ui->lineEdit->text().toDouble()>0)ui->lineEdit->setText("-"+ui->lineEdit->text());
        double value =  (ui->lineEdit->text().toDouble());
        setAmp(-value,curChanelIndex);

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



//void MainWindow::on_pushButton_num_11_clicked()
//{
//    ui->lineEdit->clear();
//}
void MainWindow::inputText(QString text)
{
    ui->lineEdit->setText( ui->lineEdit->text() + text);

}
void MainWindow::on_pushButton_num_1_clicked()
{
    //inputText("1");
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_1,Qt::NoModifier,"1");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_pushButton_num_2_clicked()
{
    //inputText("2");
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_2,Qt::NoModifier,"2");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_pushButton_num_3_clicked()
{
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_3,Qt::NoModifier,"3");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_pushButton_num_4_clicked()
{
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_4,Qt::NoModifier,"4");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_pushButton_num_5_clicked()
{
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_5,Qt::NoModifier,"5");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_pushButton_num_6_clicked()
{
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_6,Qt::NoModifier,"6");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_pushButton_num_7_clicked()
{
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_7,Qt::NoModifier,"7");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_pushButton_num_8_clicked()
{
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_8,Qt::NoModifier,"8");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_pushButton_num_9_clicked()
{
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_9,Qt::NoModifier,"9");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_pushButton_num_0_clicked()
{
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_0,Qt::NoModifier,"0");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_pushButton_num_back_clicked()
{
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_Backspace,Qt::NoModifier);
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
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
    for(int chanel = 0;chanel<8;chanel++)
    {
        if(chanelList[chanel].isOn)
        {
            if(chanel==curChanelIndex)ui->label_chanel_stat->setText("On");
            switch (chanel) {
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
            if(chanel==curChanelIndex) ui->label_chanel_stat->setText("Off");
            switch (chanel) {
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
    }
    ui->label_chanel_freq->setText(QString::number(chanelList[curChanelIndex].freq));
    ui->label_chanel_phase->setText(QString::number(chanelList[curChanelIndex].phase));
    ui->label_chanel_amp->setText(QString::number(chanelList[curChanelIndex].ampl));

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

    QStringList strlist = ui->lineEdit->text().split('.');
    if(strlist.length()>1)
    {
        return;
    }
    else
    {
        QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_Period,Qt::NoModifier,".");
        qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
    }
}
void MainWindow::txOn(int chanel)
{
    if(chanel>7)
    {
        for(int i=0; i<8;i++)
        {
            txOn(i);
            delayms (200) ;
        }
        delayms (200) ;
        //ioUpdate();
        return;
    }

    else
    {
        command[1] = chanel;
    command[2] = 3;
    command[3] = 0;
    command[4] = 0;
    command[5] = 0;
    command[6] = 0;
    chanelList[chanel].isOn = true;
    sendCommand(&command[0],chanel);
    }
}
void MainWindow::txOff(int chanel)
{
    if(chanel>7)
    {
        for(int i=0; i<8;i++)
        {
            txOff(i);
            delayms (200) ;
        }
        delayms (200) ;
        //ioUpdate();
        return;
    }

    else
    {
        command[1] = chanel;
    command[2] = 4;
    command[3] = 0;
    command[4] = 0;
    command[5] = 0;
    command[6] = 0;
    chanelList[chanel].isOn = false;
    sendCommand(&command[0],chanel);
    }
}
void MainWindow::on_pushButton_kenh_16_clicked()
{
    txOn(curChanelIndex);
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
    //showStatus("Device  not ready");
    updateChanelInfo();
    //QApplication::beep();
}
void MainWindow::sendCommand(unsigned char*command)
{
    for(int i=0;i<COMMAND_LEN;i++)
    {
        #ifndef Q_OS_WIN
        serialPutchar (fd, command[i]) ;
        #endif
    }
}
void MainWindow::on_pushButton_kenh_17_clicked()
{
    txOff(curChanelIndex);
}



void MainWindow::on_pushButton_num_control_amp_clicked()
{
    ui->label_unit->setText("dBm");
}



void MainWindow::on_pushButton_num_control_afreq_clicked()
{
    ui->label_unit->setText("Mhz");
}

void MainWindow::on_pushButton_num_control_phase_clicked()
{
    ui->label_unit->setText("deg");
}

void MainWindow::on_pushButton_num_control_ioupdate_clicked()
{
    ioUpdate();
}



void MainWindow::on_pushButton_num_control_up_2_clicked()
{
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_commit_clicked()
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

void MainWindow::on_pushButton_load_config_table_clicked()
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


void MainWindow::on_pushButton_commit_2_clicked()
{
    /*if(ui->lineEdit_pass->text()=="cndt")*/ui->frame_config_edit->setVisible(true);
}

void MainWindow::on_pushButton_sort_table_2_clicked()//test button
{
    if(ui->tableWidget->selectedItems().size()==0)showStatus("Please select a value to test");
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

            if(value>=-360&&value<360)
            {
                //ui->tableWidget->item(0,tabitem->column())->setText(QString::number(chanelList[8].freq));
                setCursor(Qt::WaitCursor);
                setPhaseTrue(value,chanel);
                delayms(1000);
                //ioUpdate();
                setCursor(Qt::ArrowCursor);
                //tabitem->setBackgroundColor(QColor(120,180,250));
                return;
            }
        }

    }
    tabitem->setBackgroundColor(QColor(250,120,20));
}

void MainWindow::on_pushButton_num_control_ioupdate_2_clicked()
{
    this->setPalette(QPalette(MY_PATLETTE_WAITING));
    ui->tabWidget->hide();
    showStatus("Device restarting");
    update();

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

#ifndef Q_OS_WIN
    delay(1000);
    serialFlush(fd);
    update();
#endif
    int k=0;
    while (true)
    {
        if(onRecvUART()>1)break;
        #ifndef Q_OS_WIN
            delay(500);
        #endif
        k++;
        if(k>30)
        {
            showStatus("Device not ready");
            break;
        }
    }
    ui->tabWidget->show();
    this->setPalette(QPalette(MY_PATLETTE_NORMAL));
}

void MainWindow::on_pushButton_send_8bytes_clicked()
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
void MainWindow::setPhaseComp(double value, unsigned int chanel)
{
    if(value<0||value>360)
    {
        showStatus("Wrong value, phase should be from -360 to 360 degrees");
        return;
    }
    if(chanel > 8)return;
    chanelList[chanel].phase = value;
    if(chanel>7)
    {
        chanelList[chanel].phase = value;
        for(int i = 0;i<8;i++)
        {
            showStatus("Sending all chanel, please wait..."+QString::number((8-i)/2.0));
            setPhaseComp(value,i);
            delayms(200);
        }
    }
    else
    {
        chanelList[chanel].phase = value;
        double phaseComp= config.getValue(chanelList[chanel].freq,chanel);
        setPhaseTrue(value+phaseComp,chanel);
    }

}
bool MainWindow::setPhaseTrue(double value, unsigned int chanel)
{
    command[2] = 0x01;
    if(value<0)value+=360;
    if(value>=360)value-=360;
    if(value<0||value>360)
    {
        showStatus("Wrong value, phase should be from -360 to 360 degrees");
        return false;
    }
    else
    {
        value = value*182.0444444444444+0.5;
        int a= value;
        command[3] = a>>8;
        command[4] = a;
        sendCommand(&command[0],chanel);
        return true;
    }
}
void MainWindow::delayms(int msec)
{
#ifndef Q_OS_WIN
    delay (msec) ;
#endif
}
bool MainWindow::setfreq(double value,unsigned int chanel)
{
    if(value<10||value>700)
    {
        showStatus("Wrong value, frequency should be from 10Mhz to 700Mhz");
        return false;
    }
    if(chanel>8)return false;
    chanelList[chanel].freq = value;
    if(chanel>7)
    {
        for(int i=0; i<8;i++)
        {
            setfreq(value,i);
            showStatus("Sending data, please wait..."+QString::number((8-i)/2.0+0.5));
            delayms (200) ;
        }
        delayms (500) ;
        ioUpdate();
        delayms(500);
        setPhaseComp(0,8);

    }
    else
    {
        command[1] = chanel;
        command[2] = 0x00;


            value = value*1720740.1+0.5;
            int a = int(value);
            command[3] = a>>24;
            command[4] = a>>16;
            command[5] = a>>8;
            command[6] = a;
            sendCommand(&command[0],chanel);


    }
    return true;
}
void MainWindow::on_pushButton_set_all_freq_clicked()
{
    double value = ui->lineEdit_pass_freq_set_all->text().toDouble();
    setfreq(value,8);

}

void MainWindow::on_pushButton_num_control_up_clicked()
{
    ui->lineEdit->setText(QString::number(ui->lineEdit->text().toDouble()+1));
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if((QApplication::mouseButtons()==(Qt::NoButton))&&(ui->tabWidget->currentIndex()==0))ui->lineEdit->setFocus();

}

void MainWindow::on_pushButton_num_control_down_2_clicked()
{
    ui->lineEdit->cursorBackward(false);
}

void MainWindow::on_pushButton_num_control_down_3_clicked()
{
    ui->lineEdit->cursorForward(false);
}

void MainWindow::on_pushButton_num_control_down_clicked()
{
    ui->lineEdit->setText(QString::number(ui->lineEdit->text().toDouble()-1));

}
void MainWindow::updateTemp()
{
    updateChanelInfo();
//    command[1] = 0xff;
//    command[2] = 0xff;
//    command[3] = 0xff;
//    command[4] = 0xff;
//    command[5] = 0xff;
//    command[6] = 0xff;
//    sendCommand(&command[0]);
}

void MainWindow::on_pushButton_num_minus_clicked()
{
    QKeyEvent * eve1 = new QKeyEvent(QEvent::KeyPress,Qt::Key_Minus,Qt::NoModifier,"-");
    qApp->postEvent((QObject*)ui->lineEdit,(QEvent *)eve1);
}

void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    QString str = ui->tableWidget->item(0,item->column())->text();
    //ui->tableWidget->item(0,tabitem->column())->setText(QString::number(chanelList[8].freq));
    ui->lineEdit_pass_freq_set_all->setText(str);
}




