/*
  Discoverable.h - Library discovering compatible lan server
  Created by Wim Mostmans, Januari 20, 2015.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Discoverable.h"
#include <Ethernet.h>
#include <EthernetUdp.h> 

Discoverable::Discoverable()
{
  _port = 41234;
  _searching = true;
}

void Discoverable::begin()
{
  _udp.begin(_port);
}

void Discoverable::search(char *tag)
{
  if( _searching ) {
    int packetSize = _udp.parsePacket();
    if( packetSize ) {
      _discoveredRemoteIPAddress = _udp.remoteIP();
      _searching = false;
    } else {
      IPAddress broadcast(255, 255, 255, 255);
      _udp.beginPacket(broadcast, _port);
      char searchBuffer[] = "discover:";
      _udp.write(searchBuffer);
      _udp.write(tag);
      _udp.endPacket(); 
    }
  }
}

IPAddress Discoverable::remoteIP()
{
  return _discoveredRemoteIPAddress;
}