#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->psswordline->setEchoMode(QLineEdit::Password);


}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_registerpushbutton_clicked()
{
    emit switchRegister();
}
