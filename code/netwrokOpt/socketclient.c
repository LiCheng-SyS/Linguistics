#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<pthread.h>
#include<sys/types.h>
#include <sys/socket.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define SERV_PORT 5000
#define MAXLINE 80
int main(){
    struct sockaddr_in serveraddr,clientaddr;
    int sockfd=  socket(AF_INET,SOCK_STREAM,0);
    
    char buf[MAXLINE]={"xxxx"};
    bzero(&serveraddr,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(SERV_PORT);
    inet_pton(AF_INET,"127.0.0.1",&serveraddr.sin_addr);
    connect(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));

    write(sockfd,buf,strlen(buf));
     
    int rlen= read(sockfd,buf,MAXLINE);
    printf("respose from server :\n");
    write(1,buf,rlen);
    close(sockfd);
    return 0;
}
