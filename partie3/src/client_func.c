#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX 1024
#define PORT 10000

void func(int clientSocket) 
{
	char buff[MAX];
	char data[MAX];
	FILE * fp; 

		//bzero(buff, sizeof(buff)); 
		printf("msg to send : "); 
		scanf("%s",buff);
		send(clientSocket, buff, sizeof(buff), 0);
		bzero(buff, sizeof(buff)); 

		recv(clientSocket,buff,sizeof(buff),0);
		printf("recu %s \n",buff);

 }
