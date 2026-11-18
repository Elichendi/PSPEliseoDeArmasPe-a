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
        printf("Soy P2\n");
        sleep(5);
        printf("Soy P2 y estoy despierto\n");
    }
    else
    {
        pid2=fork();
        if (pid2==0)
        {
            printf("Soy P3\n");
            sleep(2);
            printf("Soy P3 y estoy despierto\n");
        }
        else
        {
            pid3=fork();
            if (pid3==0)
            {
                printf("Soy P4\n");
                sleep(4);
                printf("Soy P4 y estoy despierto\n");
            }
            else
            {
            wait(NULL);
            wait(NULL);
            wait(NULL);
            printf("Soy P1\n");
            printf("Todos mis hijos han terminado\n");
            }
        }
    }
    exit(0);
}
//A) El proceso que termina primero es P3 porque es el que duerme menos tiempo
//B) Si quitamos los sleep cualquiera de los procesos P2, P3 o P4 podria terminar primero;