#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "********************************";

// This function will be called every time
// when App writes value to Virtual Pin 1
BLYNK_WRITE(V1)
{
  int i = param.asInt();

  if(i==1) digitalWrite ( D1, HIGH );
  else digitalWrite ( D1, LOW );
}

BLYNK_WRITE(V2)
{
  int i = param.asInt();

  if(i==1) digitalWrite ( D2, HIGH );
  else digitalWrite ( D2, LOW );
}

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  pinMode(D1, OUTPUT );
  digitalWrite(D1, LOW);
  pinMode(D2, OUTPUT );
  digitalWrite(D2, LOW); 
  
  Blynk.begin(auth, "mon_ssid", "mon_mot_de_passe"); //insert here your SSID and password
  
  while (Blynk.connect() == false) {
    // Wait until connected
  }

}

void loop()
{
  Blynk.run();
}
