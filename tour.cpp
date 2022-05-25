#include "tour.h"

namespace LogiqueJeu 
{
	Tour::Tour(Couleur couleur) {
		couleur_ = couleur;
	}

	bool Tour::estMouvementPossible(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition) const {
		const int deplacementHorizontal = nouvellePosition.first - positionInitiale.first;
		const int deplacementVertical = nouvellePosition.second - positionInitiale.second;

		if (positionInitiale == nouvellePosition) {
			return false;
		}

		return (deplacementHorizontal * deplacementVertical == 0 &&
			deplacementHorizontal - deplacementVertical != 0);
	}
}
