#include <stdio.h>
#include <string.h>
#include "projet.h"

int main() {
    Prod produits[100];
    int nbr_produit = 0;
    char utilisateurConnecte[20] = "";
    int estConnecte = 0;
    int choix;



    while (1) {
        if (estConnecte == 0) {
            printf("\n=== Menu Principal ===\n");
            printf("1. S'inscrire\n");
            printf("2. Se connecter\n");
            printf("Choix : ");
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    inscrire();
                    break;

                case 2:
                    estConnecte = connecter(utilisateurConnecte);
                    break;

                default:
                    printf("Choix invalide. Essayez encore.\n");
            }
        }
 if (estConnecte == 1) {
    printf("\n=== Menu Principal ===\n");
    printf("3. Ajouter un produit\n");
    printf("4. Afficher les produits\n");
    printf("5. Modifier un produit\n");
    printf("6. Supprimer un produit\n");
    printf("7. Rechercher un produit\n");
    printf("8. Trier les produits\n");
    printf("9. Quitter\n");
    printf("Choix : ");
    scanf("%d", &choix);
    switch (choix) {
        case 3:
            produits[nbr_produit] = ajouterProduit(nbr_produit + 1, utilisateurConnecte);
            nbr_produit++;
            break;

        case 4:
            afficherProduitsDepuisCSV(utilisateurConnecte);
            break;

        case 5:
            printf("Entrez l'index du produit a modifier (1 a %d) : ", nbr_produit);
            int indexModif;
            scanf("%d", &indexModif);
            if (indexModif > 0 && indexModif <= nbr_produit) {
                modifierProduit(produits, indexModif - 1);
            } else {
                printf("Index invalide.\n");
            }
            break;

        case 6:
            printf("Entrez l'index du produit à supprimer (1 à %d) : ", nbr_produit);
            int indexSuppr;
            scanf("%d", &indexSuppr);
            if (indexSuppr > 0 && indexSuppr <= nbr_produit) {
                nbr_produit = supprimerProduit(produits, nbr_produit, indexSuppr - 1);
            } else {
                printf("Index invalide.\n");
            }
            break;

        case 7: {
            char nomProduit[100];
            printf("Entrez le nom du produit à rechercher : ");
            scanf("%s", nomProduit);
            rechercherProduit(produits, nbr_produit, nomProduit, utilisateurConnecte);
            break;
        }

        case 8:
            trierProduits(produits, nbr_produit);
            break;

        case 9:
            printf("Au revoir !\n");
            return 0;

        default:
            printf("Choix invalide. Essayez encore.\n");

    }

    }}}

