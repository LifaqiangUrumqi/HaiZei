/*************************************************************************
 > File Name: euler_02_3.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 16:27:03 2018
 ************************************************************************/

#include <stdio.h>

int main() {
    int ans = 0, a = 1, b = 2;
    while (b <= 4000000) {
        if (b % 2 == 0)
            ans += b;
        b = a + b;//b为下一项
        a = b - a;//a为b的前一项，就是之前的b
    }
    printf("%d\n", ans);
    return 0;
}
