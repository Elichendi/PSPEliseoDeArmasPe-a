#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
    pid_t pid, pid2, pid3;
    pid= fork();
    if (pid==0)
    {
        printf("Soy P2 y mi PID es: %d\n",getpid());
        printf("Y el PID de mi padre es: %d\n",getppid());
    }
    else
    {
        pid2=fork();
        if (pid2==0)
        {
            pid3=fork();
            if (pid3==0)
            {
                printf("Soy P4 y mi PID es: %d\n",getpid());
                printf("Y el PID de mi padre es: %d\n",getppid());
            }
            else
            {
                wait(NULL);
                printf("Soy P3 y mi PID es: %d\n",getpid());
            }
        }
        else
        {
            wait(NULL);
            wait(NULL);
            printf("Soy P1 y mi PID es: %d\n",getpid());
        }
    }
    exit(0);
}