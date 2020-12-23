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
    void mousePressEvent(QMouseEvent *event);
    void DDA(int , int , int , int);
    void Delay(int );

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int ver, a[20],b[20],i,xi[20],j,temp,k;
    float dx,dy,slope[20];
    bool start;
};
#endif // MAINWINDOW_H
