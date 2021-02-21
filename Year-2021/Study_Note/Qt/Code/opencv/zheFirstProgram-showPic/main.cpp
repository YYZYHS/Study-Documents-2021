#include "mainwindow.h"
#include <QApplication>
//上面两个是qt有的，暂时不理会

#include <opencv2/opencv.hpp>
using namespace cv;//包含cv命名空间

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //【1】载入图片
    Mat srcImage = imread("test.jpeg");//图片要放在debug目录下，或者直接用完整的绝对地址，如下
    //Mat srcImage = imread("E:\\StudyDocuments\\Study-Documents-2021\\Year-2021\\Study_Note\\Qt\\Code\\opencv\\test.jpeg");
    //【2】显示图像
    //此处不可显示中文，后期再寻解决之道
    imshow("[original image]",srcImage);
    //【3】等待任意键按下
    waitKey(0);
}
