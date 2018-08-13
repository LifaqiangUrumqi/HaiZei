#########################################################################
# File Name: delete.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 一  8/13 20:02:59 2018
#########################################################################

#!/bin/bash
if [ ! -d ~/.Trash ]; then #如果不存在~/.Trash目录则创建一个~/.Trash目录
    mkdir ~/.Trash 
fi

if [ $# -eq 0 ]; then #如果delete.sh后没有输入任何字符的话执行以下代码
    echo "usage: $0 [-f | -r] [-dPRrvW] file ..."
    echo "unlink file"
elif [ "$1" == "-r" ] || [ "$1" == "-R" ]; then #当在delete.sh后输入-r或者-R执行以下程序
    if [ "$2" == "-f" ]; then #当-r或-R后面是-f的话直接递归并强制覆盖到回收站，然后递归并强制删除
        for ((i=3; i<=$#; i++)); do 
            file=${!i} 
            cp -rf $file ~/.Trash
            rm -rm $file 
        done
    else  #如果-r或-R后面是文件或者目录，那么该文件或目录递归并询问是否覆盖同名文件到回收站，并以此递归并询问是否删除该文件或目录
        for ((i=2; i<=$#; i++)); do
            file=${!i}
            cp -ri $file ~/.Trash/
            rm -ri $file
        done
    fi
elif [ "$1" == "-f" ]; then #当在delete.sh后输入-f执行以下程序
    if [ "$2" == "-r" ] || [ "$2" == "-R" ]; then #当-f后面是-r或-R的话直接递归并强制覆盖到回收站，然后递归并强制是否删除
        for ((i=3; i<=$#; i++)) do 
            file=${!i} 
            cp -rf $file ~/.Trash
            rm -rf $file 
        done
    else #如果-f后面是文件，那么将该文件强制覆盖同名文件到回收站，并且强制删除该文件，但是如果是目录就执行失败
        for ((i=2; i<=$#; i++)); do 
            file=${!i}
            if [[ -d $file ]]; then
                echo $0: $file: is a directory  
            elif [[ -f $file ]]; then 
                cp -f $file ~/.Trash/ 
                rm -f $file
                echo f
            fi
        done 
    fi
elif [ "$1" == "-rf" ] || [ "$1" == "-Rf" ] || [ "$1" == "-fr" ] || [ "$1" == "-fR" ]; then #当在delete.sh后输入-rf或-Rf或-fr或-fR执行以下程序
    for ((i=2; i<=$#; i++)); do #直接递归并强制覆盖的移到回收站，然后递归并强制删除
        file=${!i} 
        cp -rf $file ~/.Trash/ 
        rm -rf $file
    done
else #如果delete.sh后面是文件或者目录，那么将该文件询问是否覆盖同名文件到回收站，并且询问是否删除该文件，但是如果是目录就执行失败
    for ((i=1; i<=$#; i++)); do 
        file=${!i}
        if [ -f $file ]; then 
            cp -i $file ~/.Trash/ 
            rm -i $file 
        elif [ -d $file ]; then
            echo $0: $file: is a directory
        fi 
    done
fi
        

