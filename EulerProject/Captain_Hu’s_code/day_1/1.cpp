/*************************************************************************
	> File Name: 1.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 二  7/31 14:03:31 2018
 ************************************************************************/

#include <stdio.h>

int main() {
    int sum = 0;
    for (int i = 1; i < 1000; i++) sum += (i % 3 == 0 || i % 5 == 0) * i;
    printf("%d\n", sum);
    return 0;
}
