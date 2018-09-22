/*************************************************************************
	> File Name: switchcase.cpp
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  9/18 18:52:52 2018
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    while(~scanf("%d", &n)) {
        switch (n) {
            case 1: printf("1\n"); break;
            case 2: printf("2\n"); break;
            case 3: printf("3\n"); break;
            default: printf("error\n"); break;
        }
    }
    return 0;
}
