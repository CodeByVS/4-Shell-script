# Swapping the value of two variables.
echo "Enter the first no."
read x
echo "Enter the second no."
read y
temp=`expr $x`
x=`expr $y`
y=`expr $temp`
echo "First no:$x"
echo "Second no:$y"
