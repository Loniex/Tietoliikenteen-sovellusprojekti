#include "Keskipisteet.h"

int x=0;
int y=0;
int z=0;
int NumberOfMeasurements = 0;
int CurrentPosition=0;

void setup() {
  Serial.begin(9600);
  int pos= 0;
  
}

void MakeMeasurement() 
  {
    x = analogRead(A0);
    y= analogRead(A1);
    z=analogRead(A2);
  }
  
void calcAllAndFind(int x,int y, int z);

void loop() {
  Serial.println("Give number how many measurements");
  while(NumberOfMeasurements==0)
  {
    if(Serial.available()>0)
    {
       NumberOfMeasurements= Serial.parseInt();

    }
  }
  /*
   * 1- X-akseli-taaksepäin  Y-akseli-oikealle  Z-akseli ylös
   * 2- X-akseli-taaksepäin  Y-akseli-ylöspäin  Z-akseli-vasemmalle
   * 3- X-akseli-alaspäin    Y-akseli-oikealle  Z-akseli-taaksepäin
   * 4- X-akseli-alaspäin    Y-akseli-alaspäin  Z-akseli-oikealle
   * 5- X-akseli-ylöspäin    Y-akseli-oikealle  Z-akseli-eteenpäin
   */
  Serial.println("Give current orientation");
   while(CurrentPosition == 0){
    if(Serial.available()>0){
      CurrentPosition = Serial.parseInt();
    }
   }
  for(int M = 0;M<NumberOfMeasurements;M++)
  {
    MakeMeasurement();
    calcAllAndFind(x,y,z);
        
  }
  }

void calcAllAndFind(int x,int y, int z){
  int distance[4]={0,0,0,0};
  int loc = 0; //tells lowest distance number
  distance[0]=sqrt(pow((yp[0]-x),2)+pow((yp[1]-y),2)+pow((yp[2]-z),2));
  distance[1]=sqrt(pow((vp[0]-x),2)+pow((vp[1]-y),2)+pow((vp[2]-z),2));
  distance[2]=sqrt(pow((op[0]-x),2)+pow((op[1]-y),2)+pow((op[2]-z),2));
  distance[3]=sqrt(pow((ap[0]-x),2)+pow((ap[1]-y),2)+pow((ap[2]-z),2));
  for(int ar=0; ar >= 4; ar++){
    if(distance[ar] < distance[loc]){
      loc=ar;
    }
  }
  Serial.println(CurrentPosition);
  Serial.println(loc);
}
