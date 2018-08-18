export PATH=$PATH:/sbin
GITHUB=/Users/lifaqiang/other/GitHub/HaiZei
LOG=/var/log/mylog/
ADD=/Users/lifaqiang/g.sh
ADDALL=/Users/lifaqiang/gitall.sh
PATHS_ARR=(
"/Users/huguang/torch/install/bin"
"/Developer/NVIDIA/CUDA-8.0/bin"
"./bin"
"./"
)

LD_PATHS_ARR=(
"/Developer/NVIDIA/CUDA-8.0/lib"
)

# export paths_arr
for p in ${PATHS_ARR[@]};
do
export PATH=${p}:${PATH}
done

# export ld_paths_arr
for p in ${LD_PATHS_ARR[@]};
do
export LD_LIBRARY_PATH=${p}:${LD_LIBRARY_PATH}
done

TIME_NOW=`date -u +"%Y-%m-%d %H:%M"`
USER_NOW=`whoami`
echo "$TIME_NOW $USER_NOW LOGIN" >> /var/log/mylog/mylog.log
