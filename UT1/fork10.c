#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
    pid_t pid, pid2;
    pid=fork();
    if (pid==0)
    {
        printf("Soy P2 y mi PID es: %d\n",getpid());
        for (int i = 0; i < 100; i++)
        {
            printf("%d\n",1+i);
        }
    }
    else
    {
        pid2=fork();
        if (pid2==0)
        {
            printf("Soy P3 y mi PID es: %d\n",getpid());
            for (int i = 100; i < 200; i++)
            {
                printf("%d\n",1+i);
            }
            
        }
        else
        {
            wait(NULL);
            wait(NULL);
            printf("Soy P1\n");
            printf("Todos los calculos han finalizado\n");
        }
    }
    exit(0);
}