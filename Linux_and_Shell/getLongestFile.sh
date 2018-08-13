#########################################################################
# File Name: getLongestFile.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 一  8/13 15:26:05 2018
#########################################################################

#!/bin/bash
maxString=""
maxFilePath=""
maxLength=0
function getLongestString() {
    file=$1

    if [[ ! -n  $file ]]; then
        file=.
    fi
    for i in `find $file -type f -size -1M`; do
        filePath=$i
        #echo $filePath
        #string=`cat $filePath`
        #echo $string
        if [[ -f $filePath ]]; then
            for j in `cat $filePath`; do
                #echo $j
                if [[ ${#j} -gt $maxLength ]]; then
                    maxString=$j
                    maxFilePath=$filePath
                    maxLength=${#j}
                    #echo $maxString
                    #echo $maxLength
                fi
            done
        fi
    done
    if [[ -n $maxFilePath ]]; then 
        echo The longest string is: 
        echo $maxString
        echo 
        echo The file path of longest string is:
        echo $maxFilePath
        echo
        echo The length of longest string is:
        echo $maxLength
    fi
}
getLongestString $1
