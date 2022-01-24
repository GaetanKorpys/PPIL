/**
* \file Segment.h
* \brief Un segment est une forme géométrique composé de 2 points ( C'est une droite finie ).
* \detail C'est une des 4 formes géométriques disponible par défaut dans le sujet.
*/

#pragma once
#include "Constante.h"
#include "Exception.h"
#include "Vecteur2D.h"
#include "Forme.h"

using namespace std;

class Segment : public Forme
{
	Vecteur2D _p1; ///< Le 1er point (Vecteur2D) qui compose le segment.
	Vecteur2D _p2; ///< Le 2scd point (Vecteur2D) qui compose le segment.

	bool segmentValide(const Vecteur2D& p1, const Vecteur2D& p2)
	{
		if (p1 == p2)
			return false;
		return true;
	}

public:

	Segment(const Vecteur2D& p1, const Vecteur2D& p2, const string& couleur = BLACK);

	Segment(const Segment& op);

	~Segment(){}

	const Vecteur2D& getP1()const { return _p1; }

	void setP1(const Vecteur2D& p1);

	const Vecteur2D getP2()const { return _p2; }

	void setP2(const Vecteur2D& p2);

	void setP3(const Vecteur2D& op);

	const Segment& operator = (const Segment& op);

	bool operator == (const Segment& op)const;

	bool operator != (const Segment& op)const;

	operator string()const;

	void translation(const Vecteur2D& op);

	void homothetie(const Vecteur2D& op, double r);

	void rotation(double angle);

	const double getAire()const;

	Segment* clone() const;

	friend ostream& operator << (ostream& os, const Segment& op);
};