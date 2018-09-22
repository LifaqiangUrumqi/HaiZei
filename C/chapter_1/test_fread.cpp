/*************************************************************************
	> File Name: test_fread.cpp
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 二  9/18 20:27:01 2018
 ************************************************************************/

#include <stdio.h>
#include <string.h>\

int main() {
    FILE *fp;
    char c[] = "This is runoob";
    char buffer[20];

    /* 打开文件用于读写 */ 
    fp = fopen("file.txt", "w+");

    /* 写入数据文件 */ 
    fwrite(c, strlen(c) + 1, 1, fp);

    /* 查找文件的开头 */
    fseek(fp, SEEK_SET, 0);

    /* 读取并显示数据 */
    fread(buffer, strlen(c) + 1, 1, fp);
    printf("%s\n", buffer);
    fclose(fp);

    return 0;
}
