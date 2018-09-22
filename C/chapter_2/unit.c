/*************************************************************************
	> File Name: is_prime.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 四  9/20 19:52:28 2018
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int max_int(int n, ...) {
    va_list arg;
    va_start(arg, n);
    int ans = INT32_MIN;
    for (int i = 0; i <= n; i++) {
        int temp = va_arg(arg, int);
        ans = temp > ans ? temp : ans;
    }
    return ans;
}
