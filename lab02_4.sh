echo "Enter a value:"
read val
if [ $val -lt 25 ] && [ $val -gt 20 ]
then
      echo “You are eligible”
else
       echo “not eligible”
fi
