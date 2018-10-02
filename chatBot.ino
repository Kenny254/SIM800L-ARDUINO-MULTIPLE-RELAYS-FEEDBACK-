#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11); 

char incomingByte; 
String inputString;
int led = 12;


void setup() 
{
      pinMode(led, OUTPUT);
     
      //Serial.begin(9600);
      mySerial.begin(9600); 
      // Check if you're currently connected to SIM800L 
      while(!mySerial.available()){
        mySerial.println("AT");
        delay(100); 
        ////Serial.println("connecting....");
        }
      ///Serial.println("Connected..");  
      mySerial.println("AT+CMGF=1\r\n");  //Set SMS Text Mode 
      delay(100);  
      mySerial.println("AT+CNMI=1,2,0,0,0");  //procedure, how receiving of new messages from the network
      delay(100);
      mySerial.println("AT+CMGL=\"REC UNREAD\""); // Read unread messages
      delay(100);              
     }

void loop()

{  
  if(mySerial.available()){
      delay(30);
      
      // Serial buffer
      while(mySerial.available()){
        incomingByte = mySerial.read();
        inputString += incomingByte; 
        }
        
        delay(10);
       
        ////Serial.println(inputString);
        inputString.toUpperCase(); // uppercase the message received

        //turn LED ON or OFF
       if (inputString.indexOf("ANY UPDATES") > -1){
          digitalWrite(led, HIGH);
          delay(100);
            mySerial.write("AT+CMGS=\"your number\"\r\n");
            delay(100);
            mySerial.write("Hello Sir, everything seems okay.");
            mySerial.write((char)26);
            delay(100);
            ////Serial.println("SMS sent");
        } 
        
       
        else if (inputString.indexOf("HI THERE") > -1){
           mySerial.write("AT+CMGS=\"your number\"\r\n");
            delay(100);
            mySerial.write("Hey,everything seems fine here.");
            delay(100);
            mySerial.write((char)26);
            delay(100);
            
        }    
             
         else if (inputString.indexOf("SWITCH ON") > -1){
          digitalWrite(led, HIGH);
          mySerial.write("AT+CMGS=\"your number\"\r\n");
          delay(100);
          mySerial.write("It is now on boss");
          delay(100);
          mySerial.write((char)26);
          delay(100);
          //Serial.println("SMS sent");
          }
          
          else if (inputString.indexOf("SWITCH OFF") > -1){
          digitalWrite(led, LOW);
          mySerial.write("AT+CMGS=\"your number\"\r\n");
          delay(100);
          mySerial.write("It is off now boss,Are you leaving?");
          delay(100);
          mySerial.write((char)26);
          delay(1000);
          //Serial.println("SMS sent");
          }
          
           else if (inputString.indexOf("PLEASE FLASH") > -1){
          digitalWrite(12, HIGH);
          delay(100);
          digitalWrite(12, LOW);
          delay(100);
           digitalWrite(13, HIGH);
          delay(100);
          digitalWrite(13, LOW);
          delay(100);
          digitalWrite(9, HIGH);
          delay(100);
          digitalWrite(9, LOW);
          delay(100);
          mySerial.write("AT+CMGS=\"your number\"\r\n");
          delay(100);
          mySerial.write("Did you realize I did Red,Green,Blue?");
          delay(100);
          mySerial.write((char)26);
          delay(100);
          //Serial.println("SMS sent");
          }

          else if (inputString.indexOf("HI BOT") > -1){
          mySerial.write("AT+CMGS=\"your number\"\r\n");
          delay(100);
          mySerial.write("Hi boss,call me Jasper");
          delay(100);
          mySerial.write((char)26);
          delay(100);
          }
          
          else if (inputString.indexOf("AND HOUSE") > -1){
          mySerial.write("AT+CMGS=\"your number\"\r\n");
          delay(100);
          mySerial.write("Well watched.No motion,No fire,No smoke, Temp,Hum:20,43");
          delay(100);
          mySerial.write((char)26);
          delay(100);
          }
          else if (inputString.indexOf("JASPER") > -1){
          mySerial.write("AT+CMGS=\"your number\"\r\n");
          delay(100);
          mySerial.write("AI :2018. Under Turing Test. KR-MFA STEAM");
          delay(100);
          mySerial.write((char)26);
          delay(100);
          }
          else if (inputString.indexOf("HUJAMBO") > -1){
          mySerial.write("AT+CMGS=\"your number\"\r\n");
          delay(100);
          mySerial.write("Sijambo ,Tafadhali,charge me.");
          delay(100);
          mySerial.write((char)26);
          delay(100);
          }
                
        delay(50);

        //delete messages to save memory
        if (inputString.indexOf("OK") == -1){
        mySerial.println("AT+CMGDA=\"DEL ALL\"");
        delay(1000);}

        inputString = "";
  }
}
