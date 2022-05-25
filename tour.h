#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Tour : public Piece
	{
	public:
		Tour(Couleur couleur);

	protected:
		bool estMouvementPossible(const pair<int, int>& positionInitiale,
			                      const pair<int, int>& nouvellePosition) const override;
	};
}
