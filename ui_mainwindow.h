/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_5;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_7;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *l_num;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *l_psw;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 750);
        MainWindow->setMinimumSize(QSize(1000, 750));
        MainWindow->setMaximumSize(QSize(1000, 750));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(5, -10, 991, 439));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(43);
        label->setFont(font);
        label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_2->addWidget(label);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(43);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_4->setFont(font1);
        label_4->setFocusPolicy(Qt::TabFocus);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 600, 981, 54));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(120, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("Bradley Hand ITC"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton->setFont(font2);

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(120, 50));
        pushButton_2->setFont(font2);

        horizontalLayout_3->addWidget(pushButton_2);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 8);
        horizontalLayout_5->setStretch(2, 1);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 460, 981, 111));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font3.setPointSize(18);
        label_2->setFont(font3);

        horizontalLayout->addWidget(label_2);

        l_num = new QLineEdit(layoutWidget2);
        l_num->setObjectName(QStringLiteral("l_num"));
        l_num->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(l_num);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font3);

        horizontalLayout_2->addWidget(label_3);

        l_psw = new QLineEdit(layoutWidget2);
        l_psw->setObjectName(QStringLiteral("l_psw"));
        l_psw->setMinimumSize(QSize(0, 30));
        l_psw->setContextMenuPolicy(Qt::DefaultContextMenu);
        l_psw->setEchoMode(QLineEdit::Password);
        l_psw->setCursorMoveStyle(Qt::LogicalMoveStyle);

        horizontalLayout_2->addWidget(l_psw);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 4);

        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\223\210\345\260\224\346\273\250\345\267\245\344\270\232\345\244\247\345\255\246", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\240\241\345\233\255\350\267\257\345\276\204\350\247\204\345\210\222\347\263\273\347\273\237", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "LOGIN", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "QUIT", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\255\246\345\217\267\357\274\232", Q_NULLPTR));
        l_num->setText(QString());
        l_num->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267 \350\276\223 \345\205\245 \345\255\246 \345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        l_psw->setPlaceholderText(QApplication::translate("MainWindow", "\350\257\267 \350\276\223 \345\205\245 \345\257\206 \347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
