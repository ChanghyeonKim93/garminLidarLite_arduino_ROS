#include <Wire.h>
#include "LIDARLite.h"

#include <ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PointStamped.h>
ros::NodeHandle  nh;

std_msgs::String str_msg;
geometry_msgs::PointStamped point_msg;
ros::Publisher PointLidar("PointLidar", &point_msg);

LIDARLite myLidarLite;

void setup()
{
  myLidarLite.begin(0, true); // Set configuration to default and I2C to 400 kHz

  /*
    -----------------------------------------------------------
    configuration:  Default 0.
      0: Default mode, balanced performance.
      1: Short range, high speed. Uses 0x1d maximum acquisition count.
      2: Default range, higher speed short range. Turns on quick termination
          detection for faster measurements at short range (with decreased
          accuracy)
      3: Maximum range. Uses 0xff maximum acquisition count.
      4: High sensitivity detection. Overrides default valid measurement detection
          algorithm, and uses a threshold value for high sensitivity and noise.
      5: Low sensitivity detection. Overrides default valid measurement detection
          algorithm, and uses a threshold value for low sensitivity and noise.
    lidarliteAddress: Default 0x62. Fill in new address here if changed. See
      operating manual for instructions.
  */
  myLidarLite.configure(0); // Change this number to try out alternate configurations

  nh.initNode();
  nh.advertise(PointLidar);
}

void loop()
{
  /*
    distance(bool biasCorrection, char lidarliteAddress)

    Take a distance measurement and read the result.

    Parameters
    ----------------------------------------------------------------------------
    biasCorrection: Default true. Take aquisition with receiver bias
      correction. If set to false measurements will be faster. Receiver bias
      correction must be performed periodically. (e.g. 1 out of every 100
      readings).
    lidarliteAddress: Default 0x62. Fill in new address here if changed. See
      operating manual for instructions.
  */

  // Take a measurement with receiver bias correction and print to serial terminal
  point_msg.header.stamp = nh.now();
  point_msg.point.z = myLidarLite.distance();
  PointLidar.publish( &point_msg );
  nh.spinOnce();

}
