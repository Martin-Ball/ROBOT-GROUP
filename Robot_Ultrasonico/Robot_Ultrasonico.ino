#include <Servo.h>          //Libreria del servo motor, esta es una libreria estandar
#include <NewPing.h>        //Libreria para manejar el sensor ultrasonico. Se debe instalar previamente esta librearia

//Pines de control de driver L298N 
const int LeftMotorForward = 5;
const int LeftMotorBackward = 7;
const int RightMotorForward = 4;
const int RightMotorBackward = 2;

//Pines de sensores
#define trig_pin 8 //analog input 1
#define echo_pin 8 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //funcion de sensor
Servo servo_motor; //nombre de nuestro servo

void setup(){

  

  //digitalWrite(LeftMotorForward, H)

//  INPUT 1 = 2 INPUT 2 = 4
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  //servo_motor.attach(11); //pin de nuestro servo

  //servo_motor.write(90);
  /*delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);*/

}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

    //  INPUT 1 = 2 INPUT 2 = 4 EN= 3
    //digitalWrite(2, LOW);
    //digitalWrite(4, HIGH);
  
    //digitalWrite(LeftMotorBackward, LOW);
    //digitalWrite(RightMotorBackward, LOW);
    
    //digitalWrite(3, HIGH);

        //  INPUT 3 = 5 INPUT 4 = 7 EN= 6

    //digitalWrite(5, HIGH);
    //digitalWrite(7, LOW);
  
    //digitalWrite(LeftMotorBackward, LOW);
    //digitalWrite(RightMotorBackward, LOW);
    
    //digitalWrite(6, HIGH);

   //moveForward();
   //delay(1000);
   //moveBackward();
  

  if (distance <= 20){
    moveStop();
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}

int lookRight(){  
  servo_motor.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 

    //  digitalWrite(2, LOW);
  //digitalWrite(4, HIGH);
  }
}

void moveBackward(){

  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}
