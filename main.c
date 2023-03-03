#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
Pour l'exercice vous aurez besoin de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1 
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/

int grille[9][9];
int solution[9][9];
int i, j, v, k, colonneChoisie, ligneChoisie;

// Ecrire la fonction generer(), elle prend en paramètre la grille et renvoie le nombre d'éléments non nuls
int generer(){
    int i, j, k, valNulle, nbCaseVide = 0;
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            valNulle = rand() %2;
            if(valNulle == 0){
                grille[i][j] = 0;
                nbCaseVide++;
            }
        }
    }
    printf("GRILLE\n");  
    printf("---------------------------------\n");              
    for(i=0; i<9; ++i){
        for(j=0; j<9; ++j){
            printf("%d ", grille[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------\n\n");  
    printf("Le nombre de case vide est egal a %d \n\n", nbCaseVide);
    return 0;
}

// Ce lien vous sera utile : https://www.geeksforgeeks.org/pass-2d-array-parameter-c/


/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/

int verifierLigneColonne(){
    int i, j, v, ligneChoisie, colonneChoisie, memeLigne = 0, memeColonne = 0;
    for(i=0; i<9;i++){
        for(j=0; j<9;j++){
            if(grille[i][j] == v){
                memeLigne++;
            }
        }
        if(grille[i][j] == v){
            memeColonne++;
        }
    }
    if(memeLigne != 0){
        printf("Le chiffre est déjà sur la ligne");
    } else if(memeColonne != 0){
        printf("Le chiffre est déjà sur la colonne");
    } else{
        grille[colonneChoisie][ligneChoisie] = v;
        printf("\nGRILLE\n");  
        printf("---------------------------------\n");              
        for(i=0; i<9; ++i){
            for(j=0; j<9; ++j){
                printf("%d ", grille[i][j]);
            }
            printf("\n");
        }
        printf("---------------------------------\n"); 

    }
}

int saisir(){
    int i, j, v, ligneChoisie, colonneChoisie;
    while(&grille[9][9] != &solution[9][9]){
        printf("Veuillez saisir la coordonnees (format: vertical horizontal): ");
        scanf("%d %d", &colonneChoisie, &ligneChoisie);
        printf("Veuillez saisir la valeur: ");
        scanf("%d", &v);

        if(grille[i][j] != 0){
            printf("\nLa case est deja remplie !!\n");
        } else{
            verifierLigneColonne();
        }
    }
    
    return 0;
}

/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/


/*
Écrire la fonction verifierRegion() qui prend en paramètre deux indices k et l qui correspondent à la région (k,l)
et qui renvoie 1 si la région est correctement remplie, 0 sinon.
*/
// int verifierRegion(){
//     int k, l, juste = 0, grille[9][9];
//     for(k=0; k<3;k++){
//         for(l=0; l<3;l++){
//             k[j] = grille[i][j];
//         }
//     }
// }


//Écrire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon


//Écrire le programme principal, en supposant que la seule condition d’arrêt est la réussite du sudoku (ce test ne devra être fait que si nécessaire)


int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    int solution[9][9];
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  
    for(j=0;j<9; ++j) 
    {
    for(i=0; i<9; ++i)
        solution[j][i] = (i + j*3 +j /3) %9 +1 ; 
        
    }
    
    for(i=0;i<9; ++i) 
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");  
    //toucher le code entre les commentaires 

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            grille[i][j] = solution[i][j];
        }
    }
    generer();
    saisir();

    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}

