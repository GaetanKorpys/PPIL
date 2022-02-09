#pragma once
#include "Visiteur.h"

class VisiteurHomothetie : public Visiteur
{

	Vecteur2D _op;
	double _rapport;

public:

	VisiteurHomothetie(const Vecteur2D& op, double r)
	{
		if (r < 0)
			throw Exception("Impossible de construire une Homothétie avec un rapport < 0.");
		_op = op;
		_rapport = r;
	}

	virtual void visite(Segment& op)const;

	virtual void visite(Triangle& op)const;

	virtual void visite(Cercle& op)const;

	virtual void visite(Polygone& op)const;

	virtual void visite(Groupe& op)const;

};
