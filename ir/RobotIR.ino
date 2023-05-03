#include <IRremote.h>

int IRPIN = A0;

decode_results results;
int button = 0;
boolean goesForward = false;


int valueIR = 0;

IRrecv receiver(IRPIN);

//Pines de control de driver L298N 
const int LeftMotorForward = 5;
const int LeftMotorBackward = 7;
const int RightMotorForward = 4;
const int RightMotorBackward = 2;

void setup(){
  Serial.begin(9600);

  receiver.enableIRIn();
  
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
}
void loop() {

  if (receiver.decode(&results)) {
    unsigned int value = results.value;

    Serial.print("VALUEE: ");
    Serial.println(value);

    switch(value){
      case 2070: {
        turnRight();
        delay(100);
        break;
      }
      case 2065: {
        moveBackward(); 
        Serial.print("MOVE BACKWARD - ");
        delay(500);
        break;
      }
      case 2069: {
        turnLeft();
        delay(100);
        break;
      }
      case 2064:{
        moveForward(); 
        break;
      } 
    }

    receiver.resume();

    moveStop();
  }
}

void moveStop(){

  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
    
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW); 

}

void moveBackward(){

  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnRight(){

  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  delay(250);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnLeft(){

  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  delay(250);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}