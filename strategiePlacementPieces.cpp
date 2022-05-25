#include "strategiePlacementPieces.h"
#include "echiquier.h"

namespace LogiqueJeu 
{
	StrategiePlacementPieces::StrategiePlacementPieces(string nomStrategiePlacement) {
		Echiquier::echiquier().enregistrerPlacementDePieces(nomStrategiePlacement, this);
	}
}
