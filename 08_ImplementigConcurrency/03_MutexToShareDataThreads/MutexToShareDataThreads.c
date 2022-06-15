#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_t tid1,tid2;
pthread_mutex_t lock; //Definition of mutex object

// A void pointer is a pointer that has no associated data type with it
// https://www.geeksforgeeks.org/void-pointer-c-cpp/
void* runThread(void *arg)
{
    static int index = 0;
    pthread_mutex_lock(&lock); // Block acces to shared resource
    pthread_t id = pthread_self(); //To identify the thread

    if(pthread_equal(id,tid1))
        printf("First thread is running\n");
    else
        printf("Second thread is running\n");
    printf("Processing the common resource\n");
    index++;
    printf("Index %d \n", index);
    sleep(1);

    if(pthread_equal(id,tid1))
        printf("First thread is over\n\n");
    else
        printf("Second thread is over\n\n"); 

    pthread_mutex_unlock(&lock); // Liberate acces to shared resource
    return NULL;
}

int main(void)
{ 
    // Lock initialization 
    if (pthread_mutex_init(&lock, NULL) != 0)
        printf("\n mutex init has failed\n");


    pthread_create(&tid1, NULL, &runThread, NULL);
    pthread_create(&tid2, NULL, &runThread, NULL);

    //Wait until completion of thread
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    // To delete de mutex object
    pthread_mutex_destroy(&lock);
    return 0;
}