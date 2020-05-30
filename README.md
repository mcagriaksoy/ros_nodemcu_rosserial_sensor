# ros_nodemcu_rosserial_sensor project 
These instructions and informations are written by me(hmet cagri aksoy).The project is about ROS Controlled NodeMCU Sensor read and servo control.This project is prepared for robotics final lecture which is ongoing master deggre with EE7055 ID on [Marmara University.](https://www.marmara.edu.tr/en)

# Preliminary Information
## Nodemcu
NodeMCU is a low-cost open source IoT platform. It initially included firmware which runs on the ESP8266 Wi-Fi SoC from Espressif Systems, and hardware which was based on the ESP-12 module.[Ref](https://en.wikipedia.org/wiki/NodeMCU)
## ROS 
The Robot Operating System (ROS) is a flexible framework for writing robot software. It is a collection of tools, libraries, and conventions that aim to simplify the task of creating complex and robust robot behavior across a wide variety of robotic platforms.Why? Because creating truly robust, general-purpose robot software is hard.[Ref](https://www.ros.org/about-ros/)
## Rosserial
ROS Serial is a point-to-point version of ROS communications over serial, primarily for integrating low-cost microcontrollers (Arduino) into ROS.[Ref](http://wiki.ros.org/rosserial)

# Environment
I have used the [Arduino IDE](https://www.arduino.cc/en/main/software) to embed the rosserial to arduino based nodemcu. I have worked on ubuntu 18.04 LTS. My ros version is melodic morenia.
Board, sensors and servo:


![board](https://github.com/mcagriaksoy/ros_nodemcu_rosserial_sensor/blob/master/board_sensors_servo.jpg)

ESP board's information and configuration is not valid on arduino by default installition. First of all, I have installed that and Rosserial is included on arduino IDE from adding library section. Then, sensor value read and servo control codes are written. In Ros, nodes and topics are important. We are sending the sensor data under topics via signals. To control the servo, we are waiting the signal "1" from master which represent the our linux machine.
#
The file of mq_sensor_ROS includes MQ-* sensor configuration with nodemcu board and rosserial features.
The file of mq_servo_ROS includes MQ-* servo motor configuration with nodemcu board and rosserial features.
The file of mq_all_ROS includes MQ-* whole configuration with nodemcu board and rosserial features.

## Rosserial Connection Steps
First of all we need to run the roscore on terminal. ``` roscore ```
Then listen the COM port and listen data from the board via : ```rosrun rosserial_python serial_node.py```
#
If any rostopic is created we can use ```rostopic pub toggle_led std_msgs/UInt16 "data: 0" ```  The data can be 0-1 due to our example. For example of the LED example which is [here](https://maker.pro/arduino/tutorial/how-to-use-arduino-with-robot-operating-system-ros), we can use this command to trigger the data 1 or 0 via rostopic command.
# Thanks
Prof. Dr. Haluk Kucuk for supporting me and instructing the lecture.

## References
https://medium.com/@mehmetaraksoy/i-want-to-start-with-what-is-not-ros-2245459a9ade
https://www.google.com/search?client=firefox-b-d&q=rosserial
https://www.ros.org/
https://maker.pro/arduino/tutorial/how-to-use-arduino-with-robot-operating-system-ros

