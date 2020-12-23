#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include <iostream>
#include <cmath>

#define PI 3.141592653589793238

using namespace std;
static QImage img(700, 700, QImage::Format_RGB888);

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

void MainWindow::drawDDALine(int x1, int y1, int x2, int y2) {
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

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::Koch(int x1, int y1, int x2, int y2, int it) {
    float angle = 60 * PI / 180;
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;

    int x4 = (x1 + 2 * x2) / 3;
    int y4 = (y1 + 2 * y2) / 3;

    int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
    int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

    int xNext1[] = {x1, x3, x, x4};
    int yNext1[] = {y1, y3, y, y4};
    int xNext2[] = {x3, x, x4, x2};
    int yNext2[] = {y3, y, y4, y2};

    if (it > 0) {
        for (int i = 0; i < 4; i++)
            Koch(xNext1[i], yNext1[i], xNext2[i], yNext2[i], it-1);
    }
    else {
        for (int i = 0; i < 4; i++)
            drawDDALine(xNext1[i], yNext1[i], xNext2[i], yNext2[i]);
    }
}

void MainWindow::on_pushButton_clicked() {
    int r = 250;
    int x = 350, y = 350;

    int n, iterations;
    n = ui->textEdit->toPlainText().toInt();
    iterations = ui->textEdit_2->toPlainText().toInt();

    int arrX[n];
    int arrY[n];
    for (int i = 0; i < n; i++) {
      arrX[i] = x + r * cos(2 * PI * i / n);
      arrY[i] = y + r * sin(2 * PI * i / n);
      if (i > 0)
          Koch(arrX[i-1], arrY[i-1], arrX[i], arrY[i], iterations);
    }
    Koch(arrX[n-1], arrY[n-1], arrX[0], arrY[0], iterations);
}
