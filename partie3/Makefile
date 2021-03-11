CC?=gcc
AR?=ar

all:first dynamic program_client program_serveur 

first:
	mkdir -p ./build/lib ./build/include	
        

dynamic: src/client_func.c build/include/client.h
	$(CC) -shared -fPIC -o build/lib/libclient.so $<	



program_client: src/client.c build/include/client.h dynamic 

	$(CC) -o build/$@ $< -I./build/include -L./build/lib -lclient -l pthread

program_serveur: src/serveur.c  

	$(CC) -o build/$@ $<
	


clean:
	rm -rf ./build/lib
	

.PHONY:  dynamic parogram_client program_serveur






