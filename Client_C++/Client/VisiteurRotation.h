#pragma once
#include "Visiteur.h"

class VisiteurRotation : public Visiteur
{

	Vecteur2D _op;
	double _angle;

public:

	VisiteurRotation(const Vecteur2D& op, double angle)
	{
		if (angle < 0)
			throw Exception("Impossible de construre une Rotation avec un angle < 0.");
		_op = op;
		_angle = angle;
	}

	virtual void visite(Segment& op)const;

	virtual void visite(Cercle& op)const;

	virtual void visite(Triangle& op)const;

	virtual void visite(Polygone& op)const;

	virtual void visite(Groupe& op)const;
};