#!bin/bash

pwd
ls -alF
g++ -o app main.cpp
if [[ $? != 0 ]]
then
    apt install build-essential
fi
