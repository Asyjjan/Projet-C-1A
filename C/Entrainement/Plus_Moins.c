#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int MAX = 100, MIN = 1;
    int nombreMystere = 0, nombreEntre = 0, Continuerpartie, nbrjoueur,lvl;

    srand(time(NULL));

    printf("Salut! Le but du jeu est de determiner le chiffre mystere.\n\n");
    printf("Choisit le niveau de difficulter\nNiveau 1: 1 a 100 (Tape 1)\nNiveau 2: 1 a 1000 (Tape 2)\nNiveau 3: 1 a 10000 (Tape 3)\n");
    scanf("%d",&lvl);

    if (lvl == 2)
        {MAX = 1000;
        printf("\nTu as choisi la difficulter 2\n\n");
        }
    else if (lvl == 3)
        {MAX = 10000;
        printf("\nTu as choisi la difficulter 3\n\n");
        }
    else if (lvl == 1)
        printf("\nTu as choisi la difficulter 1\n\n");

    printf("Voulez vous jouer a 1 ou 2 joueurs ?\nTaper 1 ou 2\n");
    scanf("%d",&nbrjoueur);

if (nbrjoueur == 2)
    {
    do
    {
        printf("Vous jouer a 2 joueurs ! Saisir le nombre mystere\n");
        scanf("%d",&nombreMystere);
        int nbrcoup = 1;
        do
        {
            printf("Quel est le nombre ? ");
            scanf("%d", &nombreEntre);

            if (nombreEntre > nombreMystere)
                printf("Moins grand !\n\n");
            else if (nombreEntre < nombreMystere)
                printf("Plus grand !\n\n");
            else
                printf("Bien jouer ! le chiffre etait bien %d.\nTu as trouver en %d coups !\n\n", nombreEntre, nbrcoup);

            nbrcoup++; // equivalent à nbrcoup = nbrcoup + 1;
        } while (nombreMystere != nombreEntre);

        printf("Veux tu rejouer une partie ?\nTape 1 pour oui, 0 pour non\n");
        scanf("%d", &Continuerpartie);
    }
    while (Continuerpartie == 1);
    }
else if (nbrjoueur == 1)
    {
    do
    {
        int nbrcoup = 1;
        nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;

        do
        {
            printf("Quel est le nombre ? ");
            scanf("%d", &nombreEntre);

            if (nombreEntre > nombreMystere)
                printf("Moins grand !\n\n");
            else if (nombreEntre < nombreMystere)
                printf("Plus grand !\n\n");
            else
                printf("Bien jouer ! le chiffre etait bien %d.\nTu as trouver en %d coups !\n\n", nombreEntre, nbrcoup);

            nbrcoup++; // equivalent à nbrcoup = nbrcoup + 1;
        } while (nombreMystere != nombreEntre);

        printf("Veux tu rejouer une partie ?\nTape 1 pour oui, 0 pour non\n");
        scanf("%d", &Continuerpartie);
    }
    while (Continuerpartie == 1);
    }

    return 0;
}