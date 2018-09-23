/*************************************************************************
	> File Name: 3.my_print.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 日  9/22 10:46:13 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>

int64_t my_printf(const char *frm, ...) {
    int64_t cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cnt = 0; frm[i]; i++, cnt++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        int64_t temp = va_arg(arg, int32_t), x = 0;
                        int64_t num = 2 * (INT32_MAX + 1) - temp;
                        if (num < 0) num = temp;
                        else putchar('-');
                        int64_t bit = log10(num);
                        bit = pow(10, bit);
                        while (bit) {
                            putchar(num / bit + '0');
                            num %= bit;
                            bit /= 10;
                        }
                    } break;
                    default :
                        fprintf(stderr, "error : unknow %%%c\n", frm[i]);
                        exit(1);
                }
            } break;
            default:
                putchar(frm[i]);
        }
    }
    return cnt;
}

int main() {
    int n = 123;
    my_printf("hello world\n");
    my_printf("n = %d\n", n);
    my_printf("n = %d\n", 12000);
    my_printf("n = %d\n", -567);
    my_printf("n = %d\n", INT32_MIN);
    my_printf("n = %d\n", INT32_MAX);
    return 0;
}
