//test: 1- roscore 
//      2- rostopic pub servo std_msgs/UInt16  <angle>
#define ESP8266
#include <Servo.h> 
#include <ros.h>
#include <ESP8266WiFi.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;
int Servo_pin D1;
Servo servo;

void servo_cb( const std_msgs::UInt16& cmd_msg){
  servo.write(cmd_msg.data); //set servo angle, should be from 0-180  
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);
  
  void setup(){
  pinMode(13, OUTPUT);
  
  nh.initNode();
  nh.subscribe(sub);

  servo.attach(Servo_pin); //attach it to pin Servo_pin
}

void loop(){
  nh.spinOnce();
  delay(100);
}
