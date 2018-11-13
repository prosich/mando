#include <WiFiUdp.h>

void wakeonlan(byte *mac) {
  WiFiUDP udp;
  byte preamble[]={255,255,255,255,255,255};
  udp.beginPacket(IPAddress(255,255,255,255),9);
  udp.write(preamble,6);
  for (int i=0; i<16; i++) udp.write(mac,6);
  udp.endPacket();
}

