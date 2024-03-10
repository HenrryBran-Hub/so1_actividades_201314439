#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int process_counter = 0;
int thread_counter = 0;

void *thread_function(void *arg) {
    printf("-------------------------------------\n");
    printf("Hilo creado en el Proceso: %d.\n", getpid());
    thread_counter++;
    pthread_exit(NULL);
}

int main() {
    pid_t pid;
    pthread_t tid;
    
    printf("-------------------------------------\n");
    printf("Proceso padre. PID: %d\n", getpid());
    process_counter++;
    
    pid = fork();
    if (pid == -1) {
        perror("!!!!Fallo de bifurcacion!!!\n");
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0) { /* child process */
        printf("Proceso Hijo. ChilPID: %d, Proceso Padre PID: %d\n", getpid(), getppid());
        process_counter++;
        fork();
        printf("Despues de la bifurcacion = 0\n");
        pthread_create(&tid, NULL, thread_function, NULL);
        printf("Creacion de hilos\n");
        pthread_join(tid, NULL);
    }
    else {
        printf("Proceso padre antes de la bifurcacion. PID: %d\n", getpid());
        pthread_create(&tid, NULL, thread_function, NULL);
        pthread_join(tid, NULL);
    }
    
    fork();
    process_counter++;
    
    printf("-------------------------------------\n");
    printf("-------------------------------------\n");
    printf("| Final del Proceso PID: %d         |\n", getpid());
    printf("| Total de procesos creados: %d     |\n", process_counter);
    printf("| Total de hilos creados: %d        |\n", thread_counter);
    printf("-------------------------------------\n");
    printf("-------------------------------------\n");
    
    sleep(1); // Espera para asegurar que todos los procesos/hilos hayan finalizado
    
    return 0;
}
