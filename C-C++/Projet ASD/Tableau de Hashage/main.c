#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
  ***********************
  Projet ASD 3 
  Nom : Hazi
  prenom : Mohamed Amine 

  projet : le programme si dessous créer et initialize une table de hashage 
*/

#define TABLE_SIZE 10

typedef struct element element_t;
struct element{
  int value;
  element_t *next;
};


int hash(int x) {
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = (x >> 16) ^ x;
  return x % TABLE_SIZE;
}

void init_hash_table(element_t *table[])
{
  for (int i = 0 ; i < TABLE_SIZE ; i++){
    table[i] = malloc(sizeof(element_t));
    table[i] = NULL;
  }
}

void fill_hash_table(element_t *table[])
{

  srand(time(NULL));
  int hashed_num;
  int rand_num;
  for ( int i = 0 ; i < TABLE_SIZE ; i++ )
  {
    rand_num = rand();
    hashed_num = hash(rand_num);

    if ( table[hashed_num] == NULL)
    {
      free(table[hashed_num]);
      table[hashed_num] = malloc(sizeof(element_t));
      table[hashed_num]->value = rand_num;
    }
  }
}

void print_hash_table(element_t *table[])
{
  for ( int i = 0 ; i < TABLE_SIZE ; i++)
  {
    if (table[i] != NULL)
    {
      printf(" %d --", table[i]->value);
    }
    else
    {
      printf(" NULL --");
    }
  }
  printf(" END\n");
}

bool find_value(element_t* table[], int value)
{
  int hashed_value = hash(value);
  
  if (table[hashed_value] == NULL) return false;
  if (table[hashed_value]->value == value) return true;
  return false;
}

int main(int argc, char const *argv[])
{
  element_t *tableau[TABLE_SIZE];
  init_hash_table(tableau);
  fill_hash_table(tableau);
  print_hash_table(tableau);
  
  int randomm_num;
  clock_t start = clock();

  for (int i = 0 ; i < TABLE_SIZE * 0.8 ; i++)
  {
    randomm_num = rand() % TABLE_SIZE;
    find_value(tableau, randomm_num);
  }

  clock_t end = clock();
  double elapsed = (double)((end - start)/CLOCKS_PER_SEC);
  printf("\nClock at start : %d\nClock at end : %d\nElsapsed time : %f", start, end, elapsed);
  return 0;
}
