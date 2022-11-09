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
int l_int_points[] = { 0,0 }; //Compteur de points par joueur
bool l_bool_bateauxPlaces = 0;
bool l_bool_win = 0;
int l_int_choix[2];
int l_int_coordX;
int l_int_coordY;
int l_int_nbJoueurs;
int l_char_regles;
int l_int_tentatives;
//Variables Temps
int l_int_timeDebut;
int l_int_timeFin;
int l_int_time;
int l_int_minutes;
int l_int_secondes;
/////
int l_int_tour;
int l_int_player;
bool l_boolTab_Coules[] = { 0,0 };
int l_int_coules[] = { 0,0 };
int l_int_coulesAns[] = { 0,0 };
bool l_bool_direction; //l_bool_direction 0 pour vertical et 1 pour horizontal
TCase l_enrTab_Mer[2][LIGNES][COLONNES];
TBateau l_enr_Bateaux[N_BATEAUX];
//mer1D = version affichee a l'utilisateur

//fonction qui initialise toutes les cases de la mer a 0
void initCases(int f_int_mer) {
	//initialisation de toutes les cases a 0
	for (iBcl1 = 0; iBcl1 < LIGNES; iBcl1++) {
		for (iBcl2 = 0; iBcl2 < COLONNES; iBcl2++) {
			l_enrTab_Mer[f_int_mer][iBcl1][iBcl2].m_int_bateau = 0;
			l_enrTab_Mer[f_int_mer][iBcl1][iBcl2].m_bool_touche = 0;
		}
	}
}


//DEBUG
void afficheMerDebug(int f_int_player) {
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
			printf("%i ", l_enrTab_Mer[f_int_player][iBcl1][iBcl2].m_int_bateau);
		}
		//retour a la ligne pour rendre le resultat plus clean
		printf("\n");
		Color(COLOR_1);
	}
}

//fonction pour afficher une mer
void afficheMer(int f_int_mer) {
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
			printf("%i ", l_enrTab_Mer[f_int_mer][iBcl1][iBcl2].m_bool_touche);
		}
		//retour a la ligne pour rendre le resultat plus clean
		printf("\n");
		Color(COLOR_1);
	}
}

//fonction pour placer les bateaux
void placeBateau(int f_int_mer) {

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
				if ((l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne + 1][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne + 2][l_int_colonne].m_int_bateau == 0)) {
					//ajout du bateau dans la mer
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne + 1][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne + 2][l_int_colonne].m_int_bateau = 1;
					//stockage du bateau
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne = l_int_ligne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne = l_int_ligne+1;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne = l_int_ligne+2;
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
				if ((l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 1].m_int_bateau == 0) && (l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 2].m_int_bateau == 0)) {
					//ajout du bateau dans la mer
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 1].m_int_bateau = 1;
					l_enrTab_Mer[f_int_mer][l_int_ligne][l_int_colonne + 2].m_int_bateau = 1;
					//Stockage du bateau
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne = l_int_colonne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne = l_int_ligne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne = l_int_colonne+1;
					l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne = l_int_ligne;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne = l_int_colonne+2;
					l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne = l_int_ligne;
					//confirmation que le bateau est place
					l_bool_bateauxPlaces = 1;
				}
			} while (l_bool_bateauxPlaces == 0);
		}
	}
}

//fonctionne parfsois ex pour E456 et pour CDE4 et pour A234
void checkCoule(int f_int_mer) {
	l_int_coules[f_int_mer] = 0;
	for (iBcl1 = 0; iBcl1 < N_BATEAUX; iBcl1++) {
		if ((l_enrTab_Mer[f_int_mer][l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_ligne][l_enr_Bateaux[iBcl1].m_TCoord_Case1.m_int_colonne].m_bool_touche == 1) && (l_enrTab_Mer[f_int_mer][l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_ligne][l_enr_Bateaux[iBcl1].m_TCoord_Case2.m_int_colonne].m_bool_touche == 1) && (l_enrTab_Mer[f_int_mer][l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_ligne][l_enr_Bateaux[iBcl1].m_TCoord_Case3.m_int_colonne].m_bool_touche == 1)) {
			l_boolTab_Coules[iBcl] = 1;
		}
	}
	for (iBcl2 = 0; iBcl2 < N_BATEAUX; iBcl2++) {
		if (l_boolTab_Coules[iBcl2] == 1) {
			l_int_coules[f_int_mer]++;
		}
	}
}


//fonction qui demande une case au joueur et qui la retourne au format TCoord
TCoord demandeJoueur() {
	//declarations
	TCoord l_enr_case;

	//demande de saisie utilisateur tant que il n a pas saisi de valeur correcte (ex : A5 / D2 / C4 / ... )
	do {
		printf("Saisir la ligne : \n");
		l_int_coordY = _getch();
		//scanf_s("%c", &l_int_coordY);
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

bool checkCase(TCoord l_enr_essai,int f_int_mer) {
	if (l_enrTab_Mer[f_int_mer][l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_int_bateau == 1) {
		//printf("Touche\n");
		l_enrTab_Mer[f_int_mer][l_enr_essai.m_int_ligne][l_enr_essai.m_int_colonne].m_bool_touche = 1;
		l_int_points[f_int_mer]+=1;
		l_int_tentatives+=1;
		return(1);
	}
	else {
		//printf("Loupe\n");
		l_int_tentatives++;
		return(0);
	}
}

void regles(void) {
	printf("********* Bienvenue! *********\n");
	Sleep(500);
	printf("Connaissez vous les regles ? \n");
	Sleep(500);
	printf("Oui = o \nNon = n\n\n");
	l_char_regles = _getch();
	if (l_char_regles = 'n') {
		printf("Bah voir sur google\n");
	}
	else {
		printf("Super, alors allons-y !\n");
	}
}

int nombreJoueurs(void) {
	printf("Combien de joueurs ? \n");
	//TRANSFORMER EN SWITCH
	scanf_s("%i", &l_int_nbJoueurs);
	return(l_int_nbJoueurs);
}

void playSolo(void) {
	l_int_player = 0;
	//placement des bateaux
	placeBateau(l_int_player);
	//delai pour affichage avant suppression
	Sleep(3000);
	system("CLS");

	afficheMerDebug(l_int_player);
	Sleep(3000);

	//Debut du chrono
	l_int_timeDebut = GetTickCount();

	//Tant que le joueur n'a pas gagne le jeu continue
	while (l_int_points[l_int_player] < N_BATEAUX * 3) {
		TCoord l_enr_saisie = demandeJoueur();
		//Si le bateau est touche on affiche touche ou coule
		if (checkCase(l_enr_saisie, l_int_player)) {
			//si le bateau est coule on affiche coule
			checkCoule(1);
			if (l_int_coules[l_int_player] > l_int_coulesAns[l_int_player]) {
				l_int_coulesAns[l_int_player] = l_int_coules[l_int_player];
				system("CLS");
				afficheMer(l_int_player);
				printf("Coule !\n");
				printf("%i points\n", l_int_points[l_int_player]);
			}

			//Si non on affiche seulement touche
			else {
				system("CLS");
				afficheMer(l_int_player);
				printf("Touche !\n");
				printf("%i points\n", l_int_points[l_int_player]);
			}
		}

		//Si non on affiche Rate
		else {
			system("CLS");
			afficheMer(l_int_player);
			printf("Rate !\n");
			printf("%i points\n", l_int_points[l_int_player]);
		}


	}
}

void playDuo(void) {
	//placement des bateaux des deux joueurs
	placeBateau(1);
	placeBateau(2);

	//Debut du chrono
	l_int_timeDebut = GetTickCount();

	//
	while (l_bool_win == 0) {
		//DETERMINATION DU JOUEUR A QUI CEST LE TOUR
		//si le tour est pair, c'est au joueur 1 de jouer 
		if (l_int_tour % 2 == 0) {
			l_int_player = 1;
		}
		//Si non c'est au tour du joueur 2
		else {
			l_int_player = 2;
		}

		//Annonce du joueur qui doit jouer
		printf("C'est au joueur %i de jouer\n",l_int_player);
		//Demande de saisie
		TCoord l_enr_saisie = demandeJoueur();

		if (checkCase(l_enr_saisie,l_int_player)) {
			//si le bateau est coule on affiche coule
			checkCoule(l_int_player);
			if (l_int_coules > l_int_coulesAns) {
				l_int_coulesAns[l_int_player] = l_int_coules[l_int_player];
				system("CLS");
				afficheMer(1);
				printf("Coule !\n");
				printf("%i points\n", l_int_points[l_int_player]);
			}

			//Si non on affiche seulement touche
			else {
				system("CLS");
				afficheMer(l_int_player);
				printf("Touche !\n");
				printf("%i points\n", l_int_points[l_int_player]);
			}
		}

		//Si non on affiche Rate
		else {
			system("CLS");
			afficheMer(l_int_player);
			printf("Rate !\n");
			printf("%i points\n", l_int_points[l_int_player]);
		}

		l_int_tour++;

		
	}

}

void main(void) {

	//Acceuil et regles
	regles();
	switch (nombreJoueurs()) {
		case 1:
			playSolo();
		case 2:
			playDuo();
		default:
			printf("Tant pis, au revoir !!!");
	}
	


	//Obtention de la duree de la partie
	l_int_timeFin = GetTickCount();
	l_int_time = l_int_timeFin - l_int_timeDebut;
	l_int_minutes = l_int_time / 60000; //60*1000
	l_int_secondes = (l_int_time - (60000 * l_int_minutes)) / 1000;

	//affichage ecran victoire
	printf("Gagne\n");
	//nb tentatives
	printf("Vous avez effectue %i tentatives en une duree de %i minutes et %i secondes", l_int_tentatives, l_int_minutes, l_int_secondes);

}
