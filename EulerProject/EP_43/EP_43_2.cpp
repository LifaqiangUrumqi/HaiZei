/*************************************************************************
	> File Name: EP_43_2.cpp
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  9/ 4 23:35:26 2018
 ************************************************************************/

#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int64_t Is_Interesting(int32_t a[]) {
    if (a[0] == 0) return 0;
    int32_t p[7] = {2, 3, 5, 7, 11, 13, 17}, j = 0;
    int64_t num = a[0], ret = a[0];
    for (int32_t i = 1; i < 10; i++) {
        num = 10 * num + a[i];
        ret = 10 * ret + a[i];
        if (i < 3) continue;
        num -= 1000 * a[i - 3];
        if (num % p[i]) return 0;
    }
    return ret;
}


int32_t main() {
    int32_t a[10];
    for (int32_t i = 0; i < 10; i++) {
        a[i] = i;
    }
    int64_t sum = 0;
    do {
        sum += Is_Interesting(a);
    } while (next_permutation(a, a + 10));
    printf("%"PRId64"\n", sum);
    return 0;
}
