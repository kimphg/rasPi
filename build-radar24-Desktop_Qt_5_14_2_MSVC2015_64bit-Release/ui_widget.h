/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_setting;
    QVBoxLayout *layout;
    QGroupBox *groupBox;
    QPushButton *Start_pushButton;
    QPushButton *Stop_pushButton;
    QPushButton *Save_pushButton;
    QLineEdit *Initchar_lineEdit;
    QLabel *Initchar_label;
    QComboBox *Serialavailable_comboBox;
    QLabel *Serialavailable_label;
    QLabel *Serialbaud_label;
    QComboBox *Serialbaud_comboBox;
    QTextBrowser *Serialinfo_textBrowser;
    QLabel *Serialinfo_label;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *Numbersubplots_label;
    QSpinBox *Numbersubplots_spinBox;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *Subplot_groupBox_1;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *numberlines_spinBox_1;
    QScrollArea *lines_scrollArea_1;
    QWidget *lines_scrollAreaWidgetContents_1;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *line_groupBox_1_1;
    QGridLayout *gridLayout;
    QComboBox *color_comboBox_1_1;
    QSpinBox *y_spinBox_1_1;
    QSpinBox *x_spinBox_1_1;
    QLabel *y_label_1_1;
    QLabel *x_label_1_1;
    QLabel *color_label_1_1;
    QGroupBox *line_groupBox_1_2;
    QGridLayout *gridLayout_2;
    QComboBox *color_comboBox_1_2;
    QSpinBox *y_spinBox_1_2;
    QSpinBox *x_spinBox_1_2;
    QLabel *y_label_1_2;
    QLabel *x_label_1_2;
    QLabel *color_label_1_2;
    QGroupBox *line_groupBox_1_3;
    QGridLayout *gridLayout_3;
    QComboBox *color_comboBox_1_3;
    QSpinBox *y_spinBox_1_3;
    QSpinBox *x_spinBox_1_3;
    QLabel *y_label_1_3;
    QLabel *x_label_1_3;
    QLabel *color_label_1_3;
    QGroupBox *Subplot_groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *numberlines_spinBox_2;
    QScrollArea *lines_scrollArea_2;
    QWidget *lines_scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *line_groupBox_2_1;
    QGridLayout *gridLayout_4;
    QComboBox *color_comboBox_2_1;
    QSpinBox *y_spinBox_2_1;
    QSpinBox *x_spinBox_2_1;
    QLabel *y_label_2_1;
    QLabel *x_label_2_1;
    QLabel *color_label_2_1;
    QGroupBox *line_groupBox_2_2;
    QGridLayout *gridLayout_5;
    QComboBox *color_comboBox_2_2;
    QSpinBox *y_spinBox_2_2;
    QSpinBox *x_spinBox_2_2;
    QLabel *y_label_2_2;
    QLabel *x_label_2_2;
    QLabel *color_label_2_2;
    QGroupBox *line_groupBox_2_3;
    QGridLayout *gridLayout_6;
    QComboBox *color_comboBox_2_3;
    QSpinBox *y_spinBox_2_3;
    QSpinBox *x_spinBox_2_3;
    QLabel *y_label_2_3;
    QLabel *x_label_2_3;
    QLabel *color_label_2_3;
    QGroupBox *Subplot_groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *numberlines_spinBox_3;
    QScrollArea *lines_scrollArea_3;
    QWidget *lines_scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *line_groupBox_3_1;
    QGridLayout *gridLayout_7;
    QComboBox *color_comboBox_3_1;
    QSpinBox *y_spinBox_3_1;
    QSpinBox *x_spinBox_3_1;
    QLabel *y_label_3_1;
    QLabel *x_label_3_1;
    QLabel *color_label_3_1;
    QGroupBox *line_groupBox_3_2;
    QGridLayout *gridLayout_8;
    QComboBox *color_comboBox_3_2;
    QSpinBox *y_spinBox_3_2;
    QSpinBox *x_spinBox_3_2;
    QLabel *y_label_3_2;
    QLabel *x_label_3_2;
    QLabel *color_label_3_2;
    QGroupBox *line_groupBox_3_3;
    QGridLayout *gridLayout_9;
    QComboBox *color_comboBox_3_3;
    QSpinBox *y_spinBox_3_3;
    QSpinBox *x_spinBox_3_3;
    QLabel *y_label_3_3;
    QLabel *x_label_3_3;
    QLabel *color_label_3_3;
    QSplitter *splitter;
    QCustomPlot *Plot;
    QScrollBar *horizontalScrollBar;
    QTextBrowser *Serialincomingdata_textBrowser;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1004, 723);
        horizontalLayout_2 = new QHBoxLayout(Widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_setting = new QFrame(Widget);
        frame_setting->setObjectName(QString::fromUtf8("frame_setting"));
        layout = new QVBoxLayout(frame_setting);
        layout->setSpacing(6);
        layout->setContentsMargins(11, 11, 11, 11);
        layout->setObjectName(QString::fromUtf8("layout"));
        groupBox = new QGroupBox(frame_setting);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(270, 230));
        groupBox->setMaximumSize(QSize(270, 230));
        Start_pushButton = new QPushButton(groupBox);
        Start_pushButton->setObjectName(QString::fromUtf8("Start_pushButton"));
        Start_pushButton->setGeometry(QRect(12, 196, 75, 23));
        Stop_pushButton = new QPushButton(groupBox);
        Stop_pushButton->setObjectName(QString::fromUtf8("Stop_pushButton"));
        Stop_pushButton->setGeometry(QRect(93, 196, 75, 23));
        Save_pushButton = new QPushButton(groupBox);
        Save_pushButton->setObjectName(QString::fromUtf8("Save_pushButton"));
        Save_pushButton->setGeometry(QRect(174, 196, 75, 23));
        Initchar_lineEdit = new QLineEdit(groupBox);
        Initchar_lineEdit->setObjectName(QString::fromUtf8("Initchar_lineEdit"));
        Initchar_lineEdit->setGeometry(QRect(10, 160, 99, 20));
        Initchar_label = new QLabel(groupBox);
        Initchar_label->setObjectName(QString::fromUtf8("Initchar_label"));
        Initchar_label->setGeometry(QRect(13, 136, 101, 16));
        Serialavailable_comboBox = new QComboBox(groupBox);
        Serialavailable_comboBox->setObjectName(QString::fromUtf8("Serialavailable_comboBox"));
        Serialavailable_comboBox->setGeometry(QRect(13, 40, 101, 21));
        Serialavailable_label = new QLabel(groupBox);
        Serialavailable_label->setObjectName(QString::fromUtf8("Serialavailable_label"));
        Serialavailable_label->setGeometry(QRect(13, 23, 99, 16));
        Serialbaud_label = new QLabel(groupBox);
        Serialbaud_label->setObjectName(QString::fromUtf8("Serialbaud_label"));
        Serialbaud_label->setGeometry(QRect(13, 70, 91, 16));
        Serialbaud_comboBox = new QComboBox(groupBox);
        Serialbaud_comboBox->setObjectName(QString::fromUtf8("Serialbaud_comboBox"));
        Serialbaud_comboBox->setGeometry(QRect(13, 90, 101, 21));
        Serialinfo_textBrowser = new QTextBrowser(groupBox);
        Serialinfo_textBrowser->setObjectName(QString::fromUtf8("Serialinfo_textBrowser"));
        Serialinfo_textBrowser->setGeometry(QRect(120, 42, 138, 91));
        Serialinfo_label = new QLabel(groupBox);
        Serialinfo_label->setObjectName(QString::fromUtf8("Serialinfo_label"));
        Serialinfo_label->setGeometry(QRect(120, 23, 131, 16));

        layout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frame_setting);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(270, 150));
        groupBox_2->setMaximumSize(QSize(270, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, -1, 5, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Numbersubplots_label = new QLabel(groupBox_2);
        Numbersubplots_label->setObjectName(QString::fromUtf8("Numbersubplots_label"));
        sizePolicy.setHeightForWidth(Numbersubplots_label->sizePolicy().hasHeightForWidth());
        Numbersubplots_label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Numbersubplots_label);

        Numbersubplots_spinBox = new QSpinBox(groupBox_2);
        Numbersubplots_spinBox->setObjectName(QString::fromUtf8("Numbersubplots_spinBox"));
        sizePolicy.setHeightForWidth(Numbersubplots_spinBox->sizePolicy().hasHeightForWidth());
        Numbersubplots_spinBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        Numbersubplots_spinBox->setFont(font);
        Numbersubplots_spinBox->setReadOnly(false);
        Numbersubplots_spinBox->setAccelerated(false);
        Numbersubplots_spinBox->setMinimum(1);
        Numbersubplots_spinBox->setMaximum(5);
        Numbersubplots_spinBox->setValue(5);

        horizontalLayout->addWidget(Numbersubplots_spinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(groupBox_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 258, 406));
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(3, 3, 3, 3);
        Subplot_groupBox_1 = new QGroupBox(scrollAreaWidgetContents);
        Subplot_groupBox_1->setObjectName(QString::fromUtf8("Subplot_groupBox_1"));
        Subplot_groupBox_1->setMinimumSize(QSize(250, 80));
        Subplot_groupBox_1->setMaximumSize(QSize(250, 16777215));
        horizontalLayout_3 = new QHBoxLayout(Subplot_groupBox_1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 2);
        numberlines_spinBox_1 = new QSpinBox(Subplot_groupBox_1);
        numberlines_spinBox_1->setObjectName(QString::fromUtf8("numberlines_spinBox_1"));
        numberlines_spinBox_1->setStyleSheet(QString::fromUtf8(""));
        numberlines_spinBox_1->setMinimum(1);
        numberlines_spinBox_1->setMaximum(3);
        numberlines_spinBox_1->setValue(3);

        horizontalLayout_3->addWidget(numberlines_spinBox_1);

        lines_scrollArea_1 = new QScrollArea(Subplot_groupBox_1);
        lines_scrollArea_1->setObjectName(QString::fromUtf8("lines_scrollArea_1"));
        lines_scrollArea_1->setMinimumSize(QSize(200, 60));
        lines_scrollArea_1->setMaximumSize(QSize(200, 16777215));
        lines_scrollArea_1->setFrameShadow(QFrame::Raised);
        lines_scrollArea_1->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        lines_scrollArea_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lines_scrollArea_1->setWidgetResizable(true);
        lines_scrollAreaWidgetContents_1 = new QWidget();
        lines_scrollAreaWidgetContents_1->setObjectName(QString::fromUtf8("lines_scrollAreaWidgetContents_1"));
        lines_scrollAreaWidgetContents_1->setGeometry(QRect(0, 0, 181, 218));
        verticalLayout_3 = new QVBoxLayout(lines_scrollAreaWidgetContents_1);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        line_groupBox_1_1 = new QGroupBox(lines_scrollAreaWidgetContents_1);
        line_groupBox_1_1->setObjectName(QString::fromUtf8("line_groupBox_1_1"));
        sizePolicy.setHeightForWidth(line_groupBox_1_1->sizePolicy().hasHeightForWidth());
        line_groupBox_1_1->setSizePolicy(sizePolicy);
        line_groupBox_1_1->setMinimumSize(QSize(180, 70));
        line_groupBox_1_1->setMaximumSize(QSize(180, 70));
        gridLayout = new QGridLayout(line_groupBox_1_1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(2, 0, 2, 2);
        color_comboBox_1_1 = new QComboBox(line_groupBox_1_1);
        color_comboBox_1_1->addItem(QString());
        color_comboBox_1_1->addItem(QString());
        color_comboBox_1_1->addItem(QString());
        color_comboBox_1_1->addItem(QString());
        color_comboBox_1_1->addItem(QString());
        color_comboBox_1_1->addItem(QString());
        color_comboBox_1_1->setObjectName(QString::fromUtf8("color_comboBox_1_1"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        color_comboBox_1_1->setPalette(palette);
        QFont font1;
        font1.setPointSize(8);
        color_comboBox_1_1->setFont(font1);
        color_comboBox_1_1->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(color_comboBox_1_1, 1, 2, 1, 1);

        y_spinBox_1_1 = new QSpinBox(line_groupBox_1_1);
        y_spinBox_1_1->setObjectName(QString::fromUtf8("y_spinBox_1_1"));
        y_spinBox_1_1->setMinimum(1);
        y_spinBox_1_1->setValue(2);

        gridLayout->addWidget(y_spinBox_1_1, 1, 1, 1, 1);

        x_spinBox_1_1 = new QSpinBox(line_groupBox_1_1);
        x_spinBox_1_1->setObjectName(QString::fromUtf8("x_spinBox_1_1"));
        x_spinBox_1_1->setMinimum(1);

        gridLayout->addWidget(x_spinBox_1_1, 1, 0, 1, 1);

        y_label_1_1 = new QLabel(line_groupBox_1_1);
        y_label_1_1->setObjectName(QString::fromUtf8("y_label_1_1"));

        gridLayout->addWidget(y_label_1_1, 0, 1, 1, 1);

        x_label_1_1 = new QLabel(line_groupBox_1_1);
        x_label_1_1->setObjectName(QString::fromUtf8("x_label_1_1"));

        gridLayout->addWidget(x_label_1_1, 0, 0, 1, 1);

        color_label_1_1 = new QLabel(line_groupBox_1_1);
        color_label_1_1->setObjectName(QString::fromUtf8("color_label_1_1"));

        gridLayout->addWidget(color_label_1_1, 0, 2, 1, 1);


        verticalLayout_3->addWidget(line_groupBox_1_1);

        line_groupBox_1_2 = new QGroupBox(lines_scrollAreaWidgetContents_1);
        line_groupBox_1_2->setObjectName(QString::fromUtf8("line_groupBox_1_2"));
        sizePolicy.setHeightForWidth(line_groupBox_1_2->sizePolicy().hasHeightForWidth());
        line_groupBox_1_2->setSizePolicy(sizePolicy);
        line_groupBox_1_2->setMinimumSize(QSize(180, 70));
        line_groupBox_1_2->setMaximumSize(QSize(180, 70));
        gridLayout_2 = new QGridLayout(line_groupBox_1_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(2);
        gridLayout_2->setContentsMargins(2, 0, 2, 2);
        color_comboBox_1_2 = new QComboBox(line_groupBox_1_2);
        color_comboBox_1_2->addItem(QString());
        color_comboBox_1_2->addItem(QString());
        color_comboBox_1_2->addItem(QString());
        color_comboBox_1_2->addItem(QString());
        color_comboBox_1_2->addItem(QString());
        color_comboBox_1_2->addItem(QString());
        color_comboBox_1_2->setObjectName(QString::fromUtf8("color_comboBox_1_2"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        color_comboBox_1_2->setPalette(palette1);
        color_comboBox_1_2->setFont(font1);
        color_comboBox_1_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(color_comboBox_1_2, 1, 2, 1, 1);

        y_spinBox_1_2 = new QSpinBox(line_groupBox_1_2);
        y_spinBox_1_2->setObjectName(QString::fromUtf8("y_spinBox_1_2"));
        y_spinBox_1_2->setMinimum(1);
        y_spinBox_1_2->setValue(2);

        gridLayout_2->addWidget(y_spinBox_1_2, 1, 1, 1, 1);

        x_spinBox_1_2 = new QSpinBox(line_groupBox_1_2);
        x_spinBox_1_2->setObjectName(QString::fromUtf8("x_spinBox_1_2"));
        x_spinBox_1_2->setMinimum(1);

        gridLayout_2->addWidget(x_spinBox_1_2, 1, 0, 1, 1);

        y_label_1_2 = new QLabel(line_groupBox_1_2);
        y_label_1_2->setObjectName(QString::fromUtf8("y_label_1_2"));

        gridLayout_2->addWidget(y_label_1_2, 0, 1, 1, 1);

        x_label_1_2 = new QLabel(line_groupBox_1_2);
        x_label_1_2->setObjectName(QString::fromUtf8("x_label_1_2"));

        gridLayout_2->addWidget(x_label_1_2, 0, 0, 1, 1);

        color_label_1_2 = new QLabel(line_groupBox_1_2);
        color_label_1_2->setObjectName(QString::fromUtf8("color_label_1_2"));

        gridLayout_2->addWidget(color_label_1_2, 0, 2, 1, 1);


        verticalLayout_3->addWidget(line_groupBox_1_2);

        line_groupBox_1_3 = new QGroupBox(lines_scrollAreaWidgetContents_1);
        line_groupBox_1_3->setObjectName(QString::fromUtf8("line_groupBox_1_3"));
        sizePolicy.setHeightForWidth(line_groupBox_1_3->sizePolicy().hasHeightForWidth());
        line_groupBox_1_3->setSizePolicy(sizePolicy);
        line_groupBox_1_3->setMinimumSize(QSize(180, 70));
        line_groupBox_1_3->setMaximumSize(QSize(180, 70));
        gridLayout_3 = new QGridLayout(line_groupBox_1_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setVerticalSpacing(2);
        gridLayout_3->setContentsMargins(2, 0, 2, 2);
        color_comboBox_1_3 = new QComboBox(line_groupBox_1_3);
        color_comboBox_1_3->addItem(QString());
        color_comboBox_1_3->addItem(QString());
        color_comboBox_1_3->addItem(QString());
        color_comboBox_1_3->addItem(QString());
        color_comboBox_1_3->addItem(QString());
        color_comboBox_1_3->addItem(QString());
        color_comboBox_1_3->setObjectName(QString::fromUtf8("color_comboBox_1_3"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        color_comboBox_1_3->setPalette(palette2);
        color_comboBox_1_3->setFont(font1);
        color_comboBox_1_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(color_comboBox_1_3, 1, 2, 1, 1);

        y_spinBox_1_3 = new QSpinBox(line_groupBox_1_3);
        y_spinBox_1_3->setObjectName(QString::fromUtf8("y_spinBox_1_3"));
        y_spinBox_1_3->setMinimum(1);
        y_spinBox_1_3->setValue(2);

        gridLayout_3->addWidget(y_spinBox_1_3, 1, 1, 1, 1);

        x_spinBox_1_3 = new QSpinBox(line_groupBox_1_3);
        x_spinBox_1_3->setObjectName(QString::fromUtf8("x_spinBox_1_3"));
        x_spinBox_1_3->setMinimum(1);

        gridLayout_3->addWidget(x_spinBox_1_3, 1, 0, 1, 1);

        y_label_1_3 = new QLabel(line_groupBox_1_3);
        y_label_1_3->setObjectName(QString::fromUtf8("y_label_1_3"));

        gridLayout_3->addWidget(y_label_1_3, 0, 1, 1, 1);

        x_label_1_3 = new QLabel(line_groupBox_1_3);
        x_label_1_3->setObjectName(QString::fromUtf8("x_label_1_3"));

        gridLayout_3->addWidget(x_label_1_3, 0, 0, 1, 1);

        color_label_1_3 = new QLabel(line_groupBox_1_3);
        color_label_1_3->setObjectName(QString::fromUtf8("color_label_1_3"));

        gridLayout_3->addWidget(color_label_1_3, 0, 2, 1, 1);


        verticalLayout_3->addWidget(line_groupBox_1_3);

        lines_scrollArea_1->setWidget(lines_scrollAreaWidgetContents_1);

        horizontalLayout_3->addWidget(lines_scrollArea_1);


        verticalLayout_6->addWidget(Subplot_groupBox_1);

        Subplot_groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        Subplot_groupBox_2->setObjectName(QString::fromUtf8("Subplot_groupBox_2"));
        Subplot_groupBox_2->setMinimumSize(QSize(250, 80));
        Subplot_groupBox_2->setMaximumSize(QSize(250, 16777215));
        horizontalLayout_4 = new QHBoxLayout(Subplot_groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 2);
        numberlines_spinBox_2 = new QSpinBox(Subplot_groupBox_2);
        numberlines_spinBox_2->setObjectName(QString::fromUtf8("numberlines_spinBox_2"));
        numberlines_spinBox_2->setMinimum(1);
        numberlines_spinBox_2->setMaximum(3);
        numberlines_spinBox_2->setValue(3);

        horizontalLayout_4->addWidget(numberlines_spinBox_2);

        lines_scrollArea_2 = new QScrollArea(Subplot_groupBox_2);
        lines_scrollArea_2->setObjectName(QString::fromUtf8("lines_scrollArea_2"));
        lines_scrollArea_2->setMinimumSize(QSize(200, 60));
        lines_scrollArea_2->setMaximumSize(QSize(200, 16777215));
        lines_scrollArea_2->setFrameShadow(QFrame::Raised);
        lines_scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        lines_scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lines_scrollArea_2->setWidgetResizable(true);
        lines_scrollAreaWidgetContents_2 = new QWidget();
        lines_scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("lines_scrollAreaWidgetContents_2"));
        lines_scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 181, 218));
        verticalLayout_4 = new QVBoxLayout(lines_scrollAreaWidgetContents_2);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        line_groupBox_2_1 = new QGroupBox(lines_scrollAreaWidgetContents_2);
        line_groupBox_2_1->setObjectName(QString::fromUtf8("line_groupBox_2_1"));
        sizePolicy.setHeightForWidth(line_groupBox_2_1->sizePolicy().hasHeightForWidth());
        line_groupBox_2_1->setSizePolicy(sizePolicy);
        line_groupBox_2_1->setMinimumSize(QSize(180, 70));
        line_groupBox_2_1->setMaximumSize(QSize(180, 70));
        gridLayout_4 = new QGridLayout(line_groupBox_2_1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(2);
        gridLayout_4->setContentsMargins(2, 0, 2, 2);
        color_comboBox_2_1 = new QComboBox(line_groupBox_2_1);
        color_comboBox_2_1->addItem(QString());
        color_comboBox_2_1->addItem(QString());
        color_comboBox_2_1->addItem(QString());
        color_comboBox_2_1->addItem(QString());
        color_comboBox_2_1->addItem(QString());
        color_comboBox_2_1->addItem(QString());
        color_comboBox_2_1->setObjectName(QString::fromUtf8("color_comboBox_2_1"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        color_comboBox_2_1->setPalette(palette3);
        color_comboBox_2_1->setFont(font1);
        color_comboBox_2_1->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(color_comboBox_2_1, 1, 2, 1, 1);

        y_spinBox_2_1 = new QSpinBox(line_groupBox_2_1);
        y_spinBox_2_1->setObjectName(QString::fromUtf8("y_spinBox_2_1"));
        y_spinBox_2_1->setMinimum(1);
        y_spinBox_2_1->setValue(2);

        gridLayout_4->addWidget(y_spinBox_2_1, 1, 1, 1, 1);

        x_spinBox_2_1 = new QSpinBox(line_groupBox_2_1);
        x_spinBox_2_1->setObjectName(QString::fromUtf8("x_spinBox_2_1"));
        x_spinBox_2_1->setMinimum(1);

        gridLayout_4->addWidget(x_spinBox_2_1, 1, 0, 1, 1);

        y_label_2_1 = new QLabel(line_groupBox_2_1);
        y_label_2_1->setObjectName(QString::fromUtf8("y_label_2_1"));

        gridLayout_4->addWidget(y_label_2_1, 0, 1, 1, 1);

        x_label_2_1 = new QLabel(line_groupBox_2_1);
        x_label_2_1->setObjectName(QString::fromUtf8("x_label_2_1"));

        gridLayout_4->addWidget(x_label_2_1, 0, 0, 1, 1);

        color_label_2_1 = new QLabel(line_groupBox_2_1);
        color_label_2_1->setObjectName(QString::fromUtf8("color_label_2_1"));

        gridLayout_4->addWidget(color_label_2_1, 0, 2, 1, 1);


        verticalLayout_4->addWidget(line_groupBox_2_1);

        line_groupBox_2_2 = new QGroupBox(lines_scrollAreaWidgetContents_2);
        line_groupBox_2_2->setObjectName(QString::fromUtf8("line_groupBox_2_2"));
        sizePolicy.setHeightForWidth(line_groupBox_2_2->sizePolicy().hasHeightForWidth());
        line_groupBox_2_2->setSizePolicy(sizePolicy);
        line_groupBox_2_2->setMinimumSize(QSize(180, 70));
        line_groupBox_2_2->setMaximumSize(QSize(180, 70));
        gridLayout_5 = new QGridLayout(line_groupBox_2_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(2);
        gridLayout_5->setContentsMargins(2, 0, 2, 2);
        color_comboBox_2_2 = new QComboBox(line_groupBox_2_2);
        color_comboBox_2_2->addItem(QString());
        color_comboBox_2_2->addItem(QString());
        color_comboBox_2_2->addItem(QString());
        color_comboBox_2_2->addItem(QString());
        color_comboBox_2_2->addItem(QString());
        color_comboBox_2_2->addItem(QString());
        color_comboBox_2_2->setObjectName(QString::fromUtf8("color_comboBox_2_2"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        color_comboBox_2_2->setPalette(palette4);
        color_comboBox_2_2->setFont(font1);
        color_comboBox_2_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(color_comboBox_2_2, 1, 2, 1, 1);

        y_spinBox_2_2 = new QSpinBox(line_groupBox_2_2);
        y_spinBox_2_2->setObjectName(QString::fromUtf8("y_spinBox_2_2"));
        y_spinBox_2_2->setMinimum(1);
        y_spinBox_2_2->setValue(2);

        gridLayout_5->addWidget(y_spinBox_2_2, 1, 1, 1, 1);

        x_spinBox_2_2 = new QSpinBox(line_groupBox_2_2);
        x_spinBox_2_2->setObjectName(QString::fromUtf8("x_spinBox_2_2"));
        x_spinBox_2_2->setMinimum(1);

        gridLayout_5->addWidget(x_spinBox_2_2, 1, 0, 1, 1);

        y_label_2_2 = new QLabel(line_groupBox_2_2);
        y_label_2_2->setObjectName(QString::fromUtf8("y_label_2_2"));

        gridLayout_5->addWidget(y_label_2_2, 0, 1, 1, 1);

        x_label_2_2 = new QLabel(line_groupBox_2_2);
        x_label_2_2->setObjectName(QString::fromUtf8("x_label_2_2"));

        gridLayout_5->addWidget(x_label_2_2, 0, 0, 1, 1);

        color_label_2_2 = new QLabel(line_groupBox_2_2);
        color_label_2_2->setObjectName(QString::fromUtf8("color_label_2_2"));

        gridLayout_5->addWidget(color_label_2_2, 0, 2, 1, 1);


        verticalLayout_4->addWidget(line_groupBox_2_2);

        line_groupBox_2_3 = new QGroupBox(lines_scrollAreaWidgetContents_2);
        line_groupBox_2_3->setObjectName(QString::fromUtf8("line_groupBox_2_3"));
        sizePolicy.setHeightForWidth(line_groupBox_2_3->sizePolicy().hasHeightForWidth());
        line_groupBox_2_3->setSizePolicy(sizePolicy);
        line_groupBox_2_3->setMinimumSize(QSize(180, 70));
        line_groupBox_2_3->setMaximumSize(QSize(180, 70));
        gridLayout_6 = new QGridLayout(line_groupBox_2_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setVerticalSpacing(2);
        gridLayout_6->setContentsMargins(2, 0, 2, 2);
        color_comboBox_2_3 = new QComboBox(line_groupBox_2_3);
        color_comboBox_2_3->addItem(QString());
        color_comboBox_2_3->addItem(QString());
        color_comboBox_2_3->addItem(QString());
        color_comboBox_2_3->addItem(QString());
        color_comboBox_2_3->addItem(QString());
        color_comboBox_2_3->addItem(QString());
        color_comboBox_2_3->setObjectName(QString::fromUtf8("color_comboBox_2_3"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        color_comboBox_2_3->setPalette(palette5);
        color_comboBox_2_3->setFont(font1);
        color_comboBox_2_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout_6->addWidget(color_comboBox_2_3, 1, 2, 1, 1);

        y_spinBox_2_3 = new QSpinBox(line_groupBox_2_3);
        y_spinBox_2_3->setObjectName(QString::fromUtf8("y_spinBox_2_3"));
        y_spinBox_2_3->setMinimum(1);
        y_spinBox_2_3->setValue(2);

        gridLayout_6->addWidget(y_spinBox_2_3, 1, 1, 1, 1);

        x_spinBox_2_3 = new QSpinBox(line_groupBox_2_3);
        x_spinBox_2_3->setObjectName(QString::fromUtf8("x_spinBox_2_3"));
        x_spinBox_2_3->setMinimum(1);

        gridLayout_6->addWidget(x_spinBox_2_3, 1, 0, 1, 1);

        y_label_2_3 = new QLabel(line_groupBox_2_3);
        y_label_2_3->setObjectName(QString::fromUtf8("y_label_2_3"));

        gridLayout_6->addWidget(y_label_2_3, 0, 1, 1, 1);

        x_label_2_3 = new QLabel(line_groupBox_2_3);
        x_label_2_3->setObjectName(QString::fromUtf8("x_label_2_3"));

        gridLayout_6->addWidget(x_label_2_3, 0, 0, 1, 1);

        color_label_2_3 = new QLabel(line_groupBox_2_3);
        color_label_2_3->setObjectName(QString::fromUtf8("color_label_2_3"));

        gridLayout_6->addWidget(color_label_2_3, 0, 2, 1, 1);


        verticalLayout_4->addWidget(line_groupBox_2_3);

        lines_scrollArea_2->setWidget(lines_scrollAreaWidgetContents_2);

        horizontalLayout_4->addWidget(lines_scrollArea_2);


        verticalLayout_6->addWidget(Subplot_groupBox_2);

        Subplot_groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        Subplot_groupBox_3->setObjectName(QString::fromUtf8("Subplot_groupBox_3"));
        Subplot_groupBox_3->setMinimumSize(QSize(250, 80));
        Subplot_groupBox_3->setMaximumSize(QSize(250, 16777215));
        horizontalLayout_5 = new QHBoxLayout(Subplot_groupBox_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 2);
        numberlines_spinBox_3 = new QSpinBox(Subplot_groupBox_3);
        numberlines_spinBox_3->setObjectName(QString::fromUtf8("numberlines_spinBox_3"));
        numberlines_spinBox_3->setMinimum(1);
        numberlines_spinBox_3->setMaximum(3);
        numberlines_spinBox_3->setValue(3);

        horizontalLayout_5->addWidget(numberlines_spinBox_3);

        lines_scrollArea_3 = new QScrollArea(Subplot_groupBox_3);
        lines_scrollArea_3->setObjectName(QString::fromUtf8("lines_scrollArea_3"));
        lines_scrollArea_3->setMinimumSize(QSize(200, 60));
        lines_scrollArea_3->setMaximumSize(QSize(200, 16777215));
        lines_scrollArea_3->setFrameShadow(QFrame::Raised);
        lines_scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        lines_scrollArea_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lines_scrollArea_3->setWidgetResizable(true);
        lines_scrollAreaWidgetContents_3 = new QWidget();
        lines_scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("lines_scrollAreaWidgetContents_3"));
        lines_scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 181, 218));
        verticalLayout_5 = new QVBoxLayout(lines_scrollAreaWidgetContents_3);
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        line_groupBox_3_1 = new QGroupBox(lines_scrollAreaWidgetContents_3);
        line_groupBox_3_1->setObjectName(QString::fromUtf8("line_groupBox_3_1"));
        sizePolicy.setHeightForWidth(line_groupBox_3_1->sizePolicy().hasHeightForWidth());
        line_groupBox_3_1->setSizePolicy(sizePolicy);
        line_groupBox_3_1->setMinimumSize(QSize(180, 70));
        line_groupBox_3_1->setMaximumSize(QSize(180, 70));
        gridLayout_7 = new QGridLayout(line_groupBox_3_1);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setVerticalSpacing(2);
        gridLayout_7->setContentsMargins(2, 0, 2, 2);
        color_comboBox_3_1 = new QComboBox(line_groupBox_3_1);
        color_comboBox_3_1->addItem(QString());
        color_comboBox_3_1->addItem(QString());
        color_comboBox_3_1->addItem(QString());
        color_comboBox_3_1->addItem(QString());
        color_comboBox_3_1->addItem(QString());
        color_comboBox_3_1->addItem(QString());
        color_comboBox_3_1->setObjectName(QString::fromUtf8("color_comboBox_3_1"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        color_comboBox_3_1->setPalette(palette6);
        color_comboBox_3_1->setFont(font1);
        color_comboBox_3_1->setStyleSheet(QString::fromUtf8(""));

        gridLayout_7->addWidget(color_comboBox_3_1, 1, 2, 1, 1);

        y_spinBox_3_1 = new QSpinBox(line_groupBox_3_1);
        y_spinBox_3_1->setObjectName(QString::fromUtf8("y_spinBox_3_1"));
        y_spinBox_3_1->setMinimum(1);
        y_spinBox_3_1->setValue(2);

        gridLayout_7->addWidget(y_spinBox_3_1, 1, 1, 1, 1);

        x_spinBox_3_1 = new QSpinBox(line_groupBox_3_1);
        x_spinBox_3_1->setObjectName(QString::fromUtf8("x_spinBox_3_1"));
        x_spinBox_3_1->setMinimum(1);

        gridLayout_7->addWidget(x_spinBox_3_1, 1, 0, 1, 1);

        y_label_3_1 = new QLabel(line_groupBox_3_1);
        y_label_3_1->setObjectName(QString::fromUtf8("y_label_3_1"));

        gridLayout_7->addWidget(y_label_3_1, 0, 1, 1, 1);

        x_label_3_1 = new QLabel(line_groupBox_3_1);
        x_label_3_1->setObjectName(QString::fromUtf8("x_label_3_1"));

        gridLayout_7->addWidget(x_label_3_1, 0, 0, 1, 1);

        color_label_3_1 = new QLabel(line_groupBox_3_1);
        color_label_3_1->setObjectName(QString::fromUtf8("color_label_3_1"));

        gridLayout_7->addWidget(color_label_3_1, 0, 2, 1, 1);


        verticalLayout_5->addWidget(line_groupBox_3_1);

        line_groupBox_3_2 = new QGroupBox(lines_scrollAreaWidgetContents_3);
        line_groupBox_3_2->setObjectName(QString::fromUtf8("line_groupBox_3_2"));
        sizePolicy.setHeightForWidth(line_groupBox_3_2->sizePolicy().hasHeightForWidth());
        line_groupBox_3_2->setSizePolicy(sizePolicy);
        line_groupBox_3_2->setMinimumSize(QSize(180, 70));
        line_groupBox_3_2->setMaximumSize(QSize(180, 70));
        gridLayout_8 = new QGridLayout(line_groupBox_3_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setVerticalSpacing(2);
        gridLayout_8->setContentsMargins(2, 0, 2, 2);
        color_comboBox_3_2 = new QComboBox(line_groupBox_3_2);
        color_comboBox_3_2->addItem(QString());
        color_comboBox_3_2->addItem(QString());
        color_comboBox_3_2->addItem(QString());
        color_comboBox_3_2->addItem(QString());
        color_comboBox_3_2->addItem(QString());
        color_comboBox_3_2->addItem(QString());
        color_comboBox_3_2->setObjectName(QString::fromUtf8("color_comboBox_3_2"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        color_comboBox_3_2->setPalette(palette7);
        color_comboBox_3_2->setFont(font1);
        color_comboBox_3_2->setStyleSheet(QString::fromUtf8(""));

        gridLayout_8->addWidget(color_comboBox_3_2, 1, 2, 1, 1);

        y_spinBox_3_2 = new QSpinBox(line_groupBox_3_2);
        y_spinBox_3_2->setObjectName(QString::fromUtf8("y_spinBox_3_2"));
        y_spinBox_3_2->setMinimum(1);
        y_spinBox_3_2->setValue(2);

        gridLayout_8->addWidget(y_spinBox_3_2, 1, 1, 1, 1);

        x_spinBox_3_2 = new QSpinBox(line_groupBox_3_2);
        x_spinBox_3_2->setObjectName(QString::fromUtf8("x_spinBox_3_2"));
        x_spinBox_3_2->setMinimum(1);

        gridLayout_8->addWidget(x_spinBox_3_2, 1, 0, 1, 1);

        y_label_3_2 = new QLabel(line_groupBox_3_2);
        y_label_3_2->setObjectName(QString::fromUtf8("y_label_3_2"));

        gridLayout_8->addWidget(y_label_3_2, 0, 1, 1, 1);

        x_label_3_2 = new QLabel(line_groupBox_3_2);
        x_label_3_2->setObjectName(QString::fromUtf8("x_label_3_2"));

        gridLayout_8->addWidget(x_label_3_2, 0, 0, 1, 1);

        color_label_3_2 = new QLabel(line_groupBox_3_2);
        color_label_3_2->setObjectName(QString::fromUtf8("color_label_3_2"));

        gridLayout_8->addWidget(color_label_3_2, 0, 2, 1, 1);


        verticalLayout_5->addWidget(line_groupBox_3_2);

        line_groupBox_3_3 = new QGroupBox(lines_scrollAreaWidgetContents_3);
        line_groupBox_3_3->setObjectName(QString::fromUtf8("line_groupBox_3_3"));
        sizePolicy.setHeightForWidth(line_groupBox_3_3->sizePolicy().hasHeightForWidth());
        line_groupBox_3_3->setSizePolicy(sizePolicy);
        line_groupBox_3_3->setMinimumSize(QSize(180, 70));
        line_groupBox_3_3->setMaximumSize(QSize(180, 70));
        gridLayout_9 = new QGridLayout(line_groupBox_3_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setVerticalSpacing(2);
        gridLayout_9->setContentsMargins(2, 0, 2, 2);
        color_comboBox_3_3 = new QComboBox(line_groupBox_3_3);
        color_comboBox_3_3->addItem(QString());
        color_comboBox_3_3->addItem(QString());
        color_comboBox_3_3->addItem(QString());
        color_comboBox_3_3->addItem(QString());
        color_comboBox_3_3->addItem(QString());
        color_comboBox_3_3->addItem(QString());
        color_comboBox_3_3->setObjectName(QString::fromUtf8("color_comboBox_3_3"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        color_comboBox_3_3->setPalette(palette8);
        color_comboBox_3_3->setFont(font1);
        color_comboBox_3_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout_9->addWidget(color_comboBox_3_3, 1, 2, 1, 1);

        y_spinBox_3_3 = new QSpinBox(line_groupBox_3_3);
        y_spinBox_3_3->setObjectName(QString::fromUtf8("y_spinBox_3_3"));
        y_spinBox_3_3->setMinimum(1);
        y_spinBox_3_3->setValue(2);

        gridLayout_9->addWidget(y_spinBox_3_3, 1, 1, 1, 1);

        x_spinBox_3_3 = new QSpinBox(line_groupBox_3_3);
        x_spinBox_3_3->setObjectName(QString::fromUtf8("x_spinBox_3_3"));
        x_spinBox_3_3->setMinimum(1);

        gridLayout_9->addWidget(x_spinBox_3_3, 1, 0, 1, 1);

        y_label_3_3 = new QLabel(line_groupBox_3_3);
        y_label_3_3->setObjectName(QString::fromUtf8("y_label_3_3"));

        gridLayout_9->addWidget(y_label_3_3, 0, 1, 1, 1);

        x_label_3_3 = new QLabel(line_groupBox_3_3);
        x_label_3_3->setObjectName(QString::fromUtf8("x_label_3_3"));

        gridLayout_9->addWidget(x_label_3_3, 0, 0, 1, 1);

        color_label_3_3 = new QLabel(line_groupBox_3_3);
        color_label_3_3->setObjectName(QString::fromUtf8("color_label_3_3"));

        gridLayout_9->addWidget(color_label_3_3, 0, 2, 1, 1);


        verticalLayout_5->addWidget(line_groupBox_3_3);

        lines_scrollArea_3->setWidget(lines_scrollAreaWidgetContents_3);

        horizontalLayout_5->addWidget(lines_scrollArea_3);


        verticalLayout_6->addWidget(Subplot_groupBox_3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        layout->addWidget(groupBox_2);


        horizontalLayout_2->addWidget(frame_setting);

        splitter = new QSplitter(Widget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        Plot = new QCustomPlot(splitter);
        Plot->setObjectName(QString::fromUtf8("Plot"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Plot->sizePolicy().hasHeightForWidth());
        Plot->setSizePolicy(sizePolicy2);
        splitter->addWidget(Plot);
        horizontalScrollBar = new QScrollBar(splitter);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setMinimumSize(QSize(0, 17));
        horizontalScrollBar->setMaximumSize(QSize(16777215, 17));
        horizontalScrollBar->setSingleStep(1);
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        splitter->addWidget(horizontalScrollBar);
        Serialincomingdata_textBrowser = new QTextBrowser(splitter);
        Serialincomingdata_textBrowser->setObjectName(QString::fromUtf8("Serialincomingdata_textBrowser"));
        Serialincomingdata_textBrowser->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Serialincomingdata_textBrowser->sizePolicy().hasHeightForWidth());
        Serialincomingdata_textBrowser->setSizePolicy(sizePolicy3);
        Serialincomingdata_textBrowser->setMinimumSize(QSize(300, 90));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        Serialincomingdata_textBrowser->setPalette(palette9);
        splitter->addWidget(Serialincomingdata_textBrowser);

        horizontalLayout_2->addWidget(splitter);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "Serial Settings", nullptr));
        Start_pushButton->setText(QCoreApplication::translate("Widget", "Start", nullptr));
        Stop_pushButton->setText(QCoreApplication::translate("Widget", "Stop", nullptr));
        Save_pushButton->setText(QCoreApplication::translate("Widget", "Save", nullptr));
        Initchar_label->setText(QCoreApplication::translate("Widget", "Init char", nullptr));
        Serialavailable_label->setText(QCoreApplication::translate("Widget", "Available serial ports", nullptr));
        Serialbaud_label->setText(QCoreApplication::translate("Widget", "Serial rate", nullptr));
        Serialinfo_label->setText(QCoreApplication::translate("Widget", "Serial info", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "Plot Settings", nullptr));
        Numbersubplots_label->setText(QCoreApplication::translate("Widget", "Subplots:", nullptr));
        Subplot_groupBox_1->setTitle(QCoreApplication::translate("Widget", "Subplot 1", nullptr));
        line_groupBox_1_1->setTitle(QCoreApplication::translate("Widget", "Line 1", nullptr));
        color_comboBox_1_1->setItemText(0, QCoreApplication::translate("Widget", "blue", nullptr));
        color_comboBox_1_1->setItemText(1, QCoreApplication::translate("Widget", "red", nullptr));
        color_comboBox_1_1->setItemText(2, QCoreApplication::translate("Widget", "black", nullptr));
        color_comboBox_1_1->setItemText(3, QCoreApplication::translate("Widget", "green", nullptr));
        color_comboBox_1_1->setItemText(4, QCoreApplication::translate("Widget", "orange", nullptr));
        color_comboBox_1_1->setItemText(5, QCoreApplication::translate("Widget", "yellow", nullptr));

        y_label_1_1->setText(QCoreApplication::translate("Widget", "y", nullptr));
        x_label_1_1->setText(QCoreApplication::translate("Widget", "x", nullptr));
        color_label_1_1->setText(QCoreApplication::translate("Widget", "color", nullptr));
        line_groupBox_1_2->setTitle(QCoreApplication::translate("Widget", "Line 2", nullptr));
        color_comboBox_1_2->setItemText(0, QCoreApplication::translate("Widget", "blue", nullptr));
        color_comboBox_1_2->setItemText(1, QCoreApplication::translate("Widget", "red", nullptr));
        color_comboBox_1_2->setItemText(2, QCoreApplication::translate("Widget", "black", nullptr));
        color_comboBox_1_2->setItemText(3, QCoreApplication::translate("Widget", "green", nullptr));
        color_comboBox_1_2->setItemText(4, QCoreApplication::translate("Widget", "orange", nullptr));
        color_comboBox_1_2->setItemText(5, QCoreApplication::translate("Widget", "yellow", nullptr));

        y_label_1_2->setText(QCoreApplication::translate("Widget", "y", nullptr));
        x_label_1_2->setText(QCoreApplication::translate("Widget", "x", nullptr));
        color_label_1_2->setText(QCoreApplication::translate("Widget", "color", nullptr));
        line_groupBox_1_3->setTitle(QCoreApplication::translate("Widget", "Line 3", nullptr));
        color_comboBox_1_3->setItemText(0, QCoreApplication::translate("Widget", "blue", nullptr));
        color_comboBox_1_3->setItemText(1, QCoreApplication::translate("Widget", "red", nullptr));
        color_comboBox_1_3->setItemText(2, QCoreApplication::translate("Widget", "black", nullptr));
        color_comboBox_1_3->setItemText(3, QCoreApplication::translate("Widget", "green", nullptr));
        color_comboBox_1_3->setItemText(4, QCoreApplication::translate("Widget", "orange", nullptr));
        color_comboBox_1_3->setItemText(5, QCoreApplication::translate("Widget", "yellow", nullptr));

        y_label_1_3->setText(QCoreApplication::translate("Widget", "y", nullptr));
        x_label_1_3->setText(QCoreApplication::translate("Widget", "x", nullptr));
        color_label_1_3->setText(QCoreApplication::translate("Widget", "color", nullptr));
        Subplot_groupBox_2->setTitle(QCoreApplication::translate("Widget", "Subplot 2", nullptr));
        line_groupBox_2_1->setTitle(QCoreApplication::translate("Widget", "Line 1", nullptr));
        color_comboBox_2_1->setItemText(0, QCoreApplication::translate("Widget", "blue", nullptr));
        color_comboBox_2_1->setItemText(1, QCoreApplication::translate("Widget", "red", nullptr));
        color_comboBox_2_1->setItemText(2, QCoreApplication::translate("Widget", "black", nullptr));
        color_comboBox_2_1->setItemText(3, QCoreApplication::translate("Widget", "green", nullptr));
        color_comboBox_2_1->setItemText(4, QCoreApplication::translate("Widget", "orange", nullptr));
        color_comboBox_2_1->setItemText(5, QCoreApplication::translate("Widget", "yellow", nullptr));

        y_label_2_1->setText(QCoreApplication::translate("Widget", "y", nullptr));
        x_label_2_1->setText(QCoreApplication::translate("Widget", "x", nullptr));
        color_label_2_1->setText(QCoreApplication::translate("Widget", "color", nullptr));
        line_groupBox_2_2->setTitle(QCoreApplication::translate("Widget", "Line 2", nullptr));
        color_comboBox_2_2->setItemText(0, QCoreApplication::translate("Widget", "blue", nullptr));
        color_comboBox_2_2->setItemText(1, QCoreApplication::translate("Widget", "red", nullptr));
        color_comboBox_2_2->setItemText(2, QCoreApplication::translate("Widget", "black", nullptr));
        color_comboBox_2_2->setItemText(3, QCoreApplication::translate("Widget", "green", nullptr));
        color_comboBox_2_2->setItemText(4, QCoreApplication::translate("Widget", "orange", nullptr));
        color_comboBox_2_2->setItemText(5, QCoreApplication::translate("Widget", "yellow", nullptr));

        y_label_2_2->setText(QCoreApplication::translate("Widget", "y", nullptr));
        x_label_2_2->setText(QCoreApplication::translate("Widget", "x", nullptr));
        color_label_2_2->setText(QCoreApplication::translate("Widget", "color", nullptr));
        line_groupBox_2_3->setTitle(QCoreApplication::translate("Widget", "Line 3", nullptr));
        color_comboBox_2_3->setItemText(0, QCoreApplication::translate("Widget", "blue", nullptr));
        color_comboBox_2_3->setItemText(1, QCoreApplication::translate("Widget", "red", nullptr));
        color_comboBox_2_3->setItemText(2, QCoreApplication::translate("Widget", "black", nullptr));
        color_comboBox_2_3->setItemText(3, QCoreApplication::translate("Widget", "green", nullptr));
        color_comboBox_2_3->setItemText(4, QCoreApplication::translate("Widget", "orange", nullptr));
        color_comboBox_2_3->setItemText(5, QCoreApplication::translate("Widget", "yellow", nullptr));

        y_label_2_3->setText(QCoreApplication::translate("Widget", "y", nullptr));
        x_label_2_3->setText(QCoreApplication::translate("Widget", "x", nullptr));
        color_label_2_3->setText(QCoreApplication::translate("Widget", "color", nullptr));
        Subplot_groupBox_3->setTitle(QCoreApplication::translate("Widget", "Subplot 3", nullptr));
        line_groupBox_3_1->setTitle(QCoreApplication::translate("Widget", "Line 1", nullptr));
        color_comboBox_3_1->setItemText(0, QCoreApplication::translate("Widget", "blue", nullptr));
        color_comboBox_3_1->setItemText(1, QCoreApplication::translate("Widget", "red", nullptr));
        color_comboBox_3_1->setItemText(2, QCoreApplication::translate("Widget", "black", nullptr));
        color_comboBox_3_1->setItemText(3, QCoreApplication::translate("Widget", "green", nullptr));
        color_comboBox_3_1->setItemText(4, QCoreApplication::translate("Widget", "orange", nullptr));
        color_comboBox_3_1->setItemText(5, QCoreApplication::translate("Widget", "yellow", nullptr));

        y_label_3_1->setText(QCoreApplication::translate("Widget", "y", nullptr));
        x_label_3_1->setText(QCoreApplication::translate("Widget", "x", nullptr));
        color_label_3_1->setText(QCoreApplication::translate("Widget", "color", nullptr));
        line_groupBox_3_2->setTitle(QCoreApplication::translate("Widget", "Line 2", nullptr));
        color_comboBox_3_2->setItemText(0, QCoreApplication::translate("Widget", "blue", nullptr));
        color_comboBox_3_2->setItemText(1, QCoreApplication::translate("Widget", "red", nullptr));
        color_comboBox_3_2->setItemText(2, QCoreApplication::translate("Widget", "black", nullptr));
        color_comboBox_3_2->setItemText(3, QCoreApplication::translate("Widget", "green", nullptr));
        color_comboBox_3_2->setItemText(4, QCoreApplication::translate("Widget", "orange", nullptr));
        color_comboBox_3_2->setItemText(5, QCoreApplication::translate("Widget", "yellow", nullptr));

        y_label_3_2->setText(QCoreApplication::translate("Widget", "y", nullptr));
        x_label_3_2->setText(QCoreApplication::translate("Widget", "x", nullptr));
        color_label_3_2->setText(QCoreApplication::translate("Widget", "color", nullptr));
        line_groupBox_3_3->setTitle(QCoreApplication::translate("Widget", "Line 3", nullptr));
        color_comboBox_3_3->setItemText(0, QCoreApplication::translate("Widget", "blue", nullptr));
        color_comboBox_3_3->setItemText(1, QCoreApplication::translate("Widget", "red", nullptr));
        color_comboBox_3_3->setItemText(2, QCoreApplication::translate("Widget", "black", nullptr));
        color_comboBox_3_3->setItemText(3, QCoreApplication::translate("Widget", "green", nullptr));
        color_comboBox_3_3->setItemText(4, QCoreApplication::translate("Widget", "orange", nullptr));
        color_comboBox_3_3->setItemText(5, QCoreApplication::translate("Widget", "yellow", nullptr));

        y_label_3_3->setText(QCoreApplication::translate("Widget", "y", nullptr));
        x_label_3_3->setText(QCoreApplication::translate("Widget", "x", nullptr));
        color_label_3_3->setText(QCoreApplication::translate("Widget", "color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
