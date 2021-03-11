#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAX 1024
#define PORT 10000

int main(){

	int sockfd, ret;
	 struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	pid_t childpid;
         //creation de la socket serveur
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("erreur de connexion.\n");
		exit(1);
	}
	printf("la socket de serveur à été créé.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        //lier la socket à l'adresse et au port 
	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("erreur au niveau du binding.\n");
		exit(1);
	}
	printf("attacher le socket au port %d\n", 10000);
         //serveur en écoute des connexions des clients qui sont définies dans la structure sockaddr
	if(listen(sockfd, 10) == 0){
		printf("serveur en écoute .....\n");
	}else{
		printf("erreur de bind.\n");
	}


	while(1){
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);		
                if(newSocket < 0){
			exit(1);
		}
		printf("connexion vient de %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

		if((childpid = fork()) == 0){
			close(sockfd);

			while(1){
				recv(newSocket, buffer, 1024, 0);
				if(strcmp(buffer, ":exit") == 0){
					printf("déconnecté de %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}else{
					printf("Client: %s\n", buffer);
                                         char buff[MAX];
                                        printf("envoyer un message : "); 
		                        scanf("%s",buff);
					send(newSocket, buff, strlen(buffer), 0);
					bzero(buffer, sizeof(buffer));
				}
			}
		}

	}


	return 0;
}
