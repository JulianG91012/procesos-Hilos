#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *funcionAcumulado(void *args)
{
    char *msg;
    msg = (char *)args;
}

void *funcionPotencia(void *args)
{
    printf("Hilo 2\n");
    pthread_exit(NULL);
}

int main()
{
    char *msg1 = "Hilo 1";
    char *msg2 = "Hilo 2";
    int ret1, ret2;
    pthread_t hilo1, hilo2;

    ret1 = pthread_create(&hilo1, NULL, funcionAcumulado, (void *)msg1);
    ret2 = pthread_create(&hilo2, NULL, funcionPotencia, (void *)msg2);

    printf("Funcion principal PID: %d\n" , getpid());

    //Si es 0 está bien y si es -1 está mal
    printf("Hilo 1: %d\n", ret1);
    printf("Hilo 2: %d\n", ret2);

    return 0;
}