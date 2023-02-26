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

typedef struct msgbufer {
    long mtype;       /* message type, must be > 0 */
    char mtext[MSGLEN];    /* message data */
}MSG;




int main(){
    key_t key=ftok("./upper.c",9);
    int msgid= msgget(key,IPC_CREAT| 0666);  //创建消息队列返回一个id
    printf(" mdid=%d\n",msgid);
    //发送一条消息,此操作被中断后不会被重启    
    MSG msg;
    //倒数的为队列编号  最后一个参数为类型
    msgrcv(msgid,&msg,MSGLEN,2,0);
    printf("msg.type =%ld\n msg.text=%s\n",msg.mtype,msg.mtext);
    
    msgrcv(msgid,&msg,MSGLEN,1,0);
    printf("msg.type =%ld\n msg.text=%s\n",msg.mtype,msg.mtext);
    
    return 0;
}
