#!/bin/bash 

create_file() { 

  read -p "Enter a filename: " filename 
  if [ -e "$filename" ]
  then 
    echo "File already exists." 
  else 
    touch "$filename" 
    echo "File '$filename' created." 
  fi 
}