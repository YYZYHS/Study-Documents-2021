#include "Student.h"
#include <QtDebug>

Student::Student()
{
    qDebug()<<"生成了";
}

Student::~Student()
{
    qDebug()<<"释放了";
}
