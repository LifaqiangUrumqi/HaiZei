/*************************************************************************
 > File Name: euler_28_1.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 19:00:29 2018
 ************************************************************************/

#include <stdio.h>

int main() {
    int sum = 1;
    for (int i = 3; i <= 1001; i += 2) {
        sum += 4 * i * i - 6 * i + 6;
    }
    printf("%d\n", sum);
    return 0;
}
