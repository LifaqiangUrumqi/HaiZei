/*************************************************************************
	> File Name: T_1_5_3.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 五  9/ 7 19:53:39 2018
 ************************************************************************/


#include <stdio.h>
   /* count lines in input */
int main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
    return 0;
}

