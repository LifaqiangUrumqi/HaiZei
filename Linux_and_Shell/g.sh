#########################################################################
# File Name: g.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 五  8/17 23:55:49 2018
#########################################################################

#!/bin/bash
for ((i = 1; i <= $#; i++)); do
    git add $1
    if [[ "$i" == "*" ]]; then
        git commit -m "I commit a lot of files or directorys."
    else 
        git commit -m "I commit $i"
    fi
    git push -u origin master
done
    
