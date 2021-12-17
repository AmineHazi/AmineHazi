#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define SIZE_OF_TABLE 100000


int get_random_num()
{
  return rand()%SIZE_OF_TABLE;
}

void fille_table(int table[])
{
  srand(time(NULL)); 

  for ( int i = 0 ; i < SIZE_OF_TABLE - 1; i++ )
  {
    table[i] = get_random_num();
  }

}

bool find_ellement(int value_to_find, int table[])
{
  for (int i = 0 ; i < SIZE_OF_TABLE ; i++ )
  {
    if (table[i] == value_to_find) return true;
  }
  return false;
}

void print_table(int table[])
{
  for ( int i = 0 ; i < SIZE_OF_TABLE ; i++ )
  {
    printf("%d--", table[i]);
  }
  printf("END\n");
}


int main(int argc, char const *argv[])
{
  int tableau[SIZE_OF_TABLE];

  fille_table(tableau);

  int random_num_to_find;
  
  clock_t start = clock(); // Initilaisation de la variable start avec clock() qui donne le nombre de tick d'horloge depuis le début du programme avant l'algorithme dont on veut connaitre le temps d'éxecution.

  // Recherche de l'équivalent de 80% de la taille du tableau, ps : on recherche des nombres aléatoire.
  for (int i = 0 ; i < SIZE_OF_TABLE*0.8 ; i++)
  {
    random_num_to_find = get_random_num();
    find_ellement(random_num_to_find, tableau);
  }

  clock_t end = clock(); // À la fin de l'algorithme on définit la variable end avec clock() qui va donner le nombre de tick d'horloge depuis le début du programme après l'algorithme !
 
  double elapsed = (double)((end - start)/CLOCKS_PER_SEC); // end - start donne le nombre de tick d'horloge que l'algorithme à consomer, on le divise par (CLOCKS_PER_SEC) pour avoir le temps en seconds.
  printf("\nstart : %d \nEnd : %d \nExecution time : %f s",start, end, elapsed);

  return 0;
}