#include "ExpertPolygone.h"
#include "Polygone.h"

ExpertPolygone::ExpertPolygone(ChargementCOR* suivant) : ChargementCOR(suivant) {}
const string ExpertPolygone::getTypeForme()const {
	return "Polygone";
}
Forme* ExpertPolygone::traiterDemande(const string& donneeForme)const {
	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;

	Vecteur2D point;
	Polygone p = Polygone();


	while (copie.substr(copie.find(';') + 3) != "")
	{
		point = stringToPoint(copie.substr(0, copie.find(';')));
		p.ajouter(point);
		copie = copie.substr(copie.find(';') + 1);
	}

	string couleur = copie.substr(0, copie.find(';'));
	p.setCouleur(couleur);

	return new Polygone(p);
}