#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Show_QRcode_Picture(QString message="Hello World");

private slots:
    void on_Create_Button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
