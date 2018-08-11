/*************************************************************************
 > File Name: euler_01_1.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 15:26:27 2018
 ************************************************************************/
#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 3; i < 1000; i += 3) {
        sum += i;
    }
    for (int i = 5; i < 1000; i += 5) {
        sum += i;
    }
    for (int i = 15; i < 1000; i += 15) {
        sum -= i;
    }
    printf("%d\n", sum);
    return 0;
}
