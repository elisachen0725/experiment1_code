/*
Two Sensor Threshold

Builds on twoSensorSerial.
Instead of a smooth fade, each sensor has three steps: LOW, MEDIUM, HIGH.
Each step is a range with a Min and a Max, and has its own LED brightness.

Pin A1 : Sensor 1  ->  Pin 12 : LED 1
Pin A2 : Sensor 2  ->  Pin 27 : LED 2
*/

//Sensor variables
int sensor1Pin = A1;
int sensor1Value;

int sensor2Pin = A2;
int sensor2Value;

//The range for each step (0 - 4095)
//Anything outside the MEDIUM and HIGH ranges is LOW
// int sensor1MediumMin = 1000;
// int sensor1MediumMax = 2499;
int sensor1HighMin = 2500;
int sensor1HighMax = 4095;

// int sensor2MediumMin = 1600;
// int sensor2MediumMax = 1700;
int sensor2HighMin = 3500;
int sensor2HighMax = 4095;

//LED variables
int led1Pin = 12;
int led1Value;

int led2Pin = 27;
int led2Value;

//The brightness for each step (0 - 255)
int led1LowBrightness = 0;
//decided to remove medium brighness
// int led1MediumBrightness = 120; 
int led1HighBrightness = 255;

int led2LowBrightness = 0;
// int led2MediumBrightness = 120;
int led2HighBrightness = 255;

void setup()
{
  Serial.begin(9600);

  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop()
{
  //read both sensors (0 - 4095)
  sensor1Value = analogRead(sensor1Pin);
  sensor2Value = analogRead(sensor2Pin);

  //Sensor 1: pick a brightness based on which range it is in
  if (sensor1Value >= sensor1HighMin && sensor1Value <= sensor1HighMax)
  {
    led1Value = led1HighBrightness;
  }
  else
  {
    led1Value = led1LowBrightness;
  }

  //Sensor 2: same three steps with its own numbers
  //add led1 brightness here so it triggers both leds 
  if (sensor2Value >= sensor2HighMin && sensor2Value <= sensor2HighMax)
  {
    led2Value = led2HighBrightness;
    led1Value = led1HighBrightness;
  }
  else
  {
    led2Value = led2LowBrightness;
  }

  //set the LEDs
  analogWrite(led1Pin, led1Value);
  analogWrite(led2Pin, led2Value);

  //print the sensor and LED values on one line
  Serial.print("Sensor 1: ");
  Serial.print(sensor1Value);
  Serial.print("   LED 1: ");
  Serial.print(led1Value);
  Serial.print("   Sensor 2: ");
  Serial.print(sensor2Value);
  Serial.print("   LED 2: ");
  Serial.println(led2Value);
}
