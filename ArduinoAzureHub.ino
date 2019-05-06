#include "iot_configs.h"
#include "WiFiManager.h"
#include "sensor.h"

#include <AzureIoTHub.h>
#if defined(IOT_CONFIG_MQTT)
    #include <AzureIoTProtocol_MQTT.h>
#elif defined(IOT_CONFIG_HTTP)
    #include <AzureIoTProtocol_HTTP.h>
#endif

#include "azure.h"


static char ssid[] = IOT_CONFIG_WIFI_SSID;
static char pass[] = IOT_CONFIG_WIFI_PASSWORD;

void setup() {
    WiFiConnect(ssid,pass);
    sensor_init();
}

// Azure IoT samples contain their own loops, so only run them once
static bool done = false;
void loop() {    
    {
        getTemperature();              
        azure_run();
    }              
}
