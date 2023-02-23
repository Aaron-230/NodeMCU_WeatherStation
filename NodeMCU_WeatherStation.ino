#include "arduino_secrets.h"
//Libraries Required
#include <DHT.h>
#include <thingProperties.h>

#define DHTPIN 2; //Defines the Pins for the DHT Sensor
#define DHTTYPE DHT11; //Defines the Type of DHT Sensor

//Variables
DHT dht(DHTPIN, DHTTYPE); //DHT Variable
int sms = 1; //Soil Moisture Variable
bool soilMoisture; //Soil Moisture Variable as True or False

void setup() {
  Serial.begin(9600);
  delay(1500); //delay of 1.5 Seconds

  //Code for connnecting to Arduino Cloud
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  //Defines the Soil Moisture Sensor as the Input
  pinMode(sms, INPUT);
}

void loop() {
  ArduinoCloud.update(); //Updates the Arduino Cloud
  delay(2000); //delay for 2 Seconds
  
  int h = dht.readHumidity(); //Humidity Variable Read
  int t = dht.readTemperature(); //Temperature Variable Read
  int sm = digitalRead(sms); //Soil Moisture Variable Read
  
  //Returns True if Water is available or False if Water is not Available
  if(sm > 0){
    soilMoisture = false
  }else{
    soilMoisture = true
  }
  
  //Prints the Reading Variables
  Serial.println(t);
  Serial.println(h);
  Serial.println(soilMoisture);
  
  //Variables that are sent to the Ardunio Cloud
  temperature = t
  humidity = h
  soil = soilMoisture
}