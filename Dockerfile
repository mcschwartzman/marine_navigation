FROM ros:galactic-ros-base

RUN mkdir -p fuser_ws/src

COPY ./sensor_fusion_pkg /fuser_ws/src/sensor_fusion_pkg
COPY ./docker_entrypoint.sh /docker_entrypoint.sh

ENTRYPOINT [ "bash", "docker_entrypoint.sh" ]