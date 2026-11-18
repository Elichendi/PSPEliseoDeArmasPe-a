#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() 
{
    pid_t pid;
    pid = fork();

    if (pid==0)
    {
        printf("Soy el proceso hijo \n");
        printf("El nombre del alumno es Eliseo de Armas Peña\n");
    }

    else
    {
        wait(NULL);
        printf("Soy el proceso padre \n");
        printf("Mi PID es: %d\n",getpid());
        printf("El PID de mi hijo era: %d\n",pid);
    }
    exit(0);
}