/*************************************************************************
	> File Name: function.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 四  9/20 19:59:16 2018
 ************************************************************************/

#include <stdio.h>
#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

int is_prime(int x);
int max_int(int n, ...);

int main() {
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) printf("%d\n", i);
    }
    P(max_int(3, 1, 2, 3));
    P(max_int(4, 1, 2, 3, 9));
    P(max_int(5, 1, 12, 3, 9, 10));
    return 0;
}
