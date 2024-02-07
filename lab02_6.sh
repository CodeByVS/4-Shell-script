# find (a+b)^2
echo "Enter first value:"
read a
echo "Enter second value:"
read b
c=`expr $a + $b`
echo "$c^2" |bc
