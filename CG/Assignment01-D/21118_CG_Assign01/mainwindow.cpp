#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include"QTime"
using namespace std;
static QImage img(500,500,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver =0;
    start=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if (start){
        int p= event->pos().x();
        int q=event->pos().y();
        a[ver]=p;
        b[ver]=q;
        if (event->button()==Qt::RightButton ){
            DDA(a[ver-1],b[ver-1],a[0],b[0]);
            start=false;
        }
        else{
            if (ver>0){
                DDA(a[ver-1],b[ver-1],a[ver],b[ver]);
            }
        }
        ver++;
    }
}

void MainWindow::Delay(int millisecondsToWait)
{
    QTime dieTime= QTime::currentTime().addMSecs(millisecondsToWait );
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::DDA(int x1,int y1,int x2,int y2){
    float x,y,dx,dy,step,xin,yin;
    dx=x2-x1;
    dy=y2-y1;
    if (abs(dx)>=abs(dy)){
        step=abs(dx);
    }else{
        step=abs(dy);
    }
    xin=dx/step;
    yin=dy/step;
    x=x1;
    y=y1;
    float i=0;
    while(i<=step){
        img.setPixel(x,y,qRgb(0,255,0));
        x=x+xin;
        y=y+yin;
        i+=1;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_clicked()
{
    a[ver]=a[0];
        b[ver]=b[0];
        for(int i=0;i<ver;i++)
        {
            dx=a[i+1]-a[i];
            dy=b[i+1]-b[i];
            if(dx==0.0f) slope[i]=0.0;
            if(dy==0.0f) slope[i]=1.0;
            if((dy!=0.0f)&&(dx!=0.0f))
            {
                slope[i]=dx/dy;
            }
        }
            for (int y=0;y<600;y++)
            {
                k=0;
                for(int i=0;i<ver;i++)
                {
                    if(((b[i]<=y)&&(b[i+1]>y))||((b[i]>y)&&(b[i+1]<=y)))
                    {
                        xi[k]=int(a[i]+(slope[i]*(y-b[i])));
                        k++;
                    }
                }
                for(j=0;j<k-1;j++)
                for(i=0;i<k-j-1;i++)
                {
                    if(xi[i]>xi[i+1])
                    {
                        temp=xi[i];
                        xi[i]=xi[i+1];
                        xi[i+1]=temp;
                    }
                }
                for (int i=0;i<k;i+=2)
                {
                    Delay(10);

                    DDA(xi[i],y,xi[i+1]+1,y);

                }

         }

}
