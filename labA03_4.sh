#!/bin/bash
read n
if [ $n -gt 8 ]; then
  echo "Error: Maximum 8 arguments allowed."
  exit 1
fi

result=1
for i in "$n"; do
  if [ `expr $result % $i` -eq 0 ]; then
    result=$(( result / i ))
  elif [ `expr $i % 5` -eq 0 ]; then
    result=$(( result * i ))
  elif [ $result -gt $i ]; then
    result=$(( result - i ))
  else
    result=$(( result + i ))
  fi
done

echo "Final result: $result"
