/*************************************************************************
	> File Name: 6.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 二  7/31 14:12:12 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= 100; i++) {
        sum1 += i;
        sum2 += i * i;
    }
    printf("%d\n", sum1 * sum1 - sum2);
    return 0;
}
