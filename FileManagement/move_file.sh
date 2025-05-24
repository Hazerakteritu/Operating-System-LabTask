#!/bin/bash 

read -p "Enter source file name: " src 
read -p "Enter destination file name " dest 

if [ -e "$src" ]
then 
    mv "$src" "$dest" 
    echo "File moved to '$dest'." 
else 
    echo "Source file does not exist." 
fi
