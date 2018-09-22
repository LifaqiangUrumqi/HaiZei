/*************************************************************************
	> File Name: 3.my_print.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 四  9/20 20:48:52 2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0, cnt = 0; frm[i]; i++, cnt++) {
        switch (frm[i]) {
            case '%' : {
                i++;
                switch(frm[i]) {
                    case 'd' : {
                        int temp = va_arg(arg, int), x = 0;
                        //printf("--%d--\n", temp);
                        while (temp) {
                            x = x * 10 + temp % 10;
                            temp /= 10;
                        }
                        while (x) {
                            putchar(x % 10 + '0');
                            x /= 10;
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
