#ifndef PEDALINTERFACE_H
#define PEDALINTERFACE_H

#include <QMainWindow>
#include <QSerialPort>
#include <QBasicTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class PedalInterface; }
QT_END_NAMESPACE

class PedalInterface : public QMainWindow
{
    Q_OBJECT

public:
    PedalInterface(QWidget *parent = nullptr);
    ~PedalInterface();

private slots:
    void on_ClutchLowSlider_valueChanged(int value);

    void on_ClutchHighSlider_valueChanged(int value);

    void on_BrakeLowSlider_valueChanged(int value);

    void on_BrakeHighSlider_valueChanged(int value);

    void on_GasLowSlider_valueChanged(int value);

    void on_GasHighSlider_valueChanged(int value);

    void on_ReadValuesButton_clicked();

    bool readSerial();

    void on_SetValuesButton_clicked();

    void on_ClutchLowSpinBox_valueChanged(int arg1);

    void on_ClutchHighSpinBox_valueChanged(int arg1);

    void on_BrakeLowSpinBox_valueChanged(int arg1);

    void on_BrakeHighSpinBox_valueChanged(int arg1);

    void on_GasLowSpinBox_valueChanged(int arg1);

    void on_GasHighSpinBox_valueChanged(int arg1);

private:
    Ui::PedalInterface *ui;
    int clutchLimits[2]= {-1,-1}, gasLimits[2] = {-1,-1};
    int clutchLimitsSetting[2]= {-1,-1}, gasLimitsSetting[2] = {-1,-1};
    double brakeLimits[2] = {-1,-1};
    double brakeLimitsSetting[2] = {-1,-1};

    int rawClutch = 0, rawBrake = 0, rawGas = 0;
    int mapClutch = 0, mapBrake = 0, mapGas = 0;

    QSerialPort *pedalPort;
    QBasicTimer rawReadTimer;

//    int testVar = 0;

    int map(int x, int in_min, int in_max);
    void updateRaw();
    void updateSettingsUI();
    bool checkLimits();
    void resetInterfaceLimits();

protected:
    void timerEvent(QTimerEvent *event) override;

};
#endif // PEDALINTERFACE_H
