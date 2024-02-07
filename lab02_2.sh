read val
if [ $val -gt 18 ]
then
       echo “You are a voter”
elif [ $val -eq 18 ]
then
       echo “You may enroll \for a voter”
else
      echo “You are not eligible”
fi

