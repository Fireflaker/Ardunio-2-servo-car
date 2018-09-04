
#include <Servo.h>

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


void setup()
{
  pinMode(BUTTON_PIN, OUTPUT);

  rightWheel.attach(RIGHT_WHEEL_PIN);
  leftWheel.attach(LEFT_WHEEL_PIN);

  Stop();
  Serial.begin(115200);

  Forward();
  delay(7400);
  RightTurn();
  delay(585);
  Forward();
  delay(4100);
  RightTurn();
  delay(580);
  Forward();
  delay(2000);
  RightTurn();
  delay(585);
  Forward();
  delay(2550);
  LeftTurn();
  delay(580);
  Forward();
  delay(800);
  LeftTurn();
  delay(560);
    Forward();
  delay(2550);
  RightTurn();
  delay(800);
   Forward();
  delay(5550);


}

void loop()
{
  Stop();


}




void Forward()
{
  Serial.println("Forward");
  rightWheel.write(RIGHT_WHEEL_STOP_POSITION + 10);
  leftWheel.write(LEFT_WHEEL_STOP_POSITION - 10);
}

void RightTurn()
{
  Serial.println("Backwards with turn");
  rightWheel.write(RIGHT_WHEEL_STOP_POSITION + 10);
  leftWheel.write(LEFT_WHEEL_STOP_POSITION + 10);
}

void LeftTurn()
{
  Serial.println("Backwards with turn");
  rightWheel.write(RIGHT_WHEEL_STOP_POSITION - 10);
  leftWheel.write(LEFT_WHEEL_STOP_POSITION - 10);
}

void Stop()
{
  Serial.println("Stop");
  rightWheel.write(RIGHT_WHEEL_STOP_POSITION);
  leftWheel.write(LEFT_WHEEL_STOP_POSITION);
}

