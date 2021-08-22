#!/bin/bash

if [[ $0 == /* ]];
    then 
        cd "${0/compile.bash/}"
        cd "..";
    else
        path=$PWD
        path+="/"
        path+=$0
        cd "${path/compile.bash/}"
        cd "..";
fi;

g++ chess.cpp -o "build/chess"