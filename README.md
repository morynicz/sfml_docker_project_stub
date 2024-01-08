# The stub

## Purpose
This project is a POC for providing a docker container for development of a graphical c++ application, in this case one using SFML library.

## Content
* Dockerfile handling insltalation of the library and setting up the cmake project with ninja as compilation controller
* Makefile with incantations that will make this build an image and run it with dropping to shell, ready for compilation.
* Build and run are configured to use code in the directory without rebuilding the image after each small change in code.
  
