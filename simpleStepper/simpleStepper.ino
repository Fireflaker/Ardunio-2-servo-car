
#include <Servo.h>

#include <HCSR04.h>


UltraSonicDistanceSensor l(4, 5);
UltraSonicDistanceSensor r(6, 7);

//
// On/off button setup
//
#define BUTTON_PIN 8
bool runCar = true;

//
// Servo setup
//
#define RIGHT_WHEEL_PIN 11
#define LEFT_WHEEL_PIN 10
#define RIGHT_WHEEL_STOP_POSITION 94
#define LEFT_WHEEL_STOP_POSITION 95
Servo rightWheel;
Servo leftWheel;

int vl = 0;
int vr = 0;

int turnval = 0;


void setup()
{

  rightWheel.attach(RIGHT_WHEEL_PIN);
  leftWheel.attach(LEFT_WHEEL_PIN);

  Stop();
  Serial.begin(115200);

}

void loop()
{

  vl = l.measureDistanceCm();
  vr = r.measureDistanceCm();

  Serial.print("left:");
  Serial.print(vl);
  Serial.print("   right:");
  Serial.println(vr);

  if (vl < 50 && vr < 50 && vl > 0 && vr > 0) {


    if ((vl - vr) > 5)
    {
      LeftTurn();
    }
    else if ((vl - vr) < -5)
    {
      RightTurn();
    }
    else
    {
      Forward();
    }
  }
  else
  {
    Serial.println("Bad condition. Not moving");
    SlowForward();
    
  }


}



void Forward()
{
  Serial.println("Forward");
  rightWheel.write(RIGHT_WHEEL_STOP_POSITION + 10);
  leftWheel.write(LEFT_WHEEL_STOP_POSITION - 10);
}

void SlowForward()
{
  Serial.println("SlowForward");
  rightWheel.write(RIGHT_WHEEL_STOP_POSITION + 2);
  leftWheel.write(LEFT_WHEEL_STOP_POSITION - 2);
}

void RightTurn()
{
  Serial.println("Turn Right");
  rightWheel.write(RIGHT_WHEEL_STOP_POSITION + 10);
  leftWheel.write(LEFT_WHEEL_STOP_POSITION + 10);
}

void LeftTurn()
{
  Serial.println("Turn Left");
  rightWheel.write(RIGHT_WHEEL_STOP_POSITION - 10);
  leftWheel.write(LEFT_WHEEL_STOP_POSITION - 10);
}

void Stop()
{
  Serial.println("Stop");
  rightWheel.write(RIGHT_WHEEL_STOP_POSITION);
  leftWheel.write(LEFT_WHEEL_STOP_POSITION);
}

