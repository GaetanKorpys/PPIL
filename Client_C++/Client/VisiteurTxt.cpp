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

	oss << _id << "Segment:" << op.getP1() << ";" << op.getP2() << ";" << op.getCouleur() << ";" << op.getGroupe() << ";" <<endl;
	string ligne = oss.str();

	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());
	
	sauvgarde(ligne, _chemin);
	_id++;
}

void VisiteurTxt::visite(Cercle& op)const
{
	ostringstream oss;

	oss << _id << "Cercle:" << op.getCentre() << ";" << op.getRayon() << ";" << op.getCouleur() << ";" << op.getGroupe() << ";" << endl;
	string ligne = oss.str();

	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());

	sauvgarde(ligne, _chemin);
	_id++;
}

void VisiteurTxt::visite(Triangle& op)const
{
	ostringstream oss;

	oss << _id << "Triangle:" << op.getP1() << ";" << op.getP2() << ";" << op.getP3() << ";" << op.getCouleur() << ";" << op.getGroupe() << ";" << endl;
	string ligne = oss.str();

	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());

	sauvgarde(ligne, _chemin);
	_id++;
}

void VisiteurTxt::visite(Polygone& op)const
{
	ostringstream oss;

	oss << _id << "Polygone:";
	for(int i = 0; i < op.getNbPoints(); i++)
	{
		oss << op[i] << ";";
	}
	oss << op.getCouleur() << ";" << op.getGroupe() << ";" << endl;
	string ligne = oss.str();

	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());

	sauvgarde(ligne, _chemin);
	_id++;
}

void VisiteurTxt::visite(Groupe& op) const
{
	ostringstream oss;

	oss << _id << "Polygone:";
	for (int i = 0; i < op.getNbForme(); i++)
	{
		op[i].accepte(*this);
	}
	oss << op.getCouleur() << ";" << op.getGroupe() << ";" << endl;
	string ligne = oss.str();

	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());

	sauvgarde(ligne, _chemin);
	_id++;
}
