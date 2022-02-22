#include "ExpertTriangle.h"
#include "Triangle.h"
ExpertTriangle::ExpertTriangle(ChargementCOR* suivant) : ChargementCOR(suivant) {}
const string ExpertTriangle::getTypeForme()const {
	return "Triangle";
}
Forme* ExpertTriangle::traiterDemande(const string& donneeForme)const {
	//donneeForme sera sous forme: P1;P2;P3;Couleur

	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;

	Vecteur2D p1 = stringToPoint(copie.substr(0, copie.find(';')));
	copie = copie.substr(copie.find(';') + 1);

	Vecteur2D p2 = stringToPoint(copie.substr(0, copie.find(';')));
	copie = copie.substr(copie.find(';') + 1);

	Vecteur2D p3 = stringToPoint(copie.substr(0, copie.find(';')));
	copie = copie.substr(copie.find(';') + 1);

	string couleur = copie.substr(0, copie.find(';'));

	return new Triangle(p1, p2, p3, couleur);
}