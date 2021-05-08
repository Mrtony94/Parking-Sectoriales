
#include <Adafruit_NeoPixel.h>

#define TRIG 4
#define ECHO 5
int num_leds = 5;
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

  if(distancia <= 5){
    tira.clear();   //Apagar los leds, por si había alguna encendida
    tira.setBrightness(100);    //Intensidad del color
    tira.setPixelColor(0,255,255,255);    //Led número 0, color blanco
    tira.setPixelColor(1,255,255,255);    //Led número 1, color blanco
    //...
    tira.show();
  }
  if(distancia > 5 && distancia <= 10){
    tira.clear();  
    tira.setBrightness(100);  
    tira.setPixelColor(2,255,255,255);
    tira.setPixelColor(3,255,255,255);
     //...
    tira.show();
  }
}
