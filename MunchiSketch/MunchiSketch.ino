//Munchi Code - bookdude13

#define RELAY 12
#define SWITCH 7
#define THERM A0
#define DELAY 500

double temperature = 0.0;

void setup()
{
  pinMode(RELAY, OUTPUT);
  pinMode(SWITCH, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // if (digitalRead(SWITCH)==HIGH)
  // {
  //   digitalWrite(RELAY, LOW); // LOW means on
  // }
  // else
  // {
  //   digitalWrite(RELAY, HIGH); // HIGH means off
  // }
  temperature = read_temp();
  Serial.println(temperature);
  delay(DELAY);
}

double read_temp()
{
  double temp = analogRead(THERM);
  return (1.0 / ((3.3 / 1023.0) * temp));
}



