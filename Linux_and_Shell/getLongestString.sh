#########################################################################
# File Name: getFile.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 一  8/13 14:46:41 2018
#########################################################################

#!/bin/bash 
max=""
maxlen=0
path=""
function traverse() {
    file=$1
    if [[ -f $file ]]; then
        for i in `cat $file`; do
            if [[ ${#i} -gt $maxlen ]]; then
                (( maxlen=${#i} ))
                max=$i
                path=$file
            fi
        done
    elif [[ -d $file ]]; then
        for i in `ls $1`; do
            traverse $1"/"$i
        done
    fi

}
traverse $1
echo $maxlen
echo $max
echo $path
