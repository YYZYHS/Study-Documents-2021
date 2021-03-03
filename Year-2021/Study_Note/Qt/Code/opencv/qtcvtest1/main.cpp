#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QtDebug>

using namespace cv;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    namedWindow("Display", WINDOW_AUTOSIZE);
    VideoCapture cap;
    cap.open("D:/opencv/opencv-3.4.5/samples/data/vtest.avi");
    //cap.open(0);
    if(cap.isOpened())
        qDebug()<<"Sucess!";
    else
        qDebug()<<"False!";
    Mat frame;
    for(;;)
    {
        cap >> frame;
        if(frame.empty())
            break;
        imshow("Display", frame);
        if(waitKey(33) >= 0)
            break;
    }
    return a.exec();
}


//D:/opencv/opencv-3.4.5/samples/data/
