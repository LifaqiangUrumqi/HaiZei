/*************************************************************************
	> File Name: test_builtin_expect.cpp
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  9/18 19:46:48 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

int test_likely(int x) {
    if (LIKELY(x)) {
        x = 5;
    } else {
        x = 6;
    }
    return x;
}

int test_unlikely(int x) {
    if (UNLIKELY(x)) {
        x = 5;
    } else {
        x = 6;
    }
    return x;
}
