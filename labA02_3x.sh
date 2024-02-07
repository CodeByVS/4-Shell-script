#!bin/bash

i=0
while [ $i -lt 100 ]
do
isPrime=1
j=2
while [ $j -lt $i ]
do
if [ $((i%j)) -eq 0 ]; then
isPrime=0
break
fi
j=$((j + 1))
done
if [ $isPrime -ne 0 ]; then
echo "$i"
fi
i=$((i + 1))
done
