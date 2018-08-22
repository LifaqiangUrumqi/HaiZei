/*************************************************************************
	> File Name: 7.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 二  7/31 14:29:48 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 200000
int prime[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        prime[i] == 0 && (prime[++prime[0]] = i);
    }
    printf("%d\n", prime[10001]); 
    return 0;
}
