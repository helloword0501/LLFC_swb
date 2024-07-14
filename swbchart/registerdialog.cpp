#include "registerdialog.h"
#include "ui_registerdialog.h"
#include<QLineEdit>
#include <QRegularExpression>
RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    InitUI();

}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::InitUI()
{
    ui->passwordline->setEchoMode(QLineEdit::Password);
    ui->affirmline->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);
}

void RegisterDialog::showTip(QString str)
{
    ui->err_tip->setText(str);
     ui->err_tip->setProperty("state","err");
     repolish(ui->err_tip);
}

void RegisterDialog::on_pushButton_clicked()
{
    //验证邮箱的地址正则表达式
       auto email = ui->emailline->text();
       // 邮箱地址的正则表达式
       QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
       bool match = regex.match(email).hasMatch(); // 执行正则表达式匹配
       if(match){
           //发送http请求获取验证码
       }else{
           //提示邮箱不正确
           showTip(tr("邮箱地址不正确"));
       }
}
