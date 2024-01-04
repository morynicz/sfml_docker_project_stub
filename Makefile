PROJECT=sfml_docker

all:
	sudo docker buildx build -t ${PROJECT} --build-context code=`pwd`/code . && sudo docker run -e SDL_VIDEODRIVER=x11 -e DISPLAY=${DISPLAY} -e XAUTHORITY=${XAUTHORITY} -v /tmp/.X11-unix/:/tmp/.X11-unix/ --mount type=bind,source=`pwd`/code,target=/source,readonly -it sfml_docker