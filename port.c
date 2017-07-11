#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>


#define MAXLINE 80


int port_isfree (int port)  
{  
	struct sockaddr_in sin;  
	int                sock = -1;  
	int                ret = 0;  
	int                opt = 0;  

	memset (&sin, 0, sizeof (sin));  
	sin.sin_family = PF_INET;  
	sin.sin_port = htons (port);  

	sock = socket (PF_INET, SOCK_STREAM, 0);  
	if (sock == -1)  
		return -1;  
	ret = setsockopt (sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof (opt));  
	ret = bind (sock, (struct sockaddr *)&sin, sizeof (sin));  
	close (sock);  

	return (ret == 0) ? 1 : 0;  
}  

int main(void)
{
	struct sockaddr_in servaddr;
	int sockfd,i,serverport,ret;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

	for( i = 0; i < 65535; i++) {
		int ret = port_isfree(i);
		if(ret == 1){
			//printf("端口 %d可用\n",i);
		} else {
			printf("端口 %d被占用\n",i);
		}
	}
	close(sockfd);
	return 0;
}

