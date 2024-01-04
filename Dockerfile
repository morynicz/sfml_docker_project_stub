FROM gcc:12.1

RUN apt-get update && apt-get install -y cmake ninja-build
RUN apt install -y libsfml-dev

WORKDIR /usr/src/myapp
RUN --mount=type=bind,source=code,target=/source set -ex && cmake -G"Ninja" /source/
