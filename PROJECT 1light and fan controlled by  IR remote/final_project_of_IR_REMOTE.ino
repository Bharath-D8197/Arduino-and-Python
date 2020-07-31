/*libraries for ir remote,ir sensor&lcd*/
#include<IRremote.h>
#include<LiquidCrystal.h> 
LiquidCrystal lcd(13,12,9,8,6,5);//creating the object and assigning the digital pin number of arduino to lcd
int RECV_PIN = 11;//the pin comes out of ir sensor is connected to 11 th digital pin of arduino 
int buzzer = 3;//buzzer is connected to 3rd digital pin of arduino
int led1 = 2;// led 1 is connected to 2nd digital pin of arduino
int led2 = 4;//led2 is connected to 4th digital pin of arduino
int led3 = 7;//led 3 is connected to 7th digital pin of arduino
int motor= 10;//motor is connected to 10th digital pin of arduino
int itsONled[]={0,0,0,0,0,0};//which sets the initial value 
/*the initial state of LEDs is OFF*/
#define code1 16582903 //code received from button number 1
#define code2 16615543 //code received from button number 2
#define code3 16599223 //code received from button number 3
#define code4 16591063 //code received from button number 4 
IRrecv irrecv(RECV_PIN);//IRrecv is the pre defined function from library, irrecv is the object
decode_results results;//decode is the fuction and results is the object

void setup()//initial setup
{
  Serial.begin(9600);//to get the value serially with baud (data transferring)rate. 
  lcd.begin(16,2);//which initiallizes the lcd as 16*2(16-coloumns,2-rows)
  digitalWrite(buzzer, LOW);//which sets the initial value of buzzer pin =0
  irrecv.enableIRIn();//which enables to get value from ir remote to sensor
  pinMode(led1, OUTPUT);//directing led1 as output
  pinMode(led2, OUTPUT);//directing led2 as output
  pinMode(led3, OUTPUT);//directing led3 as output
  pinMode(motor, OUTPUT);//directing motor as output
  pinMode(buzzer, OUTPUT);//directing buzzer as output
}

void loop()//main part of code
{
  if (irrecv.decode(&results))//the signal received from remote will collected in ir sensor .which will be decoded
  {
    unsigned int value = results.value;//value is a variable of type unsigned int which stores the result from results.vale
    switch(value)//starting of swith case
    {
      case code1://which tells it is the first case 
      if(itsONled[1]==1)                      //if first led1 is on then
      {                                       //turn it off when button is pressed
        digitalWrite(led1, LOW);              //and set its state as off
        itsONled[1]=0;                       //set cursor at (0,0) position and print "    ")
        lcd.setCursor(0,0);
        lcd.print("    ");                   //which basically clears the screen
      }
      else                                 //else if first led is off
      {
        digitalWrite(led1, HIGH);          //turn it on when button is pressed
        itsONled[1]=1;                    //and set its state as on
        lcd.setCursor(0,0);            //set position of cursor at (0,0)
        lcd.print("LED1");            //  and print what is given
      }
      break;                  //which break the  body of if comes out of  switch
      case code2:             //it is the 2nd case
      if(itsONled[2]==1)//if 2nd led is on  then turn it off
      {
        digitalWrite(led2, LOW);//when the switch is pressed
        itsONled[2]=0;//and set its state as off
        lcd.setCursor(4,0);//set cursor at (4,0) and print(____)
        lcd.print("    ");//which mainly clear screen 
      }
      else
      {
        digitalWrite(led2, HIGH);//else if 2nd led is off turn it on
        itsONled[2]=1;//when button is pressed and set its state as on
      
        lcd.setCursor(4,0);//set cursor at (0,0)
        lcd.print("LED2");//print as led2 
      }
      break;//which break the body of if comes out of switch
      case code3://it is the 3rd case
      if(itsONled[3]==1)//if 3rd led is on then turn it off when switch is pressed
      {
        digitalWrite(led3, LOW);
        itsONled[3]=0;
        lcd.setCursor(8,0);//set the cursor at(8,0)
        lcd.print("    ");//clear screen
      }
      else
      {
        digitalWrite(led3, HIGH);//else if 3rd led is off turn it on when switch is pressed
        itsONled[3]=1;
        lcd.setCursor(8,0);//set cursor at (8,0)
        lcd.print("LED3");//print as led 3
      }
      break;//which comes out of if and switch condition
      case code4:
      if(itsONled[4]==1)//if motor is on set its state as off when button is pressed
      {
        digitalWrite(motor, LOW);//and set its state as off
        itsONled[4]=0;
        lcd.setCursor(13,0);// set the position of cursor at(13,0)
        lcd.print("   ");//clear screen
      }
      else//else if motor is off set its state as on
      {
        digitalWrite(motor, HIGH);//if button is pressed
        itsONled[4]=1;//set its state as high
        lcd.setCursor(13,0);//set cursor at (13,0)
        lcd.print("FAN");//print fan
      }
      break;//which comes out of if and switch
     }
    if((digitalRead(2)&&digitalRead(4)&&digitalRead(7)&&digitalRead(10))==1)//if led1,led2,led3 &fans are ON
    {//tone(buzzer,750);//this code is not work because IRremote.h library is used which will miss lead
      digitalWrite(buzzer,HIGH);//which on the buzzer with delay of 500
      //delay(500);
      lcd.setCursor(1,1);//set cursor at(1,1)
      lcd.print("HEAVY POWER");//print the message
      
    }
    else//if any one of the led or fan is off then
    {//noTone(buzzer);//code not work because IR remote.h library is used which will miss lead
      digitalWrite(buzzer, LOW);//which sets the buzzer off 
      //delay(500);
      lcd.setCursor(1,1);// which set cursor at(1,1)
      lcd.print("             ");//which clear the screen
     
    }
     Serial.print(value);
     irrecv.resume();//which receive the next value
  }
}
