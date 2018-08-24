#########################################################################
# File Name: Users_Info.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 五  8/24 20:39:47 2018
#########################################################################

#!/bin/bash
TIMENOW=`date +"%Y-%m-%d__%H:%M:%S"`
SUM_USERS=`cat /etc/passwd | grep /home/ | wc -l`
ACTIVE_USERS=`last | head -n -2 | sort | cut -d ' ' -f 1 | uniq -c | sort -k 1 -n -r | head -n 3 | awk '{printf("%s,", $2)}' | sed 's/.$//'`
ROOT_USERS=`cat /etc/group | grep 'sudo' | cut -d ':' -f 4`
PRESENT_USERS=`w -h | awk '{printf("%s_%s_%s,", $1, $3, $2)}' | sed 's/.$//'`

echo "$TIMENOW $SUM_USERS [$ACTIVE_USERS] [$ROOT_USERS] [$PRESENT_USERS]"
