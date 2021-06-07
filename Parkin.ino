#include <Servo.h>

//SENSOR FUEGO
int BUZZER = 41;      // selecciona el pin para el zumbador
int FLAME = 35;  // selecciona el pin del sensor

// IR Config


int slotAIrPin = 3; int slotAIr = HIGH;
int slotBIrPin = 4; int slotBIr = HIGH;
int slotCIrPin = 5; int slotCIr =HIGH;
int slotDIrPin = 6;  int slotDIr = HIGH;

int slotOUTIrPin = 53; int slotOUTIr = HIGH;
int slotINIrPin = 52; int slotINIr = HIGH;

// entery Gate Led Config
int gateGLEDA = 10;
int gateRLEDA = 15;

int gateGLEDB = 16;
int gateRLEDB = 17;

int gateGLEDC = 18;
int gateRLEDC = 19;

int gateGLEDD = 20;
int gateRLEDD = 21;

// Servo Config
Servo outservo;
Servo inservo;



void setup() 
{
  //SERVO
  Serial.begin(9600);                   // Activa el puerto Serial a 9600 Baudios

 // declarar buzzer como una SALIDA:
  pinMode(BUZZER, OUTPUT);
  pinMode(FLAME, INPUT);
  

  outservo.attach(44);
  outservo.write(0);
  inservo.attach(43);
  inservo.write(0);

  //LEDS
  pinMode(slotINIrPin, INPUT);
  pinMode(slotOUTIrPin, INPUT); 
  
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
//check in
int slotINval = digitalRead(slotINIrPin);
if (slotINval == 0)
    {

    Serial.println("Slot IN Busy");
    inservo.write(80);
    delay(100);
    }
else{
    Serial.println("Slot IN clear");
    inservo.write(5);
    delay(100);
    }
 int slotOUTval = digitalRead(slotOUTIrPin);
if (slotOUTval == 0)
    {
    Serial.println("Slot OUT Busy");
    outservo.write(5);
    delay(100);
    }
else{
    Serial.println("Slot OUT clear");

    outservo.write(80);
    delay(100);
    } 
  // Check Slot 
int slotAval = digitalRead(slotAIrPin);
if (slotAval == 0)
    {
    digitalWrite(gateRLEDA, HIGH);
    digitalWrite(gateGLEDA, LOW);
    Serial.println("Slot A BUSY");
    delay(100);
    }
else{
    Serial.println("Slot A clear");
    digitalWrite(gateGLEDA, HIGH);
    digitalWrite(gateRLEDA, LOW);
    delay(100);
    }
int slotBval = digitalRead(slotBIrPin);
if (slotBval == 0)
    {
    digitalWrite(gateRLEDB, HIGH);
    digitalWrite(gateGLEDB, LOW);
    Serial.println("Slot B BUSY");
    delay(100);
    }
else{
    Serial.println("Slot B clear");
    digitalWrite(gateGLEDB, HIGH);
    digitalWrite(gateRLEDB, LOW);
    delay(100);
    }
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
 
}
