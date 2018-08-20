/*************************************************************************
	> File Name: 5.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 二  7/31 14:28:21 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int ans = 1;
    for (int i = 2; i <= 20; i++) {
        ans = ans / gcd(ans, i) * i;
    }
    printf("%d\n", ans);
    return 0;
}
