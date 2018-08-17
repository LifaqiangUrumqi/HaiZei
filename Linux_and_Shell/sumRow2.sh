#########################################################################
# File Name: sumRow2.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 五  8/17 10:00:24 2018
#########################################################################

#!/bin/bash
sumF=0
sumD=0
function Traverse() {
    file=$1
    for i in `ls -a $file`; do
        if [[ "$i" == "." || "$i" == ".." ]]; then
            continue
        fi 
        if [ -d $dir_or_file ]; then
            sumD=$(($sumD + 1)) 
            Traverse $1"/"$i
        else 
            sumF=$(($sumF + 1))
        fi 
    done 
}
Traverse $1
sumD=$(($sumD + 1))
echo $sumD 
echo $sumF

