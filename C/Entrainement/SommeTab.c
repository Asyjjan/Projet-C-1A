#include <stdio.h>

int somTab (int tableau[], int tailleTab);

int main ()
{
int tableau[4] = {1, 2, 3, 4};
somTab(tableau, 4);
printf ("La somme du tableau est : %d",somTab(tableau, 4));

return 0;
}

int somTab (int tableau[], int tailleTab)
{
    int i, resultat;
    resultat = 0;

    for (i = 0; i < tailleTab; i++)
    {
        resultat= resultat + tableau[i];
    }

    return resultat;
}