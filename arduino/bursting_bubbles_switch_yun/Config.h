#ifndef __CONFIG_H__
#define __CONFIG_H__

#define DEBUG

// foursqaure details
const char* OAUTH_TOKEN  = "YOUR OAUTH TOKEN";
const char* VENUE_ID     = "YOUR VENUE ID";
//io settings
const byte transistorPin        = 4;    // transistor pin 
const byte ledPin               = 13;   // led pin


const unsigned long IO_INTERVAL = 1.5*1337;  // delay between updates, in milliseconds

#endif
