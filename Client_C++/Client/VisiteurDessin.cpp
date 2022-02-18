#include "VisiteurDessin.h"
#include "SocketSingleton.h"
#include "Constante.h"

string VisiteurDessin::requeteFenetre()const
{
	return "FENETRE" + SEPARATEUR_TYPE_REQUETE + "Fenetre de dessin" + SEPARATEUR_DONNEE + to_string(LARGEUR) + SEPARATEUR_DONNEE + to_string(HAUTEUR);
}

void VisiteurDessin::ouvrirFenetre()const
{
	//Envoyer la requete pour ouvrir une fenetre
	SocketSingleton::getInstance()->envoyerRequete(requeteFenetre());
	cout << "Requete ouverture de fenetre envoyee" << endl;
	cout << "Attente de la reponse du serveur..." << endl << endl;
	if (SocketSingleton::getInstance()->requeteSucces())
		cout << "La fenetre est ouverte" << endl << endl;
	else
		cout << "Le serveur n'a pas ouvert la fenetre" << endl << endl;
}


void VisiteurDessin::dessiner(const string& infoForme, bool groupe)const
{
	try {
		if (!groupe)
			ouvrirFenetre();
		SocketSingleton::getInstance()->envoyerRequete(infoForme);
		cout << "Requete de dessin envoyee" << endl;
		cout << "Attente de la reponse du serveur..." << endl << endl;

		/*Attendre de la reponse du serveur pour savoir s'il a dessiner
		avant de fermer la connexion*/

		if (SocketSingleton::getInstance()->requeteSucces())
			cout << "Le serveur a traite la requete : " << infoForme << endl;
		else {
			cout << "Le serveur n'a pas dessiner la forme" << endl;
			cout << "Car il ne l'a pas reconnue" << endl;
		}

	}
	catch (Exception e) {
		cerr << e << endl;
	}
}

void VisiteurDessin::visite(Segment& op) const
{
	ostringstream os;
	os << "FORME" << SEPARATEUR_TYPE_REQUETE << "Segment"  << SEPARATEUR_TYPE_DONNEE << op.getCouleur() << SEPARATEUR_DONNEE << op.getP1() << SEPARATEUR_DONNEE << op.getP2() << SEPARATEUR_DONNEE;

	try {
		//Connexion si la forme est indépendante
		if (!op.getGroupe())
			SocketSingleton::getInstance()->initialiserConnexion();

		dessiner(os.str(), op.getGroupe());

		//Donnexion si la forme est indépendante
		if (!op.getGroupe()) {
			SocketSingleton::getInstance()->fermerConnexion();
			SocketSingleton::getInstance()->killInstance();
		}
	}
	catch (Exception e) {
		cerr << e << endl;
	}
}

void VisiteurDessin::visite(Triangle& op) const
{
	ostringstream os;
	os << "FORME" << SEPARATEUR_TYPE_REQUETE << "Triangle" << SEPARATEUR_TYPE_DONNEE << op.getCouleur() << SEPARATEUR_DONNEE << op.getP1() << SEPARATEUR_DONNEE << op.getP2() << SEPARATEUR_DONNEE << op.getP3() << SEPARATEUR_DONNEE;

	try {
		//Connexion si la forme est indépendante
		if (!op.getGroupe())
			SocketSingleton::getInstance()->initialiserConnexion();

		dessiner(os.str(), op.getGroupe());

		//Donnexion si la forme est indépendante
		if (!op.getGroupe()) {
			SocketSingleton::getInstance()->fermerConnexion();
		}
	}
	catch (Exception e) {
		cerr << e << endl;
	}
}

void VisiteurDessin::visite(Cercle& op) const
{
	ostringstream os;
	os << "FORME" << SEPARATEUR_TYPE_REQUETE << "Cercle" << SEPARATEUR_TYPE_DONNEE <<  op.getCouleur() << SEPARATEUR_DONNEE << op.getRayon() << SEPARATEUR_DONNEE << op.getCentre() << SEPARATEUR_DONNEE;

	try {
		//Connexion si la forme est indépendante
		if (!op.getGroupe())
			SocketSingleton::getInstance()->initialiserConnexion();

		dessiner(os.str(), op.getGroupe());

		//Donnexion si la forme est indépendante
		if (!op.getGroupe()) {
			SocketSingleton::getInstance()->fermerConnexion();
		}
	}
	catch (Exception e) {
		cerr << e << endl;
	}
}

void VisiteurDessin::visite(Polygone& op) const
{
	ostringstream os;
	os << "FORME" << SEPARATEUR_TYPE_REQUETE << "Polygone" << SEPARATEUR_TYPE_DONNEE << op.getCouleur() << SEPARATEUR_DONNEE;
	for(int i = 0; i < op.getNbPoints(); i++)
	{
		os << op[i] << SEPARATEUR_DONNEE;
	}
	

	try {
		//Connexion si la forme est indépendante
		if (!op.getGroupe())
			SocketSingleton::getInstance()->initialiserConnexion();

		dessiner(os.str(), op.getGroupe());

		//Donnexion si la forme est indépendante
		if (!op.getGroupe()) {
			SocketSingleton::getInstance()->fermerConnexion();
		}
	}
	catch (Exception e) {
		cerr << e << endl;
	}
}

void VisiteurDessin::visite(Groupe& op) const
{
	try {
		//Connexion si la forme est indépendante
		if (!op.getGroupe()) {
			SocketSingleton::getInstance()->initialiserConnexion();
			ouvrirFenetre();
		}


		for (int i = 0; i < op.getNbForme(); i++) {
			op[i].accepte(*this);
		}

		//Donnexion si la forme est indépendante
		if (!op.getGroupe()) {
			SocketSingleton::getInstance()->fermerConnexion();
		}
	}
	catch (Exception e) {
		cerr << e << endl;
	}
}