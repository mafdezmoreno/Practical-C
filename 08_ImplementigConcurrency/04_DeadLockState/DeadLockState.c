#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

//array to stack threads
#define max 10
int stack[max];
int top=-1;
// Mutex objects. It doesn't work without initialization
// https://stackoverflow.com/questions/34936019/pthread-mutex-not-working-correctly
pthread_mutex_t pop_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t push_mutex = PTHREAD_MUTEX_INITIALIZER;



void * push(void *arg) {
    
    int n;
    pthread_mutex_lock(&push_mutex);
    sleep(0.5); //To force Dead Lock State 
                //(you may need to increase this time)
    pthread_mutex_lock(&pop_mutex);
    printf("push_mutex & pop_mutex LOCKED in PUSH\n");

    printf("Enter the value to push: \n");
    scanf("%d",&n);
    //n=3;
    top++;
    stack[top]=n;
    
    pthread_mutex_unlock(&pop_mutex);
    pthread_mutex_unlock(&push_mutex);
    printf("push_mutex & pop_mutex UNLOCKED\n");
    printf("Value is pushed to stack \n");
}


void * pop(void *arg) {
    
    int k;
    pthread_mutex_lock(&pop_mutex);
    sleep(0.5); //To force Dead Lock State
    pthread_mutex_lock(&push_mutex);
    printf("push_mutex & pop_mutex LOCKED in POP\n");

    k=stack[top];
    top--;
    printf("Value popped is %d \n",k);
    
    pthread_mutex_unlock(&push_mutex);
    //printf("push_mutex UNLOCK\n");
    pthread_mutex_unlock(&pop_mutex);
    //printf("pop_mutex UNLOCK\n");
    printf("push_mutex & pop_mutex UNLOCKED\n");
}

int main() {

    // Checking the mutex object correct initialization
    if ( pthread_mutex_init( &pop_mutex, NULL) != 0 )
    printf( "pop_mutex init failed\n" );
    if ( pthread_mutex_init( &push_mutex, NULL) != 0 )
    printf( "push_mutex init failed\n" );

    pthread_t tid1,tid2; //thread identifiers
    pthread_create(&tid1,NULL,&push,NULL);
    pthread_create(&tid2,NULL,&pop,NULL);
    printf("Both threads are created\n");

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("Both threads finished\n");

    pthread_mutex_destroy(&pop_mutex);
    pthread_mutex_destroy(&push_mutex);
    return 0;
}