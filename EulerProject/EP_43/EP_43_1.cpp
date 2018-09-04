/*************************************************************************
	> File Name: EP_43_1.cpp
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  9/ 4 17:58:57 2018
 ************************************************************************/

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

void Init_Prime() {
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

void BigInteger_Addition(char getstr[10000][11]) {
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

void Is_Divisibility_Property(char numstr[]) {
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

void Swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
    return ;
}

void Full_Permutation(char numstr[], int k, int m) {
    if (k == m) {
        //printf("%s", numstr);
        //printf("\n");
        Is_Divisibility_Property(numstr);
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
    Init_Prime();
    Full_Permutation(numstr, 0, 9);
    BigInteger_Addition(get_numstr);
    //for (int i = 1; i <= 100; i++) printf("%d\n", prime[i]);
    return 0;
}
