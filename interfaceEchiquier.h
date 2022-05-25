#pragma once
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "interfacePiece.h"
#include "echiquier.h"

namespace Affichage
{
	class InterfaceEchiquier : public QGraphicsScene
	{
		Q_OBJECT

	public:
		InterfaceEchiquier(QObject* parent = nullptr);

	public slots:
		void actualiserPosition(std::pair<int, int>& position);
		
	private:
		void creerGrille();
		void miseEnEchec();

		pair<int, int> positionRoiEnEchec_ = { 0, 0 };

		QList<InterfacePiece*> listePieces_;
		map<pair<int ,int>, QGraphicsRectItem*> listeCases_;
	};
}
