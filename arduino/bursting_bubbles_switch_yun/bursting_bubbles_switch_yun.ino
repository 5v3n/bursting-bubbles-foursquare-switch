#include "Bridge.h"
#include "Config.h"

/*
* bursting bubble switch
*
* sven kraeuter for making things happen.
*
* based on the rat pack: http://github.com/5v3n/ratpack
*
* http://makingthingshappen.de
*
*/

unsigned long lastConnectionTime = 0; // last time you connected to the server, in milliseconds
unsigned int lastCount    = -1;
unsigned int currentCount = -1;

void setup(){
  //------------------------ led setup ------------------------
  pinMode(ledPin, OUTPUT);
  pinMode(transistorPin,OUTPUT);  
  digitalWrite(transistorPin,HIGH); //turns the switch off actually
  
  Bridge.begin();
#ifdef DEBUG
  // Initialize Serial
  Serial.begin(9600);
  // Wait until a Serial Monitor is connected.
  while (!Serial){
    ;
  }
  Serial.print("Setting an unsigned int to -1 should lead to the overflow -> biggest int value: ");
  Serial.println(lastCount);
#endif
  
}

void loop() { 
  // if you're not connected, and the given time has passed since
  // your last connection, then connect again and send data:
  if(millis() - lastConnectionTime > IO_INTERVAL) {
    currentCount = receiveCurrentCheckinCount();
    if(currentCount > lastCount){
#ifdef DEBUG
      Serial.println("New checkin detected, yay!");
#endif
      digitalWrite(ledPin, HIGH);
      digitalWrite(transistorPin, LOW);
      delay(30000);
      digitalWrite(ledPin, LOW);
      digitalWrite(transistorPin,HIGH);
    }
    lastCount = currentCount;
    lastConnectionTime = millis();
  }
}

int receiveCurrentCheckinCount(){
  
  char commandBuffer[255]; //it's crude - feel free to handle the commandBuffer length more elegant
  sprintf(commandBuffer, "curl -k -s \"https://api.foursquare.com/v2/venues/%s/herenow?client_id=%s&client_secret=%s\" | grep -o '{\"hereNow\":{\"count\":[0-9]*' | grep -o '[0-9]*'", VENUE_ID, FOURSQUARE_CLIENT_ID, FOURSQUARE_CLIENT_SECRET);
  
  Process p;
  p.runShellCommand(commandBuffer);
  while(p.running());  //wait
  
  char response[255];
  
  if (p.available()>0) {
    int bytesRead = p.readBytes(response, 254);
    response[bytesRead]='\0';
  }
 
#ifdef DEBUG
  Serial.println(commandBuffer);
  Serial.print("Response from before printed command: ");
  Serial.println(response);
  Serial.println("---------");
#endif

  return atoi(response);
}
