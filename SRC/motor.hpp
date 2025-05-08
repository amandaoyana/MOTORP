#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "Arduino.h"

class Motor {
  private:
    int steps = 1;
    int direction = 1;
    int velocity = 0;
    float aceleration = 0.1;
    bool status = 0;

    uint8_t _pinA, _pinB, _pinC, _pinD;

  public:
    Motor(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD); // Set four pins of motor

    void setVelocity(int vel);
    int getVelocity();

    void setDirection(int dir);
    int getDirection();

    void setAceleration(float a);
    float getAceleration();

    void moveSteps(int steps);
    void moveContinous();
    void stop();

    bool check();
};

#endif
