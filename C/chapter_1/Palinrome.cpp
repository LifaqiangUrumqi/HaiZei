/*************************************************************************
	> File Name: Palinrome.cpp
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  9/18 19:42:47 2018
 ************************************************************************/

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (__builtin_expect(!!(x < 0), 0)) return false;
    int y = 0, z = x;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return z == y;
}

int main() {
    return 0;
}
