#include <SD.h>
#include <SoftwareSerial.h>

#define ARDUINO_GPS_RX 9 // GPS TX, Arduino RX pin
#define ARDUINO_GPS_TX 8 // GPS RX, Arduino TX pin
#define GPS_BAUD 9600
SoftwareSerial gpsPort(ARDUINO_GPS_TX, ARDUINO_GPS_RX); // Create a SoftwareSerial

const int chipSelect = 4;
File dataFile;

// Define the serial monitor port. On the Uno, Mega, and Leonardo this is 'Serial'
//  on other boards this may be 'SerialUSB'
#define SerialMonitor Serial

void setup() {
  SerialMonitor.begin(9600);
  gpsPort.begin(GPS_BAUD);
  SD.begin(chipSelect);

  dataFile = SD.open("datalog.txt", FILE_WRITE);

  while (!SerialMonitor || !gpsPort) {}
  
}

void loop() {
  while (gpsPort.available()) {
    dataFile.print(gpsPort.read());
  }
}
