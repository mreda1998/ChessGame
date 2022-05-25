#pragma once
#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QLayout>
#include <string>

#include "interfaceEchiquier.h"

namespace Affichage
{
	constexpr int LARGEUR_INTERFACE = LONGUEUR_CASE * NOMBRE_CASES + 500;
	constexpr int HAUTEUR_INTERFACE = LONGUEUR_CASE * NOMBRE_CASES * 1.1;

	class InterfaceGraphique : public QMainWindow
	{
		Q_OBJECT

	public:
		InterfaceGraphique(QWidget* parent = nullptr);
		~InterfaceGraphique();

	private slots:
		void afficherMenuSelectionEchiquier();
		void afficherMenuPrincipal();
		void afficherEchiquier(std::string nomStrategy);
		void afficherReferences();

	private:
		void creerEchiquier(const std::string nomStrategie = "FinDePartieRhanmouniNguyen");
		void creerMenuPrincipal();
		void creerMenuSelectionEchiquier();
		void creerReferences();

		QWidget* creerTitre();
		QWidget* creerWidgetSelection();

		QWidget* fenetreExecution_;
		QHBoxLayout* layoutFenetreExecution_;
		
		QWidget* menuPrincipal_;
		QWidget* menuSelectionEchiquier_;
		QWidget* menuReferences_;
		QWidget* menuEchiquier_;
	};
}
