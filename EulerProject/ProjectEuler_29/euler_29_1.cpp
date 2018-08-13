/*************************************************************************
 > File Name: euler_29_1.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 15:07:24 2018
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10000
#define MAX_M 210

int *result[MAX_N] = {0};
int result_length = 0;

int find_result(int *num) {
    for (int i = 0; i < result_length; i++) {
        /*
         int memcmp(const void *str1, const void *str2, size_t n)
         str1 -- 指向内存块的指针。
         str2 -- 指向内存块的指针。
         n -- 要被比较的字节数。
         如果返回值 < 0，则表示 str1 小于 str2。
         如果返回值 > 0，则表示 str2 小于 str1。
         如果返回值 = 0，则表示 str1 等于 str2。
         */
        if (memcmp(result[i], num, sizeof(int) * MAX_M)) continue;//num
        
        return i + 1;
    }
    return 0;
}

int *calc_num(int a, int b) {
    int *temp = (int *)calloc(sizeof(int), MAX_M));
    temp[0] = temp[1] = 1;
    for (int i = 0; i < b; i++) {
        for (int j = 1
    }
}
