#########################################################################
# File Name: amendPermissiom.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 四  8/16 12:45:54 2018
#########################################################################
#使用Linux过程中，因为普通用户切换到root用户后的操作，可能导致普通用户家
#目录出现所属用户为root文件和目录，现在想办法，让root用户每次退出的时候自
#动修正普通用户的家目录权限。
#########################################################################
#!/bin/bash
sudo -i
echo "chown -R lifaqiang /Users/lifaqiang">>/var/root/.bash_logout
echo "echo 权限已修正">>/var/root/.bash_logout
exit

