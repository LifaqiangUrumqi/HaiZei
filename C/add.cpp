/*************************************************************************
	> File Name: add.cpp
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  8/21 10:29:21 2018
 ************************************************************************/

#include <iostream>
using namespace std;

int add(int a, int b) {
    if (b == 0) return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return add(sum, carry);
}


int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        printf("%d\n", add(a, b));
    }
    return 0;

}
