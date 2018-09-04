/*************************************************************************
	> File Name: EP_43_1.cpp
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  9/ 4 17:58:57 2018
 ************************************************************************/

/*
 * Problem 43
 * Sub-string divisibility
 *The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

 *Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

 *d2d3d4=406 is divisible by 2
 *d3d4d5=063 is divisible by 3
 *d4d5d6=635 is divisible by 5
 *d5d6d7=357 is divisible by 7
 *d6d7d8=572 is divisible by 11
 *d7d8d9=728 is divisible by 13
 *d8d9d10=289 is divisible by 17
 *Find the sum of all 0 to 9 pandigital numbers with this property.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

int is_not_prime[MAX_N + 5] = {0};
int prime[MAX_N + 5] = {0};
char numstr[] = "0123456789";
char get_numstr[10000][11];
int get_sum[20] = {1, 0};
int n = 0;

void Init_Prime() {//线性筛
    is_not_prime[0] = is_not_prime[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_not_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] >= MAX_N) break;
            is_not_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

void BigInteger_Addition(char getstr[10000][11]) {//运用大整数加法来求和
    for (int i = 0; i < n; i++) {
        printf("%s\n", getstr[i]);
        int len = strlen(getstr[i]);
        if (get_sum[0] < len) get_sum[0] = len;
        for (int j = 0; j < len; j++) {
            get_sum[len - j] += (getstr[i][j] - '0');
            printf("%d:", get_sum[len - j]);
        }
        for (int j = 1; j <= get_sum[0]; j++) {
            if (get_sum[j] < 10) continue;
            get_sum[j + 1] += (get_sum[j] / 10);
            get_sum[j] %= 10;
            get_sum[0] += (j == get_sum[0]);
        } 
        printf("\n");
    }
    for (int i = get_sum[0]; i > 0; i--) {
        printf("%d", get_sum[i]);
    }
    return ;
}

void Is_Divisibility_Property(char numstr[]) {//判断是是否是符合要求的数
    int flag = 0;
    for (int i = 1; i + 2 < strlen(numstr); i++) {
        int num = (numstr[i] - '0') * 100 + (numstr[i + 1] - '0') * 10 + (numstr[i + 2] - '0');
        if (num % prime[i]) {
            flag = 0;
            break;
        }
        flag = 1;
    }
    if (flag == 1) {
        strcpy(get_numstr[n], numstr);
        get_numstr[n][10] = '\0';
        n++;
    }
    return ;
}

void Swap(char *a, char *b) {//交换字符
    char tmp = *a;
    *a = *b;
    *b = tmp;
    return ;
}

void Full_Permutation(char numstr[], int k, int m) {//用递归来进行全排列
    if (k == m) {
        Is_Divisibility_Property(numstr);//找出符合要求的数
    } else {
        for (int i = k; i <= m; i++) {
            Swap(&numstr[k], &numstr[i]);
            Full_Permutation(numstr, k + 1, m);
            Swap(&numstr[k], &numstr[i]);
        }
    }
    return ;
}

int main() {
    Init_Prime();//初始化线性筛
    Full_Permutation(numstr, 0, 9);//0到9进行全排列
    BigInteger_Addition(get_numstr);//运用大整数加法来算出最终的和
    return 0;
}
