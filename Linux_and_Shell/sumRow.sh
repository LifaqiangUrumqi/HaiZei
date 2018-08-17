#########################################################################
# File Name: sum.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 五  8/17 09:38:15 2018
#########################################################################
#统计一个目录里的文件和目录数。
#########################################################################
#!/bin/bash
sumF=0
sumD=0
file=$1
for i in `find $file -type f`; do
    sumF=$(($sumF + 1))
done
for i in `find $file -type d`; do
    sumD=$(($sumD + 1))
done 
echo "File number is $sumF"
echo "Directory number is $sumD"
