README - Gestion de Produits
Description
Ce programme permet de gérer une liste de produits en utilisant un menu interactif. Il offre les fonctionnalités suivantes :

Inscription d'un nouvel utilisateur.
Connexion d'un utilisateur existant.
Ajout, affichage, modification et suppression de produits.
Un utilisateur doit être connecté pour ajouter, modifier ou supprimer des produits.
Les produits sont stockés dans un tableau dynamique et peuvent être affichés, modifiés ou supprimés via le programme.

Fonctionnalités
S'inscrire : Permet à un nouvel utilisateur de s'inscrire.
Se connecter : Permet à un utilisateur existant de se connecter.
Ajouter un produit : Permet à un utilisateur connecté d'ajouter un produit.
Afficher les produits : Permet à un utilisateur connecté d'afficher tous ses produits.
Modifier un produit : Permet à un utilisateur connecté de modifier un produit existant.
Supprimer un produit : Permet à un utilisateur connecté de supprimer un produit existant.
Quitter : Quitte le programme.
Explication du Code Ligne par Ligne
1. Inclusion des bibliothèques
c
Copy code
#include <stdio.h>
#include <string.h>
#include "projet.h"
stdio.h : Fournit des fonctions pour les entrées/sorties standard (comme printf et scanf).
string.h : Permet de manipuler les chaînes de caractères (comme strcmp).
projet.h : Fichier d'en-tête qui contient les déclarations des fonctions et structures utilisées dans le programme.
2. Déclaration des variables
c
Copy code
Prod produits[100];
int nbr_produit = 0;
char utilisateurConnecte[20] = "";
int estConnecte = 0;
int choix;
produits[100] : Tableau pour stocker jusqu'à 100 produits, de type Prod (probablement une structure définie dans projet.h).
nbr_produit : Variable pour suivre le nombre actuel de produits dans le tableau.
utilisateurConnecte[20] : Chaîne pour stocker le nom de l'utilisateur connecté.
estConnecte : Indicateur pour savoir si un utilisateur est connecté (0 = non, 1 = oui).
choix : Variable pour stocker l'option choisie par l'utilisateur dans le menu.
3. Boucle principale
c
Copy code
while (1) {
Une boucle infinie qui affiche le menu et traite les choix de l'utilisateur jusqu'à ce qu'il choisisse de quitter.
4. Affichage du menu
c
Copy code
printf("\n=== Menu Principal ===\n");
printf("1. S'inscrire\n");
printf("2. Se connecter\n");
printf("3. Ajouter un produit\n");
printf("4. Afficher les produits\n");
printf("5. Modifier un produit\n");
printf("6. Supprimer un produit\n");
printf("7. Quitter\n");
printf("Choix : ");
scanf("%d", &choix);
Affiche les options disponibles dans le menu principal et attend une entrée de l'utilisateur (scanf).
5. Traitement des choix de l'utilisateur
c
Copy code
switch (choix) {
Selon le choix de l'utilisateur, un cas du switch est exécuté. Chaque option correspond à une fonctionnalité du programme.
Cas 1 : Inscription
c
Copy code
case 1:
    inscrire();
    break;
Appelle la fonction inscrire() pour permettre à un nouvel utilisateur de s'inscrire.
Cas 2 : Connexion
c
Copy code
case 2:
    estConnecte = connecter(utilisateurConnecte);
    break;
Appelle la fonction connecter() pour connecter l'utilisateur. Le résultat (0 ou 1) est stocké dans estConnecte.
Cas 3 : Ajouter un produit
c
Copy code
case 3:
    if (estConnecte) {
        produits[nbr_produit] = ajouterProduit(nbr_produit + 1, utilisateurConnecte);
        nbr_produit++;
    } else {
        printf("Veuillez vous connecter d'abord.\n");
    }
    break;
Si l'utilisateur est connecté (estConnecte == 1), appelle la fonction ajouterProduit() pour ajouter un produit.
Si l'utilisateur n'est pas connecté, affiche un message d'erreur.
Cas 4 : Afficher les produits
c
Copy code
case 4:
    if (estConnecte) {
        afficherProduitsDepuisCSV(utilisateurConnecte);
    } else {
        printf("Veuillez vous connecter d'abord.\n");
    }
    break;
Si l'utilisateur est connecté, appelle afficherProduitsDepuisCSV() pour afficher ses produits. Sinon, affiche un message d'erreur.
Cas 5 : Modifier un produit
c
Copy code
case 5:
    if (estConnecte) {
        printf("Entrez l'index du produit à modifier (1 à %d) : ", nbr_produit);
        int indexModif;
        scanf("%d", &indexModif);
        if (indexModif > 0 && indexModif <= nbr_produit) {
            modifierProduit(produits, indexModif - 1);
        } else {
            printf("Index invalide.\n");
        }
    } else {
        printf("Veuillez vous connecter d'abord.\n");
    }
    break;
Si l'utilisateur est connecté, demande l'index du produit à modifier. Si l'index est valide, appelle modifierProduit() pour modifier le produit.
Cas 6 : Supprimer un produit
c
Copy code
case 6:
    if (estConnecte) {
        printf("Entrez l'index du produit à supprimer (1 à %d) : ", nbr_produit);
        int indexSuppr;
        scanf("%d", &indexSuppr);
        if (indexSuppr > 0 && indexSuppr <= nbr_produit) {
            nbr_produit = supprimerProduit(produits, nbr_produit, indexSuppr - 1);
        } else {
            printf("Index invalide.\n");
        }
    } else {
        printf("Veuillez vous connecter d'abord.\n");
    }
    break;
Si l'utilisateur est connecté, demande l'index du produit à supprimer. Si l'index est valide, appelle supprimerProduit() pour supprimer le produit et met à jour nbr_produit.
Cas 7 : Quitter
c
Copy code
case 7:
    printf("Au revoir !\n");
    return 0;
Si l'utilisateur choisit de quitter, affiche "Au revoir" et termine l'exécution du programme.
Cas par défaut : Choix invalide
c
Copy code
default:
    printf("Choix invalide. Essayez encore.\n");
Si l'utilisateur entre un choix invalide, affiche un message d'erreur et réaffiche le menu.
6. Fin du programme
c
Copy code
return 0;
Le programme se termine avec return 0; lorsque l'utilisateur choisit de quitter.
Compilation
Pour compiler le programme, utilisez la commande suivante (si vous utilisez GCC) :

bash
Copy code
gcc -o gestionProduits gestionProduits.c
Cela génère un exécutable nommé gestionProduits.

Utilisation
Démarrer le programme :
Après avoir compilé le programme, vous pouvez le lancer avec la commande suivante :

bash
Copy code
./gestionProduits
Exemple de menu :
markdown
Copy code
=== Menu Principal ===
1. S'inscrire
2. Se connecter
3. Ajouter un produit
4. Afficher les produits
5. Modifier un produit
6. Supprimer un produit
7. Quitter
Inscription et connexion :
Pour s'inscrire : Choisissez l'option 1 et suivez les instructions.
Pour se connecter : Choisissez l'option 2 et entrez votre identifiant et mot de passe.
Ajouter un produit :
Pour ajouter un produit : Choisissez l'option 3, et vous devrez vous connecter d'abord.
Afficher les produits :
Pour afficher les produits : Choisissez l'option 4, et les produits de l'utilisateur connecté seront affichés.
Modifier un produit :
Pour modifier un produit : Choisissez l'option 5, entrez l'index du produit à modifier et suivez les instructions.
Supprimer un produit :
Pour supprimer un produit : Choisissez l'option 6, entrez l'index du produit à supprimer et suivez les instructions.
Quitter le programme :
Pour quitter : Choisissez l'option 7.
