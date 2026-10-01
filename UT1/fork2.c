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
        pid2=fork();
        if (pid2==0)
        {
            pid3=fork();
            if (pid3==0)
            {
                printf("Soy P4 y mi PID es: %d y el de mi padre es: %d\n",getpid(),getppid());
                printf("La suma de ambos PID es: %d\n",getpid()+getppid());
            }
            else
            {
                wait(NULL);
                printf("Soy P3 y mi PID es: %d y el de mi padre es: %d\n",getpid(),getppid());
                printf("La suma de ambos PID es: %d\n",getpid()+getppid());
            }
        }
        else
        {
            wait(NULL);
            printf("Soy P2 y mi PID es: %d y el de mi padre es: %d\n",getpid(),getppid());
            printf("La suma de ambos PID es: %d\n",getpid()+getppid());
        }
    }
    else
    {
        wait(NULL);
        printf("Soy P1 y mi PID es: %d y el de mi padre es: %d\n",getpid(),getppid());
        printf("La suma de ambos PID es: %d\n",getpid()+getppid());
    }
    exit(0);
}