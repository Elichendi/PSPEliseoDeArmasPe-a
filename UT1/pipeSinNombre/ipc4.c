#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
int main()
{
    int fd[2], fd2[2];
    int num1, recibido, factorial;
    time_t t;
    pid_t pid;
    pipe(fd);
    pipe(fd2);
    srand((unsigned) time(&t));
    pid = fork();

    if (pid == 0)
    {
        close(fd[1]);
        close(fd2[0]);
        read(fd[0], &recibido, sizeof(recibido));
        printf("El proceso padre ha generado el numero %d en el pipe1 \n", recibido);
        factorial=recibido;
        if (recibido == 0)
        {
            factorial=1;
        }
        else
        {
            for (size_t i = recibido-1; i > 0; i--)
            {
                factorial=factorial*i;
            }
        }
        write(fd2[1], &factorial, sizeof(factorial));
    }
    else
    {
        // PROCESO PADRE: escribe en el pipe
        close(fd[0]);
        close(fd2[1]);
        num1=rand() % 10;
        write(fd[1], &num1, sizeof(num1));
        read(fd2[0], &recibido, sizeof(recibido));
        printf("El factorial calculado por el proceso hijo: %d != %d\n", num1, recibido);
        wait(NULL);
    }
    exit(0);
}