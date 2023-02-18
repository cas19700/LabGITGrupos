/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/
#include <Servo.h>

//PInes del sensor ultrasónico
#define TRIG_PIN 8
#define ECHO_PIN 7

//Velocidad del sonido (cm/uS)
#define VELOCIDAD_S 0.0343

long duracion;
float distancia;
int mins; 



Servo myservo;  // Creamos el objeto de servo a utilizar
int pos = 0;    // Guarda la posicion del servo


int sensorPin = A0;   // Entrada del potenciometro
int ledPin = 13;      // Seleccionamos el pin para el LED
int ledprox = 4;
int sensorValue = 0;  // Variable analogica del sensor

// the setup function runs once when you press reset or power the board

void setup() {
  // Declaramos ledPin como salida:
  pinMode(ledPin, OUTPUT);
  myservo.attach(9);  // Se asigna la senal pwm del servo al pin 9
  
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIG_PIN, LOW);
  
  duracion = pulseIn(ECHO_PIN, HIGH);
  distancia = (duracion*VELODIDAD_S/2)*10;
  
  delay(80);
  

if (distancia > 5.00 && distancia < 500){
  digitalWrite(ledprox, HIGH); 
}
 
if (distancia < 5.00 || distancia > 500){
  digitalWrite(ledprox, LOW);
} 


  // Lectura analogica
  // Leemos el valor del sensor:
  sensorValue = analogRead(sensorPin);
  // Encendemos ledPin
  digitalWrite(ledPin, HIGH);
  // Detenemos el programa unos milisegundos dependiendo del valor analogico:
  delay(sensorValue);
  // Apagamos el ledPin:
  digitalWrite(ledPin, LOW);
  // Detenemos el programa unos milisegundos dependiendo del valor analogico:
  
  pos = map(sensorValue, 0, 1023, 0, 180);     // Se realiza el mapeo de la entrada del sensor analogico
  myservo.write(pos); 				// se cambia de posicion el servo de acuerdo a la frecuencia del delay de los leds
  
  delay(sensorValue);
  
  
}

