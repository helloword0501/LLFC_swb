#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_loginDialog(nullptr)
    ,m_resister(nullptr)
{
    ui->setupUi(this);
    InitUI();
    InitConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitUI()
{
    m_loginDialog = new LoginDialog();
    m_resister = new RegisterDialog();
    setCentralWidget(m_loginDialog);
    m_resister->hide();
}

void MainWindow::InitConnect()
{
    connect(m_loginDialog,&LoginDialog::switchRegister,this,&MainWindow::slotsChargeDialog);
}

void MainWindow::slotsChargeDialog()
{
    qDebug()<<"this";
    setCentralWidget(m_resister);
        m_loginDialog->hide();
        m_resister->show();
}

