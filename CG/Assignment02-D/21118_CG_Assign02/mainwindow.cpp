#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include <iostream>
#include "QTime"
#include <bits/stdc++.h>

using namespace std;
static QImage img(500, 500, QImage::Format_RGB888);

#define INS 0 // 0000
#define TOP 8 // 1000
#define BOTTOM 4 // 0100
#define RIGHT 2 // 0010
#define LEFT 1 // 0001

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    var = 0;
    start = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

// function to draw window
void MainWindow::drawWindow() {
    drawDDALine(xmn, ymn, xmn, ymx, 255, 255, 255);
    drawDDALine(xmn, ymx, xmx, ymx, 255, 255, 255);
    drawDDALine(xmx, ymx, xmx, ymn, 255, 255, 255);
    drawDDALine(xmn, ymn, xmx, ymn, 255, 255, 255);
}

// clearing main window
void MainWindow::clearMainWindow()
{
    for (int i = 0; i < 500; i++) {
        drawDDALine(0, i, 499, i, 0, 0, 0);
    }
}

// function to draw line by dda line drawing algorithm
void MainWindow::drawDDALine(int x1, int y1, int x2, int y2, int r = 0, int g = 255, int b = 0) {
    float x_inc, y_inc;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    x_inc = dx / ((float)steps);
    y_inc = dy / ((float)steps);

    float x = x1, y = y1;

    for (int i = 0; i < steps+1; i++) {
        img.setPixel(x, y, qRgb(r, g, b));
        x += x_inc;
        y += y_inc;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_window_clicked()
{
    xmn = ui->textEdit_xmn->toPlainText().toInt();
    ymn = ui->textEdit_ymn->toPlainText().toInt();
    xmx = ui->textEdit_xmx->toPlainText().toInt();
    ymx = ui->textEdit_ymx->toPlainText().toInt();

    drawWindow();
}

// function to take polygon as input by mouse click events
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

// function will return the code of input co-ordinates region
int MainWindow::getCode(int x, int y) {
    int code = INS;

    if (x < xmn) code |= LEFT;
    else if (x > xmx) code |= RIGHT;

    if (y < ymn) code |= BOTTOM;
    else if (y > ymx) code |= TOP;

    return code;
}

// function will clip the line whose endpoints are given as input
void MainWindow::clipLine(int x1, int y1, int x2, int y2) {
    int code1 = getCode(x1, y1);
    int code2 = getCode(x2, y2);

    bool isInside = false;
    while (true) {

        if (!code1 && !code2) { // both inside
            isInside = true;
            break;
        }
        else if ((code1 & code2) != 0) { // both outside
            break;
        }

        int out_pt_code = code1 ? code1 : code2;
        double x, y;

        if (out_pt_code & TOP) {
            x = x1 + (x2 - x1) * (ymx - y1) / (y2 - y1);
            y = ymx;
        }
        else if (out_pt_code & BOTTOM) {
            x = x1 + (x2 - x1) * (ymn - y1) / (y2 - y1);
            y = ymn;
        }
        else if (out_pt_code & RIGHT) {
            y = y1 + (y2 - y1) * (xmx - x1) / (x2 - x1);
            x = xmx;
        }
        else if (out_pt_code & LEFT) {
            y = y1 + (y2 - y1) * (xmn - x1) / (x2 - x1);
            x = xmn;
        }

        if (out_pt_code == code1) {
            drawDDALine(x1, y1, x, y, 0, 0, 0);
            x1 = x;
            y1 = y;
            code1 = getCode(x1, y1);
        }
        else {
            drawDDALine(x2, y2, x, y, 0, 0, 0);
            x2 = x;
            y2 = y;
            code2 = getCode(x2, y2);
        }
    }

    if (isInside) drawDDALine(x1, y1, x2, y2);
}

// clipping the polygon
void MainWindow::on_pushButton_line_clip_clicked()
{
    clearMainWindow();
    drawWindow();
    for (int i = 1; i < var; i++) {
        clipLine(x[i], y[i], x[i-1], y[i-1]);
    }
    clipLine(x[0], y[0], x[var - 1], y[var-1]);
}
