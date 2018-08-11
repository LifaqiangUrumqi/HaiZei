/*************************************************************************
 > File Name: euler_02_1.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 15:51:27 2018
 ************************************************************************/
#include <stdio.h>

int main() {
    int a = 0, b = 1, sum = 0, temp;
    while (a + b <= 4000000) {
        temp = a + b;
        a = b;
        b = temp;
        if (b & 1) continue;
        sum += b;
    }
    printf("%d\n", sum);
    return 0;
}
