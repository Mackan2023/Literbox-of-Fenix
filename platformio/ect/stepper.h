#ifndef STEPPER_H
#define STEPPER_H

#include <Stepper.h>

extern const int stepsPerRevolution;
extern Stepper myStepper;

void setupStepper();
void moveStepperClockwise();
void moveStepperCounterClockwise();

#endif // STEPPER_H
mackan(C)github
