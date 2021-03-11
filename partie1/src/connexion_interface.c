#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#define MAX 1024
#define PORT 8080 
#define SA struct sockaddr 
void func(int sockfd) 
{
	char buff[MAX];
	char data[MAX];
	FILE * fp; 

		bzero(buff, sizeof(buff)); 
		printf("Enter the file name : "); 
		scanf("%s",buff);
		send(sockfd, buff, sizeof(buff), 0);
		bzero(buff, sizeof(buff)); 
		recv(sockfd,buff,sizeof(buff),0);
		printf("recu %s",buff);
		 fp =fopen(buff, "r");
		if (fp == NULL) {

   		 perror("[-]Error in reading file.");
		 exit(1);
			}
		else {printf("succes\n");}
                while ( !feof( fp ) ) {
                fgets( data, MAX, fp );
                if ( ferror( fp ) ) {
               fprintf( stderr, "Reading error with code %d\n", errno );
               break;
              }else { printf("%s", data);} } 

} 
