#include "ExpertSegment.h"
#include "Segment.h"

ExpertSegment::ExpertSegment(ChargementCOR* suivant) : ChargementCOR(suivant) {}

const string ExpertSegment::getTypeForme()const {
	return "Segment";
}
Forme* ExpertSegment::traiterDemande(const string& donneeForme)const {
	//donneeForme sera sous forme: P1;P2;Couleur

	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;

	Vecteur2D po = stringToPoint(copie.substr(0, copie.find(';')));
	copie = copie.substr(copie.find(';') + 1);

	Vecteur2D pe = stringToPoint(copie.substr(0, copie.find(';')));
	copie = copie.substr(copie.find(';') + 1);

	string couleur = copie.substr(0, copie.find(';'));

	return new Segment(po, pe, couleur);
}