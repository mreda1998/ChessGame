#pragma once
#include "finDePartieRhanmouniNguyen.h"
#include "echiquier.h"
#include "roi.h"
#include "fou.h"
#include "reine.h"
#include "tour.h"

namespace LogiqueJeu
{
	FinDePartieRhanmouniNguyen FinDePartieRhanmouniNguyen::instance_ = FinDePartieRhanmouniNguyen();

	FinDePartieRhanmouniNguyen::FinDePartieRhanmouniNguyen() : StrategiePlacementPieces(FinDePartieRhanmouniNguyen::nomStrategie_) {
		description_ = "Fin de partie de la premiere partie entre\nReda Rhanmouni avec les pieces\nblanches et Huy Viet Nguyen avec les\npieces noires lors du PolyTour qui s'est\nfinie en un match nul. Tour aux blancs.\nTrouverez-vous le mouvement décisif?";
	}

	void FinDePartieRhanmouniNguyen::placerPieces() {
		LogiqueJeu::Echiquier& echiquier = LogiqueJeu::Echiquier::echiquier();
		echiquier.nettoyer();
		echiquier.definirTour(Couleur::Blanc);

		echiquier.ajouterPiece(make_unique<Roi>(Roi(Couleur::Noir)), { 5, 6 });
		echiquier.ajouterPiece(make_unique<Fou>(Fou(Couleur::Noir)), { 5, 7 });
		echiquier.ajouterPiece(make_unique<Reine>(Reine(Couleur::Noir)), { 4, 5 });

		echiquier.ajouterPiece(make_unique<Roi>(Roi(Couleur::Blanc)), { 7, 2 });
		echiquier.ajouterPiece(make_unique<Fou>(Fou(Couleur::Blanc)), { 5, 1 });
		echiquier.ajouterPiece(make_unique<Tour>(Tour(Couleur::Blanc)), { 6, 3 });
		echiquier.ajouterPiece(make_unique<Fou>(Fou(Couleur::Blanc)), { 5, 2 });
	}
}