#include <Arduino.h> // Inkluderar Arduino.h för grundläggande Arduino-funktioner.
#include <SoftwareSerial.h>
#include "sha256.h" // Exempel på en SHA-256-bibliotek

SoftwareSerial espSerial(2, 3); // RX, TX (Anslut ESP8266 till dessa stift)

void setup() {
    Serial.begin(115200);
    espSerial.begin(115200); // Starta kommunikationen med ESP8266
}

void loop() {
    // Lyssna på kommandon från ESP8266
    if (espSerial.available() > 0) {
        String command = espSerial.readStringUntil('\n');
        // Implementera logik för att hantera kommandon från ESP8266
        // Kommandon kan vara hash och fildata från HTML-filen
        // eller kommandon för att skicka status till HTML-filen
    }
}
