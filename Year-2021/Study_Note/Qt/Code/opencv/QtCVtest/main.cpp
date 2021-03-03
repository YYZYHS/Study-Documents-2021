#include <QCoreApplication>
#include <QDebug>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    namedWindow("Display", WINDOW_AUTOSIZE);
        VideoCapture cap;
        cap.open("D:/opencv/vtest.avi");
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
