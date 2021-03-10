// 
// read analog input and offer a command interface
// 
#include <SoftwareSerial.h>

String input;
int potPin = 0;    // select the input pin for the potentiometer
int curval = 0;
int prevval = 0;
SoftwareSerial wifiSerial(2, 3); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  wifiSerial.begin(9600);
  wifiSerial.println("Hello wifi!");
  wifiSerial.write("\ncmd>");
  Serial.write("Hello serial!");
    
}

void loop() {
  // put your main code here, to run repeatedly:
  curval = analogRead(potPin);    // read the value from the sensor
  delay(5);
  if (prevval != curval) {
    wifiSerial.print("Value changed: ");
    wifiSerial.println(curval, DEC);
    prevval = curval;
  }
  //Serial.println(val, DEC);  // print as an ASCII-encoded decimal
  if (wifiSerial.available() > 0) {
    // get incoming byte:
    input = wifiSerial.readStringUntil('\n');
    String valread = "\nRead command: " + input;
    wifiSerial.write(valread.c_str());
    wifiSerial.write("\ncmd>");
  }
}
