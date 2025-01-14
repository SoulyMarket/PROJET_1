echo -e "# README - Gestion de Produits\n\n\
## Description\n\n\
Ce programme permet de gérer une liste de produits en utilisant un menu interactif. Il offre les fonctionnalités suivantes :\n\
- Inscription d'un nouvel utilisateur.\n\
- Connexion d'un utilisateur existant.\n\
- Ajout, affichage, modification et suppression de produits.\n\
- Un utilisateur doit être connecté pour ajouter, modifier ou supprimer des produits.\n\
\n\
Les produits sont stockés dans un tableau dynamique et peuvent être affichés, modifiés ou supprimés via le programme.\n\n\
## Fonctionnalités\n\n\
1. **S'inscrire** : Permet à un nouvel utilisateur de s'inscrire.\n\
2. **Se connecter** : Permet à un utilisateur existant de se connecter.\n\
3. **Ajouter un produit** : Permet à un utilisateur connecté d'ajouter un produit.\n\
4. **Afficher les produits** : Permet à un utilisateur connecté d'afficher tous ses produits.\n\
5. **Modifier un produit** : Permet à un utilisateur connecté de modifier un produit existant.\n\
6. **Supprimer un produit** : Permet à un utilisateur connecté de supprimer un produit existant.\n\
7. **Quitter** : Quitte le programme.\n\n\
## Explication du Code Ligne par Ligne\n\n\
### 1. Inclusion des bibliothèques\n\
\`\`\`c\n\
#include <stdio.h>\n\
#include <string.h>\n\
#include \"projet.h\"\n\
\`\`\`\n\
- **`stdio.h`** : Fournit des fonctions pour les entrées/sorties standard (comme `printf` et `scanf`).\n\
- **`string.h`** : Permet de manipuler les chaînes de caractères (comme `strcmp`).\n\
- **`projet.h`** : Fichier d'en-tête qui contient les déclarations des fonctions et structures utilisées dans le programme.\n\n\
### 2. Déclaration des variables\n\
\`\`\`c\n\
Prod produits[100];\n\
int nbr_produit = 0;\n\
char utilisateurConnecte[20] = \"\";\n\
int estConnecte = 0;\n\
int choix;\n\
\`\`\`\n\
- **`produits[100]`** : Tableau pour stocker jusqu'à 100 produits, de type `Prod` (probablement une structure définie dans `projet.h`).\n\
- **`nbr_produit`** : Variable pour suivre le nombre actuel de produits dans le tableau.\n\
- **`utilisateurConnecte[20]`** : Chaîne pour stocker le nom de l'utilisateur connecté.\n\
- **`estConnecte`** : Indicateur pour savoir si un utilisateur est connecté (0 = non, 1 = oui).\n\
- **`choix`** : Variable pour stocker l'option choisie par l'utilisateur dans le menu.\n\n\
### 3. Boucle principale\n\
\`\`\`c\n\
while (1) {\n\
\`\`\`\n\
- Une boucle infinie qui affiche le menu et traite les choix de l'utilisateur jusqu'à ce qu'il choisisse de quitter.\n\n\
### 4. Affichage du menu\n\
\`\`\`c\n\
printf(\"\\n=== Menu Principal ===\\n\");\n\
printf(\"1. S'inscrire\\n\");\n\
printf(\"2. Se connecter\\n\");\n\
printf(\"3. Ajouter un produit\\n\");\n\
printf(\"4. Afficher les produits\\n\");\n\
printf(\"5. Modifier un produit\\n\");\n\
printf(\"6. Supprimer un produit\\n\");\n\
printf(\"7. Quitter\\n\");\n\
printf(\"Choix : \");\n\
scanf(\"%d\", &choix);\n\
\`\`\`\n\
- Affiche les options disponibles dans le menu principal et attend une entrée de l'utilisateur (`scanf`).\n\n\
### 5. Traitement des choix de l'utilisateur\n\
\`\`\`c\n\
switch (choix) {\n\
\`\`\`\n\
- Selon le choix de l'utilisateur, un cas du `switch` est exécuté. Chaque option correspond à une fonctionnalité du programme.\n\n\
#### Cas 1 : Inscription\n\
\`\`\`c\n\
case 1:\n\
    inscrire();\n\
    break;\n\
\`\`\`\n\
- Appelle la fonction `inscrire()` pour permettre à un nouvel utilisateur de s'inscrire.\n\n\
#### Cas 2 : Connexion\n\
\`\`\`c\n\
case 2:\n\
    estConnecte = connecter(utilisateurConnecte);\n\
    break;\n\
\`\`\`\n\
- Appelle la fonction `connecter()` pour connecter l'utilisateur. Le résultat (0 ou 1) est stocké dans `estConnecte`.\n\n\
#### Cas 3 : Ajouter un produit\n\
\`\`\`c\n\
case 3:\n\
    if (estConnecte) {\n\
        produits[nbr_produit] = ajouterProduit(nbr_produit + 1, utilisateurConnecte);\n\
        nbr_produit++;\n\
    } else {\n\
        printf(\"Veuillez vous connecter d'abord.\\n\");\n\
    }\n\
    break;\n\
\`\`\`\n\
- Si l'utilisateur est connecté (`estConnecte == 1`), appelle la fonction `ajouterProduit()` pour ajouter un produit.\n\
- Si l'utilisateur n'est pas connecté, affiche un message d'erreur.\n\n\
#### Cas 4 : Afficher les produits\n\
\`\`\`c\n\
case 4:\n\
    if (estConnecte) {\n\
        afficherProduitsDepuisCSV(utilisateurConnecte);\n\
    } else {\n\
        printf(\"Veuillez vous connecter d'abord.\\n\");\n\
    }\n\
    break;\n\
\`\`\`\n\
- Si l'utilisateur est connecté, appelle `afficherProduitsDepuisCSV()` pour afficher ses produits. Sinon, affiche un message d'erreur.\n\n\
#### Cas 5 : Modifier un produit\n\
\`\`\`c\n\
case 5:\n\
    if (estConnecte) {\n\
        printf(\"Entrez l'index du produit à modifier (1 à %d) : \", nbr_produit);\n\
        int indexModif;\n\
        scanf(\"%d\", &indexModif);\n\
        if (indexModif > 0 && indexModif <= nbr_produit) {\n\
            modifierProduit(produits, indexModif - 1);\n\
        } else {\n\
            printf(\"Index invalide.\\n\");\n\
        }\n\
    } else {\n\
        printf(\"Veuillez vous connecter d'abord.\\n\");\n\
    }\n\
    break;\n\
\`\`\`\n\
- Si l'utilisateur est connecté, demande l'index du produit à modifier. Si l'index est valide, appelle `modifierProduit()` pour modifier le produit.\n\n\
#### Cas 6 : Supprimer un produit\n\
\`\`\`c\n\
case 6:\n\
    if (estConnecte) {\n\
        printf(\"Entrez l'index du produit à supprimer (1 à %d) : \", nbr_produit);\n\
        int indexSuppr;\n\
        scanf(\"%d\", &indexSuppr);\n\
        if (indexSuppr > 0 && indexSuppr <= nbr_produit) {\n\
            nbr_produit = supprimerProduit(produits, nbr_produit, indexSuppr - 1);\n\
        } else {\n\
            printf(\"Index invalide.\\n\");\n\
        }\n\
    } else {\n\
        printf(\"Veuillez vous connecter d'abord.\\n\");\n\
    }\n\
    break;\n\
\`\`\`\n\
- Si l'utilisateur est connecté, demande l'index du produit à supprimer. Si l'index est valide, appelle `supprimerProduit()` pour supprimer le produit et met à jour `nbr_produit`.\n\n\
#### Cas 7 : Quitter\n\
\`\`\`c\n\
case 7:\n\
    printf(\"Au revoir !\\n\");\n\
    return 0;\n\
\`\`\`\n\
- Si l'utilisateur choisit de quitter, affiche \"Au revoir\" et termine l'exécution du programme.\n\n\
#### Cas par défaut : Choix invalide\n\
\`\`\`c\n\
default:\n\
    printf(\"Choix invalide. Essayez encore.\\n\");\n\
\`\`\`\n\
- Si l'utilisateur entre un choix invalide, affiche un message d'erreur et réaffiche le menu.\n\n\
### 6. Fin du programme\n\
\`\`\`c\n\
return 0;\n\
\`\`\`\n\
- Le programme se termine avec `return 0;` lorsque l'utilisateur choisit de quitter.\n\n\
## Compilation\n\n\
Pour compiler le programme, utilisez la commande suivante (si vous utilisez GCC) :\n\
\`\`\`bash\n\
gcc -o gestionProduits gestionProduits.c\n\
\`\`\`\n\
Cela génère un exécutable nommé `gestionProduits`.\n\n\
## Utilisation\n\n\
### Démarrer le programme :\n\
Après avoir compilé le programme, vous pouvez le lancer avec la commande suivante :\n\
\`\`\`bash\n\
./gestionProduits\n\
\`\`\`\n\
### Exemple de menu :\n\
```\n\
=== Menu Principal ===\n\
1. S'inscrire\n\
2. Se connecter\n\
3. Ajouter un produit\n\
4. Afficher les produits\n\
5. Modifier un produit\n\
6. Supprimer un produit\n\
7. Quitter\n\
```\n\n\
### Inscription et connexion :\n\
- Pour **s'inscrire** : Choisissez l'option 1 et suivez les instructions.\n\
- Pour **se connecter** : Choisissez l'option 2 et entrez votre identifiant et mot de passe.\n\n\
### Ajouter un produit :\n\
- Pour **ajouter un produit** : Choisissez l'option 3, et vous devrez vous connecter d'abord.\n\n\
### Afficher les produits :\n\
- Pour **afficher les produits** : Choisissez l'option 4, et les produits de l'utilisateur connecté seront affichés.\n\n\
### Modifier un produit :\n\
- Pour **modifier un produit** : Choisissez l'option 5, entrez l'index du produit à modifier et suivez les instructions.\n\n\
### Supprimer un produit :\n\
- Pour **supprimer un produit** : Choisissez l'option 6, entrez l'index du produit à supprimer et suivez les instructions.\n\n\
### Quitter le programme :\n\
- Pour **quitter** : Choisissez l'option 7.\n\n\
## Contact\n\n\
Pour toute question ou suggestion, vous pouvez me contacter à l'adresse suivante :\n\
`contact@exemple.com`\n" > README.txt
