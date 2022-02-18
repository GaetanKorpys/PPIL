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
		oss << _id;

	oss << "Segment:" << op.getP1() << ";" << op.getP2() << ";" << op.getCouleur() << ";" << op.getGroupe() << ";";

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
		oss << _id;

	oss << "Cercle:" << op.getCentre() << ";" << op.getRayon() << ";" << op.getCouleur() << ";" << op.getGroupe() << ";";

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
		oss << _id;

	oss << "Triangle:" << op.getP1() << ";" << op.getP2() << ";" << op.getP3() << ";" << op.getCouleur() << ";" << op.getGroupe() << ";";

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
		oss << _id;

	oss << "Polygone:";
	for(int i = 0; i < op.getNbPoints(); i++)
	{
		oss << op[i] << ";";
	}
	oss << op.getCouleur() << ";" << op.getGroupe() << ";";

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

	oss << _id << "Groupe:";
	string ligne = oss.str();
	sauvgarde(ligne, _chemin);

	for (int i = 0; i < op.getNbForme(); i++)
	{
		op[i].accepte(*this);
	}

	oss2 << op.getCouleur() << ";" << op.getGroupe() << ";" << endl;
	sauvgarde(oss2.str(), _chemin);
	  
	_id++;
}
