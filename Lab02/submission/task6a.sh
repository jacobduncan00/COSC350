#!/bin/bash                                                                                                                           
                                                                                                                                         
# Jacob Duncan                                                                                                                        
# Lab 02                                                                                                                              
# task6a.sh                                                                                                                           
                                                                                                                                                                                                                                             
for i in $(seq 1 5); do                                                                                                               
  for j in $(seq 1 $i); do                                                                                                            
    echo -n "$i"                                                                                                                      
  done                                                                                                                                
  echo                                                                                                                                
done                                                                                                                                                                                                                                                                          
exit 0   

'''''''''''''
OUTPUT

./task6a.sh 
1
22
333
4444
55555
''''''''''''

