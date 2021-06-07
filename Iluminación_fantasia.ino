#include <Adafruit_NeoPixel.h>

#define TRIG 4
#define ECHO 5
int num_leds=28;
int PIN=8;
Adafruit_NeoPixel tira=Adafruit_NeoPixel (num_leds, PIN, NEO_GRB+NEO_KHZ800);

long duracion, distancia;
int i;

void setup(){
  tira.begin();   //Iniciar comunicación con la tira
  tira.show();
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(TRIG, LOW);  //Mandar onda ultrasonido limpia sin rebotes y medir la distancia del objeto
  delayMicroseconds(10);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duracion = pulseIn(ECHO, HIGH);
  distancia = duracion/58;
  Serial.println(distancia);

  if (distancia > 41) {
    tira.clear();
    tira.show();
  }
  
  if(distancia > 32 && distancia <= 40){
      
    tira.setBrightness(100);  
    tira.setPixelColor(3,0,0,255);
    tira.setPixelColor(4,0,0,255);
    tira.setPixelColor(5,0,0,255);
    tira.setPixelColor(6,0,0,255);
    tira.setPixelColor(7,0,0,255);
    tira.setPixelColor(8,0,0,255);

    tira.show();
  }
  if(distancia > 24 && distancia <= 32){
      
    tira.setBrightness(100);  
    tira.setPixelColor(9,0,0,255);
    tira.setPixelColor(10,0,0,255);
    tira.setPixelColor(11,0,0,255);
    tira.setPixelColor(12,0,0,255);
    tira.setPixelColor(13,0,0,255);
    tira.setPixelColor(14,0,0,255);

    tira.show();
  }
  if(distancia > 16 && distancia <= 24){
      
    tira.setBrightness(100);  
    tira.setPixelColor(15,0,0,255);
    tira.setPixelColor(16,0,0,255);
    tira.setPixelColor(17,0,0,255);
    tira.setPixelColor(18,0,0,255);
    tira.setPixelColor(19,0,0,255);
    tira.setPixelColor(20,0,0,255);

    tira.show();
  }
  if(distancia > 0 && distancia <= 16){
      
    tira.setBrightness(100);  
    tira.setPixelColor(21,0,0,255);
    tira.setPixelColor(22,0,0,255);
    tira.setPixelColor(23,0,0,255);
    tira.setPixelColor(24,0,0,255);
    tira.setPixelColor(25,0,0,255);
    tira.setPixelColor(26,0,0,255);
    tira.setPixelColor(27,0,0,255);
    
    tira.show();
  }

}
