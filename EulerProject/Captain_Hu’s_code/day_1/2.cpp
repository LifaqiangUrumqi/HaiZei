/*************************************************************************
	> File Name: 2.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 二  7/31 14:04:58 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int a = 1, b = 2, sum = 0;
    while (b <= 4000000) {
        b % 2 == 0 && (sum += b);
        b = a + b;
        a = b - a;
    }
    printf("%d\n", sum);
    return 0;
}
