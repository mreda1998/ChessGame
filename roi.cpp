#include "roi.h"
#include "echiquier.h"
#include <stdexcept>

namespace LogiqueJeu
{
	int Roi::compteurRoi_ = 0;

	Roi::Roi(Couleur couleur) {

	if (compteurRoi_ == 2)
		throw logic_error("Il ne peut pas y avoir plus de 2 rois");

	compteurRoi_++;
	couleur_ = couleur;
	}

	bool LogiqueJeu::Roi::estMouvementPossible(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition) const {
		if (positionInitiale == nouvellePosition) {
			return false;
		}
		
		return (abs(nouvellePosition.first - positionInitiale.first) <= 1 &&
			abs(nouvellePosition.second - positionInitiale.second) <= 1);
	}
}