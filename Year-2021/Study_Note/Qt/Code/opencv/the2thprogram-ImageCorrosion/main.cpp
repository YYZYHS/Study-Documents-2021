#include "mainwindow.h"

#include <QApplication>

#include <opencv2/highgui/highgui.hpp>      //OpenCV highgui模块头文件
#include <opencv2/imgproc/imgproc.hpp>      //OpenCV 图像处理模块头文件

using namespace cv;                         //包含cv命名空间

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //【1】载入原图
    Mat srcImage = imread("E:\\StudyDocuments\\Study-Documents-2021\\Year-2021\\Study_Note\\Qt\\Code\\opencv\\test.jpeg");
    //【2】显示原图
    imshow("original image",srcImage);
    //【3】进行腐蚀操作
    Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
    Mat dstImage;
    erode(srcImage,dstImage,element);
    //【4】显示效果图
    imshow("Effect picture",dstImage);
    waitKey(0);

    return 0;
}
