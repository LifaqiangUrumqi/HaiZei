/*************************************************************************
	> File Name: 4.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  8/21 17:27:25 2018
 ************************************************************************/

#include <stdio.h>

int fun( int a ) {
    int b = 0;
    static int c = 3;
    a = (c++, b++);
    return a;
}

int main() {
    int a=1; 
    int b=0; 
    int c=0; 
    int d=(++a)*(c=1);
    printf("%d %d %d %d\n", a, b, c, d);
    return 0;
}
