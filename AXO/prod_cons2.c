// prod_cons2.c
// programma correto della versione prod_cons1.c

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

char buffer;
int fine = 0;
sem_t pieno, vuoto;

void * scrivi (void *arg){
	int i;
	for (i=0; i<5; i++){
		sem_wait(&vuoto);
		buffer = 'a' +i;
		if (i==4) fine =1;
		sem_post (&pieno);
	}//for
	return NULL;
}//scrivi

void *leggi (void *arg){
	char miobuffer;
	int i;
	while (fine == 0){
		sem_wait(&pieno);
		miobuffer = buffer;
		sem_post(&vuoto);
		printf("buffer contiene %.1s\n",&miobuffer);
	}//while

	//controllo per l'ultimo carratter agg alla versione precedente
	sem_getvalue (&pieno, &i);
	if(i==1){
		miobuffer = buffer;
		printf("buffer contiene %.1s\n",&miobuffer);
	}//if
	return NULL;
}//leggi

//produttore consumatore con semafori
int main(void){
	pthread_t tID1, tID2;
	sem_init (&pieno, 0, 0); //inizializza semafori
	sem_init(&vuoto, 0, 1);
	//buffer vuoto all'inizio
	pthread_create(&tID1, NULL, &scrivi, NULL);
	pthread_create(&tID2, NULL, &leggi, NULL);
	pthread_join (tID1, NULL);
	pthread_join(tID2, NULL);
	printf("fine\n");
	return 0;
}//main

