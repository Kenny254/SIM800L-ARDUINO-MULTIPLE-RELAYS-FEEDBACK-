
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11); 

char incomingByte; 
String inputString;
int led = 13;


void setup() 
{
      pinMode(led, OUTPUT);
     
      //Serial.begin(9600);
      mySerial.begin(9600); 
      // Check if you're currently connected to SIM800L 
      while(!mySerial.available()){
        mySerial.println("AT");
        delay(1000); 
        ////Serial.println("connecting....");
        }
      ///Serial.println("Connected..");  
      mySerial.println("AT+CMGF=1\r\n");  //Set SMS Text Mode 
      delay(1000);  
      mySerial.println("AT+CNMI=1,2,0,0,0");  //procedure, how receiving of new messages from the network
      delay(1000);
      mySerial.println("AT+CMGL=\"REC UNREAD\""); // Read unread messages
      delay(1000);              
     }

void loop()

{  
  if(mySerial.available()){
      delay(100);
      
      // Serial buffer
      while(mySerial.available()){
        incomingByte = mySerial.read();
        inputString += incomingByte; 
        }
        
        delay(10);
       
        ////Serial.println(inputString);
        inputString.toUpperCase(); // uppercase the message received

        //turn LED ON or OFF
        if (inputString.indexOf("ON") > -1){
          digitalWrite(led, HIGH);
          delay(100);
            mySerial.write("AT+CMGS=\"0721934493\"\r\n");
            delay(1000);
            mySerial.write("Switched ON");
            delay(1000);
            mySerial.write((char)26);
            delay(1000);
            ////Serial.println("SMS sent");
        }    
             
         if (inputString.indexOf("OFF") > -1){
          digitalWrite(led, LOW);
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write("Switched OFF");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          ////Serial.println("SMS sent");
          }

          else if (inputString.indexOf("HI ESCURO") > -1){
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write("hi boss");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          Serial.println("SMS sent");
          }
          else if (inputString.indexOf("AND HOUSE") > -1){
          digitalWrite(led, LOW);
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write("Well taken care of boss");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          Serial.println("SMS sent");
          }
          
          
        delay(50);

        //delete messages to save memory
        if (inputString.indexOf("OK") == -1){
        mySerial.println("AT+CMGDA=\"DEL ALL\"");
        delay(1000);}

        inputString = "";
  }
}
