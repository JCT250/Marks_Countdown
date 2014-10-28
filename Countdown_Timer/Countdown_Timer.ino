// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
 
#include <Wire.h>
#define digit1 0x22
#define digit2 0x20
#define digit3 0x21
#define digit4 0x23

#include "RTClib.h"
RTC_DS1307 RTC;

//const long departure = 1386844800;
const long departure = 1386891480;
long current = 0;
long remaining = 0;

int hoursremaining = 0;

int ones = 0;
int tens = 0;
int hundreds = 0;
int thousands = 0;

int led1 = 0;
int led2 = 0;
int led3 = 0;
int led4 = 0;

int dd = 75;
 
void setup () {
    Serial.begin(57600);
    Wire.begin();
    RTC.begin();
 
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //RTC.adjust(DateTime(__DATE__, __TIME__));
  }
    Serial.println("Setup Complete");
 
}
 
 void calc(){
      DateTime now = RTC.now();
     
     Serial.print(now.year(), DEC);
     Serial.print('/');
     Serial.print(now.month(), DEC);
     Serial.print('/');
     Serial.print(now.day(), DEC);
     Serial.print(' ');
     Serial.print(now.hour(), DEC);
     Serial.print(':');
     Serial.print(now.minute(), DEC);
     Serial.print(':');
     Serial.print(now.second(), DEC);
     Serial.println();
 
     Serial.println("Calculating");
     current = now.unixtime();
     Serial.print("Current Unix Time ");
     Serial.println(current);
     remaining = departure - current;
     Serial.print("Departure Unix Time ");
     Serial.println(departure);
     Serial.println("Time Remaining");
     Serial.print(remaining);
     Serial.println(" seconds");
     Serial.print(remaining / 60);
     Serial.println(" minutes");
     Serial.print(remaining / 3600);
     Serial.println(" hours");
     Serial.print(remaining / 86400L);
     Serial.println(" days");
     Serial.println();
     Serial.println("*********************************");
     Serial.println();
     hoursremaining = (remaining / 3600);
     Serial.println("Calculations Complete");
 }
 
 void parse(){
   
   Serial.println("Beginning Parsing");
   
    ones = (hoursremaining%10); //these next four lines take the number of hours remaining and break them into the number of ones, tens etc for display
    tens = ((hoursremaining/10)%10);
    hundreds = ((hoursremaining/100)%10);
    thousands = (hoursremaining/1000);
    
    switch(ones){ //this first section determines the value that needs to be sent to the first expander based upon the number that needs to be displayed on the ones display
      case 1:
      led1 = 006;
      break;
      case 2:
      led1 = 244;
      break;
      case 3:
      led1 = 118;
      break;
      case 4:
      led1 = 46;
      break;
      case 5:
      led1 = 122;
      break;
      case 6:
      led1 = 250;
      break;
      case 7:
      led1 = 70;
      break;
      case 8:
      led1 = 254;
      break;
      case 9:
      led1 = 110;
      break;
      case 0:
      led1 = 222;
      break; 
    }

    switch(tens){ //ditto but for the tens digit
      case 1:
      led2 = 006;
      break;
      case 2:
      led2 = 244;
      break;
      case 3:
      led2 = 118;
      break;
      case 4:
      led2 = 46;
      break;
      case 5:
      led2 = 122;
      break;
      case 6:
      led2 = 250;
      break;
      case 7:
      led2 = 70;
      break;
      case 8:
      led2 = 254;
      break;
      case 9:
      led2 = 110;
      break;
      case 0:
      led2 = 222;
      break;
    }

    switch(hundreds){ //ditto but for the hundreds digit
      case 1:
      led3 = 006;
      break;
      case 2:
      led3 = 244;
      break;
      case 3:
      led3 = 118;
      break;
      case 4:
      led3 = 46;
      break;
      case 5:
      led3 = 122;
      break;
      case 6:
      led3 = 250;
      break;
      case 7:
      led3 = 70;
      break;
      case 8:
      led3 = 254;
      break;
      case 9:
      led3 = 110;
      break;
      case 0:
      led3 = 222;
      break;
    }

    switch(thousands){ //ditto but for the thousands digit
      case 1:
      led4 = 006;
      break;
      case 2:
      led4 = 244;
      break;
      case 3:
      led4 = 118;
      break;
      case 4:
      led4 = 46;
      break;
      case 5:
      led4 = 122;
      break;
      case 6:
      led4 = 250;
      break;
      case 7:
      led4 = 70;
      break;
      case 8:
      led4 = 254;
      break;
      case 9:
      led4 = 110;
      break;
      case 0:
      led4 = 222;
      break;
    }    
   Serial.println("Parsing Complete");
 }
 
 void eyecandy(){

     Serial.println("Beginning Eyecandy");
     
       
       Wire.beginTransmission(digit1);
       Wire.write(6);
       delay(dd);
       Wire.endTransmission(digit1);
       Wire.beginTransmission(digit1);
       Wire.write(244);
       delay(dd);
       Wire.endTransmission(digit1);
       Wire.beginTransmission(digit1);
       Wire.write(118);
       delay(dd);
       Wire.endTransmission(digit1);
       Wire.beginTransmission(digit1);
       Wire.write(46);
       delay(dd);
       Wire.endTransmission(digit1);
       Wire.beginTransmission(digit1);
       Wire.write(122);
       delay(dd);
       Wire.endTransmission(digit1);
       Wire.beginTransmission(digit1);
       Wire.write(250);       
       delay(dd);
       Wire.endTransmission(digit1);
       Wire.beginTransmission(digit1);
       Wire.write(70);       
       delay(dd);
       Wire.endTransmission(digit1);
       Wire.beginTransmission(digit1);
       Wire.write(254);       
       delay(dd);
       Wire.endTransmission(digit1);
       Wire.beginTransmission(digit1);
       Wire.write(110);       
       delay(dd);       
       Wire.endTransmission(digit1);
       Wire.beginTransmission(digit1);
       Wire.write(222);
       delay(dd);
       Wire.endTransmission(digit1);

       
       Wire.beginTransmission(digit2);
       Wire.write(6);
       delay(dd);
       Wire.endTransmission(digit2);
       Wire.beginTransmission(digit2);
       Wire.write(244);
       delay(dd);
       Wire.endTransmission(digit2);
       Wire.beginTransmission(digit2);
       Wire.write(118);
       delay(dd);
       Wire.endTransmission(digit2);
       Wire.beginTransmission(digit2);
       Wire.write(46);
       delay(dd);
       Wire.endTransmission(digit2);
       Wire.beginTransmission(digit2);
       Wire.write(122);
       delay(dd);
       Wire.endTransmission(digit2);
       Wire.beginTransmission(digit2);
       Wire.write(250);       
       delay(dd);
       Wire.endTransmission(digit2);
       Wire.beginTransmission(digit2);
       Wire.write(70);       
       delay(dd);
       Wire.endTransmission(digit2);
       Wire.beginTransmission(digit2);
       Wire.write(254);       
       delay(dd);
       Wire.endTransmission(digit2);
       Wire.beginTransmission(digit2);
       Wire.write(110);       
       delay(dd);       
       Wire.endTransmission(digit2);
       Wire.beginTransmission(digit2);
       Wire.write(222);
       delay(dd);
       Wire.endTransmission(digit2);
       
      
       Wire.beginTransmission(digit3);
       Wire.write(6);
       delay(dd);
       Wire.endTransmission(digit3);
       Wire.beginTransmission(digit3);
       Wire.write(244);
       delay(dd);
       Wire.endTransmission(digit3);
       Wire.beginTransmission(digit3);
       Wire.write(118);
       delay(dd);
       Wire.endTransmission(digit3);
       Wire.beginTransmission(digit3);
       Wire.write(46);
       delay(dd);
       Wire.endTransmission(digit3);
       Wire.beginTransmission(digit3);
       Wire.write(122);
       delay(dd);
       Wire.endTransmission(digit3);
       Wire.beginTransmission(digit3);
       Wire.write(250);       
       delay(dd);
       Wire.endTransmission(digit3);
       Wire.beginTransmission(digit3);
       Wire.write(70);       
       delay(dd);
       Wire.endTransmission(digit3);
       Wire.beginTransmission(digit3);
       Wire.write(254);       
       delay(dd);
       Wire.endTransmission(digit3);
       Wire.beginTransmission(digit3);
       Wire.write(110);       
       delay(dd);       
       Wire.endTransmission(digit3);
       Wire.beginTransmission(digit3);
       Wire.write(222);
       delay(dd);
       Wire.endTransmission(digit3);
       

       Wire.beginTransmission(digit4);
       Wire.write(6);
       delay(dd);
       Wire.endTransmission(digit4);
       Wire.beginTransmission(digit4);
       Wire.write(244);
       delay(dd);
       Wire.endTransmission(digit4);
       Wire.beginTransmission(digit4);
       Wire.write(118);
       delay(dd);
       Wire.endTransmission(digit4);
       Wire.beginTransmission(digit4);
       Wire.write(46);
       delay(dd);
       Wire.endTransmission(digit4);
       Wire.beginTransmission(digit4);
       Wire.write(122);
       delay(dd);
       Wire.endTransmission(digit4);
       Wire.beginTransmission(digit4);
       Wire.write(250);       
       delay(dd);
       Wire.endTransmission(digit4);
       Wire.beginTransmission(digit4);
       Wire.write(70);       
       delay(dd);
       Wire.endTransmission(digit4);
       Wire.beginTransmission(digit4);
       Wire.write(254);       
       delay(dd);
       Wire.endTransmission(digit4);
       Wire.beginTransmission(digit4);
       Wire.write(110);       
       delay(dd);       
       Wire.endTransmission(digit4);
       Wire.beginTransmission(digit4);
       Wire.write(222);
       delay(dd);
       Wire.endTransmission(digit4);

   Serial.println("Eyecandy Complete");
   
 }
 
 void output(){
   Serial.println("Beginning Display");
   int runonce = 0;
   while(1==1){
     if(runonce == 0){

       Wire.beginTransmission(digit4);
       Wire.write(led4);
       Wire.endTransmission(digit4);

       Wire.beginTransmission(digit3);
       Wire.write(led3);
       Wire.endTransmission(digit3);
       
       Wire.beginTransmission(digit2);
       Wire.write(led2);
       Wire.endTransmission(digit2);
       
       Wire.beginTransmission(digit1);
       Wire.write(led1);
       Wire.endTransmission(digit1);
       
       runonce = 1;
      Serial.println("Display Complete");
     }
     else if(runonce == 1){
       delay (5000);
     } 
   }
 }
 
 
void loop (){

int runonce = 0;
if (runonce == 0){
  
Serial.println("Loop");
runonce = 1;
}
  
calc(); //done

parse(); //done

eyecandy(); //Still to do

output(); //done
  

}
