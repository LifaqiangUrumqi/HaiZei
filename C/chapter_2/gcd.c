/*************************************************************************
	> File Name: gcd.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 四  9/20 18:59:46 2018
 ************************************************************************/

#include <stdio.h>

int get_GCD(int a, int b) {
    if (b == 0) return a;
    return get_GCD(b, a % b);
}

int main() {
    int a, b, gcd;
    printf("请输入两个数字：");
    scanf("%d%d", &a, &b);
    gcd = get_GCD(a, b);

    printf("gcd(%d, %d) = %d\n", a, b, gcd);
    return 0;
}
