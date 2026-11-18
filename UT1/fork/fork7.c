#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main()
{
 printf("CCC \n");
 pid_t pid;
 pid=fork();
 if (pid!=0)
 {
    printf("AAA \n");
 } 
 else 
 {
    printf("BBB \n");
 }
 exit(0);
//la salida del codigo sera CCC AAA BBB, no se puede producir otra salida porque siempre es el padre el que llega primero al if y luego se crea con el fork el proceso hijo
/*1era forma
void main()
{
 printf("CCC \n");
 if (fork()!=0)
 {
    printf("BBB \n");
 } 
 else 
 {
    printf("AAA \n");
 }
 exit(0);
 2nda manera, Con este tienes una probabilidad de que salga primero el BBB que el AAA
 void main()
{
 printf("CCC \n");
 pid_t pid;
 pid=fork();
 if (pid!=0)
 {
    printf("AAA \n");
 } 
 else 
 {
    printf("BBB \n");
 }
 exit(0);
 */
}