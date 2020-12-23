#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void drawDDALine(int , int , int , int);
    void mousePressEvent(QMouseEvent *ev);
    void Translate(int[], int[], int, int);
    void Scale(int[], int[], double, double);
    void Rotate(int[], int[], int);

private slots:
    void on_translateBtn_clicked();

    void on_scaleBtn_clicked();

    void on_rotateBtn_clicked();

private:
    Ui::MainWindow *ui;
    bool start;
    int x[20], y[20];
    int var;
};
#endif // MAINWINDOW_H
