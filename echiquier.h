#pragma once
#include <utility>
#include <map>
#include <memory>

#include "piece.h"
#include "strategiePlacementPieces.h"

namespace LogiqueJeu 
{
	using PointeurPiece = std::unique_ptr<LogiqueJeu::Piece>;
	using GrilleEchiquier = std::map<std::pair<int, int>, PointeurPiece>;
	using IterateurGrilleEchiquier = GrilleEchiquier::iterator;

	class Echiquier
	{
	public:
		static Echiquier& echiquier();

		PointeurPiece& prendrePiece(pair<int, int> position);
		void ajouterPiece(PointeurPiece piece, pair<int, int> position);
		void deplacerPiece(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition);

		void selectionnerPlacementPieces(const string nomPlacement);
		const StrategiePlacementPieces* obtenirStrategie(const string nomPlacement);
		void nettoyer() noexcept { grille_.clear(); };

		void definirTour(Couleur couleur) noexcept { tourDeJeu_ = couleur; }
		const Couleur obtenirTourDeJeu() noexcept { return tourDeJeu_; }
		bool roiEnEchec(Couleur couleurRoi = tourDeJeu_);
		
		IterateurGrilleEchiquier begin();
		IterateurGrilleEchiquier end();
		
	private:
		Echiquier() = default;
		
		bool verifierObstacle(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition);
		bool estDeplacementPossible(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition);
		void enregistrerPlacementDePieces(string nomPlacementDePieces, StrategiePlacementPieces* placementPieces);
		
		GrilleEchiquier grille_;
		map<string, StrategiePlacementPieces*> registrePlacementsDePieces_;
		static Couleur tourDeJeu_;
		const static int taille_ = 8;
		
		unique_ptr<Piece> caseTemporaire_;

		friend class StrategiePlacementPieces;
		friend class Roi;
	};
}