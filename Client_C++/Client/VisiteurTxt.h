#pragma once
#include "Visiteur.h"
#include "Constante.h"

class VisiteurTxt : public Visiteur
{
	string _chemin;

	int _id;

	void sauvgarde(const string& ligne, const string& chemin)const;

public:

	VisiteurTxt(const string& chemin = SAUVGARDE, int id = 0);

	virtual void visite(Segment& op) const;

	virtual void visite(Triangle& op) const;

	virtual void visite(Cercle& op) const;

	virtual void visite(Polygone& op) const;


};