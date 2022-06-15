#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
#include <stdlib.h>

#define max 10
int stack[max];
int top=-1;

// Mutex objects. It doesn't work without initialization
// https://stackoverflow.com/questions/34936019/pthread-mutex-not-working-correctly
pthread_mutex_t pop_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t push_mutex = PTHREAD_MUTEX_INITIALIZER;

/* From the book:
Applying a sequence to the locking of resources is the same as allowing only one thread 
to acquire resources at a time. The other threads will only be able to acquire the 
resources after the previous thread is over. This way, we will not have a deadlock on our 
hands.
*/

// Both functions (push and pop) implement the same lock&unlock order to avoid
// Dead lock

void * push(void *arg) {
    int n;                            // LOCK/UNLOCK sequence 
    pthread_mutex_lock(&push_mutex);  //    1 LOCK push_mutex
    sleep(2);
    pthread_mutex_lock(&pop_mutex);   //    2 LOCK pop_mutex
    printf("Enter the value to push: ");
    scanf("%d",&n);
    top++;
    stack[top]=n;
    pthread_mutex_unlock(&pop_mutex);   // 3 UNLOCK pop_mutex
    pthread_mutex_unlock(&push_mutex);  // 4 UNLOCK push_mutex
    printf("Value is pushed to stack \n");
}

void * pop(void *arg) {
    int k;                              // LOCK/UNLOCK sequence 
    pthread_mutex_lock(&push_mutex);    //    1 LOCK push_mutex
    sleep(5);
    pthread_mutex_lock(&pop_mutex);     //    2 LOCK pop_mutex
    k=stack[top];
    top--;
    printf("Value popped from stack is %d \n",k);
    pthread_mutex_unlock(&pop_mutex);   // 3 UNLOCK pop_mutex
    pthread_mutex_unlock(&push_mutex);  // 4 UNLOCK push_mutex
}

int main() {

    // Checking the mutex object correct initialization
    if ( pthread_mutex_init( &pop_mutex, NULL) != 0 )
    printf( "pop_mutex init failed\n" );
    if ( pthread_mutex_init( &push_mutex, NULL) != 0 )
    printf( "push_mutex init failed\n" );

    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,&push,NULL);
    pthread_create(&tid2,NULL,&pop,NULL);

    printf("Both threads are created\n");
    
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    pthread_mutex_destroy(&pop_mutex);
    pthread_mutex_destroy(&push_mutex);
    return 0;
}