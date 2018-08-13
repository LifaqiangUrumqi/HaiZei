/*************************************************************************
	> File Name: euler_24_1.cpp
	> Author: Lifaqiang 
	> Mail: 576245069@qq.com
	> Created Time: 三  8/ 1 16:48:06 2018
 ************************************************************************/

#include<stdio.h>
#include<iostream>
using namespace std;
#define MAX_N 10

int jnum[10] = {0};//存1到9的阶乘
int dnum[10] = {0};//记录那些数字用过了

void init() {//初始化了从1到9的阶乘
    jnum[0] = dnum[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        dnum[i] = 1;//dnum数组表示这个数字用过没有，1表示用过
        jnum[i] = i * jnum[i - 1];//jnum数组表示1到9每一个的阶乘
    }
    return ;
}

int judge_num(int n, int k) {//这个是核心
    int ind = (k / jnum[n]) + 1;//ind表示要移动哪一个数字 +1表示我们要找到第几个可以用数字，如果k小于jnum[n]，那么什么也不走，直接走输出下一个数字
    
    int i = -1;//i表示数
    while (ind > 0) {
        i++;//位置加1
        ind -= dnum[i];//
    }
    dnum[i] = 0;//表示数字i已经走过了
    return i;
}

int main() {
    init();
    int n, k;//n表示要输入多少个数0到n - 1个数，k表示的是从小到大多少位
    scanf("%d%d", &n, &k);
    k -= 1;//首先减去原位置
    for (int i = n - 1; i >= 0; i--) {
        int num = judge_num(i, k);//判断要输出的数字
        printf("%d", num);
        k %= jnum[i];//相当于k = k - 所移动个个数 * jnum数组，就是剩下要走的步数
    }
    printf("\n");
    return 0;
}

