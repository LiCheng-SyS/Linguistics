#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<ctype.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */

#define SERV_PORT 5000
#define MAXLINE 80
int main(){
    struct sockaddr_in serveraddr,clientaddr;
    int listenfd,connfd;

    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];

    int readlen;

    socklen_t client_adr_len;
    // 第一个参数为网络类型,以什么类型传输,协议默认为0
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    //listen 完成 next bind
    //首先全部清掉   
    bzero(&serveraddr,sizeof(serveraddr));
    //IP PROT INIT 
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(SERV_PORT);//按照协议要求得转网络字节序
    serveraddr.sin_addr.s_addr=htons(INADDR_ANY); //ip 地址 这个宏是监听所有的
    //addr 指定地址分配给文件描述符sockfd引用的套接字  这时分配完成 next listen
    bind(listenfd,(struct sockaddr *) &serveraddr,sizeof(serveraddr));
    //限制socket监听队列中未完成的队列为3三个
    listen(listenfd,3);
    //next 等待client 链接

    printf("WAIT connections\n");

    while(1){
        //第一个为监听的文件描述符, 链接过来的地址，参数3为长度
        client_adr_len=sizeof(clientaddr);
        connfd = accept(listenfd,(struct sockaddr*)&clientaddr,&client_adr_len);
        //数据的值 connfd 
        //如果需要打印客户端的网络地址的话需要借助 inet_ntop  返回IP地址 //ntohs 转回主机字节序
        printf("received from %s:%d\n",\
               inet_ntop(AF_INET,&clientaddr.sin_addr,str,sizeof(str)),
               ntohs(clientaddr.sin_port));

        readlen=read(connfd,buf,MAXLINE);
        for(int i=0;i<readlen;i++){
            buf[i]=toupper(buf[i]);
        }
        //写回
        write(connfd,buf,readlen);

        close(connfd);
    }

    return 0;
}
