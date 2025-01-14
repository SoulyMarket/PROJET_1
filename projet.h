#ifndef PROJET_H
#define PROJET_H

typedef struct User {
    char username[20];
    char password[20];
} User;

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

typedef struct Prod {
    int id;
    char name[50];
    char description[256];
    char username[25];
    float price;
    int quantity;
    int alert_threshold;
    Date d_last_enter;
    Date d_last_exit;
} Prod;

void enregistrerUtilisateur(User utilisateur);
int verifierUtilisateur(char username[20], char password[20]);
User inscrire();
int connecter(char username[20]);
Prod ajouterProduit(int id, char username[20]);
void afficherProduitsDepuisCSV(const char* utilisateur);
int supprimerProduit(Prod produits[], int nbr_produit, int index);
void modifierProduit(Prod produits[], int index);
void rechercherProduit(Prod produits[], int nbr_produit, const char* nomProduit, const char* utilisateurConnecte);
void trierProduits(Prod produits[], int nbr_produit);

#endif // PROJET_H

