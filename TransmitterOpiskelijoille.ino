#include "messaging.h"
#include "accelerator.h"
#include <SPI.h>

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  Accelerator Aobject;
  Messaging Mobject;
  int NumberOfMeasurements = 0;
  int CurrentPosition=0;
  /*
   * 1- X-akseli-taaksepäin  Y-akseli-oikealle  Z-akseli ylös
   * 2- X-akseli-taaksepäin  Y-akseli-ylöspäin  Z-akseli-vasemmalle
   * 3- X-akseli-alaspäin    Y-akseli-oikealle  Z-akseli-taaksepäin
   * 4- X-akseli-alaspäin    Y-akseli-alaspäin  Z-akseli-oikealle
   * 5- X-akseli-ylöspäin    Y-akseli-oikealle  Z-akseli-eteenpäin
   */
   Serial.println("Give number how many measurements");
  while(NumberOfMeasurements==0)
  {
    if(Serial.available()>0)
    {
       NumberOfMeasurements = Serial.parseInt();
       /*Aobject.makeMeasurement();
       Measurement a= Aobject.getMeasurement();
       Serial.println(a.x);
       Serial.println(a.y);
       Serial.println(a.z);*/
       
    }
  }
  Serial.println("Give current orientation");
   while(CurrentPosition == 0){
    if(Serial.available()>0){
      CurrentPosition = Serial.parseInt();
    }
   }
  for(int M = 0;M<NumberOfMeasurements;M++)
  {
     Aobject.makeMeasurement();
     Measurement m = Aobject.getMeasurement();
     uint8_t id = M;
     uint8_t flags = 0;
     switch(CurrentPosition){
      case 0:
        Serial.println("No position given");
      break;
      case 1:
        flags = 1;
      break;
      case 2:
        flags = 2;
      break;
      case 3:
       flags = 3;
      break;
      case 4:
       flags = 4;
      break;
      case 5:
       flags = 5;
      break;
        
     }
     
     Mobject.createMessage(m);
     if(Mobject.sendMessage(id,flags))
     {
       Serial.println("Successfull transmission");
     }
     else
     {
       Serial.println("Transmission fails");
     }
     if(Mobject.receiveACK())
     {
       Serial.println("Receiver got message, going to next measurement");
     }
     else
     {
       Serial.println("Reciver did not get the message. Need to resend it");
       M--;  // Let's just revind for loop 
     }
  } // end of for
}   // end of loop
