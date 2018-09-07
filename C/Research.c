/*************************************************************************
	> File Name: Research.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 五  9/ 7 20:40:21 2018
 ************************************************************************/
/*
 * 在一个二维数组中（每个一维数组的长度相同），
 * 每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，
 * 判断数组中是否含有该整数。
 */

#include <stdio.h>

int main() {
    int num[100][100];
    int row, column;
    int search_number;
    int x, y, flag = 0;

    printf("Please input row and column: "); /* 输入行和列 */
    scanf("%d%d", &row, &column);
    printf("\n");

    printf("Please input a dyadic array:\n"); /* 输入符合要求的二维数组 */
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    printf("\n");

    printf("Please input serach number: "); /* 输入要查找的数 */
    scanf("%d", &search_number);
    printf("\n");

    /* 
     * 二位数组从左下角开始查找，若大于search_number往右走。
     * 否则往走当相等时置flag标志位为1，并退出！
     */
    x = row - 1;
    y = 0;
    while (x >= 0 && y <= column) {
        if (num[x][y] > search_number) {
            x--;
        } else if (num[x][y] < search_number) {
            y++;
        } else {
            flag = 1;
            break;
        }
    }

    /*
     * 输出结果。
     * 当标志位为1时，查找成功，并输出行和列。
     * 当标志位为0时，查找失败。
     */
    if (flag) printf("Find Successfully!\nrow: %d\ncolumn: %d\n", x + 1, y + 1);
    else printf("Find Fail!\n");
    
    return 0;
}
