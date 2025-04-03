#include <WiFi.h>
/* Fill in information from your Blynk Template here */
#define BLYNK_TEMPLATE_ID "TMPL6kwo-MW4I"
#define BLYNK_TEMPLATE_NAME "SLTMNIT Remote LED"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG
#include "BlynkEdgent.h"

BLYNK_WRITE(V0)
{
  if(param.asInt()==1){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);  
}

void setup()
{
  pinMode(2, OUTPUT); // Initialise digital pin 2 as an output pin
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}

