#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include"global.h"
#include <QDialog>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();
    void InitUI();

private:
    void showTip(QString str);
private slots:
    void on_pushButton_clicked();

private:
    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
