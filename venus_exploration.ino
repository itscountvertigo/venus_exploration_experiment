#include <Servo.h>

// 1300 clockwise, 1500 still, 1700 counterclockwise

Servo servoLeft;
Servo servoRight;

Servo servoGrabber;
Servo servoSensor;
 
void setup()
{
}  
 
void loop()
{
  spin_left(90);
  delay(1000);
}

void servo_attach()
{
  servoLeft.attach(12);
  servoRight.attach(13);

  servoGrabber.attach(10);
  servoSensor.attach(11);
}

void servo_detach()
{
  servoLeft.detach();
  servoRight.detach();

  servoGrabber.detach();
  servoSensor.detach();
}

void move_forward(int ms) 
{
  servo_attach();
  
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(ms);

  servo_detach();
}

void move_backward(int ms)
{
  servo_attach();
  
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(ms);

  servo_detach();
}
