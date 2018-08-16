#########################################################################
# File Name: recordingLoginAndLogout.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 四  8/16 12:52:29 2018
#########################################################################
#设计一个日志系统，记录当前用户的登录和退出操作。要求形式如：Sat 25 Nov
#12:11:28 UTC 2017 lifaqiang login.
#########################################################################
#!/bin/bash
cat >> /Users/lifaqiang/.bashrc << EOF
TIME_NOW=\`date -u +"%Y-%m-%d %H:%M"\`
USER_NOW=\`whoami\`
echo "\$TIME_NOW \$USER_NOW LOGIN" >> /var/log/mylog/mylog.log 
EOF

cat >> /Users/lifaqiang/.bash_logout << EOF
TIME_NOW=\`date -u +"%Y-%m-%d %H:%M"\`
USER_NOW=\`whoami\`
echo "\$TIME_NOW \$USER_NOW LOGOUT" >> /var/log/mylog/mylog.log 
EOF


