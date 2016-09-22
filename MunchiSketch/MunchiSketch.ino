//Munchi Code - katekuehl and bookdude13

#define RELAY 12

/*
Temperature Sensor
Reads an Analog Devices TMP36GT9Z-ND or AD22100 temperature sensor on analog pin 0
and converts the voltage value to temperature.
Connect Pin 1 to 5 V.
Connect Pin 2 to A0.
Connect Pin 3 to Gnd.
Code from http://staff.mbi-berlin.de/schultz/ts2.php
*/

//#if defined(ARDUINO) && ARDUINO >= 100
//  #include "Arduino.h"
//  #else
//  #include "WProgram.h"
//  #endif


#define TsensorPin A0       // select the input pin for the sensor
int wait = 500;            // 1/2 second wait time between measurements
double temperature = 0.0;

void setup()
{
  pinMode(RELAY, OUTPUT);
  
  //Tempature Sensor TMP36GT9Z-ND Start-up
    // declare the ledPin as an OUTPUT:
  pinMode(TsensorPin, INPUT);                   // and set pins to input.
  Serial.begin (115200);                         // Set up the Serial Connection.
  Serial.println("Reading the Temperature Sensor");    // Greet user.
}

void loop()
{
  digitalWrite(RELAY, LOW); // LOW means off
//    digitalWrite(RELAY, HIGH); // HIGH means on
  
    temperature = TMP36GT_AI_value_to_Celsius(analogRead(TsensorPin)); // read temperature
    Serial.print("Temperature read (C): ");  
    Serial.println(temperature,2);   // write temperature to Serial
    delay(wait);                              // stop the program for for <wait> milliseconds:
}

double TMP36GT_AI_value_to_Celsius(int AI_value)
{                                               // Convert Analog-input value to temperature
    float voltage;
    voltage = AI_value * (5000.0/1024);             // Sensor value in mV:
    return ((voltage -750) /10) +25;                // Temperature according to datasheet: 750 mV = 25 Â°C
                                                // 10 mV / Â°C
}


