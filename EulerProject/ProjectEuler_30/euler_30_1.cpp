/*************************************************************************
 > File Name: euler_30_1.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 19:03:29 2018
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX_N 354294

int is_equal(int x) {
    int temp = x, sum = 0;
    while (x) {
        sum += (int)pow(x % 10, 5);
        x /= 10;
    }
    return sum == temp;
}

int main() {
    int ans = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!is_equal(i)) continue;
        ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
