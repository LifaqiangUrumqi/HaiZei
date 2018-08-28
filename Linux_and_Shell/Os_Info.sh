#########################################################################
# File Name: Os_Info.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 二  8/28 12:12:44 2018
#########################################################################

#!/bin/bash

TIME_NOW=`date +"%Y-%m-%d__%H:%M:%S"` #时间

#HOSTNAME 主机名

OS_VERSION=`cat /etc/issue | tr ' ' '\n' | head -n 3 | tr '\n' '_' | sed 's/.$//'` #OS版本

KERNEL_VERSION=`cat /proc/version | cut -d ' ' -f 3` #内核版本

BOOT_TIME=`uptime -p | tr ' ' '_'` #运行时间

AVG_LOAD=`uptime | tr ' ,:' '\n' | grep -v '^$' | tail -n -3 | xargs` #平均负载

DISK_SIZE=$[ `df -m | grep '^/dev/' | awk '{print $2}' | tr '\n' '+'` 0  ] #磁盘总量

DISK_USE=$[ `df -m | grep '^/dev/' | awk '{print $3}' | tr '\n' '+'` 0  ] #磁盘使用量

DISK_RATE=$[ $DISK_USE * 100 / $DISK_SIZE ] #磁盘已用%

MEMORY_SIZE=`free -m | head -n 2 | tail -1 | awk '{print $2}'` #内存大小

MEMORY_USE=`free -m | head -n 2 | tail -1 | awk '{print $3}'` #内存使用量

MEMORY_RATE=$[ $MEMORY_USE * 100 / $MEMORY_SIZE ] #内存已用%

CPU_INFO=`cat /sys/class/thermal/thermal_zone0/temp` #CPU温度的1000倍

CPU_TEMPERATURE=`echo "scale=2;$CPU_INFO/1000" | bc` #CPU温度

ALARM_LEVEL_DISK=`test $DISK_RATE -ge 0 && test $DISK_RATE -le 80 && echo normal || (test $DISK_RATE -le 90 && echo note || echo warning)` #磁盘报警级别

ALARM_LEVEL_MEMORY=`test $MEMORY_RATE -ge 0 && test $MEMORY_RATE -le 80 && echo normal || (test $MEMORY_RATE -le 90 && echo note || echo warning)` #内存报警级别

ALARM_LEVEL_CPU=`test $CPU_INFO -ge 0 && test $CPU_INFO -le 70000 && echo normal || (test $CPU_INFO -le 80000 && echo note || echo warning)` #CPU报警级别

echo "$TIME_NOW $OS_VERSION $KERNEL_VERSION $BOOT_TIME $AVG_LOAD "$DISK_SIZE"M "$DISK_RATE"% "$MEMORY_SIZE"M "$MEMORY_RATE"% "$CPU_TEMPERATURE"°C $ALARM_LEVEL_DISK $ALARM_LEVEL_MEMORY $ALARM_LEVEL_CPU"
