#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 1024
#define ERR_EXIT(s) \
    do{\
        perror(s);\
        exit(1);\
    }while(0)

int main(){
    int listenfd;
    if((listenfd=socket(AF_INET,SOCK_STREAM,0))<0)  ERR_EXIT("socket");
    struct sockaddr_in servaddr;
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(8888);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    if(bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0) ERR_EXIT("bind");

    if(listen(listenfd,SOMAXCONN)<0) ERR_EXIT("listen");
    struct sockaddr_in clientaddr;
    int len = sizeof(clientaddr);
    int connfd;
    if((connfd=accept(listenfd,(struct sockaddr *)&clientaddr,&len))<0) ERR_EXIT("accept");
    printf("a client connected: ip=%s, port=%d\n",inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));

    char bufread[N]={0};
    while(1){
        memset(bufread,0,sizeof(bufread));
        int ret = read(connfd,bufread,sizeof(bufread));
        fputs(bufread,stdout);
        int i ;
        for(i=0;i<ret;i++) 
            bufread[i]=toupper(bufread[i]);
        write(connfd,bufread,ret);
    }
    close(connfd);
    close(listenfd);
    return 0;
}
