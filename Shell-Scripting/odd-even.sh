#!/bin/bash

check_odd_even() { 
  echo -n "Enter a number: " 
  read num 
  if [ $((num % 2)) -eq 0 ]; then 
    echo "$num is Even" 
  else 
    echo "$num is Odd" 
  fi 
}

