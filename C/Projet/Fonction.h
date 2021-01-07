#ifndef DEF_FONCTION_H
#define DEF_FONCTION_H
#define VMAX 30

typedef struct T_Case
{
    int abscisse;
    int ordonner;
} T_Case;

typedef T_Case* T_Tab_Case;

int Lire_Entier (int binf, int bsup);
void parametres (int *nlig,int *ncol,int *lvl,int *next,int *casban);
void Hasard_Ban(T_Tab_Case Casebanni, int nlig, int ncol, int nban);
int Verif(T_Tab_Case Casebanni, int taille, T_Case coordonner);
void Coup_joueur(T_Case* Pion, T_Tab_Case Casebanni, int nban, int nlig, int ncol);
int Voisines(T_Tab_Case voisine, T_Case Pion, T_Tab_Case Casebanni, int nban, int nlig, int ncol);
void AfficheGrille(T_Case Pion, T_Tab_Case Casebanni, int nban, int nlig, int ncol);
void Calcul_Nimbers(int nim[][VMAX], int nlig, int ncol);
void Coup_Ordi_Hasard(T_Case* Pion, T_Tab_Case Casebanni, int nban, int nlig, int ncol);
void Coup_Ordi_Gagnant(T_Case* Pion, T_Tab_Case Casebanni, int nim[][VMAX], int nban, int nlig, int ncol);

#endif