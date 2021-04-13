#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg1;
MCP2515 mcp2515(10);


void setup() {
  canMsg1.can_id  = 0x630;
  canMsg1.can_dlc = 8;
  canMsg1.data[0] = 0x2F;
  canMsg1.data[1] = 0x00;
  canMsg1.data[2] = 0x22;
  canMsg1.data[3] = 0x01;
  canMsg1.data[4] = 0x00;
  canMsg1.data[5] = 0x00;
  canMsg1.data[6] = 0x00;
  canMsg1.data[7] = 0x00;
  
  while (!Serial);
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_100KBPS);
  mcp2515.setNormalMode();
  

}

void loop() {
  mcp2515.sendMessage(&canMsg1);

  Serial.println("BMS power off");
  
  delay(1000);
}