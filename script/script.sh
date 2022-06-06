#!bin/bash

pwd
ls -alF
g++ -o app test/Test.cpp
if [[ $? != 0 ]]
then
    apt install build-essential
fi
