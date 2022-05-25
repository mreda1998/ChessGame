#pragma once
#include "finDePartieAlexandreJean-Macon.h"
#include "echiquier.h"
#include "roi.h"
#include "tour.h"
#include "reine.h"
#include "fou.h"

namespace LogiqueJeu 
{
	FinDePartieAlexandreJeanMacon FinDePartieAlexandreJeanMacon::instance_ = FinDePartieAlexandreJeanMacon();

	FinDePartieAlexandreJeanMacon::FinDePartieAlexandreJeanMacon() : StrategiePlacementPieces(FinDePartieAlexandreJeanMacon::nomStrategie_) {
		description_ = "Fin de partie du match final entre\nMathieu Alexandre avec les pieces\nblanches et Jean Jean-Maçon avec les\npieces noirs en 1927 lors du Grand\nTournoi de la Jean-Maçonnerie\nqui se termina en la victoire\nd'Alexandre et de son ascension au\ntitre de Champion du monde d'echecs.\nTour au blancs. Que le meilleur gagne!";
	}

	void FinDePartieAlexandreJeanMacon::placerPieces()
	{
		Echiquier& echiquier = Echiquier::echiquier();
		echiquier.nettoyer();
		echiquier.definirTour(Couleur::Blanc);

		echiquier.ajouterPiece(make_unique<Roi>(Roi(Couleur::Noir)), { 7, 7 });
		echiquier.ajouterPiece(make_unique<Reine>(Reine(Couleur::Noir)), { 6, 6 });
		echiquier.ajouterPiece(make_unique<Tour>(Tour(Couleur::Noir)), { 1, 8 });
		echiquier.ajouterPiece(make_unique<Fou>(Fou(Couleur::Noir)), { 3, 6 });

		echiquier.ajouterPiece(make_unique<Roi>(Roi(Couleur::Blanc)), { 7, 1 });
		echiquier.ajouterPiece(make_unique<Reine>(Reine(Couleur::Blanc)), { 3, 1 });
		echiquier.ajouterPiece(make_unique<Tour>(Tour(Couleur::Blanc)), { 5, 2 });
		echiquier.ajouterPiece(make_unique<Fou>(Fou(Couleur::Blanc)), { 6, 3 });
	}
}