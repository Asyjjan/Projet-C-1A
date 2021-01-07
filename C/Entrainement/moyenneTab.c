#include <stdio.h>

double moyTab (int tableau[], int tailleTab);

int main ()
{
int tableau[4] = {10, 10, 20, 20};
moyTab(tableau, 4);
printf ("La moyenne du tableau est : %lf",moyTab(tableau, 4));

return 0;
}

double moyTab (int tableau[], int tailleTab)
{
    int i, resultat;
    resultat = 0;

    for (i = 0; i < tailleTab; i++)
    {
        resultat= resultat + tableau[i];
    }

    resultat = resultat / tailleTab;

    return resultat;
}