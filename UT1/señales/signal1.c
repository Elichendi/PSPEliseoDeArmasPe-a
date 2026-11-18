#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

void fun_signal(int signum){
    time_t tiempo;
    struct tm *fecha;
    time(&tiempo);
    fecha = localtime(&tiempo);
    printf("\nFin del proceso %d: %02d/%02d/%04d %02d:%02d:%02d\n",getpid(),fecha->tm_mday,fecha->tm_mon + 1,fecha->tm_year + 1900,fecha->tm_hour,fecha->tm_min,fecha->tm_sec);
    signal(SIGINT,SIG_DFL);  // Se "re-arma" la señal con su acción por defecto
}


int main()
{
    time_t tiempo;
    struct tm *fecha;
    time(&tiempo);
    fecha = localtime(&tiempo);
    signal(SIGINT,fun_signal); // Esta línea registra la función manejadora para la señal SIGINT. A partir de aquí, si se pulsa Ctrl+C, se ejecutará fun_signal()
    printf("\nInicio del proceso %d: %02d/%02d/%04d %02d:%02d:%02d\n",getpid(),fecha->tm_mday,fecha->tm_mon + 1,fecha->tm_year + 1900,fecha->tm_hour,fecha->tm_min,fecha->tm_sec);
    while(1)
    {
        pause();
    }
}