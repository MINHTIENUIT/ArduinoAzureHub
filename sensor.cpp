#include "sensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>

static OneWire oneWire(ONE_WIRE_BUS);
static DallasTemperature DS18B20(&oneWire);

void sensor_init(){
  DS18B20.begin();
}

float getTemperature(){
  float tempC;  
  DS18B20.requestTemperatures(); 
  tempC = DS18B20.getTempCByIndex(0);
  delay(100);  
  return tempC;
}

JsonObject getValueSensor(){
   StaticJsonDocument<256> doc;
   JsonObject data = doc.to<JsonObject>();
   data["Temperature"] = getTemperature();
   return data;
}
