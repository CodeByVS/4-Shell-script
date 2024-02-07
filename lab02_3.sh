echo "Enter a number less than 100:"
read val
if [ $val -lt 100 ]
then
     echo “That\'s a small number”
     if [ [ `expr $val % 2` ] -eq 0 ]
     then
          echo “Even number”
     fi
fi
