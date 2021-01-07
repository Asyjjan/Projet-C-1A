void AfficheGrille(T_Case Pion, T_Tab_Case Casebanni, int nban, int nlig, int ncol)
{
    int nbligne, nbcolonne;
    int banned = 0;

    for (nbligne = 0;nbligne<nlig;nbligne++)
    {
        printf("%d", nbligne+1);
        for (nbcolonne = 0;nbcolonne<ncol;nbcolonne++)
        {
            T_Case caseNow;
            caseNow.abscisse = nbcolonne;
            caseNow.ordonner = nbligne;
            // Si la case est celle du Pion(banned = 2)
            if (Pion.abscisse == caseNow.abscisse && Pion.ordonner == caseNow.ordonner)
                banned=2;
            // Si la case est connu dans la table ou on stock les cases banni, on lui assigne 1 (banned = 1(vrai))
            else if (Verif(Casebanni, nban, caseNow))
            {   banned=1;
                break;
            }
            // Sinon banned reste a 0(faux)
            else
                banned=0;
        }
        // Si banned = 1, (case bannie) on met un X, si c'est une case normal (banned = 0) on met un 0 et si c'est la place du pion au début (0,0) on met un P.
        switch (banned)
        {
        case 0:
            printf("| 0 |");
            break;
        case 1:
            printf("| X |");
            break;
        case 2:
            printf("| P |");
            break;
        }
    }

}





void Coup_joueur(T_Case* Pion, T_Tab_Case Casebanni, int nban, int nlig, int ncol)
{
    printf("C'est votre tour\n");
    T_Case voisine[4];
    int nbvoisine = Voisines(voisine, *Pion, Casebanni, nban, nlig, ncol), choix;
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




int fin = 0,
char *str1="Tu as perdu !";
char *str2="Tu as gagner !";
char *str3;
do
{
    AfficheGrille(Pion,Casebanni,nban,nlig,ncol);
    if (next == 2)
    {
        switch(lvl)
        {
            case 1:
                Coup_Ordi_Hasard(&Pion, ban, nban, nlig, ncol);
                break;
            case 2:
                if (rand()%3 == 0)
                    Coup_Ordi_Gagnant(&Pion, ban, nim, nban, nlig, ncol);
                else
                    Coup_Ordi_Hasard(&Pion, ban, nban, nlig, ncol);
                    break;
            case 3:
                if (rand()%3 == 0)
                    Coup_Ordi_Hasard(&Pion, ban, nban, nlig, ncol);
                else
                    Coup_Ordi_Gagnant(&Pion, ban, nim, nban, nlig, ncol);
                break;
            case 4:
                Coup_Ordi_Gagnant(&Pion, ban, nim, nban, nlig, ncol);
                break;
        }
        next=1;
        //Si victoire
        if (Pion.ordonner==nlig)&&(Pion.abscisse==ncol))
               {
                  fin=1;
                  str3=str1;
               }
               break;
    }
    else if (next == 1)
    {
        Coup_joueur(&Pion, Casebanni, nban, nlig, ncol);
        next = 2;
        //Si victoire
        if (Pion.ordonner==nlig)&&(Pion.abscisse==ncol))
               {
                  fin=1;
                  str3=str2;
               }
               break;
    }
}
while (fin!=1);
printf("C'est termine, %s",str3);

    