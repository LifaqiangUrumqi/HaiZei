#########################################################################
# File Name: backup.sh
# Author: Lifaqiang
# mail: 576245059@qq.com
# Created Time: 五  8/17 16:16:29 2018
#########################################################################

#!/bin/bash
source .backup.rc

TIME_NOW=`date +"%Y-%m-%d %H:%M"`
TIME_FILE=`date +"%Y_%m_%d_%H_%M"`

if [[ ! -d $dest_dir ]]; then
    echo "$TIME_NOW 【ERROR】The Dest dir $dest_dir not exists" >> $log
    exit
fi

echo "$TIME_NOW backup started!" >> $log
for i in `echo $back_dir | tr ":" "\n"`; do
    if [[ ! -d $i ]]; then
        echo "%TIME_NOW backup 【ERROR】The dir $i not exist" >> $log
    fi
    echo "$i started"
    target=`echo $i | cut -d "/" -f 2- | tr "/" "_"`
    target="${target}_${TIME_FILE}.tar.gz"
    tar -czPf "${dest_dir}/${target}" $i
    if [[ $? -eq 0 ]]; then
        size=`du -h ${dest_dir}/${target} | cut -f 1`
        echo "$TIME_NOW backup $i --> $target +${size}M" >> $log
    else 
        echo "$TIME_NOW 【ERROR】Something ...." >> $log
    fi
done

Del_list=`find $dest_dir -name "*.tar.gz" -mmin +3`

for i in $Del_list; do
    size=`du -h $i | cut -f 1`
    rm -rf $i
    echo "$TIME_NOW delete $i --> remove -${size}" >> $log
done

