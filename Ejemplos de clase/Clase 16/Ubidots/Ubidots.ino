
#include <SPI.h>
#include <WiFi101.h>

#include <UbidotsArduino.h>
#define IDTEMP  "5cdaed631d84724f4fc065f8"  // Put here your Ubidots variable ID
#define IDHUM  "5cdaed711d84724fa2cc4286"  // Put here your Ubidots variable ID
#define TOKEN  "BBFF-71b9b7d9ac4bd0547fa14e7c8478460ae9e"  // Put here your Ubidots TOKEN
#define POTTEMP 0 // Temperature potentiometer 0
#define POTHUM 1 // Temperature potentiometer 1


char ssid[] = "IoT-B19"; //  your network SSID (name)
char pass[] = "meca2017*";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;            // your network key Index number (needed only for WEP)

float temperature = 0;
float humidity = 0;

int status = WL_IDLE_STATUS;

Ubidots client(TOKEN);

void setup(){
    Serial.begin(9600);
    // For now I don't need it.
    /**while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    // check for the presence of the shield:
    if (WiFi.status() == WL_NO_SHIELD) {
        Serial.println("WiFi shield not present");
        // don't continue:
        while (true);
    }

    String fv = WiFi.firmwareVersion();
    if (fv != "1.1.0") {
        Serial.println("Please upgrade the firmware");
    }
*/
    // attempt to connect to Wifi network:
    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        status = WiFi.begin(ssid, pass);

        // wait 10 seconds for connection:
        delay(10000);
    }
        
}

void loop(){
        temperature = analogRead(POTTEMP) * 100 / 1023.0;
        humidity = analogRead(POTHUM) * 100 / 1023.0;
        client.add(IDTEMP, value);
        client.add(IDHUM, value);
        client.sendAll();
}
