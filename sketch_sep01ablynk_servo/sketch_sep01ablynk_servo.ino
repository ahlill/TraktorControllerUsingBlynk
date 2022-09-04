#include <Servo.h>

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLRAFc2hIL"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "fJow4oTTz0HULR9crDzIJGwCmeUNQ0k/6" // rem /


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
#define kanan 13
#define kiri 14

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

//wifi dan password
char ssid[] = "Redmi";
char pass[] = "qwertyuiop123";

int putar = 0;

Servo servoKanan; //Deklarasi Kontrol Servo Kanan
Servo servoKiri; //Deklarasi Kontrol Servo Kanan

BLYNK_WRITE(V0) {
  servoKanan.write(param.asInt());
  Serial.print("V0 = ");
  Serial.println(param.asInt());
}
BLYNK_WRITE(V1) {
  servoKiri.write(param.asInt());
  Serial.print("V1 = ");
  Serial.println(param.asInt());
}

void setup() { //Pengaturan Pin dan Variabel
  Serial.begin(9600);
  
 Blynk.begin(auth, ssid, pass);
 pinMode(kanan, OUTPUT);
  pinMode(kiri, OUTPUT);
  
  servoKanan.attach(kanan);
  servoKiri.attach(kiri);
}

void loop() { 
  Blynk.run();
}
