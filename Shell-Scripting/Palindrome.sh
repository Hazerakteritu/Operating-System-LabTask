#Check if a String is Palindrome or not

#!/bin/bash

read -p "Enter a String: " str

rev=$(echo $str | rev)

if [ "$str" == "$rev" ]; then
    echo "Palindrome"
else
    echo "Not Palindrome"
fi
