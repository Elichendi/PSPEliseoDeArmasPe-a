#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int fd[2];
    int numeroSumado = 0;
    char buffer[30];
    pid_t pid;
    pipe(fd);

    pid = fork();

    if (pid == 0)
    {
        close(fd[1]);

        do
        {
            int bytes = read(fd[0], buffer, sizeof(buffer) - 1);

            if (strcmp(buffer, "+") == 0)
            {
                printf("Recibido carácter +\n");
                printf("La suma total es igual a: %d\n", numeroSumado);
                close(fd[0]);
            }
            else
            {
                int numrecibido = atoi(buffer);

                printf("Numero a sumar: %d\n", numrecibido);
                numeroSumado = numeroSumado + numrecibido;
            }
        }
        while (strcmp(buffer, "+") != 0);
    }
    else
    {
        // PROCESO PADRE: escribe en el pipe
        close(fd[0]);

        do
        {
            printf("Introduce un numero o + para hacer la suma de los numeros anteriores: ");
            scanf("%s", buffer);

            write(fd[1], buffer, strlen(buffer) + 1);

            if (strcmp(buffer, "+") == 0)
            {
            close(fd[1]);            
            }
            sleep(1);
        }
        while (strcmp(buffer, "+") != 0);
        wait(NULL);
    }
    exit(0);
}