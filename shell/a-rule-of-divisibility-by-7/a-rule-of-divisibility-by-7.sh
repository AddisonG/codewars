#!/bin/bash

operation() {
    printf "%06d\n" "$(( 10#$1/10 - 2*(${1: -1}) ))"
}

seven() {
    result="$1"
    count=0
    
    # Handle massive numbers
    while (( ${#result} > 6 )); do
        result="${result:0:-7}$(operation ${result: -7})"
        (( count++ ))
    done
    
    # Handle smaller numbers
    while (( ${#result} > 2 )); do
        result=$(( 10#$(operation ${result}) ))
        (( count++ ))
    done
    
    echo "$result, $count"
}

seven "$1"
