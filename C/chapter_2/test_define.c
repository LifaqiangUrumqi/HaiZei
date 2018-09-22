/*************************************************************************
	> File Name: test_define.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 四  9/20 20:15:43 2018
 ************************************************************************/

#include <stdio.h>

#define NO_NUMBER_SIGN(x) x
#define SINGLE_NUMBER_SIGN(x) #x 
#define DOUBLE_NUMBER_SIGN(x, y) x##y

int main() {
    char lifaqianglifaqiang2[100] = "hello world\n";
    printf("%s\n", DOUBLE_NUMBER_SIGN(lifaqiang, lifaqiang2));
    //int lifaqiang, lifaqiang2;
    //scanf("%d", &lifaqiang);
    //scanf("%d", $lifaqiang2);
    //printf("%d\n", NO_NUMBER_SIGN(lifaqiang));
    //scanf("%s\n", f("lifaqiang", "lifaqiang2"));
    return 0;
}
