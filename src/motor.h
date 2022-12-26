#ifndef MOTOR_H
#define MOTOR_H

#include <AccelStepper.h>
#include <Stepper.h>

class Motor
{
public:
    Motor(Stepper &doorStepper_, AccelStepper &tractionMotor_);
    void init(long maxSpeed = 1000, long accel = 500, long speedTraction = 500, long doorSpeed = 6);
    void setCounter(int counter_);
    void tractionMotorForward(int distance_);
    void tractionMotorBackward(int distance_);
    void doorStepperForward();
    void doorStepperBackward();
    void open();
    void close();
    void up();
    void down();
    void floorOne();
    void floorTwo();
    void floorThree();
    void floorFour();
    void check();

    void bounceInit(); // Just temporary
    bool bounce();     // Just temporary too

private:
    Stepper &_doorStepper;
    AccelStepper &_tractionMotor;
    int _distance;
    int _counter = 1;
};

#endif