#########################################################################
# File Name: getLongestFile.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 一  8/13 15:26:05 2018
#########################################################################

#!/bin/bash
maxString="" #最长的字符串
maxFilePath="" #所包含最长的字符串的文件路径名
maxLength=0 #最长字符串的长度
function getLongestString() {
    file=$1
    if [[ ! -n  $file ]]; then #如果getLongestFile.sh后面没有输入如何东西，那么就以getLongestFile .来处理
        file=.
    fi
    for i in `find $file -type f -size -1M`; do #筛选出小于1M的文件的绝对路径，并且一个路径一个路径的获取。
        filePath=$i
        #echo $filePath
        #string=`cat $filePath`
        #echo $string
        if [[ -f $filePath ]]; then #判断获得的绝对路径是否是文件类型
            for j in `cat $filePath`; do #以空格和回车为分隔符，分割成一个一个的字符创，并且一个字符串一个字符串的获取。
                #echo $j
                if [[ ${#j} -gt $maxLength ]]; then #如果当前字符串的长度大于之前最大字符串的长度，那么最长的字符串，最长的字符串的长度，所包含最长的字符串的文件路径都会更改成当前的。
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
        echo The longest string is: #输出最长的字符串
        echo $maxString
        echo 
        echo The file path of longest string is: #输出所包含最长的字符串的文件路径
        echo $maxFilePath
        echo
        echo The length of longest string is: #输出最长的字符串的长度
        echo $maxLength
    fi
}
getLongestString $1
