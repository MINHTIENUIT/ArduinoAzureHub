#include "map_pin.h"
#include <ArduinoJson.h>
#define ONE_WIRE_BUS D7

void sensor_init();
float getTemperature();
JsonObject getValueSensor();
