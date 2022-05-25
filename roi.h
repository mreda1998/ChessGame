#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Roi : public Piece
	{
	public:
		Roi(Couleur couleur);
		~Roi() { compteurRoi_--; }

	protected:
		bool estMouvementPossible(const pair<int, int>& positionInitiale,
			                      const pair<int, int>& nouvellePosition) const override;

	private:
		static int compteurRoi_;
	};
}
