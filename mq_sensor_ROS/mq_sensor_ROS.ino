// Cagri.Aksoy
#include <ESP8266WiFi.h>  
#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";
// threshold value
int sensorThres = 400;
int Led = D1;
int smokeA0 = A0;
int buzzer = D2;
void setup()
{
  Serial.begin(57600);
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(Led, HIGH);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(Led, LOW);
    noTone(buzzer);
  }
  delay(100);
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}
