int motorPin = 3;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
  //pinMode(ledPin, OUTPUT);
digitalWrite(motorPin, LOW);
delay(5000);
digitalWrite(motorPin, HIGH);
delay(5000);
}
