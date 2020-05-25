# ros_nodemcu_rosserial_sensor project 
ROS Controlled NodeMCU Sensor read and servo control Project. This project is prepared for robotics final lecture which is ongoing master deggre with EE7055 id on Marmara University.

# Preliminary Information
# Nodemcu
NodeMCU is a low-cost open source IoT platform. It initially included firmware which runs on the ESP8266 Wi-Fi SoC from Espressif Systems, and hardware which was based on the ESP-12 module.
# ROS 
The Robot Operating System (ROS) is a flexible framework for writing robot software. It is a collection of tools, libraries, and conventions that aim to simplify the task of creating complex and robust robot behavior across a wide variety of robotic platforms.Why? Because creating truly robust, general-purpose robot software is hard.
# Rosserial
ROS Serial is a point-to-point version of ROS communications over serial, primarily for integrating low-cost microcontrollers (Arduino) into ROS.

# Environment
I have used the arduino ide to embed the rosserial to arduino based nodemcu. I have worked on ubuntu 18.04 LTS. My ros version is melodic morenia.
Board, sensors and servo:


![board](https://github.com/mcagriaksoy/ros_nodemcu_rosserial_sensor/blob/master/board_sensors_servo.jpg)

ESP board's information and configuration is not valid on arduino by default installition. First of all, I have installed that and Rosserial is included on arduino IDE from adding library section. Then, sensor value read and servo control codes are written. In Ros, nodes and topics are important. We are sending the sensor data under topics via signals. To control the servo, we are waiting the signal "1" from master which represent the our linux machine.


# Thanks
Prof. Dr. Haluk Kucuk for supporting me and instructing the lecture.

# References
https://medium.com/@mehmetaraksoy/i-want-to-start-with-what-is-not-ros-2245459a9ade
https://www.google.com/search?client=firefox-b-d&q=rosserial
https://www.ros.org/
