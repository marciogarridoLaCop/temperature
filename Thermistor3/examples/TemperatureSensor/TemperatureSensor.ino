#include <Thermistor3.h>
//begin object Thermistor in pin 0
Thermistor temp(4);
//value of resistor in ohms
double resistor = 10000;


//variable to store the average of read
double average =0;

//number of samples
int sample = 500;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Read the data and plus to variable average
  for(int index =0; index < sample; index++){
    double temperature = temp.getTemp(resistor);
    average += temperature; 
    // a small delay for read again
    delayMicroseconds(1);
 }
 // get the average
  average = average / sample;
  Serial.print("The Temperatura in Sensor is : ");
  Serial.print( average );
  Serial.println(" Celsius");
  delay(10);
}
