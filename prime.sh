#!/bin/bash

declare -a data

function init() {
    for i in `seq 1 1230`; do
    eval $1[$i]=0
    done
}

init data

for ((i = 2; i < 10000; ++i)); do
    if [[ ${data[$i]} -eq 0 ]]; then
        data[0]=$[ ${data[0]} + 1]
        data[${data[0]}]=$i;
    fi
    for ((j = 1; j <= ${data[0]}; ++j)) ;do
        (($[ $i * ${data[$j]} ] > 10000)) && break
        data[$[ $i * ${data[$j]} ]]=1;
        (($[ $i % ${data[$j]} ] == 0)) && break
    done
done

for ((i = 1; i <= data[0]; i++)); do
    echo ${data[ $i ]}
done


