#include <OneWire>
#include <SoftwareSerial>
 
#define ONE_WIRE_BUS A0

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

char  strArray[3];
 
SoftwareSerial esp8266(2,3); // Make RX Arduino line on pin 2, make TX Arduino line on pin 3.
                             // This means that you need to connect the TX line from the ESP to the Arduino's pin 2
                             // and the RX line from the ESP to the Arduino's pin 3

void setup() {
  pinMode(MOTOR, OUTPUT);
  digitalWrite(MOTOR, HIGH);
  
  sensors.begin();
   
  sendCommand("AT+RST\r\n",2000,DEBUG); // Reset module
  sendCommand("AT+CWMODE=2\r\n",2000,DEBUG); // Configure as access point
  sendCommand("AT+CIFSR\r\n",2000,DEBUG); // Get ip address
  sendCommand("AT+CIPMUX=1\r\n",2000,DEBUG); // Configure for multiple connections
  sendCommand("AT+CIPSERVER=1,80\r\n",2000,DEBUG); // Turn on server on port 80
  
  Serial.println("Server Ready");
}


     sendHTTPResponse(connectionId,content);
     
     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand += connectionId; // Append connection id
     closeCommand += "\r\n";
     
     sendCommand(closeCommand,1000,DEBUG);
    }
  }

  delay(1000);
}


/*
* Name: mapFloat
* Description: Re-maps a number from one range to another
* Params: num - the number to map; fromMin - the lower bound of the value’s current range; 
  fromMax - the upper bound of the value’s current range; toMin - the lower bound of the value’s target range; 
  toMax - the upper bound of the value’s target range
* Returns: The mapped value
*/
float mapFloat(float num, float fromMin, float fromMax, float toMin, float toMax) {
  float fromDiff = fromMax - fromMin;
  float toDiff = toMax - toMin;
  float result = (num - fromMin) * toDiff / fromDiff + toMin;
  return result;
}


/*
* Name: split
* Description: Splits the request string by the "=" delimiter, 
  storing the first characters of the parameters' values 
  (this function is used ONLY for "settings" parameter key)
* Params: The request string sent by the device
* Returns: Nothing, stores characters in the global strArray
*/
void split(String str) {
  
  int index = str.indexOf("=") + 1;
  
  for (int i = 0; i < 3; i++) {
    strArray[i] = str.charAt(index);
    index = str.indexOf("&", index) + 1;
  }
  
}

/*
* Name: sendData
* Description: Function used to send data to ESP8266
* Params: command - the data/command to send; timeout - the time to wait for a response; 
  debug - print to Serial window?(true = yes, false = no)
* Returns: The response from the ESP8266 (if there is a reponse)
*/
String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    
    int dataSize = command.length();
    char data[dataSize];
    command.toCharArray(data,dataSize);
           
    esp8266.write(data,dataSize); // Send the characters read to the ESP8266
    if(debug)
    {
      Serial.println("\r\n====== HTTP Response From Arduino ======");
      Serial.write(data,dataSize);
      Serial.println("\r\n========================================");
    }
    
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {

        // The ESP has data so display its output to the serial window 
        char c = esp8266.read(); // Read the next character.
        response += c;
      }  
    }
    
    if(debug)
    {
      Serial.print(response);
    }
    
    return response;
}


/*
* Name: sendHTTPResponse
* Description: Function that sends HTTP 200, HTML UTF-8 response
*/
void sendHTTPResponse(int connectionId, String content)
{
     // Build HTTP response
     String httpResponse;
     String httpHeader;

     // HTTP Header
     httpHeader = "HTTP/1.1 200 OK\r\nContent-Type: text/html; charset=UTF-8\r\n"; 
     httpHeader += "Content-Length: ";
     httpHeader += content.length();
     httpHeader += "\r\n";
     httpHeader += "Connection: close\r\n\r\n";
     // There is a bug in this code: the last character of "content" is not sent.
     httpResponse = httpHeader + content + " "; // I cheated by adding this extra space
     sendCIPData(connectionId,httpResponse);
}


/*
* Name: sendCIPDATA
* Description: sends a CIPSEND=<connectionId>,<data> command
*/
void sendCIPData(int connectionId, String data)
{
   String cipSend = "AT+CIPSEND=";
   cipSend += connectionId;
   cipSend += ",";
   cipSend += data.length();
   cipSend += "\r\n";
   sendCommand(cipSend,1000,DEBUG);
   sendData(data,1000,DEBUG);
}

/*
* Name: sendCommand
* Description: Function used to send data to ESP8266.
* Params: command - the data/command to send; timeout - the time to wait for a response; 
  debug - print to Serial window?(true = yes, false = no)
* Returns: The response from the ESP8266 (if there is a reponse)
*/
String sendCommand(String command, const int timeout, boolean debug)
{
    String response = "";
           
    esp8266.print(command); // send the characters read to the ESP8266
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {

        // The ESP has data so display its output to the serial window 
        char c = esp8266.read(); // Read the next character
        response += c;
      }  
    }
    
    if(debug)
    {
      Serial.print(response);
    }
    
    return response;
}
mackan(C)github
