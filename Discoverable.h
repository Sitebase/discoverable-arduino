/*
  Discoverable.h - Library discovering compatible lan server
  Created by Wim Mostmans, Januari 20, 2015.
  Released into the public domain.
*/

#ifndef Discoverable_h
#define Discoverable_h

#include "Arduino.h"
#include <Ethernet.h>
#include <EthernetUdp.h> 

class Discoverable
{
  public:
    Discoverable();
    void begin();
    void search(char *tag);
    IPAddress remoteIP();
  private:
    unsigned int _port;
    EthernetUDP _udp;
    IPAddress _discoveredRemoteIPAddress;
    bool _searching;
};

#endif

