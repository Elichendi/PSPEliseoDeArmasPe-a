#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
    pid_t pid, pid2;
    pid= fork();
    if (pid==0)
    {
        printf("Soy el proceso P2 y voy a dormir 10 segundos\n");
        sleep(10);
        printf("Despierto\n");
    }
    else
    {
        pid2=fork();
        if (pid2==0)
        {
            printf("Soy el proceso P3 mi PID es: %d\n",getpid());
            printf("El PID de mi padre es: %d\n",getppid());
        }
        else
        {
            wait(NULL);
            wait(NULL);
        }
        
    }
    exit(0);
}