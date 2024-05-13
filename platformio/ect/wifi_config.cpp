#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <FS.h>

const char *ssid = "YourAPSSID";
const char *password = "YourAPPassword";

ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;

void setup() {
  Serial.begin(115200);

  // Starta SPIFFS-filsystemet
  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount file system");
    return;
  }

  // Läs nätverksinställningar från SPIFFS
  readNetworkSettings();

  // Starta som en WiFi-åtkomstpunkt
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  // Konfigurera webbserver
  server.on("/", HTTP_GET, handleRoot);
  server.on("/connect", HTTP_POST, handleConnect);
  server.begin();

  // Konfigurera OTA-uppdateringsserver
  httpUpdater.setup(&server);
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  // Skicka HTML-sidan när användaren ansluter till IP-adressen
  server.send(200, "text/html", "<html><body><form action='/connect' method='POST'>SSID: <input type='text' name='ssid' value='" + String(ssid) + "'><br>Password: <input type='password' name='password' value='" + String(password) + "'><br><input type='submit' value='Connect'></form></body></html>");
}

void handleConnect() {
  String newSsid = server.arg("ssid");
  String newPassword = server.arg("password");

  // Om nätverksuppgifterna ändrades, spara dem till SPIFFS
  if (newSsid != ssid || newPassword != password) {
    ssid = newSsid;
    password = newPassword;
    saveNetworkSettings();
  }

  // Anslut till det angivna WiFi-nätverket
  WiFi.begin(ssid.c_str(), password.c_str());

  // Vänta på anslutning
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Ansluten, skicka respons
  server.send(200, "text/plain", "Connected to WiFi! You can now close this page.");

  // Här kan du lägga till ytterligare åtgärder efter att du har anslutit, om så önskas
}

void readNetworkSettings() {
  // Öppna konfigurationsfilen
  File configFile = SPIFFS.open("/config.txt", "r");
  if (!configFile) {
    Serial.println("Failed to open config file");
    return;
  }

  // Läs nätverksinställningar från filen
  ssid = configFile.readStringUntil('\n');
  password = configFile.readStringUntil('\n');

  // Stäng filen
  configFile.close();
}

void saveNetworkSettings() {
  // Öppna konfigurationsfilen för skrivning
  File configFile = SPIFFS.open("/config.txt", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    return;
  }

  // Skriv nätverksinställningarna till filen
  configFile.println(ssid);
  configFile.println(password);

  // Stäng filen
  configFile.close();
}
mackan(C)github
