#include <stdio.h>

void copietab(int tab1[], int tab2[], int tailleTableau);
void affiche(int tab[], int tailleTableau);
void maximumTableau(int tableau[], int tailleTableau, int valeurMax);

int main ()
{
    int tab1[4] = {1,2,3,4};

    maximumTableau(tab1,4,2);
    affiche(tab1,4);

    return 0;

}

void maximumTableau(int tab1[], int tailleTableau, int valeurMax)
{
    for (i = 0; i < tailleTableau; i++)
    {
        if (i>2)
        {
            tab1[i]=0;
        }
        
    }
    
}

void copietab (int tab1[], int tab2[], int tailleTableau)
{
    int i;
    
    for(i = 0; i < tailleTableau ; i++)
    {
        tab2[i]=tab1[i];
    }
}

void affiche(int tab2[], int tailleTableau)
{
    int i;
 
    for (i = 0 ; i < tailleTableau ; i++)
    {
        printf("%d\n", tab2[i]);
    }
}