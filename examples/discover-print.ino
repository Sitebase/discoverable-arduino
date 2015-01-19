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
