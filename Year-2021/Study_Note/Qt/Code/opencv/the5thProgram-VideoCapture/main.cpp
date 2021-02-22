#include "mainwindow.h"
#include <QApplication>
#include <opencv2/opencv.hpp>
#include <QDebug>
using namespace cv;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //【1】从摄像头读入视频
    VideoCapture capture(0);//此处用0来代表调用摄像头,用绝对路径来指代需要读取的视频
    if (!capture.isOpened())
    {
        qDebug()<< "can't open video";
        return -1;
    }
    Mat edges;

    //【2】循环显示每一帧
    while (1)
    {
        //定义一个Mat变量，用于存储每一帧图像
        Mat frame;
        //读取当前帧
        capture>>frame;
        //将原图像转换为灰度图像
        cvtColor(frame,edges,COLOR_BGR2GRAY);
        //使用3x3内核来降噪(2x3+1=7)
        blur(edges,edges,Size(7,7));
        //进行canny边缘检测
        Canny(edges,edges,0,30,3);
        //显示当前帧
        imshow("Effect video",edges);
        //延时30ms
        if(waitKey(30) >=0) break;
    }
    return 0;

}
