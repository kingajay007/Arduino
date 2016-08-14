int val;
int tempPin = 17;

void setup()
{
Serial.begin(9600);
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*3300; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

float temp = val*0.322265625;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);
}

