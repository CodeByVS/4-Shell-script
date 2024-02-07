echo "Enter a number:"
echo "1.Home directory     2.   Bash version       3. Host name      4. current directory      5. exit"
read num
if [ $num -eq 1 ]
then
echo "$HOME"
fi
if [ $num -eq 2 ]
then
bash --version
fi
if [ $num -eq 3 ]
then
hostname
fi
if [ $num -eq 4 ]
then
pwd
fi
if [ $num -eq 5 ]
then
exit
fi
