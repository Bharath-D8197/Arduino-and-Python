//libraries used in this code//
#include<LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11);//assigning the digital pin number which connected to lcd 
long duration;//declaring the variable as LONG
int distance;//declaring variable as int
int safetyDistance;//declaring variable as int
int trigPin = 12;//declaring the variable as int and tells it is connected to digitalpin 12
int echoPin = 13;//declaring the variable as int and tells it is connected to digitalpin 13
int red2 = 2;//declaring the variable as int and tells it is connected to digitalpin 2
int red3 = 3;//declaring the variable as int and tells it is connected to digitalpin 3
int red4 = 7;//declaring the variable as int and tells it is connected to digitalpin 7
int analogValue=0;//initializing the variable as 0
int buzzer =4;//declaring the variable as int and tells it is connected to digitalpin 4
void setup()
{
  pinMode(red2, OUTPUT);//declaring variable as output
  pinMode(red3, OUTPUT);//declaring variable as output
  pinMode(red4, OUTPUT);//declaring variable as output
pinMode(buzzer, OUTPUT);//declaring variable as output
pinMode(trigPin, OUTPUT);//declaring variable as output
pinMode(echoPin, INPUT);//declaring variable as output
pinMode(A5, INPUT);//declaring variable as input
Serial.begin(9600);//command to bein serial monitor with data trasffering rate of 9600
lcd.begin(16,2);//tells lcd to bgin as 16*2
}
void loop()
{
analogValue=analogRead(A5);//assigning the analog value of A5 into new variable
Serial.println(analogValue);//print the value in serial monitor
  digitalWrite(trigPin, LOW);//to send signal from ultasonic sensors trig pin first we have to set it as low
delayMicroseconds(2);//which gives 2us delay
digitalWrite(trigPin, HIGH);//which emitts the signal 
delayMicroseconds(10);//which gives delay
digitalWrite(trigPin, LOW);//stops sending the signal
duration = pulseIn(echoPin, HIGH);//pulsein is a function which helps directly getting analog value
distance= duration*0.034/2;//formula to calculate distance
safetyDistance=distance;//assigning the vale to new variable
if(safetyDistance<=10)
{
  tone(buzzer,1000,10000);//if safety distance less than 10 controll flows inside if statement
if(analogValue>80&&analogValue<150)//the value of variable in the range of  80 to 150
{lcd.setCursor(7,1);
 digitalWrite(red2, HIGH);//first light will glow 
 digitalWrite(red3, LOW);
 digitalWrite(red4, LOW);//lcd shows a message 
    lcd.print(" ");//clear screen
//lcd.clear();
lcd.setCursor(0,0);//sets cursor at the specified position
lcd.print("ALCOHOL CONTENT");
//lcd.clear();
lcd.setCursor(0,1);
lcd.print("2in scale of  10");
//delay(1000);
}
else if(analogValue>150&&analogValue<300)//if value of variable lies in the range 150 to 300
{ digitalWrite(red2, HIGH);//2 led will glow with suitable message
 digitalWrite(red3, HIGH);
 digitalWrite(red4, LOW);
  lcd.setCursor(7,1);
    lcd.print(" ");
//lcd.clear();
lcd.setCursor(0,0);
lcd.print("ALCOHOL CONTENT");
//delay(1000);
//lcd.clear();
lcd.setCursor(0,1);
lcd.print("5in scale of  10");
//delay(1000);
}
  else if(analogValue>300&&analogValue<500)//if value of variable lies in the scale of 300 to 500 
{ digitalWrite(red2, HIGH);// all led will glow by giving suitable message
 digitalWrite(red3, HIGH);
 digitalWrite(red4, HIGH);
lcd.setCursor(7,1);
    lcd.print(" ");
lcd.setCursor(0,0);
lcd.print("ALCOHOL CONTENT");
//delay(1000);
//lcd.clear();
lcd.setCursor(0,1);
lcd.print("10in scale of 10");
//delay(1000);
}
 
  else//if any other value detected no led will glows
{
//lcd.clear();
    lcd.setCursor(7,1);
lcd.setCursor(0,0);
lcd.print("SAFE");
//delay(1000);
//lcd.clear();
lcd.setCursor(0,1);
lcd.print("NO ALCOHOL detected");
//delay(1000);
}
}
  else//if the distance more than 10 then no led will glow 
  {
    //lcd.clear();//gives suitable message
    noTone(buzzer);
    lcd.setCursor(0,0);
    lcd.print("SAFE           ");
    lcd.setCursor(0,1);
    lcd.print("NO ALCOHOL DETECTED");
  }
}
