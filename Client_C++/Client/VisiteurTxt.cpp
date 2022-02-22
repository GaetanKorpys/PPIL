#include "VisiteurTxt.h"
#include <fstream>
#include "Constante.h"

int VisiteurTxt::_id = 0;

const string VisiteurTxt::_chemin = SAUVGARDE;


void VisiteurTxt::sauvgarde(const string& ligne, const string& chemin)const
{
	ofstream fichier(chemin, ios_base::app);
	fichier << ligne;
	fichier.close();
}


void VisiteurTxt::visite(Segment& op)const
{
	ostringstream oss;
	if (!op.getGroupe())
		oss << _id << SEPARATEUR_TYPE_REQUETE;

	oss << "Segment" << SEPARATEUR_TYPE_DONNEE << op.getP1() << SEPARATEUR_DONNEE << op.getP2() << SEPARATEUR_DONNEE << op.getCouleur()  << SEPARATEUR_DONNEE << op.getGroupe() << SEPARATEUR_DONNEE;

	if (!op.getGroupe())
		oss << endl;

	string ligne = oss.str();
	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());
	
	sauvgarde(ligne, _chemin);

	if (!op.getGroupe())
		_id++;
}

void VisiteurTxt::visite(Cercle& op)const
{
	ostringstream oss;
	if (!op.getGroupe())
		oss << _id << SEPARATEUR_TYPE_REQUETE;

	oss << "Cercle" << SEPARATEUR_TYPE_DONNEE << op.getCentre() << SEPARATEUR_DONNEE << op.getRayon() << SEPARATEUR_DONNEE << op.getCouleur()  << SEPARATEUR_DONNEE << op.getGroupe() << SEPARATEUR_DONNEE;

	if (!op.getGroupe())
		oss << endl;

	string ligne = oss.str();
	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());

	sauvgarde(ligne, _chemin);

	if (!op.getGroupe())
		_id++;
}

void VisiteurTxt::visite(Triangle& op)const
{
	ostringstream oss;

	if (!op.getGroupe())
		oss << _id << SEPARATEUR_TYPE_REQUETE;

	oss << "Triangle" << SEPARATEUR_TYPE_DONNEE << op.getP1() << SEPARATEUR_DONNEE << op.getP2() << SEPARATEUR_DONNEE << op.getP3() << SEPARATEUR_DONNEE << op.getCouleur()  << SEPARATEUR_DONNEE << op.getGroupe() << SEPARATEUR_DONNEE;

	if (!op.getGroupe())
		oss << endl;

	string ligne = oss.str();
	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());

	sauvgarde(ligne, _chemin);

	if (!op.getGroupe())
		_id++;
}

void VisiteurTxt::visite(Polygone& op)const
{
	ostringstream oss;

	if (!op.getGroupe())
		oss << _id << SEPARATEUR_TYPE_REQUETE;

	oss << "Polygone" << SEPARATEUR_TYPE_DONNEE;
	for(int i = 0; i < op.getNbPoints(); i++)
	{
		oss << op[i] << SEPARATEUR_DONNEE;
	}
	oss << op.getCouleur() << SEPARATEUR_DONNEE  << op.getGroupe() << SEPARATEUR_DONNEE;

	if (!op.getGroupe())
		oss << endl;

	string ligne = oss.str();
	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());

	sauvgarde(ligne, _chemin);

	if (!op.getGroupe())
		_id++;
}

void VisiteurTxt::visite(Groupe& op) const
{
	ostringstream oss, oss2;

	oss << _id << SEPARATEUR_TYPE_REQUETE << "Groupe" << SEPARATEUR_TYPE_DONNEE;
	string ligne = oss.str();
	sauvgarde(ligne, _chemin);

	for (int i = 0; i < op.getNbForme(); i++)
	{
		op[i].accepte(*this);
	}

	oss2 << op.getCouleur() << SEPARATEUR_DONNEE << op.getGroupe() << SEPARATEUR_DONNEE << endl;
	sauvgarde(oss2.str(), _chemin);
	  
	_id++;
}
