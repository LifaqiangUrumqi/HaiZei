/*************************************************************************
 > File Name: euler_03_1.cpp
 > Author: lifaqiang
 > Mail:   576245069@qq.com
 > Created Time: 二  7/31 16:49:27 2018
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>
#define MAX 600851475143

int main() {
    int64_t num = MAX, n = 2, ans = 0;
    while (n * n <= num) {
        if (num % n == 0) ans = n;//当可以整除时，记录这个除数
        while (num % n == 0) num /= n;//当一只可以被整除，那就一直除下去
        n++;//走下一个数
    }
    if (num != 1) ans = num;//当最后一个数不是平方数时，ans等于这个数
    printf("%"PRId64"\n", ans);
    return 0;
}
