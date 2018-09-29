
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
       if (inputString.indexOf("ANY UPDATES") > -1){
          digitalWrite(led, HIGH);
          delay(100);
            mySerial.write("AT+CMGS=\"0721934493\"\r\n");
            delay(1000);
            mySerial.write("Hello Sir, everything seems okay.");
            mySerial.write((char)26);
            delay(1000);
            ////Serial.println("SMS sent");
        } 
        
       
        else if (inputString.indexOf("SWITCH ON") > -1){
          digitalWrite(led, HIGH);
          delay(100);
            mySerial.write("AT+CMGS=\"0721934493\"\r\n");
            delay(1000);
            mySerial.write("I have switched on the lights");
            delay(1000);
            mySerial.write((char)26);
            delay(1000);
            
        }    
             
         else if (inputString.indexOf("SWITCH OFF") > -1){
          digitalWrite(led, LOW);
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write("It is off now, I can see clearly thought");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          //Serial.println("SMS sent");
          }
           else if (inputString.indexOf("EBU FLASH") > -1){
          digitalWrite(led, HIGH);
          delay(1000);
          digitalWrite(led, LOW);
          delay(1000);
           digitalWrite(led, HIGH);
          delay(1000);
          digitalWrite(led, LOW);
          delay(1000);
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write("Umecheki sasa mi ni ule msee?");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          //Serial.println("SMS sent");
          }

          else if (inputString.indexOf("HI ESCURO") > -1){
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write("hi boss");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          }
          else if (inputString.indexOf("AND HOUSE") > -1){
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write("Very ell taken care of boss");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          }
          else if (inputString.indexOf("YOUR BOSS") > -1){
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write("Mr Ken Ronoh?");
          delay(4000);
          mySerial.write("Do you trust him?");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          
          }
          else if (inputString.indexOf("YES") > -1){
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write(":-)");
          delay(4000);
          mySerial.write((char)26);
          delay(1000);
          
          }
          else if (inputString.indexOf("NO") > -1){
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write(":-(");
          delay(4000);
          mySerial.write((char)26);
          delay(1000);
          
          }
          else if (inputString.indexOf("I FEEL TIRED") > -1){
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write("Take a rest, need some coffee?");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          }
          else if (inputString.indexOf("HAHA") > -1){
          mySerial.write("AT+CMGS=\"0721934493\"\r\n");
          delay(1000);
          mySerial.write("Cheka tu man");
          delay(1000);
          mySerial.write((char)26);
          delay(1000);
          }
          else if (inputString.indexOf("GREETINGS") > -1){
           mySerial.write("AT+CMGS=\"0721934493\"\r\n");
            delay(1000);
            mySerial.write("Hey you!");
            mySerial.write((char)26);
            delay(1000);
        } 
          else if (inputString.indexOf("I LOVE YOU") > -1){
           mySerial.write("AT+CMGS=\"0721934493\"\r\n");
            delay(1000);
            mySerial.write("I love you too boss");
            mySerial.write((char)26);
            delay(1000);
        } 
          
        delay(50);

        //delete messages to save memory
        if (inputString.indexOf("OK") == -1){
        mySerial.println("AT+CMGDA=\"DEL ALL\"");
        delay(1000);}

        inputString = "";
  }
}
