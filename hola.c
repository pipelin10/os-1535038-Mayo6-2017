#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define MAXTHREADS 32751

void *imprimirHola(void* null){
	pthread_t id = pthread_self();
	printf("hola %ld\n", (long)id);
	pthread_exit(NULL);
	return NULL;
}

int main(int argc, char **argv){
	long numHilos;
	
	if (argc != 2) {
		printf("Por favor digite un numero hilos a usar\n");
		printf("\t%s <numhilos>\n",argv[0]);
		exit(-1);
	}
	
	numHilos = atoi(argv[1]);
	
	if (numHilos > MAXTHREADS){
		printf("Por favor ingrese un numero menor. \n");
		exit(-1); 
	}
	
	pthread_t hilos[MAXTHREADS];
	
	
	
	for (int i = 0; i < numHilos; i++){
		pthread_create(&hilos[i], NULL, imprimirHola, NULL);	
	}
	for (int i = 0; i < numHilos; i++){
		pthread_join(hilos[i],NULL);
	}
	pthread_exit(NULL);
	return 0;
}
