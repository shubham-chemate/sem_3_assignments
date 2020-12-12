#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bits/stdc++.h"
QImage img(600, 600, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int a;
    a = ui->textEdit->toPlainText().toInt();

    int left_btm_x = 50, left_btm_y = 400;
    // co-ordinates of equilateral triangle
    DDALine(left_btm_x, left_btm_y, left_btm_x + a, left_btm_y);
    DDALine(left_btm_x, left_btm_y, left_btm_x + (a / 2), left_btm_y - (a * sqrt(3) / 2));
    DDALine(left_btm_x + a, left_btm_y, left_btm_x + (a / 2), left_btm_y - (a * sqrt(3) / 2));

    int centreX = left_btm_x + (a / 2), centreY = left_btm_y - (a / (2 * sqrt(3)));
    // incircle
    int r = a * sqrt(3) / 6;
    BresenhamCircle(centreX, centreY, r);

    // circum circle
    int R = a / sqrt(3);
    BresenhamCircle(centreX, centreY, R);

    ui->label_5->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::DDALine(int x1, int y1, int x2, int y2) {
    float x_inc, y_inc;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    x_inc = dx / ((float)steps);
    y_inc = dy / ((float)steps);

    float x = x1, y = y1;

    for (int i = 0; i < steps+1; i++) {
        img.setPixel(x, y, qRgb(0, 255, 0));
        x += x_inc;
        y += y_inc;
    }
}

void drawCircle(int xc, int yc, int x, int y)
{
    img.setPixel(xc+x, yc+y, qRgb(0, 0, 255));
    img.setPixel(xc-x, yc+y, qRgb(0, 0, 255));
    img.setPixel(xc+x, yc-y, qRgb(0, 0, 255));
    img.setPixel(xc-x, yc-y, qRgb(0, 0, 255));
    img.setPixel(xc+y, yc+x, qRgb(0, 0, 255));
    img.setPixel(xc-y, yc+x, qRgb(0, 0, 255));
    img.setPixel(xc+y, yc-x, qRgb(0, 0, 255));
    img.setPixel(xc-y, yc-x, qRgb(0, 0, 255));
}

void MainWindow::BresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int pk = 3 - 2 * r;
    drawCircle(xc, yc, x, y);
    while (x <= y) {
        x++;
        if (pk > 0) {
            y--;
            pk = pk + 4 * (x - y) + 10;
        }
        else
            pk = pk + 4 * x + 6;
        drawCircle(xc, yc, x, y);
    }
}
