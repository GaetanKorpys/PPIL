#pragma once
#include "Visiteur.h"

class VisiteurTxt : public Visiteur
{
	const static string _chemin;

	static int _id;

	void sauvgarde(const string& ligne, const string& chemin)const;

public:

	virtual void visite(Segment& op) const;

	virtual void visite(Triangle& op) const;

	virtual void visite(Cercle& op) const;

	virtual void visite(Polygone& op) const;

	virtual void visite(Groupe& op)const;
};