//Munchi Code - bookdude13

#define RELAY 12
#define SWITCH 7
#define THERM A0
#define DELAY 500

#define THERMISTORVALUE 100000
#define SERIESRESISTOR 47000
#define BCOEFFICIENT 4072

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
 
  //temperature = read_temp();
  //Serial.println(temperature);

  read_temp();
  delay(DELAY);
}

double read_temp()
{
  double reading = analogRead(THERM);
  Serial.print("Analog Reading: ");
  Serial.println(reading);

  reading = (1023 / reading) -1;
  reading = SERIESRESISTOR / reading;
  Serial.print("Thermistor Resistance: ");
  Serial.println(reading);

  double temp = reading / THERMISTORVALUE;
  temp = log(temp);
  temp /= BCOEFFICIENT;
  temp += 1.0 / (THERMISTORVALUE + 273.15);
  temp = 1.0 / temp;
  temp -= 273.15;

  Serial.print("Temperature ");
  Serial.print(temp);
  Serial.println(" *C");

  
  //return (1.0 / ((3.3 / 1023.0) * temp));
}



