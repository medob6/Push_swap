#!/bin/bash

declare -A max

# Define maximum values for each n
max[2]=1                                               
max[3]=2
max[4]=6
max[5]=11
max[6]=50
max[7]=60

for i in {2..7}
do
    # Run the Go program for each n, and process each permutation
    go run tester.go -n $i | while read hey
    do
        # Run push_swap and get the number of instructions used
        result=$(./push_swap $hey | wc -l)

        # Compare the result with the max for the current n
        if [[ $result -gt ${max[$i]} ]]
        then
            # Print FAIL message if the result exceeds max
            printf "\e[38;2;255;0;0mFAIL\e[00m $i number of instructions is: $result list of numbers: $hey\n"
            exit 1 # Exit the script if it fails
        else
            # Print SUCCESS message
            printf "\e[38;2;0;255;0mSUCCESS\e[00m $i number of instructions is: $result\n"
        fi
    done | sort | uniq
done


# i need to adjust the test for numbers bigger then 5 , for the programe to give the argemnt and test each one without waiting for the full cases , and the caase to be random because the number of possibel arrangment of a list large is soo big and take a loot of time to creat

# for list size 100 i should get max operations 700
# and for list size 500 i should not exude 5500



#  i want you to adjust the test to be better use any languge must be fast 

# 3 
# 2
# 1
# 4