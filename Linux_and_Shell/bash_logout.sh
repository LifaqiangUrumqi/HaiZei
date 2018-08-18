TIME_NOW=`date -u +"%Y-%m-%d %H:%M"`
USER_NOW=`whoami`
echo "$TIME_NOW $USER_NOW LOGOUT" >> /var/log/mylog/mylog.log
