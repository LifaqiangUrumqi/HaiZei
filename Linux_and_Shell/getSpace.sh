#########################################################################
# File Name: getSpace.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 五  8/24 20:38:52 2018
#########################################################################

#!/bin/bash

if [[ -n "$1" ]]; then
    PreAvg=$1
else
    PreAvg=100
fi

Space=`free -m | head -n 2 | tail -n 1 | awk '{printf("%s %s", $2, $2 - $3)}'`
Space=(`echo $Space`)
Occupy=`echo "scale=1;(${Space[0]}-${Space[1]})*100/${Space[0]}" | bc`
NowAvg=`echo "scale=1; 0.3*${PreAvg}+0.7*${Occupy}" | bc`
NowTime=`date +"%Y-%m-%d_%H:%M:%S"`
echo "$NowTime ${Space[0]}M ${Space[1]}M ${Occupy}% ${NowAvg}%"
