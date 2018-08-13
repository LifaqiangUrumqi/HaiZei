/*************************************************************************
 > File Name: euler_26_1.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 14:51:24 2018
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 1000

int dnum[MAX_N + 5];

int get_length(int d) {
    int y = 1, n = 1;
    memset(dnum, 0, sizeof(dnum));
    /*
    memset()函数原型是extern void *memset(void *buffer, int c, int count)
    buffer：为指针或是数组   c：是赋给buffer的值   count：是buffer的长度   sizeof()表示数组的字节数.
    这个函数在socket中多用于清空数组.如:原型是memset(buffer, 0, sizeof(buffer))
    Memset 用来对一段内存空间全部设置为某个字符，一般用在对定义的字符串进行初始化为‘ ’或‘/0’；
    */
    printf("1 / %d = 0.", d);
    while (y != 0 && dnum[y] == 0) {       //只要y的余数为0或走过0时退出
        printf("%d", y * 10 / d);          //这个是求出他的商，第一次y = 1表示的是分子为1
        dnum[y] = n;                       //dnum数组表示分子经过的先后位置
        y = y * 10 % d;                    //找到下一个余数
        n += 1;                            //走向下一个位置
    }
    printf("(%d)\n", y ? n - dnum[y] : 0); 
/*
输出余数y是否不等于0，如果满足输出余数最后一个位置与算出来下一个已经过到余数的位置相减，
最终得到循环的长度
*/
    return y ? n - dnum[y] : 0;//返回循环长度
}

int main() {
    int max_length = 0, ans = 0;
    for (int d = 2; d < 1000; d++)  {    //2到999
        int temp_length = get_length(d); //获得循环节长度
        if (temp_length > max_length) {
            max_length = temp_length;    //当当前循环节长度temp_length大于之前得到的最大循环节长度max_length时，那么最大循环节长度就是他
            ans = d;                     //得出ans为获得最大循环节长度的分数的分母
        }
    }
    printf("得到循环节最长的数和循环节长度分别为：%d -> %d\n", ans, max_length);
    return 0;
}
