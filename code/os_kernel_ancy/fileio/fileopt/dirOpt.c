#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
void printfdir(char *dirname){
    char pathname[1024];
    DIR *dir;//代表目录
    struct dirent *dp;
    struct stat st;
    if(!(dir=opendir(dirname))){
        perror("opendir fail");
        exit(1);
    }
    while(dp=readdir(dir)){
        //只要为真 就可以一直读
        if(!strcmp(dp->d_name,".")||!strcmp(dp->d_name,"..")){
        //  判断是否有这个路径//如果有跳出去
            //strcmp0是相等
            //printf(" path L->>>> %s ",dp->d_name);
            continue;
        }
        sprintf(pathname,"%s/%s",dirname,dp->d_name);
        if(stat(pathname,&st)<0) {
            perror(" stat");
            exit(1);
        }
        //如果是路径
        if(S_ISDIR(st.st_mode)){
            printfdir(pathname);
        }
        printf("%s\n",dp->d_name);
    }
    putchar(10);
    closedir(dir);
}



int main(int argc,char **argv){
    if(argc<2){
        printf("use : cmd +path\n");
        return 1;
    } 
    //每次都是结构体
    printfdir(argv[1]);
    return 1;
}
