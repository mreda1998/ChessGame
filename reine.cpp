#include "reine.h"

namespace LogiqueJeu
{
	Reine::Reine(Couleur couleur) {
		couleur_ = couleur;
	}

	bool Reine::estMouvementPossible(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition) const {
		const int deplacementHorizontal = nouvellePosition.first - positionInitiale.first;
		const int deplacementVertical = nouvellePosition.second - positionInitiale.second;

		if (positionInitiale == nouvellePosition) {
			return false;
		}

		if ((abs(positionInitiale.first - nouvellePosition.first) != abs(positionInitiale.second - nouvellePosition.second)))
			return (deplacementHorizontal * deplacementVertical == 0 && deplacementHorizontal - deplacementVertical != 0);

		return true;
	}
}