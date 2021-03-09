#ifndef input_WINDOW_H
#define input_WINDOW_H

#include <QWidget>
#include <QString>
#include <QMessageBox>

namespace Ui {
class input_window;
}

class input_window : public QWidget
{
    Q_OBJECT

public:
    explicit input_window(QWidget *parent = nullptr);
    ~input_window();
    QString Name_client = "";
    QString getName();

signals:
    void input_signal();


private slots:

    void on_input_clicked();

private:
    Ui::input_window *ui;
};

#endif // input_WINDOW_H
