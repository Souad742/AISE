CC?=gcc
AR?=ar

all:first static static1 static2 static3 program_info program_interface program_capteur

first:
	mkdir -p ./build/lib ./build/include

static: src/info.c build/include/info.h
	$(CC) -c $< -o info.o
	$(AR) rcs build/lib/libinfo.a info.o

static1: src/memory_capacity.c build/include/info.h
	$(CC) -c $< -o memory_capacity.o
	$(AR) rcs build/lib/libmemory_capacity.a memory_capacity.o

static2: src/connexion_capteur.c build/include/connexion_capteur.h
	$(CC) -c $< -o connexion_capteur.o
	$(AR) rcs build/lib/libconnexion_capteur.a connexion_capteur.o
        

static3: src/connexion_interface.c build/include/interface.h
	$(CC) -c $< -o interface.o
	$(AR) rcs build/lib/libinterface.a interface.o


program_info: src/main.c build/include/info.h static static1

	$(CC) -o build/$@_static -static $< -I./build/include -L./build/lib -linfo -lmemory_capacity 



program_interface: src/main_interface.c build/include/interface.h static3 

	$(CC) -o build/$@_static -static $< -I./build/include -L./build/lib -linterface


program_capteur: src/main_capteur.c build/include/connexion_capteur.h static2 

	$(CC) -o build/$@_static -static $< -I./build/include -L./build/lib -lconnexion_capteur
	./build/program_info_static >htop


clean:
	rm -rf ./build/lib

.PHONY: static static1 static2 static3 program_info parogram_interface program_capteur
