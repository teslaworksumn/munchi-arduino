//Munchi Code - bookdude13

#define RELAY 12
#define DELAY 500

double temperature = 0.0;

void setup()
{
  pinMode(RELAY, OUTPUT);
}

void loop()
{
//  digitalWrite(RELAY, LOW); // LOW means on 
  digitalWrite(RELAY, HIGH); // HIGH means off
  temperature = read_temp();
  delay(DELAY);
}

double read_temp()
{
    return 0.0;
}


