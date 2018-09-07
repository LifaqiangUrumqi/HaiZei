/*************************************************************************
	> File Name: T_1_5.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 五  9/ 7 19:17:10 2018
 ************************************************************************/

#include <stdio.h>

int main() {
    //printf("EOF is %d\n", EOF);
    int c;

    while ((c = getchar()) != EOF) {
        printf("%dccc\n", c);
        printf("%dddd\n", (c != EOF) ? 1 : 0);
    }

//    printf("%d - at EOF\n", c);
    /* while (c != EOF) {
        putchar(c);
        c = getchar();
    } */

    return 0;
}
