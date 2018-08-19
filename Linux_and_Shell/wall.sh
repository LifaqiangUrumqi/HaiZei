#########################################################################
# File Name: wall.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 日  8/19 21:04:29 2018
#########################################################################

#!/bin/bash
words=$1
for i in `w -h | awk '{print $2}'`; do
    echo "$USER say: $words" >> /dev/$i
done
