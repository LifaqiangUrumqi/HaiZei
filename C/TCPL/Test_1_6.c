/*************************************************************************
	> File Name: Test_1_6.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 五  9/ 7 20:00:29 2018
 ************************************************************************/

#include <stdio.h>

int main() {
    int c; 

    while ((c = getchar()) != EOF) 
        printf("%d\n", c);
    printf("%d - at EOF\n", c);
    return 0;
}
