#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include <Wire.h>

// Set I2C bus to use: Wire, Wire1, etc.
#define WIRE Wire


float temperature;
float humidity;
float pressure;

#define ALTITUDE 0

Adafruit_BME280 bme; // I2C

void setup(void) {
 Serial.begin(9600);
    WIRE.begin();

 
  while (!Serial)
     delay(10);
  Serial.println("\nI2C Scanner");
  scan_i2c();
  
  bool status;
    
   // default settings
    status = bme.begin(0x76);  //The I2C address of the sensor I use is 0x76
    if (!status) {
        Serial.print("Sensor not working, check connections");
        while (1);
    }
}

void scan_i2c()
{
 


byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    WIRE.beginTransmission(address);
    error = WIRE.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");


}

void loop() {
  
 delay(2000);

getPressure();
getHumidity();
getTemperature();
 
  
 
 //Printing Temperature
 String temperatureString = String(temperature,1);
 Serial.write("T:"); 
 Serial.print(temperatureString);
 Serial.write((char)223);
 Serial.write("C ");
 Serial.println();
 
 //Printing Humidity
 String humidityString = String(humidity,0); 
 Serial.write("H: ");
 Serial.print(humidityString);
 Serial.write("%");
 Serial.println();
 
 //Printing Pressure
 Serial.write("P: ");
 String pressureString = String(pressure,2);
 Serial.print(pressureString);
 Serial.write(" hPa");
 Serial.println();
}

float getTemperature()
{
  temperature = bme.readTemperature();
}

float getHumidity()
{
  humidity = bme.readHumidity();
}

float getPressure()
{
  pressure = bme.readPressure();
  pressure = bme.seaLevelForAltitude(ALTITUDE,pressure);
  pressure = pressure/100.0F;
}
