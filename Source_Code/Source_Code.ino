/*  IR Remote With Servo Motor
 * 
 *  GitHub URL - https://github.com/narayanvyas/Arduino-IR-Remote-With-Servo-Motor
 * 
 *  Developed By Web Dev Fusion
 *  URL - https://www.webdevfusion.com
 *  
 * Components
 * ----------
 *  - Arduino Uno
 *  - IR Receiver Module
 *  - IR Remote
 *  - Jumper Wires
 *  - Breadboard / PCB
 *  - Servo Motor
 *  - 2 LEDs
 *  - 2 x 220 Ohm Resistors
 *  
 *  Libraries
 *  ---------
 *  - IRRemote - https://github.com/z3t0/Arduino-IRremote (Search In Library Manager)
 *  
 */

#include "IRremote.h"
#include <Servo.h>

int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11
int servoPin = 10;       // Servo Pin
Servo Servo1;  

IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);
  Serial.println("IR Receiver Button Decode"); 
  irrecv.enableIRIn(); // Start the receiver
  Servo1.attach(servoPin);
  pinMode(6, OUTPUT);    //Red LED
  pinMode(7, OUTPUT);     //Green LED
}

void loop()
{
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}

void translateIR() // takes action based on IR code received
// describing Remote IR codes 

{
  switch(results.value)
  {
    case 16753245:
      Serial.println("1 Pressed");
      Servo1.write(20);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      break;
    case 16736925:
      Serial.println("2 Pressed");
      Servo1.write(40);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      break;
    case 16769565:
    case 4294967295:
      Serial.println("3 Pressed");
      Servo1.write(60);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      break;
    case 16720605:
      Serial.println("4 Pressed");
      Servo1.write(80);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      break;
    case 16712445:
      Serial.println("5 Pressed");
      Servo1.write(100);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      break;
    case 16761405:
      Serial.println("6 Pressed");
      Servo1.write(120);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      break;
    case 16769055:
      Serial.println("7 Pressed");
      Servo1.write(140);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      break;
    case 16754775:
    case 2747854299:
    case 255:
      Serial.println("8 Pressed");
      Servo1.write(160);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      break;
    case 16748655:
      Serial.println("9 Pressed");
      Servo1.write(180);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      break;
    case 16750695:
      Serial.println("0 Pressed");
      Servo1.write(0);
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      break;
    default: 
      Serial.println("Wrong Button");
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6, LOW);
      break;
  }
  delay(500);
} 
