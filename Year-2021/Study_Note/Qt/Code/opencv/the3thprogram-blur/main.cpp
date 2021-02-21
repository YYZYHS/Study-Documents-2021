#include "mainwindow.h"

#include <QApplication>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //【1】载入原始图
    Mat srcImage = imread("E:\\StudyDocuments\\Study-Documents-2021\\Year-2021\\Study_Note\\Qt\\Code\\opencv\\test.jpeg");
    //【2】显示原始图
    imshow("original image",srcImage);
    //【3】进行均值滤波操作
    Mat dstImage;
    blur(srcImage,dstImage,Size(7,7));
    //【4】显示效果图
    imshow("Effect picture",dstImage);
    waitKey(0);
    return 0;
}
