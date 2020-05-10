#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "load.h"
#include "QDebug"
#include "iostream"
#include "QString"
#include "qmessagebox.h"
#include "qpushbutton.h"
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
     QString num = this->ui->l_num->text();
     QString psw = this->ui->l_psw->text();
    if ((num=="170300504")&&(psw=="1234")){
        Load L;
        this->close();
        L.exec();
    }
	else {
		QMessageBox::critical(this, "Information","The password is incorrect!","OK","Cancel");
	}

}
