#include <stdio.h>
#include <pthread.h>
int main(){
	pid_t pid1,pid2;
	pid1=fork();
	if(pid1==0){//primo processo figlio
		printf("FIGLIO 1: PID = %d\n",getpid());
		printf("FIGLIO 1: eseguo exit.\n");
		return(0);
	} else{//processo padre
		pid2=fork();
		if(pid2==0){//secondo processo figlio
			printf("FIGLIO 2: PID = %d\n",getpid());
			printf("FIGLIO 2: eseguo exit.\n");
			return(0);
		}else{//processo padre
			printf("PADRE: PID= %d\n",getpid());
			printf("PADRE: PID DEL FIGLIO 1 = %d\n",pid1);
			printf("PADRE: PID DEL FIGLIO 2 = %d\n",pid2);
			return(0);
		}
	}
}//main
