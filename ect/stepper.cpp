#include "stepper.h"

const int stepsPerRevolution = 200; // ändra detta för att passa antalet steg per varv
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // initiera Stepper-biblioteket på stiften 8 till 11

void setupStepper() {
    // Eventuell initialiseringskod för steppermotorn
}

void moveStepperClockwise() {
    myStepper.setSpeed(10);
    myStepper.step(stepsPerRevolution);
    delay(50);
}

void moveStepperCounterClockwise() {
    myStepper.setSpeed(10);
    myStepper.step(-stepsPerRevolution);
    delay(50);
}
