#pragma once
#include "strategiePlacementPieces.h"

namespace LogiqueJeu
{
	class FinDePartieCarlosChukBondAliola : public StrategiePlacementPieces
	{
	public:
		void placerPieces() override;

	private:
		FinDePartieCarlosChukBondAliola();

		static FinDePartieCarlosChukBondAliola instance_;
		inline static const string nomStrategie_ = "FinDePartieCarlosChukBondAliola";
	};
}
