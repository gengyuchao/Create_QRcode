#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QImage"

#include <string>
#include <vector>
#include "QrCode.hpp"
using namespace qrcodegen;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->textEdit->append(QString::number(qr1.getModule(x, y)));
    Show_QRcode_Picture();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Show_QRcode_Picture(QString message)
{

    // Manual operation
    std::vector<QrSegment> segs =
        QrSegment::makeSegments(message.toUtf8());
    QrCode qr1 = QrCode::encodeSegments(
        segs, QrCode::Ecc::HIGH, 5, 10, 2, false);
    //创建二维码画布
    QImage QrCode_Image=QImage(qr1.getSize(),qr1.getSize(),QImage::Format_RGB888);

    for (int y = 0; y < qr1.getSize(); y++) {
        for (int x = 0; x < qr1.getSize(); x++) {
            if(qr1.getModule(x, y)==0)
                QrCode_Image.setPixel(x,y,qRgb(255,255,255));
            else
                QrCode_Image.setPixel(x,y,qRgb(0,0,0));
        }
    }

    //图像大小转换为适当的大小
    QrCode_Image=QrCode_Image.scaled(ui->label->width(),ui->label->height(),
                    Qt::KeepAspectRatio);
    //转换为QPixmap在Label中显示
    ui->label->setPixmap(QPixmap::fromImage(QrCode_Image));

}

void MainWindow::on_Create_Button_clicked()
{
    Show_QRcode_Picture(ui->textEdit->toPlainText());
}
