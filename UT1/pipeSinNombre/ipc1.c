#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
void main(){

    int fd[2]; 
    char buffer[30];
    pid_t pid;
    time_t hora;
    char *fecha ;
     time(&hora);
     fecha = ctime(&hora) ;
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
               close(fd[1]); // Cierra el descriptor de lectura
               printf("Soy el proceso hijo de PID: %d \n", getpid());
               read(fd[0], buffer, sizeof(buffer));
               printf("\t Fecha/Hora: %s \n", buffer);
               close(fd[0]);


     }
     else
     {
               close(fd[0]); // Cierra el descriptor de lectura
               write(fd[1], fecha, 30);
               close(fd[1]);
               wait(NULL);
     }
}