#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Fou : public Piece
	{
	public:
		Fou(Couleur couleur);

	protected:
		bool estMouvementPossible(const pair<int, int>& positionInitiale,
			                      const pair<int, int>& nouvellePosition) const override;
	};
}
