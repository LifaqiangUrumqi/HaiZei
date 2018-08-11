/*************************************************************************
 > File Name: euler_06_1.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 18:56:29 2018
 ************************************************************************/

#include <stdio.h>

int main() {
    int sum1 = 0, sum2 = 0, n = 100;
    do {
        sum1 += n;
        sum2 += n * n;
    } while (--n);
    printf("%d\n", sum1 * sum1 - sum2);
    return 0;
}
