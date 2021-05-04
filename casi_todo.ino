
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//I2C pins declaration for LCD
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 

// Servo Config
Servo enteryservo;
Servo exitservo;
int enterypos = 180;
int exitpos = 90;

// IR Config
int enteryIrPin = 12; int enteryIr = HIGH;
int exitIrPin = 11; int exitIr = HIGH;
int slotAIrPin = 7; int slotAIr = HIGH;
int slotBIrPin = 8; int slotBIr = HIGH;
int slotCIrPin = 9; int slotCIr =HIGH;
int slotDIrPin = 10;  int slotDIr = HIGH;

// entery Gate Led Config
int gateGLED = 6;
int gateRLED = 13;

// LDR Config & Lighting
int LDRPin = A2;
int LightLEDPin = 5;
int LDRValue = 0;

// Slot Status LED




void setup() 
{
  Serial.begin(9600);
// LCD Setup
lcd.begin(16,2);//Defining 16 columns and 2 rows of lcd display
lcd.backlight();//To Power ON the back light

//Servo Setup
enteryservo.attach(A0); 
exitservo.attach(A1);
enteryservo.write(5);
// IR Pin Setup
pinMode(enteryIrPin, INPUT);
pinMode(exitIrPin, INPUT);
pinMode(slotAIrPin, INPUT);
pinMode(slotBIrPin, INPUT);
pinMode(slotCIrPin, INPUT);
pinMode(slotDIrPin, INPUT);

//Gate LED setup
pinMode(gateGLED, OUTPUT);
pinMode(gateRLED, OUTPUT);

// Lighting Setup
pinMode(LightLEDPin, OUTPUT);


}

void loop() 
{  
// Check Slot 
int slotAval = digitalRead(slotAIrPin);
int slotBval = digitalRead(slotBIrPin);
int slotCval = digitalRead(slotCIrPin);
int slotDval = digitalRead(slotDIrPin);

   // Check Slot A
if (slotAval == 0)
    {
    digitalWrite(gateRLED, HIGH);
    Serial.println("Slot A BUSY");
    lcd.setCursor(0,0);
    lcd.print("SlotA=");
    lcd.setCursor(6,0);
    lcd.print("1");
    lcd.setCursor(7,0);
    lcd.print(",");
    delay(100);
    }
else{
    Serial.println("Slot A clear");
    digitalWrite(gateRLED, LOW);
    lcd.setCursor(0,0);
    lcd.print("SlotA=");
    lcd.setCursor(6,0);
    lcd.print("0");
    lcd.setCursor(7,0);
    lcd.print(",");
    delay(100);
    }
    // Check Slot B
if (slotBval == 0)
    {
    //digitalWrite(gateRLED, HIGH);
    Serial.println("Slot B BUSY");
    lcd.setCursor(9,0);
    lcd.print("SlotB=");
    lcd.setCursor(15,0);
    lcd.print("1");
    delay(100);
    }
else{
    Serial.println("Slot B clear");
    //digitalWrite(gateRLED, LOW);
    lcd.setCursor(9,0);
    lcd.print("SlotB=");
    lcd.setCursor(15,0);
    lcd.print("0");
    delay(100);
   }
   // Check Slot C
if (slotCval == 0)
    {
    //digitalWrite(gateRLED, HIGH);
    Serial.println("Slot C BUSY");
    lcd.setCursor(0,1);
    lcd.print("SlotC=");
    lcd.setCursor(6,1);
    lcd.print("1");
    lcd.setCursor(7,1);
    lcd.print(",");
    delay(100);
    }
else{
    Serial.println("Slot C clear");
    //digitalWrite(gateRLED, LOW);
    lcd.setCursor(0,1);
    lcd.print("SlotC=");
    lcd.setCursor(6,1);
    lcd.print("0");
    lcd.setCursor(7,1);
    lcd.print(",");
    delay(100);
    }
    // Check Slot D
if (slotDval == 0)
    {
    //digitalWrite(gateRLED, HIGH);
    Serial.println("Slot D BUSY");
    lcd.setCursor(9,1);
    lcd.print("SlotD=");
    lcd.setCursor(15,1);
    lcd.print("1");
    delay(100);
    }
else{
    Serial.println("Slot D clear");
    //digitalWrite(gateRLED, LOW);
    lcd.setCursor(9,1);
    lcd.print("SlotD=");
    lcd.setCursor(15,1);
    lcd.print("0");
    delay(100);
    }
//==============================================================================================================================
    //Case Park Full
if(   !(digitalRead(enteryIrPin)) && !(digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Full No Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(2,1);
   lcd.print("Parking Full");
   digitalWrite(gateGLED, LOW);
   digitalWrite(gateRLED, HIGH);
   delay(5000);
   lcd.clear();  
     }
//===============================================================================================================================
   //Case Park Avalibale 1
if(   !(digitalRead(enteryIrPin)) && !(digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//================================================================================================================================     
          //Case Park Avalibale 2
if(   !(digitalRead(enteryIrPin)) && !(digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//====================================================================================================================================
     //Case Park Avalibale 3
if(   !(digitalRead(enteryIrPin)) && !(digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//=====================================================================================================================================     
     //Case Park Avalibale 4
if(   !(digitalRead(enteryIrPin)) && !(digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//========================================================================================================================================
     //Case Park Avalibale 5
if(   !(digitalRead(enteryIrPin)) && !(digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//==================================================================================================================================
     //Case Park Avalibale 6
if(   !(digitalRead(enteryIrPin)) && !(digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//=======================================================================================================================================
     //Case Park Avalibale 7
if(   !(digitalRead(enteryIrPin)) && !(digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//========================================================================================================================================
     //Case Park Avalibale 8
if(   !(digitalRead(enteryIrPin)) && (digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//==========================================================================================================================================
     //Case Park Avalibale 9
if(   !(digitalRead(enteryIrPin)) && (digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//=====================================================================================================================================
     //Case Park Avalibale 10
if(   !(digitalRead(enteryIrPin)) && (digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//=====================================================================================================================================
     //Case Park Avalibale 11
if(   !(digitalRead(enteryIrPin)) && (digitalRead(slotAIrPin)) && !(digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//=================================================================================================================================
     //Case Park Avalibale 12
if(   !(digitalRead(enteryIrPin)) && (digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//=================================================================================================================================
     //Case Park Avalibale 13
if(   !(digitalRead(enteryIrPin)) && (digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && !(digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//==================================================================================================================================
     //Case Park Avalibale 14
if(   !(digitalRead(enteryIrPin)) && (digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && !(digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }
//===================================================================================================================================
     //Case Park Avalibale 15
if(   !(digitalRead(enteryIrPin)) && (digitalRead(slotAIrPin)) && (digitalRead(slotBIrPin)) && (digitalRead(slotCIrPin)) && (digitalRead(slotDIrPin)))   
     {
     Serial.println("Welcome, Parking Available Slots");  //print slot1 and slo2 available
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("wlecome");
   lcd.setCursor(0,1);
   lcd.print("Parking Avilable");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   enteryservo.write(90); 
   delay(5000);
   enteryservo.write(5);
   lcd.clear();
   }  
      
//=============================================================================================================================      
  // case car leaving
  if( !(digitalRead(exitIrPin)))    // no input detected
        { Serial.println("Good Bye");  
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("Good Bye");
   lcd.setCursor(3,1);
   lcd.print("Drive Safe");
   digitalWrite(gateGLED, HIGH);
   digitalWrite(gateRLED, LOW);
   exitservo.write(5); 
   delay(5000);
   exitservo.write(90);
   lcd.clear();
        }
//==============================================================================================================================
// Lighting 
 LDRValue = analogRead(LDRPin);
  if (LDRValue>= 200){
    digitalWrite(LightLEDPin, HIGH);
  }else{digitalWrite(LightLEDPin, LOW);}
//==============================================================================================================================        
  }    
