
#include <Servo.h>

//SENSOR FUEGO
int BUZZER = 41;      // selecciona el pin para el zumbador
int FLAME = 35;  // selecciona el pin del sensor

// IR Config
int slotAIrPin = 3; int slotAIr = HIGH; int gateGLEDA = 7; int gateRLEDA = 8;
int slotBIrPin = 4; int slotBIr = HIGH; int gateGLEDB = 9; int gateRLEDB = 10;
int slotCIrPin = 5; int slotCIr = HIGH; int gateGLEDC = 11; int gateRLEDC = 12;
int slotDIrPin = 6;  int slotDIr = HIGH; int gateGLEDD = 13; int gateRLEDD = 14;

//IR in & OUT
int slotOUTIrPin = 53; int slotOUTIr = HIGH; int ledoutOK = 20; int ledoutF = 21; 
int slotINIrPin = 52; int slotINIr = HIGH; int ledinOK = 22; int ledinF = 23; 


// Servo Config
Servo outservo;
Servo inservo;


void setup() 
{
  Serial.begin(9600);  // Activa el puerto Serial a 9600 Baudios

 // declarar buzzer como una SALIDA:
  pinMode(BUZZER, OUTPUT);
  pinMode(FLAME, INPUT);

//SERVOS
  outservo.attach(44);
  outservo.write(0);
  inservo.attach(43);
  inservo.write(0);

  //LEDS
   pinMode(ledinOK, OUTPUT); pinMode(ledinF, OUTPUT);
   pinMode(ledoutOK, OUTPUT); pinMode(ledoutF, OUTPUT);

  pinMode(slotINIrPin, INPUT); pinMode(slotOUTIrPin, INPUT); 
  
  pinMode(slotAIrPin, INPUT);
  pinMode(slotBIrPin, INPUT);
  pinMode(slotCIrPin, INPUT);
  pinMode(slotDIrPin, INPUT);

  //Gate LED setup
  pinMode(gateGLEDA, OUTPUT);
  pinMode(gateRLEDA, OUTPUT);
  
  pinMode(gateGLEDB, OUTPUT);
  pinMode(gateRLEDB, OUTPUT);
  
  pinMode(gateGLEDC, OUTPUT);
  pinMode(gateRLEDC, OUTPUT);
  
  pinMode(gateGLEDD, OUTPUT);
  pinMode(gateRLEDD, OUTPUT);

}

void loop() 
{  
  
//SERVO ENTRADA

int slotINval = digitalRead(slotINIrPin);
if (slotINval == 0)
    {
    digitalWrite(ledinF, HIGH);
    digitalWrite(ledinOK, LOW);
    Serial.println("Slot IN Busy");
    inservo.write(80);
    delay(1000);
    }
else{
    Serial.println("Slot IN clear");
    digitalWrite(ledinOK, HIGH);
    digitalWrite(ledinF, LOW);
    inservo.write(5);
    delay(100);
    }
    
//SERVO SALIDA

 int slotOUTval = digitalRead(slotOUTIrPin);
if (slotOUTval == 0)
    {
    digitalWrite(ledoutF, HIGH);
    digitalWrite(ledoutOK, LOW);
    Serial.println("Slot OUT Busy");
    outservo.write(5);
    delay(1000);
    }
else{
    Serial.println("Slot OUT clear");
    digitalWrite(ledoutOK, HIGH);
    digitalWrite(ledoutF, LOW);
    outservo.write(80);
    delay(100);
    } 

    
  // Check Slot A
int slotAval = digitalRead(slotAIrPin);
if (slotAval == 0)
    {
    digitalWrite(gateRLEDA, HIGH);
    digitalWrite(gateGLEDA, LOW);
    Serial.println("Slot A Ocupado");
    delay(100);
    }
else{
    Serial.println("Slot A Libre");
    digitalWrite(gateGLEDA, HIGH);
    digitalWrite(gateRLEDA, LOW);
    delay(100);
    }
    
//Check Slot B
int slotBval = digitalRead(slotBIrPin);
if (slotBval == 0)
    {
    digitalWrite(gateRLEDB, HIGH);
    digitalWrite(gateGLEDB, LOW);
    Serial.println("Slot B Ocupado");
    delay(100);
    }
else{
    Serial.println("Slot B Libre");
    digitalWrite(gateGLEDB, HIGH);
    digitalWrite(gateRLEDB, LOW);
    delay(100);
    }
//Check Slot C
int slotCval = digitalRead(slotCIrPin);
if (slotCval == 0)
    {
    digitalWrite(gateRLEDC, HIGH);
    digitalWrite(gateGLEDC, LOW);
    Serial.println("Slot C BUSY");
    delay(100);
    }
else{
    Serial.println("Slot C clear");
    digitalWrite(gateGLEDC, HIGH);
    digitalWrite(gateRLEDC, LOW);
    delay(100);
    }

//Check Slot D
int slotDval = digitalRead(slotDIrPin);
if (slotDval == 0)
    {
    digitalWrite(gateRLEDD, HIGH);
    digitalWrite(gateGLEDD, LOW);
    Serial.println("Slot D BUSY");
    delay(100);
    }
else{
    Serial.println("Slot D clear");
    digitalWrite(gateGLEDD, HIGH);
    digitalWrite(gateRLEDD, LOW);
    delay(100);
    }

 digitalWrite(BUZZER,digitalRead(FLAME));
 

//==============================================================================================================================
     //Case Park Full
 if(   !(digitalRead(slotINIr)) && !(digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
      {
    Serial.println("Welcome, Parking Full No Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, LOW);
//    digitalWrite(gateRLED, HIGH);
    delay( 3000); 
      }
 //===============================================================================================================================
    //Case Park Avalibale 1
 if(   !(digitalRead(slotINIr)) && !(digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
      {
    Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay(3000);
    inservo.write(5);
    }
 //================================================================================================================================     
           //Case Park Avalibale 2
 if(   !(digitalRead(slotINIr)) && !(digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
      {
    Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay(3000);
    inservo.write(5);
    }
 //====================================================================================================================================
      //Case Park Avalibale 3
 if(   !(digitalRead(slotINIr)) && !(digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
      {
    Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay(3000);
    inservo.write(5);
    }
 //=====================================================================================================================================     
      //Case Park Avalibale 4
 if(   !(digitalRead(slotINIr)) && !(digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
      {
    Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay(3000);
    inservo.write(5);
    }
 //========================================================================================================================================
      //Case Park Avalibale 5
 if(   !(digitalRead(slotINIr)) && !(digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
      {
    Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay(3000);
    inservo.write(5);
    }
 //==================================================================================================================================
      //Case Park Avalibale 6
 if(   !(digitalRead(slotINIr)) && !(digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
      {
      Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay( 3000);
    inservo.write(5);
    }
 //=======================================================================================================================================
      //Case Park Avalibale 7
 if(   !(digitalRead(slotINIr)) && !(digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
      {
      Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay( 3000);
    inservo.write(5);
    }
 //========================================================================================================================================
      //Case Park Avalibale 8
 if(   !(digitalRead(slotINIr)) && (digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
      {
      Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available

//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay( 3000);
    inservo.write(5);

    }
 //==========================================================================================================================================
      //Case Park Avalibale 9
 if(   !(digitalRead(slotINIr)) && (digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
      {
      Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay( 3000);
    inservo.write(5);
    }
 //=====================================================================================================================================
      //Case Park Avalibale 10
 if(   !(digitalRead(slotINIr)) && (digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
      {
      Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay( 3000);
    inservo.write(5);
    }
 //=====================================================================================================================================
      //Case Park Avalibale 11
 if(   !(digitalRead(slotINIr)) && (digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
      {
      Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay( 3000);
    inservo.write(5);
    }
 //=================================================================================================================================
      //Case Park Avalibale 12
 if(   !(digitalRead(slotINIr)) && (digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
      {
      Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay( 3000);
    inservo.write(5);
    }
 //=================================================================================================================================
      //Case Park Avalibale 13
 if(   !(digitalRead(slotINIr)) && (digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
      {
      Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay( 3000);
    inservo.write(5);
    }
 //==================================================================================================================================
      //Case Park Avalibale 14
 if(   !(digitalRead(slotINIr)) && (digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
      {
      Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay( 3000);
    inservo.write(5);
    }
 //===================================================================================================================================
      //Case Park Avalibale 15
 if(   !(digitalRead(slotINIr)) && (digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
      {
      Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    inservo.write(80); 
    delay(3000);
    inservo.write(5);
    }  

 //=============================================================================================================================      
   // case car leaving
   if( !(digitalRead(slotOUTIr)))    // no input detected
         { 
    Serial.println("Good Bye");  
//    digitalWrite(gateGLED, HIGH);
//    digitalWrite(gateRLED, LOW);
    outservo.write(5); 
    delay(3000);
    outservo.write(80);
    
         }
 //==============================================================================================================================        
   }    
