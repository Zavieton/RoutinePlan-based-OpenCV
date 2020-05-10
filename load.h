#ifndef LOAD_H
#define LOAD_H

#include <QDialog>
namespace Ui {
class Load;
}

class Load : public QDialog
{
    Q_OBJECT

public:
    explicit Load(QWidget *parent = 0);
    ~Load();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

	void on_Mapshow_clicked();

	void on_Routeclc_clicked();


private:
    Ui::Load *ui;
};






#endif // LOAD_H
