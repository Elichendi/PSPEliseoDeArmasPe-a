#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2]; //array para el pipe
    pipe(fd); //pipe
    pid_t pid = fork();
    for (int i = 0; i < 68; i++)
    {
        int numero=i;

        if (pid == 0) 
        {
            // HIJO: solo lee
            close(fd[1]);
            int recibido;
            read(fd[0], &recibido, sizeof(recibido));
            printf("HIJO: He recibido %d\n", recibido);
            sleep(1.5);
        }
    else 
        {
            // PADRE: solo escribe
            close(fd[0]);
            write(fd[1], &numero, sizeof(numero));
            printf("PADRE: He enviado %d\n", numero);
            sleep(1);
        }
    }
}
