#include <Arduino.h>    // För grundläggande Arduino-funktioner.
#include <FS.h>         // För SPIFFS-filhantering
#include <string.h>     // För att använda stränghanteringsfunktioner i C/C++.
#include <stdio.h>      // För att använda standardin- och standardut-funktioner i C/C++.
#include <Hash.h>       // För att använda SHA-256 hash-algoritmfunktioner.
#include <ArduinoOTA.h> // För OTA-uppdatering av ESP8266
#include <ESP8266HTTPUpdateServer.h>  // För OTA-uppdatering av ESP8266
#include <ESP8266WebServer.h>         // För att skapa webbserver på ESP8266
#include <ESP8266WiFi.h>              // För ESP8266 WiFi-funktioner

// WiFi-nätverksinställningar
const char* ssid = "admin";
const char* password = "lösenordet";
// Pin
const int ledPin = LED_BUILTIN;  // Ange pin 2 som en utgång

// Asynkron webbserver
ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;
File fsUploadFile; // Filobjekt för att hantera uppladdning av filer
SHA256 sha256; // Objekt för att beräkna SHA-256 hash

// Variabel för att hålla reda på om uppdatering pågår
bool updating = false;

void setup() {
    Serial.begin(115200);

    //********** SPIFFS-initiering **********
    if (!SPIFFS.begin()) {
        Serial.println("SPIFFS initialization failed!");
        return;
    } else {
        Serial.println("SPIFFS initialized successfully!");
    }

    //********** Anslutning till WiFi-nätverket **********
    pinMode(ledPin, OUTPUT);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        digitalWrite(ledPin, HIGH);    // Tänd LED
        delay(250);                     // Vänta i 250 ms
        digitalWrite(ledPin, LOW);      // Släck LED
        delay(250);                     // Vänta i 250 ms
        Serial.println("Connecting to WiFi...");
        //#else
        //Serial.println("No connection Found :(");
        //#endif
    }
    Serial.println("Connected :)");

    //********** Konfigurera HTTP-routes **********
    server.on("/save-settings", HTTP_POST, handleSaveSettings);
    server.on("/upload", HTTP_POST, handleUpload);
    server.on("/index", HTTP_GET, handleIndex);
    server.on("/update", HTTP_POST, handleUpdate);

    // Hantera HTTP POST-förfrågningar för att spara WiFi-inställningar
    server.on("/save-settings", HTTP_POST, [](AsyncWebServerRequest *request) {
        // Extrahera WiFi-inställningarna från POST-förfrågan
        if (request->hasParam("ssid", true) && request->hasParam("password", true)) {
            String ssid = request->getParam("ssid", true)->value();
            String password = request->getParam("password", true)->value();

            // Spara WiFi-inställningarna i en konfigurationsfil
            File configFile = SPIFFS.open("/config.txt", "w");
            if (!configFile) {
                Serial.println("Failed to open config file for writing");
                request->send(500, "text/plain", "Internal Server Error");
                return;
            }
            configFile.println(ssid);
            configFile.println(password);
            configFile.close();
            request->send(200, "text/plain", "WiFi settings saved successfully :)");
        } else {
            Serial.println("Missing ssid or password in request");
            request->send(400, "text/plain", "Bad Request");
        }
    });

    // Hantera uppladdning av fil från HTML och skicka index.html till klienten
    server.on("/upload", HTTP_POST, handleFileUpload);

    File file = SPIFFS.open("/index.html", "r");
    if (file) {
        String htmlPage = file.readString();
        file.close();
        server.on("/index", HTTP_GET, [htmlPage](AsyncWebServerRequest *request) {
            request->send(200, "text/html", htmlPage);
        });
        Serial.println("index file are uploaded :) comleat");
    } else {
        Serial.println("index file are error :( reuploade");
    }

    // Hantera uppdatering av STM32_binär fil
    server.on("/update-stm", HTTP_POST, [](AsyncWebServerRequest *request) {
        // Ladda ner och skicka stm.bin-filen
        downloadAndSendBinFile("/stm.bin", "application/octet-stream", "stm.bin");
    });

    // Hantera uppdatering av ESP_binär fil
    server.on("/update-esp", HTTP_POST, [](AsyncWebServerRequest *request) {
        // Ladda ner och skicka esp.bin-filen
        downloadAndSendBinFile("/esp.bin", "application/octet-stream", "esp.bin");
    });
    // Aktivera uppdateringar för ArduinoOTA, SPIFFS, och webbservern
    ArduinoOTA.begin();
    SPIFFS.begin();
    server.begin();
    WiFi.begin(ssid, password);

    // Vänta på anslutning till WiFi
    while (WiFi.status() != WL_CONNECTED) {
        Serial.println("Connecting to WiFi...");
        delay(500);
    }

    // När ansluten till WiFi
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop() {

    // Kontrollera om OTA-uppdatering pågår
    if (ArduinoOTA.isRunning()) {
        // Uppdatering pågår, tänd LED
        digitalWrite(ledPin, HIGH);
        updating = true; // Markera att uppdatering pågår
    } else {
        // Inga uppdateringar pågår, släck LED om den tidigare var tänd
        if (updating) {
            digitalWrite(ledPin, LOW);
            updating = false; // Markera att uppdatering inte pågår längre
        }
    }

    // Hantera OTA-uppdateringar
    ArduinoOTA.handle();
    server.handleClient();  // Hantera webbserverns klienter
}

//********** Funktion för att hantera uppladdning av fil **********
void handleUpload(AsyncWebServerRequest* request) {
    // Kontrollera om det finns en fil att hantera
    if (request->hasParam("file", true) && request->hasParam("hash", true)) {
        // Hämta filen och dess hash-värde från förfrågan
        AsyncWebParameter* fileParam = request->getParam("file", true);
        AsyncWebParameter* hashParam = request->getParam("hash", true);
        
        // Öppna filen för att skriva
        fsUploadFile = SPIFFS.open("/" + fileParam->value(), "w");
        if (!fsUploadFile) {
            Serial.println("Failed to open file for writing");
            request->send(500, "text/plain", "Internal Server Error");
            return;
        }
        
        // Återställ SHA-256-hashberäkningen
        sha256.reset();
    } else {
        // Felaktig förfrågan om fil och/eller hash saknas
        request->send(400, "text/plain", "Bad Request");
    }
}

//********** Funktion för att ladda ner och skicka .bin-fil **********
void downloadAndSendBinFile(const char* filename, const char* contentType, const char* alias) {
    // Öppna den binära filen för läsning
    File binFile = SPIFFS.open(filename, "r");
    if (!binFile) {
        Serial.println("Failed to open binary file for reading");
        return;
    }

    // Skicka binärfilen till klienten
    server.streamFile(binFile, contentType, alias);
    binFile.close();
}

// Funktion för att skicka index.html-sidan till klienten
void handleIndex() {
    File file = SPIFFS.open("/index.html", "r");
    if (file) {
        server.streamFile(file, "text/html");
        file.close();
    } else {
        Serial.println("Failed to open index.html file");
        server.send(404, "text/plain", "File Not Found");
    }
}

