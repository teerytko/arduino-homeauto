#include <SoftwareSerial.h>


int inByte = 0;         // incoming serial byte
String input;
SoftwareSerial wifiSerial(2, 3); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.write("HELLO");
  Serial.write("\ncmd>");
  wifiSerial.begin(9600);
  wifiSerial.println("Hello wifi!");
    
}

void loop() {
  // put your main code here, to run repeatedly:
  if (wifiSerial.available())
    Serial.write(wifiSerial.read());
  if (Serial.available() > 0) {
    // get incoming byte:
    input = Serial.readStringUntil("\n");
    String valread = "\nRead: " + input;
    // read first analog input, divide by 4 to make the range 0-255:
    Serial.write(valread.c_str());
    wifiSerial.write(valread.c_str());
    Serial.write("\ncmd>");
  }
}
