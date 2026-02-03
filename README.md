# marine_navigation
A collection of ros packages for ocean navigation

## sensor_fusion_pkg
This package includes the following nodes:

### fused_data.py
This Node subscribes to /imu/data and /depth and publishes a fused data point to /vertical_velocity. Currently the actual fusion math is not implemented and this Node stands as a simple scaffolding for this pipeline. The next step in this Node will be implementing a simple EKF to generate this data point.

## Running
Included in this repository is a Dockerfile and simple run script that can be executed on any linux machine with Docker installed. Just run `./run.sh` and you'll build the dockerfile and get dropped into its shell, where you can run your typical ros2 commands.

```
colcon test // workspace is already built and sourced
ros2 run sensor_fusion_pkg fused_data // actually runs the fusion node 
```

## TODO
1. Implement the EKF in the actual fused_data node
2. Upgrade to a non EOL ROS2 distro (I used galactic because it's what I had on my bare-metal machine for testing)
3. Write simple launch file to get the node up and running
4. Obtain sample rosbag and include for use in testing