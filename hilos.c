#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *funcionAcumulado(void *args)
{
    int subnumero = 0;
    int acumulado = 0;
    for (int i = 0; i < 10; i++)
    {
        acumulado += i;
        subnumero += 1;
        printf("Thread[1] de Acumulado[%d]: %d\n", subnumero, acumulado);
        usleep(1000000);
    }
    printf("\n");
}

void *funcionProductoria()
{
    int subnumero = 0;
    int productoria = 1;
    for (int i = 1; i < 11; i++)
    {
        productoria *= i;
        subnumero += 1;
        printf("Thread[2] de Productoria[%d]: %d\n", subnumero, productoria);
        usleep(1000000);
    }
    printf("\n");
}

void *funcionPotencia(void *args)
{
    int potencia = 1;
    int subnumero = 0;
    for (int i = 0; i < 10; i++)
    {
        potencia *= 2;
        subnumero += 1;
        printf("Thread[3] de Potencia[%d]: %d\n", subnumero, potencia);
        usleep(1000000);
    }
    printf("\n");
}

void *funcionFibonacci(void *args)
{
    int subnumero = 0;
    int fibonacci = 0;
    int fibonacciAnterior = 1;
    int fibonacciAnteriorAnterior = 0;
    for (int i = 0; i < 10; i++)
    {
        subnumero += 1;
        fibonacci = fibonacciAnterior + fibonacciAnteriorAnterior;
        fibonacciAnteriorAnterior = fibonacciAnterior;
        fibonacciAnterior = fibonacci;
        printf("Thread[4] Cálculo Fibonacci[%d]: %d\n", subnumero, fibonacci);
        usleep(1000000);
    }
    printf("\n");
}

int main()
{
    char *msg1 = "Hilo 1";
    char *msg2 = "Hilo 2";
    char *msg3 = "Hilo 3";
    char *msg4 = "Hilo 4";
    int ret1, ret2, ret3, ret4;
    pthread_t hilo1, hilo2, hilo3, hilo4;

    ret1 = pthread_create(&hilo1, NULL, funcionAcumulado, (void *)msg1);
    ret2 = pthread_create(&hilo2, NULL, funcionProductoria, (void *)msg2);
    ret3 = pthread_create(&hilo3, NULL, funcionPotencia, (void *)msg3);
    ret4 = pthread_create(&hilo4, NULL, funcionFibonacci, (void *)msg4);
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);
    pthread_join(hilo3, NULL);
    pthread_join(hilo4, NULL);

    // Si es 0 está bien y si es 0< está mal
    printf("Hilo 1: %d\n", ret1);
    printf("Hilo 2: %d\n", ret2);
    printf("Hilo 3: %d\n", ret3);
    printf("Hilo 4: %d\n", ret4);

    return 0;
}