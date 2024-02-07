echo "Enter a number"
read x
n=10
reverse=0
while [ $x -ne 0 ]; do
remainder=`expr $x%$n | bc`
reverse=`expr $reverse*$n+$remainder | bc`
x=$((x/10))
done
echo "$reverse"
