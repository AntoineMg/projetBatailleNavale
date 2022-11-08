#include "PrjInfo2022.h"
#include "Fonctions.cpp"
#define LIGNES 6
#define COLONNES 6
#define N_BATEAUX 2


//Declarations variables globales
int l_int_check = 0;
int iBcl;
int iBcl1;
int iBcl2;
int l_int_ligne = 0;
int l_int_colonne = 0;
bool l_bool_bateauxPlaces = 0;
char l_char_choix[2];
int l_int_coordX = 0;
int l_int_coordY = 0;

//l_bool_direction 0 pour vertical et 1 pour horizontal
bool l_bool_direction;
TCase l_enrTab_Mer1[LIGNES][COLONNES];

//fonction pour afficher une mer
void afficheMer(void) {
	for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
		for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
			printf("%i ", l_enrTab_Mer1[iBcl1][iBcl2].m_int_bateau);
		}
		printf("\n");
	}
}

//fonction pour placer les bateaux
void placeBateau(void) {

	srand(time(NULL));

	for (iBcl1 = 0; iBcl1 < N_BATEAUX; iBcl1++) {
		
		l_bool_direction = rand() % 2;

		//execution fonction placement

		if (l_bool_direction == 0) {
			
			do {
				//determination aleatoire de la premiere case du bateau
				l_int_ligne = rand() % 4;
				l_int_colonne = rand() % 6;

				//Si la case choisie aleatoirement et les 2 suivantes verticales sont libres, alors on place le bateau
				if ((l_enrTab_Mer1[l_int_ligne][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer1[l_int_ligne + 1][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer1[l_int_ligne + 2][l_int_colonne].m_int_bateau == 0)) {
					//ajout du bateau dans le tableau
					l_enrTab_Mer1[l_int_ligne][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer1[l_int_ligne + 1][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer1[l_int_ligne + 2][l_int_colonne].m_int_bateau = 1;
					l_bool_bateauxPlaces = 1;
				}
			} while (l_bool_bateauxPlaces == 0);
				
		}

		else {
			
			do{
				//determination aleatoire de la premiere case du bateau
				l_int_ligne = rand() % 6;
				l_int_colonne = rand() % 4;

				//Si la case choisie aleatoirement et les 2 suivantes horizontales sont libres, alors on place le bateau
				if ((l_enrTab_Mer1[l_int_ligne][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer1[l_int_ligne][l_int_colonne + 1].m_int_bateau == 0) && (l_enrTab_Mer1[l_int_ligne][l_int_colonne + 2].m_int_bateau == 0)) {
					//ajout du bateau dans le tableau
					l_enrTab_Mer1[l_int_ligne][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer1[l_int_ligne][l_int_colonne + 1].m_int_bateau = 1;
					l_enrTab_Mer1[l_int_ligne][l_int_colonne + 2].m_int_bateau = 1;
					l_bool_bateauxPlaces = 1;
				}
			} while (l_bool_bateauxPlaces == 0);
		}
	}
}

void main(void) {
	//Declarations variables main


	//initialisation de toutes les cases a 0
	for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
		for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
			l_enrTab_Mer1[iBcl1][iBcl2].m_int_bateau = 0;
			l_enrTab_Mer1[iBcl1][iBcl2].m_bool_touche = 0;
		}
	}
	placeBateau();
	afficheMer();

	printf("Saisir les coordonnees : \n");
	l_int_coordY = getchar();
	scanf("%i", &l_int_coordX);
	l_int_coordY = l_int_coordY - 65;
	l_int_coordX = l_int_coordX +1;

	if (l_enrTab_Mer1[l_int_coordY][l_int_coordX].m_int_bateau == 1) {
		printf("Touche\n");
	}
	else {
		printf("Loupe\n");
		
	}
	printf("Coord X = %i", l_int_coordX);
	printf("Coord Y = %i", l_int_coordY);
}
	
	
	





