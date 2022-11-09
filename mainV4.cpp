#include "PrjInfo2022.h"

#define LIGNES 6
#define COLONNES 6
#define N_BATEAUX 2
#define COLOR_1 15
#define COLOR_2 3
#define TEMPS 50
#define TAILLE 4
#define TEMPS2 200


//Declarations variables globales
int echecs = 0; //var debug
int iBcl; // compteur de boucle
int iBcl1; // compteur de boucle n2
int iBcl2; // compteur de boucle n3
int iBcl3; // compteur de boucle n4
int l_int_ligne = 0; // 
int l_int_cpt = 0;
int l_int_joueur = 0;
int l_int_colonne = 0;
int l_int_points = 0;
bool l_bool_bateauxPlaces = 0;
bool l_bool_win = 0;
int l_int_choix[2];
int l_int_coordX;
int l_int_coordY;
int l_int_regle;
int l_int_point = 0;
int l_int_tentative = 0;
int l_int_sec = 0;
int l_int_min = 0;
bool l_bool_direction; //l_bool_direction 0 pour vertical et 1 pour horizontal
TCase l_enrTab_Mer1[LIGNES][COLONNES];
TCase l_enrTab_Mer1D[LIGNES][COLONNES];

//mer1D = version affichee a l'utilisateur

//fonction qui initialise toutes les cases de la mer a 0
void initCases(void) {
    //initialisation de toutes les cases a 0
    for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
        for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
            l_enrTab_Mer1[iBcl1][iBcl2].m_int_bateau = 0;
            l_enrTab_Mer1[iBcl1][iBcl2].m_bool_touche = 0;
        }
    }
}
//FUSIONNER CES 2 FONCTIONS
void initCases2(void) {
    //initialisation de toutes les cases a 0
    for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
        for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
            l_enrTab_Mer1D[iBcl1][iBcl2].m_int_bateau = 0;
            l_enrTab_Mer1D[iBcl1][iBcl2].m_bool_touche = 0;
        }
    }
}

//DEBUG
void afficheMerDebug(void) {
    //affichage de la ligne d'en tete en couleur1
    Color(COLOR_1);
    printf("   1 2 3 4 5 6\n");
    Color(COLOR_2);

    //boucle for pour afficher les lignes en couleur 2 ainsi que l'en tete de chaque ligne en couleur 1
    for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
        Color(COLOR_1);
        printf("%c  ", iBcl1 + 65);
        Color(COLOR_2);
        //boucle for pour afficher les colonnes
        for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
            printf("%i ", l_enrTab_Mer1[iBcl1][iBcl2].m_int_bateau);
        }
        //retour a la ligne pour rendre le resultat plus clean
        printf("\n");
        Color(COLOR_1);
    }
}

//fonction pour afficher une mer
void afficheMer(void) {
    //affichage de la ligne d'en tete en couleur1
    Color(COLOR_1);
    printf("   1 2 3 4 5 6\n");
    Color(COLOR_2);

    //boucle for pour afficher les lignes en couleur 2 ainsi que l'en tete de chaque ligne en couleur 1
    for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
        Color(COLOR_1);
        printf("%c  ", iBcl1 + 65);
        Color(COLOR_2);
        //boucle for pour afficher les colonnes
        for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
            printf("%i ", l_enrTab_Mer1D[iBcl1][iBcl2].m_int_bateau);
        }
        //retour a la ligne pour rendre le resultat plus clean
        printf("\n");
        Color(COLOR_1);
    }
}

//fonction pour placer les bateaux
void placeBateau(void) {

    //init aleatoire
    srand(time(NULL));

    //boucle pour generer un certain nombre de bateau
    for (iBcl1 = 0; iBcl1 < N_BATEAUX; iBcl1++) {

        //determination aleatoire de la direction du bateau
        l_bool_direction = rand() % 2;
        l_bool_bateauxPlaces = 0;

        //execution fonction placement si bateau vertical
        if (l_bool_direction == 0) {

            //replace le bateau tant que celui-ci n'est pas dans une case libre
            do {

                //determination aleatoire de la premiere case du bateau
                l_int_ligne = rand() % 4;
                l_int_colonne = rand() % 6;

                //Si la case choisie aleatoirement et les 2 suivantes verticales sont libres, alors on place le bateau
                if ((l_enrTab_Mer1[l_int_ligne][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer1[l_int_ligne + 1][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer1[l_int_ligne + 2][l_int_colonne].m_int_bateau == 0)) {
                    //ajout du bateau dans la mer
                    l_enrTab_Mer1[l_int_ligne][l_int_colonne].m_int_bateau = 1;
                    l_enrTab_Mer1[l_int_ligne + 1][l_int_colonne].m_int_bateau = 1;
                    l_enrTab_Mer1[l_int_ligne + 2][l_int_colonne].m_int_bateau = 1;

                    //confirmation que le bateau est place
                    l_bool_bateauxPlaces = 1;
                }
            } while (l_bool_bateauxPlaces == 0);

        }

        //execution fonction placement si bateau horizontal
        else {

            do {
                //determination aleatoire de la premiere case du bateau
                l_int_ligne = rand() % 6;
                l_int_colonne = rand() % 4;

                //Si la case choisie aleatoirement et les 2 suivantes horizontales sont libres, alors on place le bateau
                if ((l_enrTab_Mer1[l_int_ligne][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer1[l_int_ligne][l_int_colonne + 1].m_int_bateau == 0) && (l_enrTab_Mer1[l_int_ligne][l_int_colonne + 2].m_int_bateau == 0)) {
                    //ajout du bateau dans la mer
                    l_enrTab_Mer1[l_int_ligne][l_int_colonne].m_int_bateau = 1;
                    l_enrTab_Mer1[l_int_ligne][l_int_colonne + 1].m_int_bateau = 1;
                    l_enrTab_Mer1[l_int_ligne][l_int_colonne + 2].m_int_bateau = 1;
                    //confirmation que le bateau est place

                    l_bool_bateauxPlaces = 1;
                }
            } while (l_bool_bateauxPlaces == 0);
        }
    }
}


//fonction qui demande une case au joueur et qui la retourne au format TCoord
TCoord demandeJoueur(void) {
    //declarations
    TCoord l_enr_case;

    //demande de saisie utilisateur tant que il n a pas saisi de valeur correcte (ex : A5 / D2 / C4 / ... )
    do {
        printf("Saisir la ligne : \n");
        l_int_coordY = _getch();
        // printf("%i", l_int_coordY);
    } while (int((l_int_coordY) < 97) || (int(l_int_coordY) > 102));

    do {
        printf("Saisir la colonne : \n");
        scanf_s("%i", &l_int_coordX);
    } while ((l_int_coordX < 1) || (l_int_coordX > 6));

    //assignation des valeurs saisies a l_enr case
    //-1 car decalage index
    l_enr_case.m_int_ligne = l_int_coordY - 97;
    l_enr_case.m_int_colonne = l_int_coordX - 1;

    //retourne l_enr_case sous forme de Tcoord
    return(l_enr_case);
}

bool checkCase(TCoord l_enr_essai) {
    if (l_enrTab_Mer1[l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_int_bateau == 1) {
        //printf("Touche\n");
        l_enrTab_Mer1[l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_bool_touche = 1;
        l_int_points++;
        return(0);
    }
    else {
        //printf("Loupe\n");
        return(0);
    }
}

void regles(void) {
    printf("\t\t*********Bienvenue!*********\n\t\t");
    Sleep(500);
    printf("Connaissez vous les regles ? \n");
    Sleep(500);
    //TRANSFORMER EN SWITCH
    printf("Oui = Y \nNon = N\n");
    l_int_regle = _getch();
    if (l_int_regle == 'n') {
        printf("Bah va voir sur google !\n");
    }
    else {
        printf("C'est parti !\n");
    }
    printf("Combien de joueur ? \n");
    Sleep(500);
    //TRANSFORMER EN SWITCH
    printf("1 \n2 \n");
    l_int_regle = _getch();
    if (l_int_regle == '1') {
        printf("Bonne chance ;)\n");
    }
    else {
        printf("Joueur 1, Tu vas placer tes bateaux \n");
    }
    
}

// Test logo 
void logo(void) {
    Sleep(250);
    printf("oooooooooo.                .               o8o  oooo  oooo                 ooooo      ooo                                 oooo            \n");
    printf("`888'   `Y8b             .o8                    `888  `888                 `888b.     `8'                                 `888            \n");
    printf(" 888     888  .oooo.   .o888oo  .oooo.    oooo   888   888   .ooooo.        8 `88b.    8   .oooo.   oooo   oooo  .oooo.    888   .ooooo.  \n");
    printf(" 888oooo888' `P  )88b    888   `P  )88b    888   888   888  d88' `88b       8   `88b.  8  `P  )88b   `88.  .8'  `P  )88b   888  d88' `88b \n");
    printf(" 888    `88b  .oP8888    888    .oP8888    888   888   888  888  88888      8     P888 8   .oP8888    `888        oP8888   888  888ooo888 \n");
    printf(" 888    .88P d8(  888    888 . d8(  888    888   888   888  888    8o       8       `888  d8(  888     `888'    d8(  888   888  888    .o \n");
    printf(" o888bood8P'  `Y888888o   888    Y8888o   o888o o888o o888o `Y8bod8P'      o8o        `8  `Y8888888     `8'     `Y888888o o888o `Y8bod8P' \n");
    printf("");
    printf("                             __/___                           \n");
    printf("                      _____ /______|\n");
    printf("             _______ / _____\_______\_____\n");
    printf("             \              < < <       | \n");
    printf("             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");




    Sleep(1500);
    printf("Chargement [");
        for (iBcl = 0; iBcl < TAILLE; iBcl++) {
        Sleep(TEMPS2);
        printf("|");
        Sleep(TEMPS2);
        printf("|");
        Sleep(TEMPS2);
        printf("|");
        Sleep(TEMPS2);

    }













}

void main(void) {

        keybd_event(VK_MENU, 0x38, 0, 0); //Appuie sur ALT
        keybd_event(VK_RETURN, 0x1c, 0, 0); //Appuie ENTREE
        keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0); // Relache ENTREE
        keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); //Relache ALT
        logo();
        system("CLS");
    //Acceuil et regles
    regles();
    //placement des bateaux
    placeBateau();
    //delai pour affichage avant suppression
    Sleep(1000);
    system("CLS");  
    
    
    do {
        do {

        l_int_joueur = (l_int_cpt % 2) + 1;
        printf("Joueur %i joue\n", l_int_joueur);   
        l_int_cpt++;
        TCoord l_enr_essai = demandeJoueur();
        system("CLS");

        if (l_enrTab_Mer1[l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_int_bateau == 1) {
            printf("Touche\n");
            l_int_tentative++;

            if (l_enrTab_Mer1[l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_int_bateau == 'X')
            {
                printf("Case deja trouve");
                l_int_tentative++;
                l_int_point++;
                afficheMerDebug();

            }

            else {
                l_enrTab_Mer1[l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_int_bateau = 'X';
                l_int_tentative++;
                l_int_point++;
                afficheMerDebug();

            }
        }
        else {
            printf("Loupe\n");
            l_int_tentative++;

        }

        //Debug
        printf("Coord ligne = %i \n", l_enr_essai.m_int_ligne);
        printf("Coord colonne = %i \n", l_enr_essai.m_int_colonne);
        printf("Point : %i \n", l_int_point);
    } while (TRUE);


    } while (l_int_point != 6);

    printf("******** Bravo vous avez gagner *********\n\t");
    printf("Vous avez utilise %i tentatives ! \n", l_int_tentative);
}
