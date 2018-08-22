/*************************************************************************
	> File Name: 10.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 二  7/31 14:36:10 2018
 ************************************************************************/

#include <iostream>
#include <cinttypes>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 2000000

int prime[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = 2 * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    int64_t sum = 0;
    for (int i = 2; i <= MAX_N; i++) {
        prime[i] == 0 && (sum += i);
    }
    printf("%" PRId64 "\n", sum);
    return 0;
}
