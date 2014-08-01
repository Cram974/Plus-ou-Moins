#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(int argc, char *argv[])
{
  int continu = 1;
  while (continu)
  {
        int nb = 0, nb_mist=0, born_sup = 0, born_inf = 0, nivo = 0, coups = 1, aide = 1;
        while (nivo<1 || nivo>3)
        {
              printf("Choix du Niveau: \n1\tFacile (entre 1 et 100)\n2\tMoyen (entre 1 et 1000)\n3\tDifficile (entre 1 et 10000)\n");
              printf("Votre Choix: ");
              scanf("%ld", &nivo);
        }
        printf("\n\n");
        printf("Voulez vous activer l'aide\n1\toui\n0\tnon\n");
        printf("Votre Choix: ");
        scanf("%ld", &aide);
        born_sup = pow(10, nivo+1);
        nivo = 0;
        srand(time(NULL));
        nb_mist = (rand() % (born_sup - born_inf + 1)) + born_inf;
        while (nb != nb_mist)
        {
              printf("\n\nVous devez trouver un nombre entre %ld et %ld\n", born_inf, born_sup);
              printf("Proposition: ");
              scanf("%ld", &nb);
              if (born_inf>=nb || nb>=born_sup)
              {
                    printf("Veuillez entrer un nombre entre %ld et %ld", born_inf, born_sup); 
              }
              else if (nb_mist < nb)
              {
                   printf("C'est moins!");
                   if (aide)
                   {
                            born_sup = nb;
                   }
              }
              else if (nb_mist > nb)
              {
                   printf("C'est plus!");
                   if (aide)
                   {
                            born_inf = nb;
                   }
              }
              coups++;
        }
        printf("\n\nBravo vous avez trouver le nombre %ld en %ld coup(s)\n\n", nb_mist, coups);
        printf("Voulez vous rejouer?\n1\toui\n0\tnon\n");
        printf("Votre Choix: ");
        scanf("%ld", &continu);
        printf("\n\n");
  }	
  return 0;
}
