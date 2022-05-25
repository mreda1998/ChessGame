#pragma once
#include <utility>
using namespace std;

enum class Couleur {
	Blanc,
	Noir
};

namespace LogiqueJeu 
{
	class Piece
	{
	public:
		virtual ~Piece() = default;
		Couleur obtenirCouleur() noexcept { return couleur_; }

	protected:
		virtual bool estMouvementPossible(const pair<int, int>& positionInitiale,
			                              const pair<int, int>& nouvellePosition) const = 0;

		Couleur couleur_;

	private:
		friend class Echiquier;
	};
}
