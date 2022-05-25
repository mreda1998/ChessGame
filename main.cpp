/* Projet : Jeu d'échec réduit
 * Fichier : main.cpp
 * Auteurs : Reda Rhanmouni,	2087548,
 *			 Huy Viet Nguyen,	2136378
 * Date : 6 mai 2022
 * Icônes des pièces issues de : Cburnett. Wikimedia Commons. Disponible : https://commons.wikimedia.org/wiki/File:Chess_Pieces_Sprite.sv
 */

#include "roi.h"
#include "reine.h"
#include "tour.h"
#include "fou.h"

#include "interfaceGraphique.h"
#include "echiquier.h"

#include <iostream>
#include <QApplication>
#include <QPushButton>

#include <gtest/gtest.h>

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.

	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
#endif
//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	QApplication jeu(argc, argv);
	
	Affichage::InterfaceGraphique interface(nullptr);
	interface.show();
	
	return jeu.exec();
}

//Tests de création et ajout de pieces
TEST(CreationAjoutPieces, AjoutReineNoir) {
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Noir)), { 4, 4 });
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Reine*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 4 }).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 4 })->obtenirCouleur() == Couleur::Noir);
}

TEST(CreationAjoutPieces, AjoutRoiNoir) {
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Noir)), { 2, 4 });
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 2, 4 }).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 2, 4 })->obtenirCouleur() == Couleur::Noir);
}

TEST(CreationAjoutPieces, AjoutTourNoir) {
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc)), { 3, 4 });
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 4 }).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 4 })->obtenirCouleur() == Couleur::Blanc);
}

TEST(CreationAjoutPieces, AjoutFouNoir) {
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), { 2, 4 });
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 2, 4 }).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 2, 4 })->obtenirCouleur() == Couleur::Blanc);
}

TEST(CreationAjoutPieces, AjoutReineBlanc) {
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Blanc)), { 4, 4 });
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Reine*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 4 }).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 4 })->obtenirCouleur() == Couleur::Blanc);
}

TEST(CreationAjoutPieces, AjoutRoiBlanc) {
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), { 2, 4 });
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 2, 4 }).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 2, 4 })->obtenirCouleur() == Couleur::Blanc);
}

TEST(CreationAjoutPieces, AjoutTouBlanc) {
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc)), { 3, 4 });
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 4 }).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 4 })->obtenirCouleur() == Couleur::Blanc);
}

TEST(CreationAjoutPieces, AjoutFouBlanc) {
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), { 2, 4 });
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 2, 4 }).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 2, 4 })->obtenirCouleur() == Couleur::Blanc);
}

//Tests de déplacements sans captures
TEST(DeplacementSansCapture, Reine) {
	pair<int, int> positionInitiale = { 4, 4 };
	pair<int, int> nouvellePosition = { 6, 6 };

	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Blanc)), positionInitiale);
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionInitiale, nouvellePosition);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Reine*>(LogiqueJeu::Echiquier::echiquier().prendrePiece(nouvellePosition).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece(positionInitiale) == nullptr);
}

TEST(DeplacementSansCapture, Roi) {
	pair<int, int> positionInitiale = { 4, 4 };
	pair<int, int> nouvellePosition = { 3, 4 };

	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), positionInitiale);
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionInitiale, nouvellePosition);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece(nouvellePosition).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece(positionInitiale) == nullptr);
}

TEST(DeplacementSansCapture, Tour) {
	pair<int, int> positionInitiale = { 4, 8 };
	pair<int, int> nouvellePosition = { 8, 8 };

	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc)), positionInitiale);
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionInitiale, nouvellePosition);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece(nouvellePosition).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece(positionInitiale) == nullptr);
}

TEST(DeplacementSansCapture, Fou) {
	pair<int, int> positionInitiale = { 1, 1 };
	pair<int, int> nouvellePosition = { 8, 8 };

	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), positionInitiale);
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionInitiale, nouvellePosition);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece(nouvellePosition).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece(positionInitiale) == nullptr);
}

//Tests déplacements impossibles
TEST(DeplacementImpossible, Obstacle) {
	pair<int, int> positionInitiale = { 1, 1 };
	pair<int, int> nouvellePosition = { 8, 8 };

	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), positionInitiale);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc)), {3, 3});
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionInitiale, nouvellePosition);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece(positionInitiale).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece(nouvellePosition) == nullptr);
}

TEST(DeplacementImpossible, MouvementPieceNonLegale) {
	pair<int, int> positionInitiale = { 1, 1 };
	pair<int, int> nouvellePosition = { 2, 3 };

	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), positionInitiale);
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionInitiale, nouvellePosition);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece(positionInitiale).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece(nouvellePosition) == nullptr);
}

TEST(DeplacementImpossible, MiseEnEchec) {
	pair<int, int> positionInitiale = { 1, 1 };
	pair<int, int> nouvellePosition = { 2, 2 };

	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), { 1, 2 });
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Noir)), { 1, 8 });
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), positionInitiale);
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionInitiale, nouvellePosition);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece(positionInitiale).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece(nouvellePosition) == nullptr);
}

TEST(DeplacementImpossible, ExterieurEchiquier) {
	pair<int, int> positionInitiale = { 1, 1 };
	pair<int, int> nouvellePosition = { 1, 9 };

	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), positionInitiale);
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionInitiale, nouvellePosition);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece(positionInitiale).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece(nouvellePosition) == nullptr);
}

//Tests échecs
TEST(Echecs, DejaEnEchec) {
	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), { 1, 1 });
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Noir)), { 2, 1 });

	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().roiEnEchec());
}

TEST(Echecs, MiseEnEchec) {
	pair<int, int> positionInitiale = { 3, 2 };
	pair<int, int> nouvellePosition = { 1, 2 };

	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), { 1, 1 });
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Noir)), { positionInitiale });
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().roiEnEchec() == false);
	
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Noir);
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionInitiale, nouvellePosition);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().roiEnEchec());
}

//Test de captures
TEST(CapturePieces, Capture) {
	pair<int, int> positionInitiale = { 3, 2 };
	pair<int, int> nouvellePosition = { 1, 2 };

	LogiqueJeu::Echiquier::echiquier().nettoyer();
	LogiqueJeu::Echiquier::echiquier().definirTour(Couleur::Blanc);
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc)), { positionInitiale});
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Noir)), { nouvellePosition });
	LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionInitiale, nouvellePosition);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece(nouvellePosition).get()) != nullptr);
	EXPECT_TRUE(LogiqueJeu::Echiquier::echiquier().prendrePiece(positionInitiale) == nullptr);
}

//Tests de sélection de placement de pièces
TEST(PlacementPieces, RhanmouniNguyen) {
	LogiqueJeu::Echiquier::echiquier().selectionnerPlacementPieces("FinDePartieRhanmouniNguyen");
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 5, 6 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 5, 7 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Reine*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 5 }).get()) != nullptr);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 7, 2 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 5, 1 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 6, 3 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 5, 2 }).get()) != nullptr);
}

TEST(PlacementPieces, AlexandreJean) {
	LogiqueJeu::Echiquier::echiquier().selectionnerPlacementPieces("FinDePartieAlexandreJean-Macon");

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 7, 7 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Reine*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 6, 6 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 1, 8 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 6 }).get()) != nullptr);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 7, 1 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Reine*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 1 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 5, 2 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 6, 3 }).get()) != nullptr);
}

TEST(PlacementPieces, CarlosBond) {
	LogiqueJeu::Echiquier::echiquier().selectionnerPlacementPieces("FinDePartieCarlosChukBondAliola");

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 5, 7 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 7 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 7 }).get()) != nullptr);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 2 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 1 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 1 }).get()) != nullptr);
}

TEST(PlacementPieces, GrandeMurailleDesTours) {
	LogiqueJeu::Echiquier::echiquier().selectionnerPlacementPieces("GrandeMurailleDesTours");

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 1, 8 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Reine*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 4 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Reine*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 5 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 1, 7 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 5, 4 }).get()) != nullptr);
	
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 1, 1 }).get()) != nullptr);

	for (int i = 1; i <= 8; i++) {
		EXPECT_TRUE(dynamic_cast<LogiqueJeu::Tour*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ i, 2 }).get()) != nullptr);
	}
}

TEST(PlacementPieces, FolieDeMasse) {
	LogiqueJeu::Echiquier::echiquier().selectionnerPlacementPieces("FolieDeMasse");

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 5, 8 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 4 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 2 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 8, 1 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 7 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 5, 7 }).get()) != nullptr);

	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Roi*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 7, 1 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 5 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 1, 1 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 6, 3 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 3, 7 }).get()) != nullptr);
	EXPECT_TRUE(dynamic_cast<LogiqueJeu::Fou*>(LogiqueJeu::Echiquier::echiquier().prendrePiece({ 4, 3 }).get()) != nullptr);
}
