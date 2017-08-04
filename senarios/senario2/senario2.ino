//skeleton code for senario 2
//this is the transmitter
//there are many ways to code this!
//see if you can figure out the other ways
//and which ways are better
//the includes!!
//these let the program know what added functions and objects it needs acces to and to check for them
//make sure you have the libraries in your computer's library folder
//ask if you need help, they should be on Valery's github o
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//set the RF radio with which pins it's on these match the CE and CSN pins that you wired from the transciver to the arduino 
RF24 radio(9, 10);

// constant Variables
const byte rxAddr[6] = "00001";
//these don't change as you run your code
//like the pins that are in use
const int tempPin = A0; 

//variables that change
char text[6];
String stringOne = "";
int temperature;

void setup() {
  // cool!
  //let's go over what interupts do
  //when the pin that is the first term of the attachInterrupt function
  //changes value it actives the function that is the second term of the attachInterupt function
  //google or ask for help if you need it

  Serial.begin(9600);
  pinMode(tempPin, INPUT);
  attachInterrupt(0, sensor0, RISING);
  attachInterrupt(1, sensor1, RISING);
  radio.begin();
  //radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);

  radio.stopListening();

}
//these functions change what value is being sent across the transmitter.
//curently a number is being sent
void sensor0() {
  noInterrupts();
  temperature=analogRead(tempPin);
  delay(125);
  interrupts();
}


void sensor1() {
  noInterrupts();

  delay(125);
  interrupts();
}

void loop() {
  //stringOne is what is being transmitted
  //the below line of code stores the temperature value(the value that the interupts modify)as a string in the string one variable
  //it is then stored as a char array in the text variable
  //which fianlly is sent over the radio
  stringOne = (String) temperature;
  stringOne.toCharArray(text, 6);
  Serial.println(text);
  radio.write(&text, sizeof(text));
  //the delay is important so the radio doesn't get over worked
  delay(125);
}
