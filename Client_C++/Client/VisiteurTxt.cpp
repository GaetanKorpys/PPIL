#include "VisiteurTxt.h"
#include <fstream>

VisiteurTxt::VisiteurTxt(const string& chemin, int id)
{
	_id = id;
	_chemin = chemin;
}


void VisiteurTxt::sauvgarde(const string& ligne, const string& chemin)const
{
	ofstream fichier(chemin, ios_base::app);
	fichier << ligne;
	fichier.close();
}


void VisiteurTxt::visite(Segment& op)const
{
	ostringstream oss;

	oss << _id << "Segment:" << op.getP1() << ";" << op.getP2() << ";" << op.getCouleur() << endl;
	string ligne = oss.str();

	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());
	
	sauvgarde(ligne, _chemin);
}

void VisiteurTxt::visite(Cercle& op)const
{
	
}

void VisiteurTxt::visite(Triangle& op)const
{
	

}

void VisiteurTxt::visite(Polygone& op)const
{
	
}