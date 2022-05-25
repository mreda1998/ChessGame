//Icônes des pièces issues de : Cburnett. Wikimedia Commons. Disponible : https://commons.wikimedia.org/wiki/File:Chess_Pieces_Sprite.sv

#pragma once
#include <QPen>
#include "interfacePiece.h"
#include "echiquier.h"
#include "roi.h"
#include "reine.h"
#include "tour.h"
#include "fou.h"

namespace Affichage
{
	InterfacePiece::InterfacePiece(std::pair<int, int> position) {
		ajouterIcone(position);

		setFlag(QGraphicsItem::ItemIsMovable);
		setFlag(QGraphicsItem::ItemIsSelectable);

		positionActuelle_ = position;
	}

	void InterfacePiece::mouseReleaseEvent(QGraphicsSceneMouseEvent* evenement) {
		int x = (pos().x() + LONGUEUR_CASE / 2) - ((int(pos().x()) + LONGUEUR_CASE / 2) % LONGUEUR_CASE);
		int y = (pos().y() + LONGUEUR_CASE / 2) - ((int(pos().y()) + LONGUEUR_CASE / 2) % LONGUEUR_CASE);
		std::pair<int, int> nouvellePosition = { x / LONGUEUR_CASE + 1, 8 - y / LONGUEUR_CASE };

		LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionActuelle_, nouvellePosition);

		if (LogiqueJeu::Echiquier::echiquier().prendrePiece(positionActuelle_).get() == nullptr) {
			emit changementPosition(nouvellePosition);
			setPos(x, y);
			positionActuelle_ = nouvellePosition;
		}

		else {
			setPos((positionActuelle_.first - 1) * LONGUEUR_CASE, (NOMBRE_CASES - positionActuelle_.second) * LONGUEUR_CASE);
		}

		QGraphicsPixmapItem::mouseReleaseEvent(evenement);
	}

	void InterfacePiece::ajouterIcone(std::pair<int, int>& position) {
		LogiqueJeu::Piece* piece = LogiqueJeu::Echiquier::echiquier().prendrePiece(position).get();

		if (piece->obtenirCouleur() == Couleur::Blanc) {
			if (dynamic_cast<LogiqueJeu::Roi*>(piece) != nullptr) {
				setPixmap(QPixmap("icones_pieces/roi_blanc.png"));
			}

			else if (dynamic_cast<LogiqueJeu::Reine*>(piece) != nullptr) {
				setPixmap(QPixmap("icones_pieces/reine_blanc.png"));
			}

			else if (dynamic_cast<LogiqueJeu::Tour*>(piece) != nullptr) {
				setPixmap(QPixmap("icones_pieces/tour_blanc.png"));
			}

			else if (dynamic_cast<LogiqueJeu::Fou*>(piece) != nullptr) {
				setPixmap(QPixmap("icones_pieces/fou_blanc.png"));
			}

			else {
				setPixmap(QPixmap("icones_pieces/erreur.png"));
			}
		}

		else {
			if (dynamic_cast<LogiqueJeu::Roi*>(piece) != nullptr) {
				setPixmap(QPixmap("icones_pieces/roi_noir.png"));
			}

			else if (dynamic_cast<LogiqueJeu::Reine*>(piece) != nullptr) {
				setPixmap(QPixmap("icones_pieces/reine_noir.png"));
			}

			else if (dynamic_cast<LogiqueJeu::Tour*>(piece) != nullptr) {
				setPixmap(QPixmap("icones_pieces/tour_noir.png"));
			}

			else if (dynamic_cast<LogiqueJeu::Fou*>(piece) != nullptr) {
				setPixmap(QPixmap("icones_pieces/fou_noir.png"));
			}

			else {
				setPixmap(QPixmap("icones_pieces/erreur.png"));
			}
		}
	}	
}
