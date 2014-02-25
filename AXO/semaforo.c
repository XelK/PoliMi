/*
 * 			semaforo.c
 *  This programe dimostare the use of semaphores in c
 *  the scope of program is print the sting "axbycz"
 *  with use of 2 threads, where tread 1 can print abc 
 *  and tread 2 xyz, so we use semaphore to regular the 
 *  execution of program cicle
 *
 */
#include <pthread.h> 
#include <stdio.h> 
#include <semaphore.h>
sem_t sem1, sem2;
void * tf1 (void * arg){
	sem_wait (&sem1);
	printf("x");
	sem_post(&sem2);
	sem_wait(&sem1);
	printf("y");
	sem_post(&sem2);
	sem_wait(&sem1);
	printf ("z");
	return NULL;
} //tf1
void *tf2 (void * arg){
	printf("a");
	sem_post(&sem1);
	sem_wait(&sem2);
	printf("b");
	sem_post(&sem1);
	sem_wait(&sem2);
	printf("c");
	sem_post(&sem1);
	return NULL;
} // tf2
int main (void){
	pthread_t tID1, tID2;
	sem_init(&sem1, 0, 0);
	sem_init(&sem2, 0, 0);
	pthread_create(&tID1, NULL, &tf1, NULL);
	pthread_create(&tID2, NULL, &tf2, NULL);
	pthread_join (tID1, NULL);
	pthread_join (tID2, NULL);
	printf("\nfine\n");
	return 0;
} //main
