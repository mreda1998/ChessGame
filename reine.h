#pragma once
#include "piece.h"

namespace LogiqueJeu 
{
	class Reine : public Piece
	{
	public:
		Reine(Couleur couleur);

	private:
		bool estMouvementPossible(const pair<int, int>& positionInitiale,
			                      const pair<int, int>& nouvellePosition) const override;
	};
}
