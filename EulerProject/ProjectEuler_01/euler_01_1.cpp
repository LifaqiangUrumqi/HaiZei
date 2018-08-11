/*************************************************************************
 > File Name: euler_01_1.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 15:26:24 2018
 ************************************************************************/
#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0|| i % 5 == 0) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
