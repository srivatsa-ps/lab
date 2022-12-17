echo "enter a string"
read str
len=${#str}
i=${{len-1}}
while [ $i -ge 0 ] 
do 
reverse=$reverse${str:$i:1}
i=${{i-1}}
done
echo "the original string is $str"
echo "the reversed string is $rev"
