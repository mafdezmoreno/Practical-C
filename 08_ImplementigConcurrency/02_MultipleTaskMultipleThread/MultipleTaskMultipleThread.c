#include<pthread.h>
#include<stdio.h>
#include<unistd.h>


void *runThread1(void *arg){
    int i;
    printf("Running Thread 1\n");
    for(i=1;i<=5;i++){
        printf("Thread 1 - %d\n",i);
        sleep(0.2); //0.2 seconds. To force parallel execution
    }
}

void *runThread2(void *arg){
    int i;
    printf("Running Thread 2\n");
    for(i=1;i<=5;i++){
        printf("Thread 2 - %d\n",i);
        sleep(0.2); //0.2 seconds. To force parallel execution
    }
}

int main(){
    pthread_t tid1, tid2; // thread identifiers
    pthread_create(&tid1, NULL, runThread1, NULL);
    pthread_create(&tid2, NULL, runThread2, NULL);

    //waits until both of the threads have completed their respective tasks
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("Both threads are over\n");
    return 0;
}