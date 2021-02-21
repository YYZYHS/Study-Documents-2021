#include "mainwindow.h"

#include <QApplication>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //【0】载入原始图
    Mat srcImage = imread("E:\\StudyDocuments\\Study-Documents-2021\\Year-2021\\Study_Note\\Qt\\Code\\opencv\\test.jpeg");
    imshow("original image",srcImage);//显示原始图
    Mat dstImage,edge,grayImage;//定义参数
    //【1】创建与src同类型和大小的矩阵(dst)
    dstImage.create(srcImage.size(),srcImage.type());
    //【2】将原图像转换为灰度图像
    //此句代码的OpenCV2版为：
    //cvtColor(srcImage,grayImage,CV_BGR2GRAY);
    //此句代码的OpenCV3版为：
    cvtColor(srcImage,grayImage,COLOR_BGR2GRAY);
    //【3】先使用5x5内核来降噪
    blur(grayImage,edge,Size(5,5));
    //【4】运行Canny算子
    Canny(edge,edge,3,9,3);
    //【5】显示效果图
    imshow("Effect picture",edge);
    waitKey(0);
    return 0;

}
