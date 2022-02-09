#pragma once
#include "Visiteur.h"

class VisiteurTranslation : public Visiteur
{

	Vecteur2D _op;

public:

	VisiteurTranslation(const Vecteur2D& op)
	{
		_op = op;
	}

	virtual void visite(Segment& op)const;

	virtual void visite(Cercle& op)const;

	virtual void visite(Triangle& op)const;

	virtual void visite(Polygone& op)const;

	virtual void visite(Groupe& op)const;

};