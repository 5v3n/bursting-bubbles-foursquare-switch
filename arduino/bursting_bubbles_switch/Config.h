#ifndef __CONFIG_H__
#define __CONFIG_H__

// Wifi parameters
char passphrase[] = "YOUR WIRELESS PASSPHRASE";
char ssid[] = "YOUR WIRELESS PASSPHRASE SSID";
// ratpack server
char* HOST         = "YOUR APP'S URL";
char* USERAGENT    = "ratpack-client/xbee-wifly-shield";
char* RESOURCE     = "/status.json";
//io settings
byte transistorPin        = 4;    // transistor pin 
byte ledPin               = 13;   // led pin


const unsigned long IO_INTERVAL = 5*1337;  // delay between updates, in milliseconds

#endif
