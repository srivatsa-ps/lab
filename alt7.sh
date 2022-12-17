echo "enter the 7 digit number"
read num
size=${#num}
if [ $size -eq 7 ] && [[ $num~=[0-9] ]]
then
echo "yes its 7 digits"
echo " digit1 ${num:0:1}"
echo " digit3 ${num:2:1}"
echo " digit5 ${num:4:1}"
echo " digit7 ${num:6:1}"

fi

