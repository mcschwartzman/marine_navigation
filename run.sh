#!/bin/sh

docker build -t ros:sensor_fuser .

docker run --rm -it ros:sensor_fuser