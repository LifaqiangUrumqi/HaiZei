/*************************************************************************
	> File Name: T_1_2.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 五  9/ 7 18:44:26 2018
 ************************************************************************/

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main() {
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));    
    }
    // float fahr, celsius;
    // int lower, upper, step;

    // lower = 0;             /* 温度表的下限 */
    // upper = 300;           /* 温度表的上限 */
    // step = 20;             /* 步长 */ 

    // celsius = lower;
    // printf("Celsius  Fahr");
    // while (fahr <= upper) {
        // fahr = 9 * celsius / 5 + 32;
        // printf("%3.0f  %6.1f\n", celsius, fahr);
        // celsius = 5 * (fahr - 32) / 9;
        // printf("%3.0f  %6.1f\n", fahr, celsius);
        // celsius += step;
    return 0;
}
