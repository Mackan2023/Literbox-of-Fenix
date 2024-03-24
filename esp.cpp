#include <Arduino.h>			// För grundläggande Arduino-funktioner.
#include <ESP8266WiFi.h>		// För att använda WiFi-funktioner på ESP8266-baserade enheter.
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>	// För att använda den asynkrona webbservern på ESP8266-baserade enheter.
#include <ESP8266mDNS.h>		
#include <WiFiUdp.h>			
#include <ArduinoOTA.h>			
#include <FS.h>					// För SPIFFS-filhantering
#include <string.h>				// För att använda stränghanteringsfunktioner i C/C++.
#include <stdio.h>				// För att använda standardin- och standardut-funktioner i C/C++.
#include <sha256.h>				// För att använda SHA-256 hash-algoritmfunktioner.

// WiFi-nätverksinställningar
const char* ssid = "admin";
const char* password = "lösenordet";
// Pin
const int ledPin = LED_BUILTIN;	 // Ange pin 2 som en utgång

// Asynkron webbserver
AsyncWebServer server(80);

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
        digitalWrite(ledPin, HIGH); 	// Tänd LED
        delay(250);						// Vänta i 250 ms
        digitalWrite(ledPin, LOW);		// Släck LED
        delay(250);						// Vänta i 250 ms
        Serial.println("Connecting to WiFi...");
			else {
			Serial.println("No connection Found :(");}
		}
    Serial.println("Connected :)");

	//********** Hantera HTTP POST-förfrågningar för att spara WiFi-inställningar **********
	server.on("/save-settings", HTTP_POST, [](AsyncWebServerRequest *request) {
		// Extrahera WiFi-inställningarna från POST-förfrågan
		if (request->hasParam("ssid", true) && request->hasParam("password", true)) {
			String ssid = request->getParam("ssid", true)->value();
			String password = request->getParam("password", true)->value();
		// Spara WiFi-inställningarna i en konfigurationsfil
		File configFile = SPIFFS.open("/config.txt", "w");
		if (!configFile) {
			Serial.println("Failed to open config file for writing");
			return;
		}

		configFile.println(ssid);
		configFile.println(password);
		configFile.close();

		Serial.println("WiFi settings saved successfully :)");
    } else {
		Serial.println("Wifi setting NOT saved :(");
    }

    request->send(200);
  });

    //********** Hantera uppladdning av fil från HTML **********
	server.on("/upload", HTTP_POST, handleUpdate);
	
	// Läs innehållet från index.html-filen
    File file = SPIFFS.open("/index.html", "r");
    if (file) {
        String htmlPage = file.readString();
        file.close();
        server.on("/index", HTTP_GET, [](AsyncWebServerRequest *request) {
            request->send(200, "text/html", htmlPage);
        });
		Serial.println("index file are uploaded :) comleat");
    } else {
        Serial.println("index file are error :( reuploade");
    }
    
	//********** Hantera uppdatering av binär fil **********
    server.on("/update", HTTP_POST, [](AsyncWebServerRequest *request) {
        // Ladda ner och skicka .bin-filen
        downloadAndSendBinFile();
        request->send(200);
    });
	// Aktivera funktioner
    ArduinoOTA.begin();
    SPIFFS.begin();
	server.begin();
	wifi.begin(ssid, password);
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

}//********** Funktion för att hantera uppladdning av fil **********
void handleUpload(AsyncWebServerRequest* request) {
    // Kod för att hantera uppladdning av fil
}

//********** Funktion för att ladda ner och skicka .bin-fil **********
void downloadAndSendBinFile() {
    // Kod för att ladda ner och skicka .bin-fil
}
