#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <errno.h>
#define MAX 1024
#define PORT 8080 
#define SA struct sockaddr 
// function send_file 
// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
 char buff[MAX]={0};
	
   
   recv(sockfd,buff,sizeof(buff),0);
   printf("Message received: %s \n", buff);
   bzero(buff, MAX);  
   strcpy(buff, "htop");
    if (send(sockfd, buff, sizeof(buff), 0) == -1) {
          perror("[-]Error in sending file.");
          exit(1);
     }else {printf("file send!"); }
    bzero(buff, MAX); 
        
} 
