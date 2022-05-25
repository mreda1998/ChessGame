#pragma once
#include "strategiePlacementPieces.h"

namespace LogiqueJeu
{
	class FolieDeMasse : public StrategiePlacementPieces
	{
	public:
		void placerPieces() override;

	private:
		FolieDeMasse();
		~FolieDeMasse() override = default;

		static FolieDeMasse instance_;
		inline static const string nomStrategie_ = "FolieDeMasse";
	};
}
