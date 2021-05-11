int BUZZER = 13.;      // selecciona el pin para el zumbador
int FLAME = 2;  // selecciona el pin del sensor
void setup() {
 //Seteo de la velocidad del puerto serial
 Serial.begin(9600);
 // declarar buzzer como una SALIDA:
  pinMode(BUZZER, OUTPUT);
  pinMode(FLAME, INPUT);
}
void loop() {
  
  digitalWrite(BUZZER,digitalRead(FLAME));
 }
