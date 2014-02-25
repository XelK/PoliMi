#include <stdio.h>
#include <sys/types.h>
void main(int argc, char * argv[]){

	pid_t pid;
	int retstatus = 0;
	int errore = -1;

	pid = fork();
	if (pid == -1){
		printf("Errore creazione processo\n");
		exit(errore);
	}
	if (pid == 0){
	// pid == 0, sono nel figlio
	printf ("Sono il processo figlio.\n");
	}
	else{
		//pid != 0, sono nel padre
		printf("Sono il processo padre.\n");
		exit(retstatus);
	}

}//main
