#define SPEED1 11        //Defining the Enable pins 
#define SPEED2 10
#define SPEED3 6
#define SPEED4 5

#define mtr1in1 4       // Defining the in pins
#define mtr1in2 7
#define mtr2in1 2
#define mtr2in2 3
#define mtr3in1 8
#define mtr3in2 9
#define mtr4in1 12
#define mtr4in2 13



int jy1=0;     // AXIS of Joystick
int jy2=0;

char x;


void setup() {
  // put your setup code here, to run once:

  //Setting pins as OUTPUT and INPUTS
  for (int i=2; i<14; i=i+1){
    pinMode(i, OUTPUT);
  }
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  /*for (int k=2; k<5; k=k+1){   Setting all as low
    digitalWrite(k, LOW);
  }
  */
 

  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  jy1=analogRead(A0);
  jy2=analogRead(A2);
  x=Serial.read();
  if(x=='1'){ 

     digitalWrite(mtr3in1, LOW);
     digitalWrite(mtr3in2, LOW);
     digitalWrite(mtr4in1, LOW);
     digitalWrite(mtr4in2, LOW); // Pins that turn on the motor driver

    if(jy1<470){ // backwards
     jy1=map(jy1, 0, 470, 0, 255);
     analogWrite(SPEED1, jy1);
     digitalWrite(mtr1in1, HIGH);
     digitalWrite(mtr1in2, LOW);
     }
    else if(jy1>550){  // forward
     jy1=map(jy1, 550, 1023, 0, 255);
     analogWrite(SPEED1, jy1);
     digitalWrite(mtr1in1, LOW);
     digitalWrite(mtr1in2, HIGH);
    }
    else {
    digitalWrite(mtr1in1, LOW);
    digitalWrite(mtr1in2, LOW);
  }
     if(jy2<470){ // backwards
     jy2=map(jy2, 0, 470, 0, 255);
     analogWrite(SPEED2, jy2);
     digitalWrite(mtr2in1, HIGH);
     digitalWrite(mtr2in2, LOW);
     }
    else if(jy2>550){  // forward
     jy2=map(jy2, 550, 1023, 0, 255);
     analogWrite(SPEED2, jy2);
     digitalWrite(mtr2in1, LOW);
     digitalWrite(mtr2in2, HIGH);
    }
    else {
    digitalWrite(mtr2in1, LOW);
    digitalWrite(mtr2in2, LOW);
  }
  }
   if(x=='2'){ 

     digitalWrite(mtr1in1, LOW);
     digitalWrite(mtr1in2, LOW);
     digitalWrite(mtr2in1, LOW);
     digitalWrite(mtr2in2, LOW); // Pins that turn on the motor driver

    if(jy1<470){ // backwards
     jy1=map(jy1, 0, 470, 0, 255);
     analogWrite(SPEED3, jy1);
     digitalWrite(mtr3in1, HIGH);
     digitalWrite(mtr3in2, LOW);
     }
    else if(jy1>550){  // forward
     jy1=map(jy1, 550, 1023, 0, 255);
     analogWrite(SPEED3, jy1);
     digitalWrite(mtr3in1, LOW);
     digitalWrite(mtr3in2, HIGH);
    }
    else {
    digitalWrite(mtr3in1, LOW);
    digitalWrite(mtr3in2, LOW);
  }
     if(jy2<470){ // backwards
     jy2=map(jy2, 0, 470, 0, 255);
     analogWrite(SPEED4, jy2);
     digitalWrite(mtr4in1, HIGH);
     digitalWrite(mtr4in2, LOW);
     }
    else if(jy2>550){  // forward
     jy2=map(jy2, 550, 1023, 0, 255);
     analogWrite(SPEED4, jy2);
     digitalWrite(mtr4in1, LOW);
     digitalWrite(mtr4in2, HIGH);
    }
    else {
    digitalWrite(mtr4in1, LOW);
    digitalWrite(mtr4in2, LOW);
  }
  }
 
}
