/*************************************************************************
	> File Name: K_and_R.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 四  9/20 18:33:28 2018
 ************************************************************************/

#include <stdio.h>

int is_prime(x)
int x;
{
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int num;
    printf("请输入一个数：");
    scanf("%d", &num);
    printf("%d\n", is_prime(num));
    return 0;
}
