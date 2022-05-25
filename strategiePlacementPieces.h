#pragma once
#include <string>
using namespace std;

namespace LogiqueJeu 
{
	class StrategiePlacementPieces
	{
	public:
		virtual void placerPieces() = 0;
		virtual string lireDescription() const noexcept { return description_; }

	protected:
		StrategiePlacementPieces(string nomStrategiePlacement);
		virtual ~StrategiePlacementPieces() = default;

		string description_ = "Aucune description disponible";
	};
}
