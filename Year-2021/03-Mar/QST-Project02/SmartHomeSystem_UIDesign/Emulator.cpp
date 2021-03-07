#include "Emulator.h"
#include "ui_Emulator.h"

Emulator::Emulator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Emulator)
{
    ui->setupUi(this);
}

Emulator::~Emulator()
{
    delete ui;
}
