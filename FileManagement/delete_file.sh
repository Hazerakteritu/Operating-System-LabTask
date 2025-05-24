#!/bin/bash 

read -p "Enter filename to delete: " filename 

if [ -e "$filename" ]
then
   rm "$filename" 
    echo "File '$filename' deleted."  
  else 
     echo "File does not exist."
fi 
