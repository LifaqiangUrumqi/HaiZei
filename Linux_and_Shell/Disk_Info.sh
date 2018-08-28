#########################################################################
# File Name: Disk_Info.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 二  8/28 15:44:28 2018
#########################################################################

#!/bin/bash

TIME_NOW=`date +"%Y-%m-%d__%H:%M:%S"` #时间

DISK_ARRAY=(`df -m | grep '^/dev/' | awk '{print 1" "$6" "$2" "$4" "$5}' | tr ' ' ';' | tr '\n' ' '`)

DISK_TOTAL=$[ `echo ${DISK_ARRAY[*]} | tr ' ' '\n' | cut -d ';' -f 3 | tr '\n' '+' | sed 's/.$//'` ] #磁盘总量

DISK_FREE=$[ `echo ${DISK_ARRAY[*]} | tr ' ' '\n' | cut -d ';' -f 4 | tr '\n' '+' | sed 's/.$//'` ] #磁盘空闲量

DISK_USE_RATE=`echo "scale=1; ($DISK_TOTAL - $DISK_FREE) * 100 / $DISK_TOTAL" | bc` #磁盘使用比例

echo "$TIME_NOW 0 disk $DISK_TOTAL $DISK_FREE "$DISK_USE_RATE"%"
echo $TIME_NOW ${DISK_ARRAY[0]} | tr ';' ' '
echo $TIME_NOW ${DISK_ARRAY[1]} | tr ';' ' '
