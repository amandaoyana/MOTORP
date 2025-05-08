#include "motor.hpp"

Motor miMotor(10, 11, 12, 13);

bool esperando = false;

void setup() {
  miMotor.setVelocity(1000);
  miMotor.setDirection(1);       // Empezar en dirección positiva
  miMotor.moveSteps(1000);
}

void loop() {
  if (!miMotor.check() && !esperando) {
    esperando = true;            // Para evitar múltiples reinicios en un solo ciclo

    delay(500);                  // Pausa opcional entre cambios de dirección

    int nuevaDireccion = -miMotor.getDirection(); // Cambiar dirección
    miMotor.setDirection(nuevaDireccion);
    miMotor.moveSteps(1000);     // Volver a mover
    esperando = false;
  }
}

