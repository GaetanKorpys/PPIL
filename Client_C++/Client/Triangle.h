/**
* \file Triangle.h
* \brief Un triangle est une forme géométrique composé de 3 points.
* \detail C'est une des 4 formes géométriques disponible par défaut dans le sujet.
*/
#pragma once
#include "Exception.h"
#include "Vecteur2D.h"
#include "Forme.h"


using namespace std;

class Triangle : public Forme
{
	Vecteur2D _p1; ///< Le 1er point (Vecteur2D) qui compose le triangle.
	Vecteur2D _p2; ///< Le 2scd point (Vecteur2D) qui compose le triangle.
	Vecteur2D _p3; ///< Le 3ème point (Vecteur2D) qui compose le triangle.

	bool triangleValide(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3)
	{
		if( (p1 == p2) || (p1 == p3) || (p2 == p3) )
			return false;
		return true;
	}

public:

	Triangle(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3, const string& couleur = BLACK);

	Triangle(const Triangle& op);

	~Triangle(){}

	const Vecteur2D& getP1()const
	{
		return _p1;
	}

	void setP1(const Vecteur2D& op);

	const Vecteur2D& getP2()const
	{
		return _p2;
	}

	void setP2(const Vecteur2D& op);

	const Vecteur2D& getP3()const
	{
		return _p3;
	}

	void setP3(const Vecteur2D& op);

	const Triangle& operator = (const Triangle& op);

	bool operator == (const Triangle& op)const;

	bool operator != (const Triangle& op)const;

	operator string()const;

	void translation(const Vecteur2D& op);

	void homothetie(const Vecteur2D& op, double r);

	void rotation(const Vecteur2D& op, double angle);

	const double getAire()const;

	Triangle* clone() const;

	Triangle& accepte(const VisiteurTransformation& op);

	friend ostream& operator << (ostream& os, const Triangle& op);
};
