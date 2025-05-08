#include "motor.hpp"

Motor::Motor(uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD) {
  _pinA = pinA;
  _pinB = pinB;
  _pinC = pinC;
  _pinD = pinD;

  pinMode(_pinA, OUTPUT);
  pinMode(_pinB, OUTPUT);
  pinMode(_pinC, OUTPUT);
  pinMode(_pinD, OUTPUT);
}

void Motor::setVelocity(int vel) {
  velocity = vel;
}

int Motor::getVelocity() {
  return velocity;
}

void Motor::setDirection(int dir) {
  direction = dir;
}

int Motor::getDirection() {
  return direction;
}

void Motor::setAceleration(float a) {
  aceleration = a;
}

float Motor::getAceleration() {
  return aceleration;
}

void Motor::moveSteps(int s) {
  steps = s;
  status = 1;
}

void Motor::moveContinous() {
  steps = -1;
  status = 1;
}

void Motor::stop() {
  status = 0;
}

bool Motor::check() {
  if (status == 0) return false;
  if (steps == 0) {
    status = 0;
    return false;
  }

  static int stepIndex = 0;
  const int seq[8][4] = {
    {1,0,0,0}, {1,1,0,0}, {0,1,0,0}, {0,1,1,0},
    {0,0,1,0}, {0,0,1,1}, {0,0,0,1}, {1,0,0,1}
  };

  int dir = direction == 1 ? 1 : -1;
  stepIndex = (stepIndex + dir + 8) % 8;

  digitalWrite(_pinA, seq[stepIndex][0]);
  digitalWrite(_pinB, seq[stepIndex][1]);
  digitalWrite(_pinC, seq[stepIndex][2]);
  digitalWrite(_pinD, seq[stepIndex][3]);

  delay(1000 / velocity);

  if (steps > 0) steps--;

  return true;
}
