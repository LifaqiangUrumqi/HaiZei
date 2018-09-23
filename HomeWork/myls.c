/*************************************************************************
	> File Name: myls.c
	> Author: Lifaqiang
	> Mail: 576245069@qq.com 
	> Created Time: 日  9/22 17:41:55 2018
 ************************************************************************/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void mode_to_letters(int mode, char *str) {
	strcpy(str,"----------");	/*default=无参数*/
    if (S_ISDIR(mode))//目录文件
		str[0] = 'd';
	if (S_ISCHR(mode))//文件设备文件
		str[0] = 'c';
	if (S_ISBLK(mode))//块设备文件
		str[0] = 'b';
    if (S_ISFIFO(mode))//管道文件
		str[0] = 'f';
	if (S_ISSOCK(mode))//套接字文件
		str[0] = 's';
	if (S_ISLNK(mode))//链接文件
		str[0] = 'l';

	if (mode & S_IRUSR)//用户权限
		str[1]='r';
	if (mode & S_IWUSR)
		str[2]='w';
	if (mode & S_IXUSR)
		str[3]='x';
	
	if (mode & S_IRGRP)//组权限
		str[4]='r';
	if (mode & S_IWGRP)
		str[5]='w';
	if (mode & S_IXGRP)
		str[6]='x';

	if (mode & S_IROTH)//其他人权限
		str[7]='r';
	if (mode & S_IWOTH)
		str[8]='w';
	if (mode & S_IXOTH)
		str[9]='x';
}

void dostat(char *filename, int flag) {
	struct stat info;
	char modestr[11]; //模式字符串
	stat(filename, &info); //获取文件详细信息
	mode_to_letters(info.st_mode, modestr); //将模式等用字符wrx表示
    if (flag > 1) {
	    printf("%s", modestr);
	    //st_nlink链接该文件的硬链接数，刚建立的文件值为1
	    printf("%4d ", (int)info.st_nlink);
	    printf("%-8s ", getpwuid(info.st_uid)->pw_name);//输出用户名
	    printf("%-8s ", getgrgid(info.st_gid)->gr_name);//输出组名
	    printf("%8ld ", (long)info.st_size);//输出大小
        printf("%.12s ", 4 + ctime(&info.st_mtime));//输出时间信息
    }
    if (modestr[0] == 'd') {
        printf("\033[01;36m%s\033[0m\n", filename);//输出文件名，浅蓝色代表目录文件
    } else if (modestr[0] == 'c') {
        printf("\033[01;34m%s\033[0m\n", filename);//输出文件名，深蓝色代表文件设备
    } else if (modestr[0] == 'b') {
        printf("\033[01;33m%s\033[0m\n", filename);//输出文件名，黄色代表块设备文件
    } else if (modestr[0] == 'f') {
        printf("\033[01;30m%s\033[0m\n", filename);//输出文件名，灰色代表管道文件
    } else if (modestr[0] == 's') {
        printf("\033[01;32m%s\033[0m\n", filename);//输出文件名，绿色代表套接字文件
    } else if (modestr[0] == 'l') {
        printf("\033[01;35m%s\033[0m\n", filename);//输出文件名，粉色代表链接文件
    } else {
        printf("%s\n", filename);//输出文件名
    }
}



void do_ls(char dirname[], int flag) {
    DIR *dir;
    struct dirent *direntp;
    if ((dir = opendir(dirname)) == NULL) {
        printf("");
    } else {
        while ((direntp = readdir(dir)) != NULL) {
            if ((flag == 0 || flag == 2) && (direntp->d_name[0] == '.' || (direntp->d_name[0] == '.' && direntp->d_name[1] == '.'))) continue;
            dostat(direntp->d_name, flag);
        }
    }
    
}


int main(int argc, char *argv[]) {
    int flag;
    if (argc == 1) {
        flag = 0;
        do_ls(".", flag);
    }
    else if (argc == 2) {
        if (strcmp(argv[1], "-a") == 0) {
            flag = 1;
            do_ls(".", flag);
        } else if (strcmp(argv[1], "-l") == 0) {
            flag = 2;
            do_ls(".", flag);
        } else if (strcmp(argv[1], "-al") == 0 || strcmp(argv[1], "-la") == 0) {
            flag = 3;
            do_ls(".", flag);
        } else {
            while (argc--) {
                flag = 0;
                do_ls(*++argv, flag);
            }
        }
    } else if (argc > 2) {
        if (strcmp(argv[1], "-a") == 0) {
            if (strcmp(argv[2], "-l") == 0 && argc == 3) {
                flag = 3;
                do_ls(".", flag);
            } else {
                argc--;
                argv++;
                while (argc--) {
                flag = 1;
                do_ls(*++argv, flag);
                }
            } 
        } else if (strcmp(argv[1], "-l") == 0) {
            if (strcmp(argv[2], "-a") == 0 && argc == 3) {
                flag = 3;
                do_ls(".", flag);
            } else {
                argc--;
                argv++;
                while (argc--) {
                flag = 2;
                do_ls(*++argv, flag);
                }
            }
        } else if (strcmp(argv[1], "-al") == 0 || strcmp(argv[1], "-la") == 0) {
            argc--;
            argv++;
            while (argc--) {
            flag = 3;
            do_ls(*++argv, flag);
            }
        }
    }
    return 0;
}
