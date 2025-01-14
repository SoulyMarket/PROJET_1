#include <stdio.h>
#include <string.h>
#include "projet.h"

void enregistrerUtilisateur(User utilisateur) {
    FILE* fichier = fopen("utilisateurs.txt", "a");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des utilisateurs.\n");
        return;
    }
    fprintf(fichier, "%s %s\n", utilisateur.username, utilisateur.password);
    fclose(fichier);
}

int verifierUtilisateur(char username[20], char password[20]) {
    FILE* fichier = fopen("utilisateurs.txt", "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier des utilisateurs.\n");
        return 0;
    }

    char file_username[20], file_password[20];
    while (fscanf(fichier, "%s %s", file_username, file_password) != EOF) {
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            fclose(fichier);
            return 1;
        }
    }
    fclose(fichier);
    return 0;
}

User inscrire() {
    User utilisateur;
    printf("=== Inscription ===\n");
    printf("Entrez un nom d'utilisateur : ");
    scanf("%s", utilisateur.username);
    printf("Entrez un mot de passe : ");
    scanf("%s", utilisateur.password);

    enregistrerUtilisateur(utilisateur);
    printf("Inscription réussie ! Vous pouvez maintenant vous connecter.\n");
    return utilisateur;
}

int connecter(char username[20]) {
    char password[20];
    printf("=== Connexion ===\n");
    printf("Nom d'utilisateur : ");
    scanf("%s", username);
    printf("Mot de passe : ");
    scanf("%s", password);

    if (verifierUtilisateur(username, password)) {
        printf("Connexion réussie. Bienvenue, %s !\n", username);
        return 1;
    } else {
        printf("Nom d'utilisateur ou mot de passe incorrect.\n");
        return 0;
    }
}

Prod ajouterProduit(int id, char username[20]) {
    Prod produit;
    produit.id = id;
    strcpy(produit.username, username);
    printf("\n=== Ajouter un Produit ===\n");
    printf("Nom : ");
    scanf(" %[^\n]", produit.name);
    printf("Description : ");
    scanf(" %[^\n]", produit.description);
    printf("Prix : ");
    scanf("%f", &produit.price);
    printf("Quantité : ");
    scanf("%d", &produit.quantity);
    printf("Seuil d'alerte : ");
    scanf("%d", &produit.alert_threshold);
    printf("Date de dernière entrée (jj mm aaaa) : ");
    scanf("%d %d %d", &produit.d_last_enter.day, &produit.d_last_enter.month, &produit.d_last_enter.year);
    printf("Date de dernière sortie (jj mm aaaa) : ");
    scanf("%d %d %d", &produit.d_last_exit.day, &produit.d_last_exit.month, &produit.d_last_exit.year);

    FILE *fichier = fopen("produits.csv", "a");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier produits.csv\n");
        return produit;
    }
    fprintf(fichier, "%d,%s,%s,%s,%.2f,%d,%d,%02d/%02d/%04d,%02d/%02d/%04d\n",
            produit.id,
            produit.name,
            produit.description,
            produit.username,
            produit.price,
            produit.quantity,
            produit.alert_threshold,
            produit.d_last_enter.day,
            produit.d_last_enter.month,
            produit.d_last_enter.year,
            produit.d_last_exit.day,
            produit.d_last_exit.month,
            produit.d_last_exit.year);
    fclose(fichier);
    id++;
    printf("Produit ajouté et sauvegardé dans produits.csv\n");
    return produit;
}

void afficherProduitsDepuisCSV(const char* utilisateur) {
    FILE* fichier = fopen("produits.csv", "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier produits.csv\n");
        return;
    }
    char id[10], nom[50], description[100], user[20], prix[10], quantite[10], seuil[10];
    char entree[20], sortie[20];
    int ligne_num = 0;

    printf("\n=== Liste des Produits pour l'utilisateur %s ===\n", utilisateur);

    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                  id, nom, description, user, prix, quantite, seuil, entree, sortie) == 9) {
        ligne_num++;
        if (strcmp(user, utilisateur) == 0) {
            printf("\nID : %s\n", id);
            printf("Nom : %s\n", nom);
            printf("Description : %s\n", description);
            printf("Prix : %s\n", prix);
            printf("Quantité : %s\n", quantite);
            printf("Seuil d'alerte : %s\n", seuil);
            printf("Date d'entrée : %s\n", entree);
            printf("Date de sortie : %s\n", sortie);
        }
    }
    fclose(fichier);
}

int supprimerProduit(Prod produits[], int nbr_produit, int index) {
      FILE* fichier = fopen("produits.csv", "r");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier produits.csv\n");
        return;
    }
    if (index < 0) {
        printf("Index invalide.\n");
        return;
    }
    char id[10], nom[50], description[100], user[20], prix[10], quantite[10], seuil[10];
    char entree[20], sortie[20];
    int ligne_num = 0;
    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                  id, nom, description, user, prix, quantite, seuil, entree, sortie) == 9) {
    if (index < 0 || index >= nbr_produit) {
        printf("Index invalide.\n");
        return nbr_produit;
    }

    for (int i = index; i < nbr_produit - 1; i++) {
        produits[i] = produits[i + 1];
    }

    printf("Produit supprimé avec succès.\n");
    return nbr_produit - 1;
}}

void modifierProduit(Prod produits[], int index) {
    FILE* fichier = fopen("produits.csv", "r+");
    if (fichier == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier produits.csv\n");
        return;
    }

    if (index < 0) {
        printf("Index invalide.\n");
        fclose(fichier);
        return;
    }

    char id[10], nom[50], description[100], user[20], prix[10], quantite[10], seuil[10];
    char entree[20], sortie[20];
    int ligne_num = 0;

    while (fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                  id, nom, description, user, prix, quantite, seuil, entree, sortie) == 9) {

        if (ligne_num == index) {
            printf("\n=== Modifier le Produit ===\n");
            printf("Nom (actuel : %s) : ", produits[index].name);
            scanf(" %49[^\n]", produits[index].name);

            printf("Description (actuel : %s) : ", produits[index].description);
            scanf(" %99[^\n]", produits[index].description);

            printf("Prix (actuel : %.2f) : ", produits[index].price);
            scanf("%f", &produits[index].price);

            printf("Quantité (actuel : %d) : ", produits[index].quantity);
            scanf("%d", &produits[index].quantity);

            printf("Seuil d'alerte (actuel : %d) : ", produits[index].alert_threshold);
            scanf("%d", &produits[index].alert_threshold);

            printf("Date de dernière entrée (actuel : %d-%d-%d) : ", produits[index].d_last_enter.day, produits[index].d_last_enter.month, produits[index].d_last_enter.year);
            scanf("%d %d %d", &produits[index].d_last_enter.day, &produits[index].d_last_enter.month, &produits[index].d_last_enter.year);

            printf("Date de dernière sortie (actuel : %d-%d-%d) : ", produits[index].d_last_exit.day, produits[index].d_last_exit.month, produits[index].d_last_exit.year);
            scanf("%d %d %d", &produits[index].d_last_exit.day, &produits[index].d_last_exit.month, &produits[index].d_last_exit.year);

            printf("Produit modifié avec succès.\n");
            fseek(fichier, 0, SEEK_SET);
            FILE* fichierTemp = fopen("produits_temp.csv", "w");
            if (fichierTemp == NULL) {
                printf("Erreur lors de la création du fichier temporaire.\n");
                fclose(fichier);
                return;
            }
            for (int i = 0; fscanf(fichier, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                                   id, nom, description, user, prix, quantite, seuil, entree, sortie) == 9; i++) {
                if (i == index) {
                    fprintf(fichierTemp, "%s,%s,%s,%s,%f,%d,%d,%d-%d-%d,%d-%d-%d\n",
                            id, produits[index].name, produits[index].description, user, produits[index].price, produits[index].quantity,
                            produits[index].alert_threshold, produits[index].d_last_enter.day, produits[index].d_last_enter.month, produits[index].d_last_enter.year,
                            produits[index].d_last_exit.day, produits[index].d_last_exit.month, produits[index].d_last_exit.year);
                } else {
                    fprintf(fichierTemp, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n", id, nom, description, user, prix, quantite, seuil, entree, sortie);
                }
            }

            fclose(fichier);
            fclose(fichierTemp);
            remove("produits.csv");
            rename("produits_temp.csv", "produits.csv");

            return;
        }
        ligne_num++;
    }
    printf("Produit non trouvé.\n");
    fclose(fichier);
}

