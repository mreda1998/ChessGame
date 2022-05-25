#pragma once
#include "folieDeMasse.h"
#include "echiquier.h"
#include "roi.h"
#include "reine.h"
#include "tour.h"
#include "fou.h"

namespace LogiqueJeu
{
	FolieDeMasse FolieDeMasse::instance_ = FolieDeMasse();

	FolieDeMasse::FolieDeMasse() : StrategiePlacementPieces(FolieDeMasse::nomStrategie_) {
		description_ = "Boujour agent, ici Qt. C_Thanos, dans\nsa folie, a transformé toute les\npieces de l'échiquier en fous.\nLes Blancs doivent gagner pour sauver\nle Multiverse. Bonne chance.";
	}

	void FolieDeMasse::placerPieces()
	{
		LogiqueJeu::Echiquier& echiquier = LogiqueJeu::Echiquier::echiquier();
		echiquier.nettoyer();
		echiquier.definirTour(Couleur::Blanc);

		/*---------------------------------------Pieces noirs-------------------------------------*/
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Noir)), { 5, 8 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Noir)), { 4, 4 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Noir)), { 3, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Noir)), { 8, 1 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Noir)), { 4, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Noir)), { 5, 7 });

		/*---------------------------------------Pieces blanches-------------------------------------*/
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), { 7, 1 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), { 4, 5 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), { 1, 1 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), { 6, 3 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), { 3, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), { 4, 3 });
	}
}
