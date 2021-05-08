#include <DFRobotDFPlayerMini.h>
#include <Servo.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void alcolimetro();

int valor_limite= 400;                  // Fija el valor limite en el que se activa la alarma    
float valor_alcohol;                    // Fij el valor despues de visualizar el nivel con el Monitor Serial

// Servo Config
Servo exitservo;

// IR Config
int exitIRpin = 3; int exitIR = HIGH; //pin del IR y estado

//LED Config
int ledexitOK = 5; //led verde
int ledexitF = 4; //led rojo

void setup() { 
  Serial.begin(9600);                   // Activa el puerto Serial a 9600 Baudios
  Serial.begin(115200); // comunicacion arduino y pc

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println("ERROR!!!!!");
    while(true);
  }
  Serial.println("Modulo Funcionando");

  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  // myDFPlayer.play(1);  //Play the first mp3

  //Servo Setup
  exitservo.attach(A1);
  exitservo.write(5);
  
  // IR Pin Setup
  pinMode(exitIRpin, INPUT);

  //LEDS
   pinMode(ledexitOK, OUTPUT);//le decimos que el led pin 26 será de salida
   pinMode(ledexitF, OUTPUT);//le decimos que el led pin 26 será de salida
}

void loop()
{ 
  digitalWrite(ledexitF, HIGH);//led rojo se enciende
  if (!(digitalRead(exitIRpin)))
  {
    Serial.println("Good Bye1"); 
    alcolimetro();
    Serial.println("Good Bye2"); 
  }
  
}

void alcolimetro()
{
  valor_alcohol=analogRead(A0);        // Pin A0 del analogico para sensor alcolemia 
  Serial.println(valor_alcohol);       // Envia al Serial el valor leido del Sensor MQ3 
  float porcentaje=(valor_alcohol/10000);  //calcula el porcentaje
  Serial.println(porcentaje);            // Envia al Serial el porcentaje 
  Serial.println(' ');    
  
  if(valor_alcohol > valor_limite)    // Si la medida de gas metano es mayor de valor limite
  {
    myDFPlayer.play(1); //primera cancion donde rechazamos la salida del parking
    delay(50);
    myDFPlayer.pause();  //pause the mp3
    delay(50);
    //digitalWrite(ledexitF, HIGH);//led rojo se mantiene encendido
   }
   else   // Si es menor del valor limite apaga el Zumbador
   {                                
      myDFPlayer.play(2); //Segunda cancion donde permitimos la salida del parking
      delay(50);
      myDFPlayer.pause();  //pause the mp3
      delay(50);
      digitalWrite(ledexitF, LOW);//led rojo se apaga
      digitalWrite(ledexitOK, HIGH);//led verde se enciende
      exitservo.write(5);
      delay(5000);
      exitservo.write(90);
      digitalWrite(ledexitF, HIGH);//led rojo se enciende       
    }
    delay(400);                          // Espera 300ms para realizar la proxima medida
}
  
