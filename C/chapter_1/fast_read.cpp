/*************************************************************************
	> File Name: fast_read.cpp
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  9/18 19:57:24 2018
 ************************************************************************/

#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

char ss[1<<17], *A = ss, *B == ss;
inline char gc() {
    /* 先判断A == B 如果成功运行&&之后的代码 */
    /* 再运行(A == ss) + fread(ss, 1, 1 << 17, stdin)， fread表示读入ss的数据，如果没读入进来，fread返回值为0，否则不为0，  */
    /* 当fread返回值为零那么相当于B = (A = ss) + 0，则表示为A == B，逗号之前运行完之后，运行逗号后面的表达式，逗号之后的的表达式为A == B，如果fread返回值为0，那么A == B的值为1，则运行-1，否则若读入的数不为空，则运行*A++，意思是指针指向A的下一行地址，即A读入下个数组。  */
    return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? -1 : *A++;
}

template<template T> inline void sdf(T &x) {
    char c;
    T y;
    /* 依次按指针读入gc中的字符，因为数字的ASCII码在48到57之间，所以这一个语句的意思是寻找这个字符中是否含有负号，如果有则y=-1 */
    while (c = gc(), (c < 48 || c > 57) && c != -1) {
        if (c == '-') y = -1;
    }
    /* 等同于x = c - 48，意思就是讲字符数字转化成数字，用^比-更快 */
    x = c ^ 48;

    /* 如果字符是数字里面，那么(x<<1)+(x<<3)意思是x*10，因为x<<1即x*2，x<<3即x*8，c ^ 48意思是c - 48，即将数字字符转化成数字  */
    while (c = gc(), (c <= 57 && c >= 48)) {
        x = (x << 1) + (x << 3) + (c ^ 48);
    }
    /* 若y=-1则表示x为负数，否则为正数 */
    x *= y;
}

int main() {
    int n, a;
    sdf(n);
    for (int i = 0; i < n; i++) {
        sdf(a);
    }
    return 0;
}
