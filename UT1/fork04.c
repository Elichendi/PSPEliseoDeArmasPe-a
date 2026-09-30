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
        printf("Soy el hijo 1\n");
        sleep(3);
        exit(0);
    }
    else
    {
        pid2=fork();
        if (pid2==0)
        {
            printf("Soy el hijo 2\n");
            sleep(1);
            exit(0);
        }
        else
        {
            wait(NULL);
            wait(NULL);
            printf("Soy el Padre\n");
            printf("Todos mis hijos han terminado\n");
        }
        
    }
    exit(0);
}