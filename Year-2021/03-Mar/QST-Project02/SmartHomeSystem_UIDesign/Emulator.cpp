#include "Emulator.h"
#include "ui_Emulator.h"
#include <QDebug>

Emulator::Emulator(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Emulator)
{
    ui->setupUi(this);
    setMouseTracking(true);
}

Emulator::~Emulator()
{
    delete ui;
}

void Emulator::on_pushButton_3_clicked()
{
    emit mainwindowclose();
    this->close();
}

void Emulator::on_spinBox_valueChanged(int arg1)
{
    qDebug()<<arg1;
    ui->horizontalSlider->setValue(ui->spinBox->value());
    m.temp = ui->spinBox->value();
}

void Emulator::on_horizontalSlider_valueChanged(int value)
{
    qDebug()<<value;
    ui->spinBox->setValue(ui->horizontalSlider->value());
    m.temp = ui->horizontalSlider->value();
}

void Emulator::on_pushButton_clicked()
{
//    int temperature = ui->spinBox->value();
//    //QString text ="当前温度："<<temperature<<"℃"；
//    QString text = QString("当前温度：%1℃").arg(temperature);
//    ui->label_3->setText(text);
    emit getstatus();
}

void Emulator::LED_on()
{
    //开灯
    QPixmap ledon = QPixmap(":/Image/Image/led-on.png");
    ui->LED->setPixmap(ledon);
    m.ledstatu = 0;

    //////////////应该烧入板子的程序/////////////////
//    int on;
//    int led_no;
//    int fd;
//    /* 检查 led 控制的两个参数，如果没有参数输入则退出。*/
//    if (argc != 3 || sscanf(argv[1], "%d", &led_no) != 1 || sscanf(argv[2],"%d", &on) != 1 ||on < 0 || on >  || led_no < 0 || led_no > 3)
//    {
//        fprintf(stderr, "Usage: leds led_no 0|1\n");
//        exit(1);
//    }
//    /*打开/dev/leds 设备文件*/
//    fd = open("/dev/leds0", 0);
//    if (fd < 0)
//    {
//        fd = open("/dev/leds", 0);
//    }
//    if (fd < 0)
//    {
//        perror("open device leds");
//        exit(1);
//    }
//    /*通过系统调用 ioctl 和输入的参数控制 led*/
//    ioctl(fd, on, led_no);
//    /*关闭设备句柄*/
//    close(fd); return 0;
}

void Emulator::LED_off()
{
    //关灯
    QPixmap ledoff = QPixmap(":/Image/Image/led-off.png");
    ui->LED->setPixmap(ledoff);
    m.ledstatu = 1;

}

QString Emulator::GetTemperature()
{
    return ui->label_3->text();
}

void Emulator::on_pushButton_5_clicked()
{
    //开警报
    Beep_on();
    emit MainwindowBeepOn();

}

void Emulator::on_pushButton_6_clicked()
{
    //关警报
    Beep_off();
    emit MainWindowBeepOff();
}

void Emulator::on_pushButton_4_clicked()
{
    //模拟警报器

}

void Emulator::Beep_on()
{
    buzzer->setLoops(100);
    buzzer->play();
    m.beepstatu = 0;


    //////////////////////应该烧入板子的程序///////////////////
//    int freq = 1000 ;
//        open_buzzer();
//        printf( "\nBUZZER TEST ( PWM Control )\n" );
//        printf( "Press +/- to increase/reduce the frequency of the BUZZER\n" ) ;
//        printf( "Press 'ESC' key to Exit this program\n\n" );
//        while( 1 )
//        {
//            int key;
//            set_buzzer_freq(freq);
//            printf( "\tFreq = %d\n", freq );
//            key = getch();
//            switch(key)
//            {
//            case '+':
//                if( freq < 20000 )
//                    freq += 10;
//                break;
//            case '-':
//                if( freq > 11 )
//                    freq -= 10 ;
//                break;
//            case ESC_KEY:
//            case EOF:
//                stop_buzzer();
//                exit(0);
//            default:
//                break;
//            }
//        }
}
void Emulator::Beep_off()
{
    buzzer->stop();
    m.beepstatu = 1;
}

void Emulator::on_pushButton_2_clicked()
{
    LED_off();
    Beep_off();
    ui->spinBox->setValue(0);
    ui->horizontalSlider->setValue(0);
    emit MainWindowBeepOff();
    emit MainWindowLedOff();

}

void Emulator::on_pushButton_4_clicked(bool checked)
{
    if(checked)
        ui->pushButton_4->setText("结束模拟");
    else
        ui->pushButton_4->setText("模拟警戒");
    a = checked;
    qDebug()<<a;
}

void Emulator::mouseMoveEvent(QMouseEvent *event)
{
    if(a)
    {//按住鼠标左键移动到下面的范围中时，系统会报警，再移出去则接触报警
        if(event->x()>=80&&event->x()<=780)
            if(event->y()>=390&&event->y()<=560)
            {
                emit MainwindowBeepOn();
                Beep_on();
            }
            else
            {
                emit MainWindowBeepOff();
                Beep_off();
            }
        else
        {
            emit MainWindowBeepOff();
            Beep_off();
        }

    }
    else
    {
        emit MainWindowBeepOff();
        Beep_off();
    }
}
