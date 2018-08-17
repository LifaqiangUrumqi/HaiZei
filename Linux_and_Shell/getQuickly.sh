#########################################################################
# File Name: getQuickly.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 四  8/16 12:39:45 2018
#########################################################################
#完成以下功能：假设自己的代码目录A比较长，每次cd到该目录都很费事，现在，
#想一个办法可以使用一个代号A，使用cd $A就可以快速到达该目录。
#!/bin/bash
echo "A=/Users/lifaqiang/other/HaiZei_4/Linux_and_shell/" >> /Users/lifaqiang/.bashrc 
source /Users/lifaqiang/.bashrc 
cd $A
