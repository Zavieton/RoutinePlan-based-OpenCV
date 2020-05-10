/********************************************************************************
** Form generated from reading UI file 'load.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOAD_H
#define UI_LOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Load
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *Line_RouteLength;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Mapshow;
    QPushButton *Routeclc;

    void setupUi(QDialog *Load)
    {
        if (Load->objectName().isEmpty())
            Load->setObjectName(QStringLiteral("Load"));
        Load->resize(1050, 700);
        Load->setMinimumSize(QSize(1050, 700));
        Load->setMaximumSize(QSize(1050, 700));
        pushButton = new QPushButton(Load);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 640, 141, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(18);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        pushButton->setFont(font);
        layoutWidget = new QWidget(Load);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(800, 70, 206, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout->addWidget(comboBox_2);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        Line_RouteLength = new QLineEdit(layoutWidget);
        Line_RouteLength->setObjectName(QStringLiteral("Line_RouteLength"));

        horizontalLayout_3->addWidget(Line_RouteLength);

        horizontalLayout_3->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        pushButton_2 = new QPushButton(Load);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(880, 640, 81, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_2->setFont(font3);
        label_3 = new QLabel(Load);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 10, 500, 600));
        label_3->setFont(font1);
        widget = new QWidget(Load);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(910, 430, 95, 151));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Mapshow = new QPushButton(widget);
        Mapshow->setObjectName(QStringLiteral("Mapshow"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        Mapshow->setFont(font4);

        verticalLayout_2->addWidget(Mapshow);

        Routeclc = new QPushButton(widget);
        Routeclc->setObjectName(QStringLiteral("Routeclc"));
        Routeclc->setFont(font4);

        verticalLayout_2->addWidget(Routeclc);


        retranslateUi(Load);

        QMetaObject::connectSlotsByName(Load);
    } // setupUi

    void retranslateUi(QDialog *Load)
    {
        Load->setWindowTitle(QApplication::translate("Load", "Route", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Load", "\347\224\237\346\210\220\350\267\257\345\276\204", Q_NULLPTR));
        label->setText(QApplication::translate("Load", "\350\265\267\345\247\213\347\202\271\344\275\215\347\275\256:", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Load", "1", Q_NULLPTR)
         << QApplication::translate("Load", "2", Q_NULLPTR)
         << QApplication::translate("Load", "3", Q_NULLPTR)
         << QApplication::translate("Load", "4", Q_NULLPTR)
         << QApplication::translate("Load", "5", Q_NULLPTR)
         << QApplication::translate("Load", "6", Q_NULLPTR)
         << QApplication::translate("Load", "7", Q_NULLPTR)
         << QApplication::translate("Load", "8", Q_NULLPTR)
         << QApplication::translate("Load", "9", Q_NULLPTR)
         << QApplication::translate("Load", "10", Q_NULLPTR)
         << QApplication::translate("Load", "11", Q_NULLPTR)
         << QApplication::translate("Load", "12", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Load", "\345\210\260\350\276\276\347\202\271\344\275\215\347\275\256:", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Load", "1", Q_NULLPTR)
         << QApplication::translate("Load", "2", Q_NULLPTR)
         << QApplication::translate("Load", "3", Q_NULLPTR)
         << QApplication::translate("Load", "4", Q_NULLPTR)
         << QApplication::translate("Load", "5", Q_NULLPTR)
         << QApplication::translate("Load", "6", Q_NULLPTR)
         << QApplication::translate("Load", "7", Q_NULLPTR)
         << QApplication::translate("Load", "8", Q_NULLPTR)
         << QApplication::translate("Load", "9", Q_NULLPTR)
         << QApplication::translate("Load", "10", Q_NULLPTR)
         << QApplication::translate("Load", "11", Q_NULLPTR)
         << QApplication::translate("Load", "12", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Load", "\350\267\257\345\276\204\351\225\277\345\272\246", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Load", "\351\200\200\345\207\272", Q_NULLPTR));
        label_3->setText(QString());
        Mapshow->setText(QApplication::translate("Load", "\347\224\237\346\210\220\345\234\260\345\233\276", Q_NULLPTR));
        Routeclc->setText(QApplication::translate("Load", "\346\270\205\351\231\244\350\267\257\345\276\204", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Load: public Ui_Load {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOAD_H
