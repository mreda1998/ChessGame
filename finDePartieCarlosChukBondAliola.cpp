#pragma once
#include "finDePartieCarlosChukBondAliola.h"
#include "echiquier.h"
#include "roi.h"
#include "tour.h"
#include "fou.h"

namespace LogiqueJeu 
{
	FinDePartieCarlosChukBondAliola FinDePartieCarlosChukBondAliola::instance_ = FinDePartieCarlosChukBondAliola();

	FinDePartieCarlosChukBondAliola::FinDePartieCarlosChukBondAliola() : StrategiePlacementPieces(FinDePartieCarlosChukBondAliola::nomStrategie_) {
		description_ = "Fin de partie du match final entre\nCarlos, le Banquier, avec les pièces\nnoires et JamesAmwee\nChukBondAliola, plus connu sous le\nnom de James Bond, avec les pièces\nblanches lors du Casino Royal en\n2006. Heureusement, les enjeux sont\nbeaucoup moins importants que\nla partie réelle.";
	}

	void FinDePartieCarlosChukBondAliola::placerPieces()
	{
		LogiqueJeu::Echiquier& echiquier = LogiqueJeu::Echiquier::echiquier();
		echiquier.nettoyer();
		echiquier.definirTour(Couleur::Blanc);

		echiquier.ajouterPiece(make_unique<Roi>(Roi(Couleur::Noir)), { 5, 7 });
		echiquier.ajouterPiece(make_unique<Fou>(Fou(Couleur::Noir)), { 4, 7 });
		echiquier.ajouterPiece(make_unique<Tour>(Tour(Couleur::Noir)), { 3, 7 });

		echiquier.ajouterPiece(make_unique<Roi>(Roi(Couleur::Blanc)), { 4, 2 });
		echiquier.ajouterPiece(make_unique<Tour>(Tour(Couleur::Blanc)), { 3, 1 });
		echiquier.ajouterPiece(make_unique<Fou>(Fou(Couleur::Blanc)), { 4, 1 });
	}
}