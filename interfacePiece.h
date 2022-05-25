//Icônes des pièces issues de : Cburnett. Wikimedia Commons. Disponible : https://commons.wikimedia.org/wiki/File:Chess_Pieces_Sprite.sv

#pragma once
#include <QObject>
#include <QGraphicsPixmapItem>

namespace Affichage 
{
	constexpr int LONGUEUR_CASE = 106;
	constexpr int NOMBRE_CASES = 8;
	
	class InterfacePiece : public QObject, public QGraphicsPixmapItem
	{
		Q_OBJECT

	public:
		InterfacePiece(std::pair<int, int> position);

	protected:
		void mouseReleaseEvent(QGraphicsSceneMouseEvent* evenement) override;

	signals:
		void changementPosition(std::pair<int, int>& position);

	private:
		void ajouterIcone(std::pair<int, int>& position);

		std::pair<int, int> positionActuelle_;
		friend class InterfaceEchiquier;
	};
}