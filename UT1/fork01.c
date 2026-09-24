#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{
    pid_t pid, pid_hijo, pid_padre;
    pid = fork();

    if (pid==0)
    {
        printf("Soy el proceso hijo \n");
        printf("Mi PID es: %d\n",getpid());
        printf("El PID de mi padre es: %d\n",getppid());
    }

    else
    {
        pid_hijo = wait(NULL);
        printf("Soy el proceso padre \n");
        printf("Mi PID es: %d\n",getpid());
        printf("El PID de mi hijo era: %d\n",pid_hijo);
        printf("El proceso hijo ha terminado");
    }
}
