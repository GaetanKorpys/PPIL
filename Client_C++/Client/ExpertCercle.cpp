#include "ExpertCercle.h"
#include "Cercle.h"

ExpertCercle::ExpertCercle(ChargementCOR* suivant) : ChargementCOR(suivant) {}

const string ExpertCercle::getTypeForme()const {
	return "Cercle";
}
Forme* ExpertCercle::traiterDemande(const string& donneeForme)const {
	//donneeForme sera sous forme: Centre;rayon;Couleur

	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;

	Vecteur2D centre = stringToPoint(copie.substr(0, copie.find(';')));
	copie = copie.substr(copie.find(';') + 1);

	double rayon = stod(copie.substr(0, copie.find(';')));
	copie = copie.substr(copie.find(';') + 1);


	string couleur = copie.substr(0, copie.find(';'));


	return new Cercle(centre, rayon, couleur);
}