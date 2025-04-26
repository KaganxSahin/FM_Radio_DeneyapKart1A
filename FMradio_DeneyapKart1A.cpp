#include <Wire.h>
#include <TEA5767Radio.h>
#include <Deneyap_OLED.h>    

#define POT_PIN A0        
#define MIN_FREQUENCY 87.5
#define MAX_FREQUENCY 108.0

TEA5767Radio radio;
OLED OLED;    
float lastFrequency = 0.0;

void setup() {
  
  Serial.begin(115200);
  Wire.begin();

  if(!OLED.begin(0x7A)){                              
     delay(3000);
     Serial.println("I2C bağlantısı başarısız");    
    }
    
  delay(500); 
  
  float initialFrequency = 99.5; 
  radio.setFrequency(initialFrequency);
  lastFrequency = initialFrequency;

  Serial.println("FM Radyo Baslatildi (FM Radio Started)");
  Serial.print("Baslangic Frekansi(Starting Frequency:): ");
  Serial.print(initialFrequency);
  Serial.println(" MHz");
}

void loop() {
  
  int potValue = analogRead(POT_PIN);
  float newFrequency = map(potValue, 0, 1023, MIN_FREQUENCY * 10, MAX_FREQUENCY * 10) / 10.0;
  newFrequency = round(newFrequency * 10) / 10.0;

  if (abs(newFrequency - lastFrequency) >= 0.1) {
    lastFrequency = newFrequency;
    radio.setFrequency(newFrequency);

    Serial.print("Frekans Ayarlandı(Frequency Set): ");
    Serial.print(newFrequency);
    Serial.println(" MHz");

    OLED.clearDisplay();               
    OLED.setTextXY(2, 4);               
    OLED.putString("FREKANS");        
    OLED.setTextXY(4, 3);               
    OLED.putFloat(newFrequency);                       
    OLED.putString(" MHz");             

  }

  delay(200);
}