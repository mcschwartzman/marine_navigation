#!/bin/sh

cd /fuser_ws
colcon build
source /opt/ros/galactic/setup.bash
source install/setup.bash

/bin/bash
