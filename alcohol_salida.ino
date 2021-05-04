int valor_limite= 400;                  // Fiaja el valor limite en el que se activa la alarma    
float valor_alcohol;
                                        // Fije el valor despues de visualizar el nivel con el Monitor Serial
void setup() { 
  Serial.begin(9600);                   // Activa el puerto Serial a 9600 Baudios
  pinMode(13,OUTPUT);                   // Configura el Pin 13 como salida para el Zumbador
}

void loop() { 
  valor_alcohol=analogRead(A0);
  Serial.println(valor_alcohol);       // Envia al Serial el valor leido del Sensor MQ3 
  float porcentaje=(valor_alcohol/10000);  //calcula el porcentaje
  Serial.println(porcentaje);            // Envia al Serial el porcentaje 
  Serial.println(' ');    
  
  if(valor_alcohol > valor_limite){    // Si la medida de gas metano es mayor de valor limite
       digitalWrite(13, HIGH);          // Enciende el Zumbador conectado al Pin 13
   }
   else{                                // Si es menor del valor limite apaga el Zumbador
      digitalWrite(13, LOW); 
   }
  delay (400);                          // Espera 300ms para realizar la proxima medida
}
