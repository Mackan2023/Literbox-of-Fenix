#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <U8glib.h>
#include "ect/HX711.h"
#include "ect/optical.h"
#include "ect/wifi.h"
#include "ect/stepper.h"
#include <SoftwareSerial>
#include "wifi_config.cpp"


// För din motor
int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// För din optiska läsgaffel (ersätt "OpticalReader" med det verkliga namnet)
OpticalReader opticalReader;

SoftwareSerial esp8266(2, 3); // RX, TX pins på Arduino

void setup() {
    // Kod som körs en gång vid start
    Serial.begin(9600); // Starta seriell kommunikation

    pinMode(13, OUTPUT); // Sätt upp en pinne som en utgång

    SPI.begin(); // Initiera SPI
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

    Wire.begin(); // Initiera Wire (I2C)
    Serial.println("Setup completed");

    myStepper.setSpeed(10); // set the speed at 60 rpm
    Serial.println("Initializing the scale");

    // Skala (HX711)
    setupHX711();

    // Optisk läsgaffel
    opticalReader.begin(2); // Använd rätt stift för din optiska läsgaffel

    //wifi
    connectToWiFi();

    //stepper
    setupStepper();

    //wifi
    Serial.begin(9600);
  esp8266.begin(9600);
  delay(1000);

  // Börja med att starta om ESP8266-modulen
  sendCommand("AT+RST\r\n", 2000, true);
  delay(2000);

  // Ställ in WiFi-läge (1 för Station mode)
  sendCommand("AT+CWMODE=1\r\n", 1000, true);
  delay(1000);

  // Anslut till WiFi-nätverk
  connectToWiFi("SSID", "PASSWORD");

  // Starta en enkel TCP-server på port 80
  sendCommand("AT+CIPMUX=1\r\n", 1000, true);
  sendCommand("AT+CIPSERVER=1,80\r\n", 1000, true);
}

void loop() {
    // Kod som körs upprepade gånger

    // Exempel: Skicka data via SPI
    SPI.transfer(0x55);

    // Exempel: Skicka data via I2C
    Wire.beginTransmission(8); // Adress 8 på I2C-bussen
    Wire.write("Hello");
    Wire.endTransmission();
    delay(1000);

    //stepper
    int opticalReading = readOptical(); // Ändrat variabelnamn här
    Serial.println("Optical Reading: " + String(opticalReading));
    delay(1000);

    moveStepperClockwise();
    delay(1000);

    moveStepperCounterClockwise();
    delay(1000);

    // Läs vikt från våg
    float weight = readScale();
    Serial.println("Weight Reading: " + String(weight));
    delay(1000);

    //optical
    int anotherOpticalReading = readOptical(); // Ändrat variabelnamn här
    Serial.println("Another Optical Reading: " + String(anotherOpticalReading));
    delay(1000);

    //wifi
      // Läs inkommande data från WiFi-modulen
  if (esp8266.available()) {
    String response = esp8266.readString();
    Serial.println("Received: " + response);

    // Hantera inkommande data här
  }
}

void connectToWiFi(const char* ssid, const char* password) {
  // Anslut till WiFi-nätverk
  String command = "AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) + "\"\r\n";
  sendCommand(command, 5000, true);
}

void sendCommand(String command, int timeout, bool debug) {
  esp8266.print(command);
  long int startTime = millis();

  while ((millis() - startTime) < timeout) {
    while (esp8266.available()) {
      char c = esp8266.read();
      Serial.print(c);
    }
  }
}
