#-------Largest element from array using for loop..........
#!/bin/bash

read -p "Enter the number of elements: "  n
echo "Enter elements: "
read -a arr

max=${arr[0]}
for i in ${arr[@]}
do 
if (( i > max ))
then max=$i
fi
done