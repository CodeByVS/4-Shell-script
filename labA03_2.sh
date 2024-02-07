#!/bin/bash
echo "Enter a number check it is palindrome or not"
read num
n=$num
reversed=0
while [ $n -ne 0 ]; do
remainder=$(( $n % 10 ))
reversed=$(( reversed * 10 + remainder ))
n=$(( $n / 10 ))
done
echo " Reversed number: $reversed"
if [ $reversed -eq $num ]; then
echo "Number is palindrome"
else
echo "Number is not palindrome"
fi
