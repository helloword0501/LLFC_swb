#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"logindialog.h"
#include"registerdialog.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitUI();
    void InitConnect();

private:

private slots:
   void slotsChargeDialog();
private:
    Ui::MainWindow *ui;
    LoginDialog* m_loginDialog;
    RegisterDialog *m_resister;
};
#endif // MAINWINDOW_H
