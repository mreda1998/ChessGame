#pragma once
#include "strategiePlacementPieces.h"

namespace LogiqueJeu
{
	class FinDePartieRhanmouniNguyen : public StrategiePlacementPieces
	{
	public:
		void placerPieces() override;

	private:
		FinDePartieRhanmouniNguyen();
		~FinDePartieRhanmouniNguyen() override = default;

		static FinDePartieRhanmouniNguyen instance_;
		inline static const string nomStrategie_ = "FinDePartieRhanmouniNguyen";
	};
}