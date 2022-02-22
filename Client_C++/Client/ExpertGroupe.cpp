#include "ExpertGroupe.h"
#include "Groupe.h"
#include "COR.h"

ExpertGroupe::ExpertGroupe(ChargementCOR* suivant) : ChargementCOR(suivant) {}

const string ExpertGroupe::getTypeForme()const {
	return "Groupe";
}

string ExpertGroupe::getComposant(string& copie)const {
	string res;
	if (copie.substr(1, copie.find(':') - 1) != "Groupe") {

		res = copie.substr(1, copie.find('&') - 1);
	
		copie = copie.substr(copie.find('&') + 1);

		return res;
	}

	int pos = copie.find_last_of("&&");
	res = copie.substr(1, pos - 1);
	copie = copie.substr(pos + 1);
	return res;

}

Forme* ExpertGroupe::traiterDemande(const string& donneeForme)const {
	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;


	Groupe g = Groupe();
	Forme* composant;
	string infoForme;

	COR* cor = COR::getInstance();
	Chargement* chargeurForme = cor->getChargeurForme();

	while (copie != "")
	{
		
		infoForme = getComposant(copie);
	
		composant = chargeurForme->resoudre("", infoForme);
		g.ajouter(*composant);
	}
	string couleur = copie.substr(0, copie.find(';'));
	g.setCouleur(couleur);

	return new Groupe(g);
}