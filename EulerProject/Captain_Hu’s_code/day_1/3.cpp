/*************************************************************************
	> File Name: 3.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 二  7/31 14:07:18 2018
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using std::cin;
using std::cout;
using std::endl;

#define NUM 600851475143

int main() {
    int64_t num = NUM, ans = 0;
    for (int64_t i = 2; i * i <= num; i++) {
        if (num % i) continue;
        while (num % i == 0) num /= i;
        ans = i;
    }
    if (num) ans = num;
    printf("%" PRId64 "\n", ans);
    return 0;
}
