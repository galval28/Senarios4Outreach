//skeleton code for senario 2
//this is the reciever
//there are many ways to code this!
//see if you can figure out the other ways
//and which ways are better

//the includes!!
//these let the program know what added functions and objects it needs acces to and to check for them
//make sure you have the libraries in your computer's library folder
//ask if you need help, they should be on Valery's github

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "SPI.h" // Comment out this line if using Trinket or Gemma
//set the RF radio with which pins it's on these match the CE and CSN pins that you wired from the transciver to the arduino 
RF24 radio(9, 10);

//the variables
//let's start with the constant varibles
const byte rxAddr[6] = "00001";
const int speakPin = 7;
const int led0 = A0;
const int led1 = A1;
const int led2 = A2;
const int led3 = A3;
// let's put the LEDs on the analog pins so they are seperate from the transciver
//other variables
int command = 0;

void setup() {
  pinMode(speakPin, OUTPUT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  interrupts();
  //see the transmitter sketch for more on interupts
  //or ask or google
  attachInterrupt(0, interrupt, FALLING);
  Serial.begin(9600);
  radio.begin();
  //the radio sends a high signal to pin0 when it is reciveing something
  radio.openReadingPipe(0, rxAddr);
  radio.startListening();


}
void interrupt(){
  //when 
  uint8_t data;
  radio.read(&data, sizeof(data));
  //comand is the integer value recived by the reciver
  command = data;
}
void loop() {
  // try a couple if statements that change what happens depending on the value in comand
  // or look up case statements and try those!
  if(command!=0){
    Serial.println(command);
    //print the command vlaue to the serial monitor so you can see what it is
    //the reset the command value back to 0 so it is not constantly printing
    command=0;}
  }
  

}
