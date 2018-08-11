/*************************************************************************
 > File Name: euler_04_1.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 18:32:27 2018
 ************************************************************************/

#include <stdio.h>

int is_palindromic(int x) {
    int temp = x, num = 0;
    while (x) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return temp == num;
}

int main() {
    int ans = 0;
    for (int i = 100; i< 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (i * j < ans) continue;//如果两个三位数相乘小于前一个回文数，那么重新循环
            if (!is_palindromic(i * j)) continue;//如果不是回文数，那么就循环
            ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
