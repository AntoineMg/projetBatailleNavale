#include "PrjInfo2022.h"
#define LIGNES 6
#define COLONNES 6
#define N_BATEAUX 2
#define COLOR_1 15
#define COLOR_2 3


//Declarations variables globales
int echecs = 0; //var debug
int iBcl; // compteur de boucle
int iBcl1; // compteur de boucle n2
int iBcl2; // compteur de boucle n3
int l_int_ligne = 0; // 
int l_int_colonne = 0;
int l_int_points = 0;
bool l_bool_bateauxPlaces = 0;
bool l_bool_win = 0;
int l_int_choix[2];
int l_int_coordX;
int l_int_coordY;
int l_int_regle;
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
		printf("%c  ",iBcl1+65);
		Color(COLOR_2);
		//boucle for pour afficher les colonnes
		for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
			printf("%i ", l_enrTab_Mer1[iBcl1][iBcl2].m_bool_touche);
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
			
			do{
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
		scanf_s("%c", &l_int_coordY);
		printf("%i", l_int_coordY);
	} while (int((l_int_coordY) < 97) || (int(l_int_coordY) > 102));

	do {
		printf("Saisir la colonne : \n");
		scanf_s("%i", &l_int_coordX);
	} while ((l_int_coordX < 1) || (l_int_coordX > 6));

	//assignation des valeurs saisies a l_enr case
	//-1 car decalage index
	l_enr_case.m_int_ligne = l_int_coordY - 97;
	l_enr_case.m_int_colonne = l_int_coordX-1;

	//retourne l_enr_case sous forme de Tcoord
	return(l_enr_case);
}

bool checkCase(TCoord l_enr_essai) {
	if (l_enrTab_Mer1[l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_int_bateau == 1) {
		//printf("Touche\n");
		l_enrTab_Mer1[l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_bool_touche = 1;
		l_int_points++;
		return(1);
	}
	else {
		//printf("Loupe\n");
		return(0);
	}
}

void regles(void) {
	printf("*********Bienvenue!*********\n");
	Sleep(500);
	printf("Connaissez vous les regles ? \n");
	Sleep(500);
	//TRANSFORMER EN SWITCH
	printf("Oui = O \nNon = N\n");
	l_int_regle = _getch();

	switch (l_int_regles) {
		case 'n':
		case 'N':
			printf("Bah va voir sur google !\n");
		case 'y':
		case 'Y':
		case 'o':
		case 'O':
			printf("C'est parti !\n");
		default :
			printf("")


	}
	if (l_int_regle == 'n') {
		
	}
	else {
		
	}
}

void main(void) {

	//Acceuil et regles
	regles();
	//placement des bateaux
	placeBateau();
	//delai pour affichage avant suppression
	Sleep(3000);
	system("CLS");

	//afficheMer();

	//Tant que le joueur n'a pas gagne le jeu continue
	while (l_int_points < N_BATEAUX*3) {
		TCoord l_enr_saisie = demandeJoueur();
		if (checkCase(l_enr_saisie)) {
			system("CLS");
			afficheMer();
			printf("Touche !\n");
			printf("%i points");
		}

		else {
			system("CLS");
			afficheMer();
			printf("Rate !\n");
			printf("%i points");
		}

		
	}


}
