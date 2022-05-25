#pragma once
#include "strategiePlacementPieces.h"

namespace LogiqueJeu
{
	class FinDePartieAlexandreJeanMacon : public StrategiePlacementPieces
	{
	public:
		void placerPieces() override;

	private:
		FinDePartieAlexandreJeanMacon();
		~FinDePartieAlexandreJeanMacon() override = default;

		static FinDePartieAlexandreJeanMacon instance_;
		inline static const string nomStrategie_ = "FinDePartieAlexandreJean-Macon";
	};
}
