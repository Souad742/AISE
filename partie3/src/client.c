#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include"client.h"
#define MAX 1024
#define PORT 10000
//fonction d'envoie de de récéption des informations

int main(){

	int clientSocket, ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];
        //création de la socket on spécifiant IPV4, protocole utilisé= tcp, le dérnier argument est souvent à 0
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("[-]Erreur de connexion.\n");
		exit(1);
	}
	printf("socket de client a été créé\n");
        //Mise à zéro du tampon de façon à connaître le délimiteur de fin de chaîne.
	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;//IPV4
	serverAddr.sin_port = htons(PORT);//on spécifie le port
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");//on spécifie l'adresse
        //connexion du client
	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
 
	if(ret < 0){
		printf("erreur de connexion.\n");
		exit(1);
	}
	       printf("client connécté au serveur.\n");


                 pthread_t mythread;
                 while(1){
		
		pthread_create( &mythread , NULL , (void*)func , (void*)clientSocket);
		//Now join the thread , so that we dont terminate before the thread
		pthread_join( mythread , NULL);}



         //fermer la socket
	close(clientSocket);

	return 0;
}
