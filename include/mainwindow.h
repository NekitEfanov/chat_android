#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QArrayData>
#include <QTextStream>
#include <QString>
#include <memory>

#include "input_window.h"
#include "chat.h"
#include "client_server.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString data;
    QString nameclient;

private slots:
    void authorizeUser();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<input_window> ui_Input;
    std::shared_ptr<chat> ui_Chat;
};

#endif // MAINWINDOW_H
