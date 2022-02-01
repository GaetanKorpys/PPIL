#pragma once
#include "VisiteurTransformation.h"

class VisiteurTranslation : public VisiteurTransformation
{

	Vecteur2D _op;

public:

	VisiteurTranslation(const Vecteur2D& op)
	{
		_op = op;
	}

	virtual Segment& visite(Segment& op)const;

	virtual Cercle& visite(Cercle& op)const;

	virtual Triangle& visite(Triangle& op)const;

	virtual Polygone& visite(Polygone& op)const;

};