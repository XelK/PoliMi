//		deadlock_mutex.c
//
#include <pthread.h>
#include <stdio.h>
pthread_mutex_t mutexA, mutexB;
void * lockApoiB(void * arg){
	pthread_mutex_lock (&mutexA);
	printf("thread %d: iniz 1\n",(int) arg);
	pthread_mutex_lock(&mutexB);
	printf("thread %d: iniz 2\n", (int) arg);		
	printf("thread %d: fine 2\n", (int) arg);
	pthread_mutex_unlock(&mutexB);
	printf("thread %d: fine 1\n", (int) arg);
	pthread_mutex_unlock (&mutexA);
	return NULL;
} //lockApoiB
void *lockBpoiA (void *arg){
	pthread_mutex_lock (&mutexB);
	printf("thread %d: iniz 2\n", (int) arg);
	pthread_mutex_lock(&mutexA);
	printf("thread %d: fine 2\n", (int) arg);
	pthread_mutex_unlock(&mutexB);
	return NULL;
}//lockBpoiA
int main(void){
	pthread_t tID1, tID2;
	pthread_mutex_init(&mutexA,NULL);
	pthread_mutex_init(&mutexB,NULL);
	pthread_create(&tID1, NULL, &lockApoiB, (void *)1);
	pthread_create(&tID2, NULL, &lockApoiB, (void *)2);
	pthread_join(tID1,NULL);
	pthread_join(tID2,NULL);
	printf("fine\n");
	return 0;
} //main
