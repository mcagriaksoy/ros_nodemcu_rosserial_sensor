# NodeMCU Ros Project
These instructions and information are written by me(hmet cagri aksoy). The project is about ROS Controlled NodeMCU Sensor read and servo control. This project is prepared for robotics final lecture which is ongoing master deggre with EE7055 ID on [Marmara University.](https://www.marmara.edu.tr/en)

# Preliminary Information
## Nodemcu
NodeMCU is a low-cost open-source IoT platform. It initially included firmware that runs on the ESP8266 Wi-Fi SoC from Espressif Systems and hardware which was based on the ESP-12 module.[Ref](https://en.wikipedia.org/wiki/NodeMCU)
## ROS 
The Robot Operating System (ROS) is a flexible framework for writing robot software. It is a collection of tools, libraries, and conventions that aim to simplify the task of creating complex and robust robot behavior across a wide variety of robotic platforms. Why? Because creating a truly robust, general-purpose robot software is hard.[Ref](https://www.ros.org/about-ros/)
## Rosserial
ROS Serial is a point-to-point version of ROS communications over serial, primarily for integrating low-cost microcontrollers (Arduino) into ROS.[Ref](http://wiki.ros.org/rosserial)

# Environment
I have used the [Arduino IDE](https://www.arduino.cc/en/main/software) to embed the rosserial to Arduino based nodemcu. I have worked on ubuntu 18.04 LTS. My ros version is melodic morenia.
Board, sensors, and servo:


![board](https://github.com/mcagriaksoy/ros_nodemcu_rosserial_sensor/blob/master/board_sensors_servo.jpg)

ESP board's information and configuration are not valid on Arduino by default installation. First of all, I have installed that, and Rosserial is included on Arduino IDE from adding the library section. Then, the sensor value read and servo control codes are written. In Ros, nodes and topics are important. We are sending the sensor data under topics via signals. To control the servo, we are waiting for the signal "1" from the master which represent our Linux machine.
#
The file of mq_sensor_ROS includes MQ-* sensor configuration with nodemcu board and rosserial features.
The file of mq_servo_ROS includes MQ-* servo motor configuration with nodemcu board and rosserial features.
The file of mq_all_ROS includes MQ-* whole configuration with nodemcu board and rosserial features.

## Rosserial Connection Steps
First of all, we need to run the roscore on terminal. ``` roscore ```
Then listen the COM port and listen to data from the board via: ```rosrun rosserial_python serial_node.py```
#
If any rostopic is created we can use ```rostopic pub toggle_led std_msgs/UInt16 "data: 0" ```  The data can be 0-1 due to our example. For an example of an LED example which is [here](https://maker.pro/arduino/tutorial/how-to-use-arduino-with-robot-operating-system-ros), we can use this command to trigger the data 1 or 0 via rostopic command.

# Summary

In summary, thanks to this project I have learned how to install ros on OS, what is rosserial and how can we use and implement it in our Arduino based boards. Also, I have understood that rosserial does not work very well on ESP based boards. I recommend using AVR based boards like Arduino Uno, instead of ESPDuino or similar ESP8266 or many different versions of ESP. I have found rosserial has still some open issues regarding this support. 
On the other hand, nodemcu boards only supply 3.3v at max. So I have used some USB to TTL converter to simply gain 5V from the computer's USB. Thanks to this converter I have connected my sensor 5v input and servo's 5v input. 
The rosserial becomes very popular and easy to use, Arduino programming is also very enjoyable and easy. The rosserial allows us to interface between ros and our development boards, so, enables the use of two very famous and useful technologies to explore new opportunities in robotics. This method allows for distributed computing, centralized control, control abstraction, and several other benefits to robotic systems at a very low cost.
# Thanks
Prof. Dr. Haluk Kucuk for supporting me and instructing the lecture.

## References
https://medium.com/@mehmetaraksoy/i-want-to-start-with-what-is-not-ros-2245459a9ade
https://www.google.com/search?client=firefox-b-d&q=rosserial
https://www.ros.org/
https://maker.pro/arduino/tutorial/how-to-use-arduino-with-robot-operating-system-ros

