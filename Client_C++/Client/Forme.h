/**
* \file Forme.h
* \brief Une forme est caractérisée par une couleur.
* \detail Il existe 2 types de formes, les simples (Segment, Triangle ...) et les composées.
* \detail Une forme composée aussi appelée Groupe est un ensemble de forme simple et de forme composée.
*/

#pragma once
#include "Constante.h"
#include "Vecteur2D.h"
#include <iostream>

using namespace std;

class Forme
{
	string _couleur;
	bool _groupe;

public :

	Forme() 
	{
		_couleur = BLACK;
		_groupe = false;
	}

	Forme(const string& couleur) 
	{ 
		_couleur = couleur; 
		_groupe = false;
	}

	Forme(const Forme& op) 
	{
		_couleur = op._couleur; 
		_groupe = op._groupe;
	}

	~Forme(){}

	string getCouleur()const { return _couleur; }

	void setCouleur(const string& couleur) { _couleur = couleur; }

	bool getGroupe()const { return _groupe; }

	void setGroupe(bool groupe) { _groupe = groupe; }

	virtual const Forme& operator = (const Forme& op);

	virtual bool operator == (const Forme& op)const;

	virtual bool operator != (const Forme& op)const;

	virtual operator string()const;

	virtual void affiche(ostream& os = cout)
	{
		os << (*this);
	}

	virtual void translation(const Vecteur2D& op) = 0;

	virtual void homothetie(const Vecteur2D& op, double r) = 0;

	virtual void rotation(const Vecteur2D& op, double angle) = 0;

	virtual const double getAire() const = 0;

	virtual Forme* clone() const = 0;

	friend ostream& operator << (ostream& os, const Forme& op)
	{
		os << (string)op;
		return os;
	}
};

