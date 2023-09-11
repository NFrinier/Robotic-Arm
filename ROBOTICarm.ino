#include <Servo.h>

Servo Servo1; 
Servo Servo2;
Servo Servo3;

int servoPin1 = 12; 
int servoPin2 = 11;
int servoPin3 = 10;

int reps = 1;

int angle1 = 120;
int angle2 = 180;
int angle3 = 90;

int count = 0;

void setup() {
  // put your setup code here, to run once:
  Servo1.attach(servoPin1); // attaches the servo variable to the servo pin
  Servo2.attach(servoPin2);
  Servo3.attach(servoPin3);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(25);
  angle1 -= 10;
  angle2 -= 10;
  //angle3 += 1;

  if(angle1 == 50)
  {
    angle1 = 120;
  }

  if(angle2 == 110)
  {
    angle2 = 180;

    while(true)
    {
        delay(25);
        angle3 -= 10;
        Servo3.write(angle3);
        if(angle3 == 0)
        {
          
          delay(5000);
          angle3 = 90;
          Servo3.write(angle3);
          Servo2.write(angle2);
          Servo1.write(angle1);
          delay(2000);
          break;
        }
       
    }
  }
//  if(angle3 == 180)
 // {
  //  angle3 = 0;
  //}

  Servo1.write(angle1); 
  Servo2.write(angle2);
  if(angle1 == 120 && angle2 == 180)
  {
    count++;
    if(count == reps)
    {
      Servo1.write(120);
      Servo2.write(180);
      Servo3.write(90);
      delay(1000);
      exit(0);
    }
  }
  
}