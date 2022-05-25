#include "fou.h"

namespace LogiqueJeu
{
	Fou::Fou(Couleur couleur) {
		couleur_ = couleur;
	}

	bool LogiqueJeu::Fou::estMouvementPossible(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition) const 
	{
		if (positionInitiale == nouvellePosition) {
			return false;
		}

		return (abs(positionInitiale.first - nouvellePosition.first) == abs(positionInitiale.second - nouvellePosition.second));
	}
}