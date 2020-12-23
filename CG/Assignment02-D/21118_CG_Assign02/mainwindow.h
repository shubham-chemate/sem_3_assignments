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
    void drawDDALine(int , int , int , int , int, int, int);
    void mousePressEvent(QMouseEvent *ev);
    int getCode(int, int);
    void clipLine(int, int, int, int);
    void drawWindow();
    void clearMainWindow();

private slots:

    void on_pushButton_window_clicked();
    void on_pushButton_line_clip_clicked();

private:
    Ui::MainWindow *ui;
    int x[20], y[20], var;
    bool start;
    int xmn, ymn, xmx, ymx;
};
#endif // MAINWINDOW_H
