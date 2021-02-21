#include "mainwindow.h"
#include <QApplication>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cv::Mat image = imread("E:\\StudyDocuments\\Study-Documents-2021\\Year-2021\\Study_Note\\Qt\\Code\\opencv\\test.jpg");
    //读入一张照片
//    namedWindow("Display window",WINDOW_AUTOSIZE);
    imshow("Display window",image);
    //在窗口中显示载入的图片
    waitKey(6000);
    //等待6000ms后窗口自动关闭

//    MainWindow w;
//    w.show();
//    return a.exec();
}
