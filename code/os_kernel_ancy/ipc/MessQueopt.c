#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGLEN 20

typedef struct msgbufer{
    long mtype;
    char mtext[MSGLEN];
}MSG;

int main()
{
    key_t key=ftok("./upper.c",9);
    int msgid= msgget(key,IPC_CREAT| 0666);  //创建消息队列返回一个id
    printf(" mdid=%d\n",msgid);
    //发送一条消息,此操作被中断后不会被重启
    MSG msg;
    msg.mtype=1;
    //目的区域，源，长度
    strncpy(msg.mtext,"hello\n",MSGLEN);
    msgsnd(msgid,&msg,MSGLEN,0);
    
    msg.mtype=2;  //协议
    strncpy(msg.mtext,"shangxian:online\n",MSGLEN);
    msgsnd(msgid,&msg,MSGLEN,0);

    //目的区域，源，长度
    return 0;
}
