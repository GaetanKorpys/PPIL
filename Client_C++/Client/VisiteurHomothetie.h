#pragma once
#include "VisiteurTransformation.h"

class VisiteurHomothetie : public VisiteurTransformation
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

	virtual Segment& visite(Segment& op)const;

	virtual Cercle& visite(Cercle& op)const;

	virtual Triangle& visite(Triangle& op)const;

	virtual Polygone& visite(Polygone& op)const;

};
