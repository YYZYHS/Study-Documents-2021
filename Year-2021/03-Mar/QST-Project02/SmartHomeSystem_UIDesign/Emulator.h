#ifndef EMULATOR_H
#define EMULATOR_H

#include <QWidget>

namespace Ui {
class Emulator;
}

class Emulator : public QWidget
{
    Q_OBJECT

public:
    explicit Emulator(QWidget *parent = nullptr);
    ~Emulator();

private:
    Ui::Emulator *ui;
};

#endif // EMULATOR_H
