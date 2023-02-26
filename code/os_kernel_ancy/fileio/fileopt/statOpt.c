#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char *argv[]){
    if(argc<2){
        printf("usage : cmd  filename /dirname\n");
        exit(1);
    }


    struct stat st;
    stat(argv[1],&st);

    /*
    if(S_ISDIR(st.st_mode))
    {
        printf("directory\n");
    }else{
        printf("other file type");
    }
    */
    switch(st.st_mode & S_IFMT){
    case  S_IFREG:
        printf("other file type\n");
        break;
    case  S_IFDIR:
        printf("dir file type\n");
        break;
    case  S_IFCHR:
        printf("charactor device\n");
        break;
    default:
        printf("other file type\n");
    }



    return 0;
}
