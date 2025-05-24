//Factorial of a Number using Recursion

#!/bin/bash
fact()
{
   if (( $1 <= 1))
   then echo 1
   else
      local result=$(fact $(($1 - 1)))
      echo $(($1*result))
   fi
}

read -p "Enter a Number: " num
result=$(fact $num)
echo "Factorial of $num is $result"