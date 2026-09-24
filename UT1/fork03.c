#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main()
{
printf("Inicio\n");
pid_t pid = fork();
printf("Después del fork\n");
if (pid == 0) {
 printf("Soy el hijo\n");
} else {
 printf("Soy el padre\n");
}
printf("Fin\n");
//Hay 2 procesos: un proceso padre y un proceso hijo con el fork
//La instrucción "Inicio" la ejecuta el padre ya que el hijo no existe "despues del fork" lo ejecutan los 2,
//"Soy el hijo solo lo ejecutara el hijo", "soy el padre" solo la ejecutara el padre y "Fin" lo ejecutan los 2.
//la parte que puede aparece en distinto orden es todo despues del fork ya que es aleatorio si el hijo o el padre avanza.
}