#include "hx711.h"

HX711 scale;

void setupHX711() {
    // Eventuell initialiseringskod för HX711
}

float readScale() {
    return scale.get_units();
}mackan(C)github
