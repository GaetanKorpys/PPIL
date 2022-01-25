/**
* \file Groupe.h
* \brief Un groupe est un ensemble de forme géométrique.
*/

#pragma once
#include "Forme.h"
#include "Exception.h"
#include <vector>

class Groupe :public Forme
{
	vector<Forme *> _listeFormes;

	void copie(const vector<Forme *>& op);

public:

	Groupe(){}

	Groupe(const Groupe& op);

	~Groupe();

	int getNbForme()const;

	const Forme& getForme(int index)const;

	const Groupe& operator = (const Groupe& op);

	bool operator == (const Groupe& op)const;

	bool operator != (const Groupe& op)const;

	void operator + (const Forme& op);

	void operator - (int index);

	const Forme& operator[](int index)const;

	void ajouter(const Forme& op);

	void supprimer(int index);

	operator string()const;

	void translation(const Vecteur2D& op);

	void homothetie(const Vecteur2D& op, double r);

	void rotation(const Vecteur2D& op, double angle);

	const double getAire()const;

	Groupe* clone() const;

	friend ostream& operator << (ostream& os, const Groupe& op);
};