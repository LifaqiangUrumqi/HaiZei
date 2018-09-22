/*************************************************************************
	> File Name: factor.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 四  9/20 18:42:40 2018
 ************************************************************************/

#include <stdio.h>

int get_Factor(int n) {
    if (n == 0) return 1;
    return n * get_Factor(n - 1);
}

int main() {
    int n;
    printf("请输入一个数：");
    scanf("%d", &n);
    printf("%d! = %d\n", n, get_Factor(n));
    return 0;
}
