#include "echiquier.h"
#include "roi.h"
#include <iostream>

int calculerDirection(int valeurInitiale, int nouvelleValeur);

namespace LogiqueJeu 
{
	Couleur Echiquier::tourDeJeu_ = Couleur::Blanc;

	Echiquier& Echiquier::echiquier() {
		static Echiquier echiquier;
		return echiquier;
	}

	PointeurPiece& Echiquier::prendrePiece(pair<int, int> position) {
		return grille_[position];
	}

	void Echiquier::ajouterPiece(PointeurPiece piece, pair<int, int> position) {
		grille_[position] = move(piece);
	}

	void Echiquier::deplacerPiece(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) 
	{
		if (tourDeJeu_ == grille_[positionInitiale]->obtenirCouleur())
		{
			if (estDeplacementPossible(positionInitiale, nouvellePosition))
			{
				if (grille_[nouvellePosition] == nullptr)
				{
					grille_[nouvellePosition] = move(grille_[positionInitiale]);
					if (roiEnEchec()) {
						grille_[positionInitiale] = move(grille_[nouvellePosition]);
					}

					else {
						tourDeJeu_ = (tourDeJeu_ == Couleur::Blanc) ? Couleur::Noir : Couleur::Blanc;
					}
				}

				else
				{
					if (grille_[nouvellePosition]->couleur_ != tourDeJeu_) 
					{
						caseTemporaire_ = move(grille_[nouvellePosition]);
						grille_[nouvellePosition] = move(grille_[positionInitiale]);
						if (roiEnEchec()) {
							grille_[positionInitiale] = move(grille_[nouvellePosition]);
							grille_[nouvellePosition] = move(caseTemporaire_);
						}

						else {
							tourDeJeu_ = (tourDeJeu_ == Couleur::Blanc) ? Couleur::Noir : Couleur::Blanc;
						}
					}
				}
			}
		}
	}

	bool Echiquier::roiEnEchec(Couleur couleuRoi) 
	{
		for (auto& element : grille_) 
		{
			if (dynamic_cast<Roi*>(element.second.get()) != nullptr) 
			{
				if (element.second.get()->couleur_ == couleuRoi) 
				{
					for (auto& autreElement : grille_) {
						if (autreElement.second != nullptr) {
							if (autreElement.second->couleur_ != tourDeJeu_) {
								if (estDeplacementPossible(autreElement.first, element.first))
									return true;
							}
						}
					}
				}
			}
		}

		return false;
	}

	void Echiquier::selectionnerPlacementPieces(const string nomPlacement) {
		registrePlacementsDePieces_[nomPlacement]->placerPieces();
	}

	const StrategiePlacementPieces* Echiquier::obtenirStrategie(const string nomPlacement) {
		return registrePlacementsDePieces_[nomPlacement];
	}

	IterateurGrilleEchiquier Echiquier::begin() {
		return grille_.begin();
	}

	IterateurGrilleEchiquier Echiquier::end() {
		return grille_.end();
	}

	bool Echiquier::verifierObstacle(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition)
	{
		const int directionHorizontale = calculerDirection(positionInitiale.first, nouvellePosition.first);
		const int directionVerticale = calculerDirection(positionInitiale.second, nouvellePosition.second);
		int x = positionInitiale.first;
		int y = positionInitiale.second;

		while (true) {
			x += directionHorizontale;
			y += directionVerticale;

			if (nouvellePosition == pair<int, int>{x, y})
				break;

			else if (grille_[{ x, y }] != nullptr)
				return true;
		}

		return false;
	}

	bool Echiquier::estDeplacementPossible(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition)
	{
		if (1 <= nouvellePosition.second && nouvellePosition.second <= 8)
		{
			if (1 <= nouvellePosition.first && nouvellePosition.first <= 8)
			{
				if (grille_[positionInitiale]->estMouvementPossible(positionInitiale, nouvellePosition))
				{
					if (!verifierObstacle(positionInitiale, nouvellePosition))
					{
						return true;
					}
				}
			}
		}

		return false;
	}

	void Echiquier::enregistrerPlacementDePieces(string nomPlacementDePieces, StrategiePlacementPieces* strategie) {
		registrePlacementsDePieces_[nomPlacementDePieces] = strategie;
	}
	
	
}

extern int calculerDirection(int valeurInitiale, int nouvelleValeur) 
{
	const int variation = nouvelleValeur - valeurInitiale;

	return (variation == 0) ? 0 : variation / abs(variation);
}
