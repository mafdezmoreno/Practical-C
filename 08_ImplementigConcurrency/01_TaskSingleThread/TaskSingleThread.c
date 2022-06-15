#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //Requiered

void *runThread(void *arg)
{
    int i;
    printf("Running Thread \n");
    for(i=1;i<=5;i++)
        printf("%d\n",i);
    return NULL;
}

int main()
{
    pthread_t tid; // Thread identifier
    printf("In main function\n");
    pthread_create(&tid, NULL, runThread, NULL); // Create a thread and pass the identifier 
    pthread_join(tid, NULL); // Wait until the thread completes its tas
    printf("Thread over\n");
    return 0;
}