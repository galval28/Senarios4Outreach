//skeleton code for senario 1
//there are many ways to do this code!
//see if you can figure out the other ways
//and which ways are better
//try rewritting with the map function https://www.arduino.cc/en/Reference/Map
// constant Variables
//these don't change as you run your code
//like the pins that are in use

//the pins
//if you are using different Pins change these to match your setup
const int readPin = A0;
//using digitalRead(readPin) you will get a nubmer 0-1023 based on the voltage between the point
//where the pin is connected to and ground
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int led4 = 5;
// non constant variables
int readValue; //this is the value that the readPin will read

void setup() {
  //uncomment the lines and pick if it's an input or output
  //pinMode(readPin, INPUT/OUTPUT);
  //pinMode(ledPin1, INPUT/OUTPUT);
  //pinMode(ledPin2, INPUT/OUTPUT);
  //pinMode(ledPin3, INPUT/OUTPUT);
  //pinMode(ledPin4, INPUT/OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //uncomment the line below and chose the action and pin
  //readValue = digitalRead/digitalWrite(readPin/ledPin1);
  Serial.println(readValue);
  //if(readValue < put a number here){
  digitalWrite(ledPin1, HIGH);
  }
else(){
digitalWrite(ledPin,LOW)} //this turns off the LED when it's not in use
//use the code snippets above to finish the project and make it your own!!
//don't be afraid to ask for help!
}
