/**
* \file Cercle.h
* \brief Un Cercle est une forme géométrique composé d'un point centrale et d'un rayon.
* \detail C'est une des 4 formes géométriques disponible par défaut dans le sujet.
*/
#pragma once
#include "Exception.h"
#include "Vecteur2D.h"
#include "Forme.h"

class Cercle :public Forme
{
	Vecteur2D _centre; ///< Le centre du cercle.
	double _rayon; ///< Le rayon du cercle.

public:

	Cercle(const Vecteur2D& op, double rayon, const string& couleur = BLACK);

	Cercle(const Cercle& op);

	~Cercle(){}

	const Vecteur2D& getCentre()const { return _centre; }

	void setCentre(const Vecteur2D& centre) { _centre = centre; }

	double getRayon()const { return _rayon; }

	void setRayon(double rayon)
	{
		if (rayon <= 0)
		{
			throw Exception("Impossible de construire un cercle avec ce rayon.");
		}
		else
		{
			_rayon = rayon;
		}
	}

	const Cercle& operator = (const Cercle& op);

	bool operator == (const Cercle& op)const;

	bool operator != (const Cercle& op)const;

	operator string()const;

	void translation(const Vecteur2D& op);

	void homothetie(const Vecteur2D& op, double r);

	void rotation(const Vecteur2D& op, double angle);

	const double getAire()const;

	Cercle* clone() const;

	Cercle& accepte(const VisiteurTransformation& op);

	friend ostream& operator << (ostream& os, const Cercle& op);
};