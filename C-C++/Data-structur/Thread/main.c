#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* myTurn( void* arg){
    while(1)
    {
        sleep(1);
        printf("My Turn\n");
    }
    return NULL;
}

void yourTurn(){
    while (1)
    {
        sleep(2);
        printf("Your Turn\n");
    }
}

int main(int argc, char const *argv[])
{
    pthread_t newthread;

    pthread_create(&newthread, NULL, myTurn, NULL);
    // myTurn();
    yourTurn();
    return 0;
}
