/*************************************************************************
	> File Name: 3.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  8/21 16:52:36 2018
 ************************************************************************/
#include <stdio.h>

#include <string.h>

int main() {

    char st[20]="hello\0\t\\";

    printf("%d %d\n", strlen(st), sizeof(st));

}
