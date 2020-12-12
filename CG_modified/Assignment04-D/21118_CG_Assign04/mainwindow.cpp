#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include <iostream>
#include "QTime"
#include <bits/stdc++.h>
#define PI 3.141592653589793238

using namespace std;
static QImage img(600, 600, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    var = 0;
    drawDDALine(300, 0, 300, 599);
    drawDDALine(0, 300, 599, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// function to draw line by dda line drawing algorithm
void MainWindow::drawDDALine(int x1, int y1, int x2, int y2) {
    float x_inc, y_inc;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    x_inc = dx / ((float)steps);
    y_inc = dy / ((float)steps);

    float x = x1, y = y1;

    for (int i = 0; i < steps+1; i++) {
        img.setPixel(x, y, qRgb(255, 255, 255));
        x += x_inc;
        y += y_inc;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

// taking 2d shape as input from mainwindow
void MainWindow::mousePressEvent(QMouseEvent *ev) {

    if (start) {
        int p = ev->pos().x();
        int q = ev->pos().y();
        x[var] = p;
        y[var] = q;

        if (ev->button() == Qt::RightButton) {
            drawDDALine(x[var-1], y[var-1], x[0], y[0]);
            start = false;
        }
        else {
            if (var > 0) {
                drawDDALine(x[var], y[var], x[var-1], y[var-1]);
            }
        }
        var++;
    }
}

// translate the polygon
void MainWindow::Translate(int X[20], int Y[20], int tx, int ty) {
    int tX[var], tY[var];
    for (int i = 0; i < var; i++) {
        tX[i] = X[i] + tx;
        tY[i] = Y[i] + ty;
    }
    for (int i = 0; i < var; i++) {
        if (i == 0) drawDDALine(tX[0], tY[0], tX[var-1], tY[var-1]);
        else drawDDALine(tX[i], tY[i], tX[i-1], tY[i-1]);
    }
}

// scale the polygon
void MainWindow::Scale(int X[20], int Y[20], double sx, double sy) {
    int sX[var], sY[var];
    for (int i = 0; i < var; i++) {
        sX[i] = X[i] - 300;
        sY[i] = Y[i] - 300;
    }
    for (int i = 0; i < var; i++) {
        sX[i] = sX[i]*sx;
        sY[i] = sY[i]*sy;
    }
    Translate(sX, sY, 300, 300);
}

// rotate the polygon
void MainWindow::Rotate(int X[20], int Y[20], int angle) {
    double angleInRad = angle * (PI / 180.0);
    int rX[var], rY[var];
    for (int i = 0; i < var; i++) {
        rX[i] = X[i] - 300;
        rY[i] = Y[i] - 300;
    }

    for (int i = 0; i < var; i++) {
        int tempX = rX[i], tempY = rY[i];
        rX[i] = (tempX*cos(angleInRad)) - (tempY*sin(angleInRad));
        rY[i] = (tempX*sin(angleInRad)) + (tempY*cos(angleInRad));
    }

    Translate(rX, rY, 300, 300);
}

void MainWindow::on_translateBtn_clicked()
{
    var--;
    int tx = ui->textEdit_tx->toPlainText().toInt();
    int ty = ui->textEdit_ty->toPlainText().toInt();

    Translate(x, y, tx, ty);
    var++;
}

void MainWindow::on_scaleBtn_clicked()
{
    var--;
    double sx = ui->textEdit_sx->toPlainText().toDouble();
    double sy = ui->textEdit_sy->toPlainText().toDouble();
    Scale(x, y, sx, sy);
    var++;
}

void MainWindow::on_rotateBtn_clicked()
{
    var--;
    int angle = ui->textEdit_angle->toPlainText().toInt();

    Rotate(x, y, angle);
    var++;
}
