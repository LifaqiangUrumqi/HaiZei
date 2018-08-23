/*************************************************************************
	> File Name: 11.cpp
	> Author: hug
	> Mail:   hug@haizeix.com
	> Created Time: 二  7/31 14:39:18 2018
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 20

int num[MAX_N + 10][MAX_N + 10] = {0};
int dir[4][2] = {
    0, 1, 1, 0, 1, 1, 1, -1
};

int main() {
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            scanf("%d", num[i] + j);
        }
    } 
    int ans = 0;
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            for (int k = 0; k < 4; k++) {
                int p = 1;
                for (int step = 0; step < 4; step++) {
                    int x = i + step * dir[k][0];
                    int y = j + step * dir[k][1];
                    p *= num[x][y];
                }
                if (p > ans) ans = p;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
