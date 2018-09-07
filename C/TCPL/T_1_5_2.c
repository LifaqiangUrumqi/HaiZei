/*************************************************************************
	> File Name: T_1_5_2.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 五  9/ 7 19:40:08 2018
 ************************************************************************/

#include <stdio.h>

int main() {
    double nc;

    for (nc = 0; getchar() != EOF; ++nc) 
    ;
    printf("%.0f\n", nc);
    return 0;
}
