#pragma once
#include "VisiteurTransformation.h"

class VisiteurRotation : public VisiteurTransformation
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

	virtual Segment& visite(Segment& op)const;

	virtual Cercle& visite(Cercle& op)const;

	virtual Triangle& visite(Triangle& op)const;

	virtual Polygone& visite(Polygone& op)const;

};