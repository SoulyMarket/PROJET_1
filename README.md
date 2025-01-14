# Gestion des Produits

Ce programme permet de gérer une liste de produits en offrant des fonctionnalités comme l'inscription, la connexion, l'ajout, la modification, la suppression, et l'affichage des produits.

## Fonctionnalités principales
1. **Inscription des utilisateurs** : Permet d'enregistrer un nouvel utilisateur.
2. **Connexion des utilisateurs** : Permet à un utilisateur existant de se connecter.
3. **Ajout de produits** : Les utilisateurs connectés peuvent ajouter de nouveaux produits.
4. **Affichage des produits** : Liste les produits stockés.
5. **Modification de produits** : Permet de modifier un produit existant.
6. **Suppression de produits** : Supprime un produit de la liste.
7. **Quitter le programme** : Met fin à l'exécution.

---

## Structure du programme

### Inclusion des bibliothèques et fichiers nécessaires
```c
#include <stdio.h>
#include <string.h>
#include "projet.h"

### Définition des variables principales
```c
Prod produits[100];
int nbr_produit = 0;
char utilisateurConnecte[20] = "";
int estConnecte = 0;
int choix;

### Fonctionnement du programme
Le programme utilise une boucle infinie pour afficher différents menus en fonction de l'état de connexion de l'utilisateur. Deux menus principaux sont définis : un pour les utilisateurs non connectés et un autre pour les utilisateurs connectés.

---

#### Menu pour les utilisateurs non connectés
```c
if (estConnecte == 0) {
    printf("\n=== Menu Principal ===\n");
    printf("1. S'inscrire\n");
    printf("2. Se connecter\n");
    printf("Choix : ");
    scanf("%d", &choix);
}

#### Menu pour les utilisateurs connectés
```c
if (estConnecte == 1) {
    printf("\n=== Menu Principal ===\n");
    printf("3. Ajouter un produit\n");
    printf("4. Afficher les produits\n");
    printf("5. Modifier un produit\n");
    printf("6. Supprimer un produit\n");
    printf("7. Quitter\n");
    printf("Choix : ");
    scanf("%d", &choix);
}
### Gestion des choix avec `switch`

Lorsque l'utilisateur est connecté, un menu principal propose différentes options. Ces choix sont gérés à l'aide d'une structure `switch`. Voici les explications détaillées des cas disponibles :

1. **Ajouter un produit (Choix 3)**  
   Cette option permet à l'utilisateur d'ajouter un nouveau produit.  
   - La fonction `ajouterProduit()` est appelée avec deux arguments : le numéro du produit (basé sur le compteur `nbr_produit`) et le nom de l'utilisateur connecté.
   - Le produit créé est ajouté au tableau `produits`.
   - Le compteur `nbr_produit` est incrémenté pour refléter l'ajout.

2. **Afficher les produits (Choix 4)**  
   Cette option affiche la liste des produits associés à l'utilisateur connecté.  
   - La fonction `afficherProduitsDepuisCSV()` lit les données dans un fichier CSV spécifique à l'utilisateur et affiche chaque produit.

3. **Modifier un produit (Choix 5)**  
   Cette option permet de mettre à jour les informations d'un produit existant.  
   - L'utilisateur est invité à entrer l'index du produit qu'il souhaite modifier. Cet index doit être compris entre 1 et le nombre total de produits (`nbr_produit`).
   - Si l'index est valide, la fonction `modifierProduit()` est appelée pour mettre à jour le produit dans le tableau.
   - Si l'index est invalide, un message d'erreur est affiché.

4. **Supprimer un produit (Choix 6)**  
   Cette option permet à l'utilisateur de supprimer un produit.  
   - L'utilisateur doit fournir l'index du produit qu'il souhaite supprimer, compris entre 1 et `nbr_produit`.
   - Si l'index est valide, la fonction `supprimerProduit()` est appelée pour retirer le produit du tableau. Le compteur `nbr_produit` est mis à jour.
   - En cas d'index invalide, un message d'erreur est affiché.

5. **Quitter (Choix 7)**  
   Cette option met fin à l'exécution du programme.  
   - Un message de départ est affiché : `Au revoir !`.
   - Le programme se termine avec la commande `return 0`.

6. **Choix invalide (Default)**  
   Si l'utilisateur entre une option non prise en charge, le programme affiche le message suivant :  
   `Choix invalide. Essayez encore.`

---

Le code correspondant est organisé comme suit :

```c
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
    case 7:
        printf("Au revoir !\n");
        return 0;
    default:
        printf("Choix invalide. Essayez encore.\n");
}

