#include "interfaceGraphique.h"
#include "echiquier.h"
#include <QDebug>
#include <QLabel>

namespace Affichage
{
	InterfaceGraphique::InterfaceGraphique(QWidget* parent) : QMainWindow(parent)
	{
		setWindowTitle("Jeu d'échec - Par Reda Rhanmouni et Huy Viet Nguyen");
		setFixedSize(LARGEUR_INTERFACE, HAUTEUR_INTERFACE);

		fenetreExecution_ = new QWidget(this);
		fenetreExecution_->setFixedSize(LARGEUR_INTERFACE, HAUTEUR_INTERFACE);

		layoutFenetreExecution_ = new QHBoxLayout(fenetreExecution_);
		layoutFenetreExecution_->SetFixedSize;
		layoutFenetreExecution_->setAlignment(Qt::AlignCenter);
		layoutFenetreExecution_->setSpacing(50);

		setCentralWidget(fenetreExecution_);

		creerMenuPrincipal();
		creerMenuSelectionEchiquier();
		creerReferences();
		creerEchiquier();

		layoutFenetreExecution_->addWidget(menuPrincipal_);
		layoutFenetreExecution_->addWidget(menuSelectionEchiquier_);
		layoutFenetreExecution_->addWidget(menuReferences_);
		layoutFenetreExecution_->addWidget(menuEchiquier_);

		afficherMenuPrincipal();
	}

	InterfaceGraphique::~InterfaceGraphique() {
		qDebug() << "Destruction de l'interface graphique" << Qt::endl;
	}

	void InterfaceGraphique::creerEchiquier(const std::string nomStrategie)
	{
		menuEchiquier_ = new QWidget(fenetreExecution_);
		menuEchiquier_->setFixedSize(LARGEUR_INTERFACE, HAUTEUR_INTERFACE);
		menuEchiquier_->setFocusPolicy(Qt::NoFocus);
		QHBoxLayout* layout = new QHBoxLayout(menuEchiquier_);

		QGraphicsView* vueEchiquier_ = new QGraphicsView(fenetreExecution_);
		InterfaceEchiquier* echiquier = new InterfaceEchiquier(vueEchiquier_);
		vueEchiquier_->setFixedSize(NOMBRE_CASES * LONGUEUR_CASE, NOMBRE_CASES * LONGUEUR_CASE);
		vueEchiquier_->setScene(echiquier);
		vueEchiquier_->setAlignment(Qt::AlignLeft);
		vueEchiquier_->centerOn(0, 0);
		vueEchiquier_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		vueEchiquier_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		vueEchiquier_->setFocusPolicy(Qt::NoFocus);
		layout->addWidget(vueEchiquier_);

		QWidget* menuEchiquier = new QWidget(fenetreExecution_);
		QVBoxLayout* layoutMenuEchiquier = new QVBoxLayout(menuEchiquier);
		menuEchiquier->setFocusPolicy(Qt::NoFocus);
		
		QLabel* descriptionEchiquier = new QLabel(vueEchiquier_);
		descriptionEchiquier->setFixedSize(450, 600);
		descriptionEchiquier->setText((LogiqueJeu::Echiquier::echiquier().obtenirStrategie(nomStrategie)->lireDescription()).c_str());
		descriptionEchiquier->setAlignment(Qt::AlignTop);
		descriptionEchiquier->setFont(QFont("Arial", 15));
		descriptionEchiquier->setStyleSheet("border: 1px solid black;");
		descriptionEchiquier->setFocusPolicy(Qt::NoFocus);
		layoutMenuEchiquier->addWidget(descriptionEchiquier);

		QPushButton* boutonRetour = new QPushButton(vueEchiquier_);
		boutonRetour->setFixedSize(450, 100);
		boutonRetour->setFont(QFont("Arial", 20));
		boutonRetour->setText("Retour au menu de sélection");
		boutonRetour->setFocusPolicy(Qt::NoFocus);
		layoutMenuEchiquier->addWidget(boutonRetour);
		connect(boutonRetour, &QPushButton::clicked, this, &InterfaceGraphique::afficherMenuSelectionEchiquier);

		layout->addWidget(menuEchiquier);

		menuEchiquier_->hide();
	}

	QWidget* InterfaceGraphique::creerTitre()
	{
		constexpr int taillePoliceEcriture = 60;

		QWidget* titre = new QWidget(menuPrincipal_);
		QVBoxLayout* layoutTitre = new QVBoxLayout(titre);

		QLabel* nomJeu = new QLabel(titre);
		nomJeu->setFont(QFont("Arial", taillePoliceEcriture));
		nomJeu->setText("Jeu d'échec");
		layoutTitre->addWidget(nomJeu);

		QLabel* nomAuteurs = new QLabel(titre);
		nomAuteurs->setFont(QFont("Arial", taillePoliceEcriture / 2));
		nomAuteurs->setText("par Huy Viet Nguyen et Reda Rhanmouni");
		layoutTitre->addWidget(nomAuteurs);

		return titre;
	}

	void InterfaceGraphique::creerMenuPrincipal()
	{
		constexpr int largeurBouton = 600;
		constexpr int hauteurBouton = 100;
		constexpr int taillePoliceEcriture = 40;

		menuPrincipal_ = new QWidget(this);
		QVBoxLayout* layoutMenuDeSelection = new QVBoxLayout(menuPrincipal_);

		layoutMenuDeSelection->addWidget(creerTitre());

		QPushButton* boutonJouer = new QPushButton(menuPrincipal_);
		boutonJouer->setFixedSize(largeurBouton, hauteurBouton);
		boutonJouer->setFont(QFont("Arial", taillePoliceEcriture));
		boutonJouer->setText("Jouer");
		layoutMenuDeSelection->addWidget(boutonJouer);
		connect(boutonJouer, &QPushButton::clicked, this, &InterfaceGraphique::afficherMenuSelectionEchiquier);

		QPushButton* boutonReferences = new QPushButton(menuPrincipal_);
		boutonReferences->setFixedSize(largeurBouton, hauteurBouton);
		boutonReferences->setFont(QFont("Arial", taillePoliceEcriture));
		boutonReferences->setText("Références");
		layoutMenuDeSelection->addWidget(boutonReferences);
		connect(boutonReferences, &QPushButton::clicked, this, &InterfaceGraphique::afficherReferences);

		QPushButton* boutonQuitter = new QPushButton(menuPrincipal_);
		boutonQuitter->setFixedSize(largeurBouton, hauteurBouton);
		boutonQuitter->setFont(QFont("Arial", taillePoliceEcriture));
		boutonQuitter->setText("Quitter");
		layoutMenuDeSelection->addWidget(boutonQuitter);
		connect(boutonQuitter, &QPushButton::clicked, this, &QMainWindow::close);

		menuPrincipal_->hide();
	}

	void InterfaceGraphique::creerMenuSelectionEchiquier() {
		menuSelectionEchiquier_ = new QWidget(this);
		QHBoxLayout* layoutMenuSelectionEchiquier = new QHBoxLayout(menuSelectionEchiquier_);
		layoutMenuSelectionEchiquier->addWidget(creerWidgetSelection());

		menuSelectionEchiquier_->hide();
	}

	QWidget* InterfaceGraphique::creerWidgetSelection()
	{
		constexpr int largeurBouton = 700;
		constexpr int hauteurBouton = 100;
		constexpr int taillePoliceEcriture = 20;

		QWidget* widgetSelection = new QWidget(menuSelectionEchiquier_);
		QVBoxLayout* layoutSelection = new QVBoxLayout(widgetSelection);

		QPushButton* BoutonFinPartieRhanmouniNguyen = new QPushButton(menuSelectionEchiquier_);
		BoutonFinPartieRhanmouniNguyen->setFixedSize(largeurBouton, hauteurBouton);
		BoutonFinPartieRhanmouniNguyen->setFont(QFont("Arial", taillePoliceEcriture));
		BoutonFinPartieRhanmouniNguyen->setText("Fin de partie Rhanmouni contre Nguyen");
		layoutSelection->addWidget(BoutonFinPartieRhanmouniNguyen);
		connect(BoutonFinPartieRhanmouniNguyen, &QPushButton::clicked, this, [&]() {this->afficherEchiquier("FinDePartieRhanmouniNguyen"); });

		QPushButton* BoutonFinPartieCohnRubinstein = new QPushButton(menuSelectionEchiquier_);
		BoutonFinPartieCohnRubinstein->setFixedSize(largeurBouton, hauteurBouton);
		BoutonFinPartieCohnRubinstein->setFont(QFont("Arial", taillePoliceEcriture));
		BoutonFinPartieCohnRubinstein->setText("Fin de partie Carlos contre ChukBondAliola");
		layoutSelection->addWidget(BoutonFinPartieCohnRubinstein);
		connect(BoutonFinPartieCohnRubinstein, &QPushButton::clicked, this, [&]() {this->afficherEchiquier("FinDePartieCarlosChukBondAliola"); });

		QPushButton* BoutonFinPartieAlekhineCapablanca = new QPushButton(menuSelectionEchiquier_);
		BoutonFinPartieAlekhineCapablanca->setFixedSize(largeurBouton, hauteurBouton);
		BoutonFinPartieAlekhineCapablanca->setFont(QFont("Arial", taillePoliceEcriture));
		BoutonFinPartieAlekhineCapablanca->setText("Fin de partie Alexandre contre Jean-Maçon");
		layoutSelection->addWidget(BoutonFinPartieAlekhineCapablanca);
		connect(BoutonFinPartieAlekhineCapablanca, &QPushButton::clicked, this, [&]() {this->afficherEchiquier("FinDePartieAlexandreJean-Macon"); });

		QPushButton* BoutonFinPartieOuvertureCrabe = new QPushButton(menuSelectionEchiquier_);
		BoutonFinPartieOuvertureCrabe->setFixedSize(largeurBouton, hauteurBouton);
		BoutonFinPartieOuvertureCrabe->setFont(QFont("Arial", taillePoliceEcriture));
		BoutonFinPartieOuvertureCrabe->setText("La grande Muraille des Tours");
		layoutSelection->addWidget(BoutonFinPartieOuvertureCrabe);
		connect(BoutonFinPartieOuvertureCrabe, &QPushButton::clicked, this, [&]() {this->afficherEchiquier("GrandeMurailleDesTours"); });

		QPushButton* BoutonFinPartieOuvertureRhanmouniNguyen = new QPushButton(menuSelectionEchiquier_);
		BoutonFinPartieOuvertureRhanmouniNguyen->setFixedSize(largeurBouton, hauteurBouton);
		BoutonFinPartieOuvertureRhanmouniNguyen->setFont(QFont("Arial", taillePoliceEcriture));
		BoutonFinPartieOuvertureRhanmouniNguyen->setText("Folie de masse");
		layoutSelection->addWidget(BoutonFinPartieOuvertureRhanmouniNguyen);
		connect(BoutonFinPartieOuvertureRhanmouniNguyen, &QPushButton::clicked, this, [&]() {this->afficherEchiquier("FolieDeMasse"); });

		QPushButton* boutonRetour = new QPushButton(menuReferences_);
		boutonRetour->setFixedSize(largeurBouton, hauteurBouton);
		boutonRetour->setFont(QFont("Arial", taillePoliceEcriture));
		boutonRetour->setText("Retour au menu principal");
		layoutSelection->addWidget(boutonRetour);
		connect(boutonRetour, &QPushButton::clicked, this, &InterfaceGraphique::afficherMenuPrincipal);

		return widgetSelection;
	}

	void InterfaceGraphique::creerReferences() 
	{
		menuReferences_ = new QWidget(fenetreExecution_);
		QVBoxLayout* layoutMenuReference = new QVBoxLayout(menuReferences_);
		layoutMenuReference->setSpacing(50);

		QLabel* references = new QLabel(menuReferences_);
		references->setFont(QFont("Arial", 15));
		references->setText("Icônes des pièces issues de : Cburnett. Wikimedia Commons.\nDisponible : https://commons.wikimedia.org/wiki/File:Chess_Pieces_Sprite.sv");
		layoutMenuReference->addWidget(references);

		QPushButton* boutonRetour = new QPushButton(menuReferences_);
		boutonRetour->setFixedSize(600, 100);
		boutonRetour->setFont(QFont("Arial", 20));
		boutonRetour->setText("Retour au menu principal");
		layoutMenuReference->addWidget(boutonRetour);
		connect(boutonRetour, &QPushButton::clicked, this, &InterfaceGraphique::afficherMenuPrincipal);

		menuReferences_->hide();
	}

	void InterfaceGraphique::afficherMenuSelectionEchiquier() {
		menuSelectionEchiquier_->show();
		menuPrincipal_->hide();
		menuEchiquier_->hide();
		menuReferences_->hide();
	}

	void InterfaceGraphique::afficherMenuPrincipal() {
		menuPrincipal_->show();
		menuSelectionEchiquier_->hide();
		menuEchiquier_->hide();
		menuReferences_->hide();
	}

	void InterfaceGraphique::afficherEchiquier(std::string nomStrategie) {
		LogiqueJeu::Echiquier::echiquier().selectionnerPlacementPieces(nomStrategie);
		creerEchiquier(nomStrategie);
		menuPrincipal_->hide();
		menuEchiquier_->show();
		menuSelectionEchiquier_->hide();
		menuReferences_->hide();
	}

	void InterfaceGraphique::afficherReferences() {
		menuPrincipal_->hide();
		menuSelectionEchiquier_->hide();
		menuEchiquier_->hide();
		menuReferences_->show();
	}
}
