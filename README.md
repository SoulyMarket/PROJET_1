# README

## Explication du Programme (Ligne par Ligne)

1. **Importation des bibliothèques et fichiers** :
   ```c
   #include <stdio.h>
   #include <string.h>
   #include "projet.h"
   ```
   - Ces lignes incluent les bibliothèques standard et un fichier d'en-tête personnalisé contenant des fonctions complémentaires.

2. **Initialisation des variables principales** :
   ```c
   Prod produits[100];
   int nbr_produit = 0;
   char utilisateurConnecte[20] = "";
   int estConnecte = 0;
   ```
   - `produits[100]` : Tableau pour stocker jusqu'à 100 produits.
   - `nbr_produit` : Nombre actuel de produits.
   - `utilisateurConnecte` : Stocke le nom de l'utilisateur connecté.
   - `estConnecte` : Indique si un utilisateur est connecté (1 = oui, 0 = non).

3. **Boucle principale du menu** :
   ```c
   while (1) {
   ```
   - Une boucle infinie permettant à l'utilisateur d'interagir avec le programme.

4. **Affichage du menu principal** :
   ```c
   printf("\n=== Menu Principal ===\n");
   printf("1. S'inscrire\n");
   printf("2. Se connecter\n");
   printf("3. Ajouter un produit\n");
   printf("4. Afficher les produits\n");
   printf("5. Modifier un produit\n");
   printf("6. Supprimer un produit\n");
   printf("7. Quitter\n");
   printf("Choix : ");
   ```
   - Affiche les options disponibles pour l'utilisateur.

5. **Lecture du choix de l'utilisateur** :
   ```c
   scanf("%d", &choix);
   ```
   - Récupère l'option sélectionnée par l'utilisateur.

6. **Traitement des options avec un switch** :
   ```c
   switch (choix) {
   case 1:
       inscrire();
       break;
   case 2:
       estConnecte = connecter(utilisateurConnecte);
       break;
   ```
   - `case 1` : Appelle la fonction `inscrire` pour enregistrer un nouvel utilisateur.
   - `case 2` : Appelle `connecter` pour permettre à l'utilisateur de se connecter.

7. **Ajout de produits (case 3)** :
   ```c
   if (estConnecte) {
       produits[nbr_produit] = ajouterProduit(nbr_produit + 1, utilisateurConnecte);
       nbr_produit++;
   } else {
       printf("Veuillez vous connecter d'abord.\n");
   }
   ```
   - Ajoute un produit uniquement si l'utilisateur est connecté.

8. **Affichage des produits (case 4)** :
   ```c
   if (estConnecte) {
       afficherProduits(produits, nbr_produit);
   } else {
       printf("Veuillez vous connecter d'abord.\n");
   }
   ```
   - Affiche la liste des produits si l'utilisateur est connecté.

9. **Modification et suppression des produits (cases 5 et 6)** :
   - Les options permettent à un utilisateur connecté de modifier ou supprimer des produits après vérification de l'index.

10. **Quitter le programme (case 7)** :
    ```c
    printf("Au revoir !\n");
    return 0;
    ```
    - Termine le programme.

11. **Gestion des erreurs** :
    ```c
    default:
        printf("Choix invalide. Essayez encore.\n");
    ```
    - Affiche un message d'erreur pour une saisie invalide.

---

Chaque fonction (comme `inscrire`, `connecter`, etc.) est probablement définie dans le fichier d'en-tête `projet.h` ou dans un autre fichier lié.

