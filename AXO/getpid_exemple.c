#include <stdio.h>
#include <sys/types.h>

int main(){

	pid_t pid;
	printf("Prima della fork: PID= %d\n",getpid());
	pid = fork();
	if (pid==0) { //processo figlio
		printf ("FIGLIO: PID= %d\n",getpid());
		return (0);	
	}
	else{//processo padre
		printf("PADRE: PID= %d\n",getpid());
		printf("PADRE: PID DEL FIGLIO = %d\n",pid);
		return(0);
	}//endif

}//main
