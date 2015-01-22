Discoverable device
===================
Arduino library that makes it possible to search on your local network for a specific device or service using UDP. 
This library is developed to use in combination with `discoverable-node` which is a NodeJS library.

A example use case could be that you have a home automation platform build using NodeJS and you want your Arduino to connect to that server to publish some data to it.
Normally you would need to configure the IP address of the NodeJS server into the Arduino source. 

But a much easier and plug and play solution for this would be that using the discoverable device library the Arduino will do a broadcast on the local network asking for the server.

Usage
-----
Check out the library in your `Arduino/libraries` folder and you're ready to use it.

	git clone git@github.com:Sitebase/discoverable-arduino.git Discoverable

In your Arduino IDE you can check out the example application via `File > Examples > Discoverable > basic`.

How to use
----------
Usage is very simple. For a good example check out the examples folder.

	#include <SPI.h> 
	#include <Ethernet.h>
	#include <EthernetUdp.h>
	#include <Discoverable.h>

	Discoverable discover;

	byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
	IPAddress ip(192, 168, 1, 177);

	EthernetClient ethClient;

	void setup() {
	  Serial.begin(9600);
	  Ethernet.begin(mac,ip);
	  discover.begin();
	}

	void loop() {
	  if( !discover.remoteIP() ) {
	    discover.search("general");
	  } else {
	    Serial.print("Remote address is: ");
	    Serial.println(discover.remoteIP());
	  }
	  delay(1000);
	}

