#include "motor.h"

Motor::Motor(Stepper &doorStepper_, AccelStepper &tractionMotor_)
    : _doorStepper(doorStepper_), _tractionMotor(tractionMotor_)
{
}

void Motor::init(long maxSpeed, long accel, long speedTraction, long doorSpeed)
{
    _tractionMotor.setMaxSpeed(maxSpeed);
    _tractionMotor.setSpeed(speedTraction);
    _tractionMotor.setAcceleration(accel);
    _doorStepper.setSpeed(doorSpeed);
}

void Motor::check()
{
    _tractionMotor.runSpeed();
}

void Motor::tractionMotorForward(int distance_)
{
    _tractionMotor.moveTo(distance_);
    while (_tractionMotor.distanceToGo() > 0)
    {
        _tractionMotor.run();
    }
}

void Motor::tractionMotorBackward(int distance_)
{
    _tractionMotor.moveTo(distance_);
    while (_tractionMotor.distanceToGo() > 0)
    {
        _tractionMotor.run();
    }
}

void Motor::setCounter(int counter_)
{
    _counter = counter_;
}

void Motor::up()
{
    switch (_counter)
    {
    case 1:
        tractionMotorForward(50);
        _tractionMotor.run();
        break;
    case 2:
        tractionMotorForward(100);
        break;
    case 3:
        tractionMotorForward(150);
        break;
    }
}

void Motor::down()
{
    switch (_counter)
    {
    case 2:
        tractionMotorBackward(50);
        break;
    case 3:
        tractionMotorBackward(100);
        break;
    case 4:
        tractionMotorBackward(150);
        break;
    }
}

// Just temporary code

void Motor::bounceInit()
{
    _tractionMotor.setMaxSpeed(1000);
    _tractionMotor.setAcceleration(300);
    // _tractionMotor.moveTo(3000);
}

bool Motor::bounce()
{
    _tractionMotor.moveTo(3000);
    if (_tractionMotor.distanceToGo() == 0)
    {
        _tractionMotor.moveTo(-3000);
    }

    _tractionMotor.runToPosition();
    return true;
}