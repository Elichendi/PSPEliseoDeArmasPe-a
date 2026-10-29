#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>
int main()
{
    int fd[2];
    int num1, num2, recibido1, recibido2;
    time_t t;
    pid_t pid;
    pipe(fd);
    srand((unsigned) time(&t));
    pid = fork();

    if (pid == 0)
    {
        close(fd[0]);
        num1=rand() % 50;
        num2=rand() % 50;
        write(fd[1], &num1, sizeof(num1));
        write(fd[1], &num2, sizeof(num2));
    }
    else
    {
        // PROCESO PADRE: escribe en el pipe
        close(fd[1]);
        read(fd[0], &recibido1, sizeof(recibido1));
        read(fd[0], &recibido2, sizeof(recibido2));
        int suma= recibido1+recibido2;
        int resta= recibido1-recibido2;
        int multi= recibido1*recibido2;
        int div= recibido1/recibido2;
        printf("%d + %d = %d\n", recibido1, recibido2, suma);
        printf("%d - %d = %d\n", recibido1, recibido2, resta);
        printf("%d * %d = %d\n", recibido1, recibido2, multi);
        printf("%d / %d = %d\n", recibido1, recibido2, div);
        wait(NULL);
    }
    exit(0);
}
