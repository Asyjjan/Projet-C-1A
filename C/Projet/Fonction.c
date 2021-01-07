#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Fonction.h"
#define VMAX 30
#define VMIN 5


int Lire_Entier (int binf, int bsup)
{
    int n;
    do
    {
        scanf("%d",&n);        
    } while ((n<binf) || (n>bsup));

    return n;
}



void parametres (int *nlig,int *ncol,int *lvl,int *next,int *nban)
{

    printf("Parametres du jeu\n-------------------\n");
    printf("Nombre de lignes: "); 
    *nlig=Lire_Entier(5,30);
    printf("Nombre de colonnes: "); 
    *ncol=Lire_Entier(5,30);
    printf("Niveau (1 a 3): "); 
    *lvl=Lire_Entier(1,4);
    printf("A qui le tour de commencer ?\nJoueur (1) - Ordinateur (2): "); 
    *next=Lire_Entier(1,2);
    
    if (*next == 1)
        printf("Vous allez commencer la partie !");
    else 
        printf("L'ordinateur commence la partie !");

    printf("\n-------------------\n");

    int MAX = 0, MIN =0;
    
    if (*nlig > *ncol)
        {MAX = *nlig;
        MIN = *ncol;}
    else if (*ncol > *nlig)
        {MAX = *ncol;
        MIN = *nlig;}
    else if (*nlig == *ncol)
        {MAX = *nlig;
        MIN = *ncol;}

        srand(time(NULL));
        *nban = (rand() % (MAX - MIN + 1)) + MIN;

}



void Hasard_Ban(T_Tab_Case Casebanni, int nlig, int ncol, int nban)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < nban; i++)
    {
        int abscisse = 0;
        int ordonner = 0;
        T_Case caseNow;

        while (1)
        {
            abscisse = rand() % ncol;
            ordonner = rand() % nlig;
            caseNow.abscisse = abscisse;
            caseNow.ordonner = ordonner;

            // On verifie si la case se trouve dans un des deux coins autorisés ou si la case se trouve dans la "partie centrale" du plateau
            if ((abscisse == 0 && ordonner == nlig-1 || abscisse == nlig-1 && ordonner == 0) || (abscisse > 0 && abscisse < ncol-1 && ordonner > 0 && ordonner < nlig-1))
            {
                // Si OK, on vérifie que la case ne soi pas bannie
                if (!Verif(Casebanni, i, caseNow))
                {
                    // Il ne faut surtout pas que 2 cases bannies soient en diagonal du bas gauche vers le haut droit cf contrainte.
                    T_Case DiagGauche, DiagDroite;
                    DiagGauche.ordonner = ordonner+1;
                    DiagDroite.ordonner = ordonner-1;
                    DiagGauche.abscisse = abscisse-1;
                    DiagDroite.abscisse = abscisse+1;

                    // Si la case est celle d'en bas a gauche, on regarde si la case dans la diagonal droite n'est pas déjà bannie.
                    if (abscisse == 0 && !Verif(Casebanni, i, DiagDroite))
                        break;

                    // Si la case est celle d'en haut a droite, on regarde si la case dans la diagonal gauche n'est pas déjà bannie.
                    else if (ordonner == 0 && !Verif(Casebanni, i, DiagGauche))
                        break;

                    // Finalement, on verifie si elle n'a aucune diagonal interdite cf ligne 91.
                    else if (!Verif(Casebanni, i, DiagGauche) && !Verif(Casebanni, i, DiagDroite))
                        break;
                }
            }
        }
        // Les conditions étant respecter, on l'ajoute au tableau stockant les cases bannies.
        Casebanni[i] = caseNow;
    }
}



int Verif(T_Tab_Case Casebanni, int taille, T_Case coordonner)
{
    int i;

    for (i = 0; i < taille ;i++)
        if (Casebanni[i].abscisse == coordonner.abscisse && Casebanni[i].ordonner == coordonner.ordonner)
            return 1;

    return 0;
}



void AfficheGrille(T_Case Pion, T_Tab_Case Casebanni, int nban, int nlig, int ncol)
{
    int nbligne, nbcolonne;
    int i;
 printf("\n  ");
    for (i = 1;i<=ncol;i++)
    {
        printf("%d", i);
            printf(" ");
    }
    printf("\n");
    for (nbligne = 0;nbligne<nlig;nbligne++)
    {
        printf("%d|", nbligne+1);
        for (nbcolonne = 0;nbcolonne<ncol;nbcolonne++)
        {
            T_Case caseNow;
            caseNow.abscisse = nbcolonne;
            caseNow.ordonner = nbligne;
            if (Pion.abscisse == caseNow.abscisse && Pion.ordonner == caseNow.ordonner)
                printf("P");
            else if (Verif(Casebanni, nban, caseNow))
                printf("X");
            else
                printf("-");
            printf("|");
        }
        printf("\n");
    }
    printf("\n");
}




void Calcul_Nimbers(int nim[][VMAX], int nlig, int ncol, int nban,,)
{
    int i, j, nimber = 0;
    nim[nlig][ncol]=0;
    for (i = ncol - 1 ; i >= 0 ; i--)
    {
        for (j = nlig - 1 ; j >= 0 ; j--)
        { 
        nimber++;
        if (nimber%3 > 0)
        {
            nim[i][j]=1;
        }
        else
        {
            nim[i][j]=0;
        }

        }
    nimber++
    }
}



int Voisines(T_Tab_Case voisine, T_Case Pion, T_Tab_Case Casebanni, int nban, int nlig, int ncol)
{
    int nbvoisine = 0;
    {
        T_Case droite;
        droite.abscisse = Pion.abscisse+1;
        droite.ordonner = Pion.ordonner;
        if (droite.abscisse < ncol && !Verif(Casebanni, nban, droite))
        {
            voisine[nbvoisine++] = droite;
            droite.abscisse++;
            if (droite.abscisse < ncol && !Verif(Casebanni, nban, droite))
                voisine[nbvoisine++] = droite;
        }
    }
    {
        T_Case bas;
        bas.abscisse = Pion.abscisse;
        bas.ordonner = Pion.ordonner+1;
        if (bas.ordonner < nlig && !Verif(Casebanni, nban, bas))
        {
            voisine[nbvoisine++] = bas;
            bas.ordonner++;
            if (bas.ordonner < nlig && !Verif(Casebanni, nban, bas))
                voisine[nbvoisine++] = bas;
        }
    }
    return nbvoisine;
}



void Coup_joueur(T_Case* Pion, T_Tab_Case Casebanni, int nban, int nlig, int ncol)
{
    printf("C'est votre tour\n");
    T_Case voisine[4];
    int nbvoisine = Voisines(voisine, *Pion, Casebanni, nban, nlig, ncol), choix=0;
    if (nbvoisine == 1)
    {
        printf("Vous ne pouvez qu'allez ici (1) : (%d,%d)\nvalider --->\n", voisine[0].ordonner+1, voisine[0].abscisse+1);
        getchar();
        choix = 0;
    }
    else
    {
        printf("Ou veux-tu allez ?\n");
        int i;
        for (i = 0;i<nbvoisine;i++)
            printf(" (%d) => [%d,%d]", i+1, voisine[i].ordonner+1, voisine[i].abscisse+1);
        printf("\n---> ");
        choix = Lire_Entier(1, nbvoisine+1)-1;
    }
    *Pion = voisine[choix];
}



void Coup_Ordi_Hasard(T_Case* Pion, T_Tab_Case Casebanni, int nban, int nlig, int ncol)
{
    T_Case voisine[4];
    int nbvoisine = Voisines(voisine, *Pion, Casebanni, nban, nlig, ncol);
    int choix = rand()%nbvoisine;
    *Pion = voisine[choix];
    printf("Le pion va en [%d,%d]\n", Pion->abscisse+1, Pion->ordonner+1);
}



void Coup_Ordi_Gagnant(T_Case* Pion, T_Tab_Case Casebanni, int nim[][VMAX], int nban, int nlig, int ncol)
{
    T_Case voisine[4];
    int nbvoisine = Voisines(voisine, *Pion, Casebanni, nban, nlig, ncol);
    int i;
    for (i = 0;i<nbvoisine;i++)
    {
        T_Case caseNow = voisine[i];
        if (nim[caseNow.abscisse][caseNow.ordonner] == 0)
        {
            *Pion = voisine[i];
            printf("Le pion adverse se déplace en [%d,%d]\n", Pion->abscisse+1, Pion->ordonner+1);
            return;
        }
    }
    Coup_Ordi_Hasard(Pion, Casebanni, nban, nlig, ncol);
}