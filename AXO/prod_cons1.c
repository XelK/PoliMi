//				prod_cons1.c
// produttore consumatore con semafori versione con errore
// programma che mostra l'utilizzo dei semafori
// dove uno o piu thread produttori scrivono caratteri  e uno o piu tread
// consumatori leggono caratteri
//
// questa e' la versione piu semplice docve il buffer puo' contenere un solo
// carattere:
// - un thread vi scrive caratteri in sequenza (produttore)
// - un tread legge i caratteri uno alla volta (consumatore)
//
// Occorrono due semafori che indicano lo stato del buffer:
// - pieno per bloccare il consumatore (inizializzato a 0)
//   usato per bloccare il consumatore
// - vuoto per bloccare il produttore (inizializzato a 1)
//	 usato per bloccare il produttore
//
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
char buffer;
int fine =0;
sem_t pieno, vuoto;

void * scrivi (void *arg){
	int i;
	for(i=0;i<5;i++){
		sem_wait(&vuoto);
		buffer = 'a' +i;
		sem_post(&pieno);
	}//for
	fine =1;
	return NULL;
}//scrivi
void * leggi(void * arg){
	char miobuffer;
	int i;
	while (fine == 0){
		sem_wait (&pieno);
		miobuffer = buffer;
		sem_post (&vuoto);
		printf ("il buffer contiene %.1s\n",&miobuffer);
	}//while
	return NULL;
}//leggi
int main (void){
	pthread_t tID1, tID2;
	sem_init(&pieno, 0, 0);
	sem_init(&vuoto, 0, 1);
	//buffer vuoto all'inizio
	pthread_create(&tID2, NULL, &leggi, NULL);
	pthread_create(&tID1, NULL, &scrivi, NULL);
	pthread_join(tID1,NULL);
	pthread_join(tID2,NULL);
	printf("\nfine");
	return 0;
}//main
