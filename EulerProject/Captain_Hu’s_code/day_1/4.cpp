/*************************************************************************
	> File Name: 4.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 二  7/31 14:10:17 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int is_valid(int x) {
    int temp = x, num = 0;
    while (x) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return temp == num;
}

int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            if (is_valid(i * j) && i * j > ans) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
