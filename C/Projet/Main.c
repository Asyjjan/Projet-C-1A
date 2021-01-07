#include <stdio.h>
#include "Fonction.h"
#include "Fonction.c"
#define VMAX 30
#define VMIN 5

int main ()
{
    printf("----------- Jeu de Nim -----------\n\n");

    int nlig = 0, ncol = 0, lvl = 0, next = 0, nban = 0, fin = 0;
    int nim[VMAX][VMAX];
    T_Case Casebanni[VMAX];
    T_Case Pion;
    Pion.abscisse = 0;
    Pion.ordonner = 0;
    
    parametres(&nlig,&ncol,&lvl,&next,&nban);
    Hasard_Ban(Casebanni,nlig,ncol,nban);
    Calcul_Nimbers(nim, nlig, ncol);
    printf("\n\n");

do
{
    AfficheGrille(Pion,Casebanni,nban,nlig,ncol);
    if (next == 2)
    {
        switch(lvl)
        {
            case 1:
                Coup_Ordi_Hasard(&Pion, Casebanni, nban, nlig, ncol);
                break;
            case 2:
                if (rand()%3 == 0)
                    Coup_Ordi_Gagnant(&Pion, Casebanni, nim, nban, nlig, ncol);
                else
                    Coup_Ordi_Hasard(&Pion, Casebanni, nban, nlig, ncol);
                    break;
            case 3:
                if (rand()%3 == 0)
                    Coup_Ordi_Hasard(&Pion, Casebanni, nban, nlig, ncol);
                else
                    Coup_Ordi_Gagnant(&Pion, Casebanni, nim, nban, nlig, ncol);
                break;
            case 4:
                Coup_Ordi_Gagnant(&Pion, Casebanni, nim, nban, nlig, ncol);
                break;
        }
        next=1;
    }
    else if (next == 1)
    {
        Coup_joueur(&Pion, Casebanni, nban, nlig, ncol);
        next = 2;
    }
}
while (Pion.abscisse < ncol-1 || Pion.ordonner < nlig-1);
    printf("\n");
    AfficheGrille(Pion,Casebanni,nban,nlig,ncol);
    printf("C'est termine !\n");
    if (next == 1)
        printf("Tu as gagné beau gosse !\n");
    else
        printf("Dommage, boouh perdant !\n");
    return 0;
}