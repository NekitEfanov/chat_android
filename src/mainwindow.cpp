#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdexcept>

using namespace std;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Chat");

    ui_Chat.reset(new chat());
    ui_Input.reset(new input_window());

    connect(ui_Input.get(),
            SIGNAL(input_signal()),
            this,
            SLOT(authorizeUser())
    );

    ui->gridLayout->replaceWidget(ui->widget, ui_Input.get());
    ui_Input->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::authorizeUser()
{
   nameclient = ui_Input->getName();

   if(nameclient.size() > 2 && nameclient.size() < 13) {
        try {
            ui_Chat->tryToConnect(nameclient);
        }  catch (const exception &e) {
            return;
        }

        ui_Input->hide();
        ui->gridLayout->replaceWidget(ui_Input.get(), ui_Chat.get());
        ui_Chat->show();
    }

   else
       QMessageBox::critical(this, "Error", "Number of characters 3-12");
}
