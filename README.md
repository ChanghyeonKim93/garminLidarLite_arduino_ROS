# garminLidarLite_arduino_ROS
garmin Lidar liter with ROS + arduino uno ( or micro available)

## Preliminaries

1. In arduino IDE : Sketch -> include library -> manage library -> search : rosserial_arduino & install
2. In ros :

sudo apt-get install ros-{version}-rosserial-arduino
sudo apt-get install ros-{version}-rosserial


## How to subscribe in ros from arduino? 

1. In arduino IDE , upload your .ino file . 
2. 
roscore
rosrun rosserial_python serial_node.py /dev/ttyACM0 (**In case of not found the tty, re-configure your usb port)

## How to connect the lines? 
(no need to connect capacitor... maybe ! ) 

## Configuration
<img src="https://github.com/ChanghyeonKim93/garminLidarLite_arduino_ROS/blob/master/arduino_lidar_configuration.png"/>
