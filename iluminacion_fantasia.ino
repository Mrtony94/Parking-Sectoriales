#include <Adafruit_NeoPixel.h>

#define TRIG 4
#define ECHO 5
int num_leds = 8;
Adafruit_NeoPixel tira=Adafruit_NeoPixel (num_leds, 2, NEO_GRB+NEO_KHZ800);

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
  distancia = duracion/58,3;
  Serial.println(distancia);

  if(distancia <= 25){
       //Apagar los leds, por si había alguna encendida
    tira.setBrightness(100);    //Intensidad del color
    tira.setPixelColor(0,255,255,0);    //Led número 0, color blanco
    tira.setPixelColor(1,255,255,0);    //Led número 1, color blanco
    //...
    tira.show();
  }
  if(distancia > 25 && distancia <= 50){
      
    tira.setBrightness(100);  
    tira.setPixelColor(2,255,0,255);
    tira.setPixelColor(3,255,0,255);
     //...
    tira.show();
  }
  if(distancia > 50 && distancia <= 70){
      
    tira.setBrightness(100);  
    tira.setPixelColor(4,0,0,255);
    tira.setPixelColor(5,0,0,255);
     //...
    tira.show();
  }
  if(distancia > 70 && distancia <= 90){
      
    tira.setBrightness(100);  
    tira.setPixelColor(6,255,0,255);
    tira.setPixelColor(7,255,0,255);
     //...
    tira.show();
  }
  if (distancia > 90){
    tira.clear();
    tira.show();
  }
}
