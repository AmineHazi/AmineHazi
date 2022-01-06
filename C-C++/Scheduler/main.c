
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_FILE_ATTENTE 500

typedef struct client client_t;
struct client{
    int numero_client;
    int charge;
};

client_t nouveau_client(int position)
{
    client_t nouveau = { .numero_client = position , .charge = ((rand()%10) + 1) };
    return nouveau;
}
client_t file_attente[MAX_FILE_ATTENTE];
void remplissage_file(client_t file_attente[])
{
    for(int i = 0 ; i < MAX_FILE_ATTENTE ; i++){
        file_attente[i] = nouveau_client(i);
    }
}

bool file_vide(client_t file_attente[]){
    bool vide = true;
    for(int i = 0 ; i < MAX_FILE_ATTENTE ; i++)
    {
        if (file_attente[i].charge > 0) vide = false;
    }
    return vide;
}

void scheduleur(client_t file_attente[])
{
    do{
        for(int i = 0 ; i < MAX_FILE_ATTENTE ; i++)
    {
        if(file_attente[i].charge > 0)
        {
            file_attente[i].charge--;
            if(file_attente[i].charge == 0) file_attente[i].charge = -1;
        }
    }
    } while (!file_vide(file_attente));

}


void print_file_attente(client_t file_attente[])
{
    printf("\n*******DEBUT*******\n");
    for(int i = 0 ; i < MAX_FILE_ATTENTE ; i++)
    {
        printf("Numero du client : %d\tCharge de la demande : %d\n", file_attente[i].numero_client, file_attente[i].charge);
    }
    printf("\n********END********\n");
}

void *filling_thread(void* arg)
{
    remplissage_file(file_attente);
    print_file_attente(file_attente);
    return NULL;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    pthread_t thread_one;

    pthread_create(&thread_one, NULL, &filling_thread, NULL);


    return 0;
}
