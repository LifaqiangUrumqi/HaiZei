/*************************************************************************
	> File Name: Test_1_8.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 五  9/ 7 20:20:06 2018
 ************************************************************************/

#include <stdio.h>

int main() {
    int c, ns = 0, nb = 0, nn = 0;
    while ((c = getchar()) != 0) {
        if (c == ' ') ns++;
        if (c == '\t') nb++;
        if (c == '\n') nn++;
    }
    printf("' ' = %d, \\t = %d, \\n = %d\n", ns, nb, nn);
    return 0;
}
