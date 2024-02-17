#include <SoftwareSerial.h> 

SoftwareSerial hc06(0,1);

String cmd=""; 
String finalcmd;
float sensor_val=0;

void setup(){
 	//Initialize Serial Monitor
 	Serial.begin(9600);
 	//Initialize Bluetooth Serial Port
 	hc06.begin(9600); 
 // pinMode(7,INPUT); 
}

void loop(){ 

 
 	//Read data from HC06
 	while(hc06.available()>0){ 
      
 			cmd+=(char)hc06.read();
      // Serial.println(cmd);
 	}  

 /* if(digitalRead(7)==0)
    {
    cmd="0"; // Stop if bluetooth gets disconnected
    // Serial.println("BT Disconnected"); 
    finalcmd = cmd.toInt();
    } 

  */
 	//Select function with cmd
 	if(cmd!=""){
 			// Serial.print("Command recieved : ");
 			// Serial.println(cmd);
 			// // We expect ON or OFF from bluetooth
 			// // if(cmd=="ON"){
 			// // 				Serial.println("Function is on");
 			// // }else if(cmd=="OFF"){
 			// // 				Serial.println("Function is off");
 			// // }else{
 			// // 				Serial.println("Function is off by default");
 			// // }   

      // if(cmd=="1")
      // {
      //   Serial.println("Forward");
      // } 
      // if(cmd=="2") 
      // {
      //   Serial.println("Backward"); 
      // } 
      // if(cmd=="3")
      // { 
      //    Serial.println("Left"); 
      // } 
      // if(cmd=="4")
      // {
      //   Serial.println("Right");
      // } 
      // if(cmd=="0")
      // {
      //   Serial.println("Stop");
      // } 
      finalcmd=cmd;
 			 cmd="";//reset cmd   
    

 	}  
  Serial.println(finalcmd);
  
 	// Simulate sensor measurement
 	// sensor_val=(float)random(256); // random number between 0 and 255
 			
 	//Write sensor data to HC06
 	// hc06.print(sensor_val);
 //	delay(100);
} 
// 1 for forward
// 2 for backward
// 3 for left 
// 4 for right 
// 0 for stop
// 4 for left


