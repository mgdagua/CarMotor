#include <SoftwareSerial.h>

SoftwareSerial myApp(7,8); //7 es Rx y 8 es TX
  //RXD BLUETOOTH al pin 8
  //TXD BLUETOOTH AL PIN 7 

char myChar;
//Puente h
int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;
void setup() {
  Serial.begin(9600);
  myApp.begin(9600);
  Serial.println("Serial pc listo");
  myApp.println("App lista");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  while(myApp.available()){
    myChar=myApp.read();
    Serial.print(myChar);
    myApp.print(myChar);
    myApp.print("#");
    if(myChar=='U'){
      adelante();
    }
     if(myChar=='D'){
      atras();
    }
     if(myChar=='L'){
      izquierda();
    }
     if(myChar=='R'){
      derecha();
    }
     if(myChar=='p'){
      parar();
    }
  }
  while(Serial.available()){
    myChar=Serial.read();
    myApp.print(myChar);
    myApp.print("#");
  }
}

void adelante(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void atras(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void izquierda(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void derecha(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
void parar(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW); 
}
