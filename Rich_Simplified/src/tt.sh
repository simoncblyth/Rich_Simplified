#!/bin/bash -l 

export X4PhysicalVolume=INFO
export GMeshLib=INFO

export RichTbLHCbR1SphMirror_mode=1
export RichTbLHCbR1FlatMirror_mode=1 


if [ -n "$DEBUG" ]; then 
    lldb__ TimeTest
else
    TimeTest
fi  


