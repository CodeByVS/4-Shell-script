#Find area of a circle
pie=3.14 | bc
echo "Enter the radius:"
read r
y="$r^2" |bc
x=`expr $pie \* $y | bc`
echo "$x"

