#include "input_window.h"
#include "ui_input_window.h"

input_window::input_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::input_window)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("background-color: white;");
    ui->label_2->setStyleSheet("background-color: white;");
}

input_window::~input_window()
{
    delete ui;
}


QString input_window::getName()
{
    Name_client = ui->line_name->text();
    return input_window::Name_client;
}

void input_window::on_input_clicked()
{
    emit input_signal();
}
