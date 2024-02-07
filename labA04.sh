#!/bin/bash
read a
read b
read c
read d
read e
x=$(( a + b + c + d + e ))
echo "Sum is:$x"
avg=$(($x / 5 ))
echo "Average is:$avg"
if [ $x -gt $avg ]; then
echo "sum is greater"
else
echo "average is greater"
fi

