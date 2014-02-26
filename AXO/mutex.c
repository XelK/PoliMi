//		mutex.c
//	trasferimento sincronizzato con mutex
//
#include <pthread.h>
#include <stdio.h>
int contoA = 100, contoB = 200;
int totale;
pthread_mutex_t conti; //dichiarazione di mutex
void * trasferisci (void * arg){
	int importo = * ((int *) arg);
	int cA,cB;
	pthread_mutex_lock(&conti);
	//inizio sequenza critica
	cA = contoA; //leggi contoA in var locale
	cB = contoB; //leggi contoB in var locale
	contoA = cA + importo;
	contoB = cB - importo;
	pthread_mutex_unlock(&conti);
	//fine sequenza critica 
	return NULL;
} //trasferisci

int main(void){
	pthread_t tID1, tID2;
	int importo1 = 10, importo2 = 20;
	pthread_mutex_init (&conti, NULL);
	// inizializza mutex
	pthread_create(&tID1,NULL,&trasferisci,&importo1);
	pthread_create(&tID2,NULL,&trasferisci,&importo2);
	pthread_join (tID1,NULL);
	pthread_join (tID2,NULL);
	totale = contoA+contoB;
	printf("contoA = %d contoB = %d\n",contoA,contoB);
	printf("il totale e' %d\n", totale);
	return 0;
} //main
