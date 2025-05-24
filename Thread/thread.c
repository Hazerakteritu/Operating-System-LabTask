//Thread create() and join()
//program to create thread. Thread prints 0-4 while the main process prints 20-24

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread1_func(void *arg);
int i,n, j;

int main(){
    pthread_t a;  
    pthread_create(&a, NULL, thread1_func, NULL);      
    pthread_join( a, NULL);    //process waits for thread to finish
    
    printf("Inside Main Program\n");
    for(j=20; j<25; j++){
        printf("Main Thread:  %d\n", j);
        sleep(1);
    }
}

void *thread1_func(void *arg){
   printf("Inside Thread\n");
   for(int i=0; i<=4; i++){
       printf("%d\n", i);
   }
}

