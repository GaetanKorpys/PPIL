/**
* \file Polygone.h
* \brief Un polygone est une forme géométrique composé d'au minimum 3 points.
* \detail C'est une des 4 formes géométriques disponible par défaut dans le sujet.
*/
#pragma once
#include "Exception.h"
#include "Constante.h"
#include "Vecteur2D.h"
#include "Forme.h"
#include <vector>

class Polygone : public Forme
{
	vector<Vecteur2D> _listePoints;

	bool polygoneValide(const vector<Vecteur2D>& op)const;

	void copie(const vector<Vecteur2D>& op);

public:

	Polygone(){}

	Polygone(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3, const string& couleur = BLACK);

	Polygone(const vector<Vecteur2D>& op, const string& couleur = BLACK);

	Polygone(const Polygone& op);

	~Polygone();

	int getNbPoints()const;

	const Vecteur2D& getPoint(int index)const;

	const Polygone& setPoint(int index, const Vecteur2D& op);

	const Polygone& operator = (const Polygone& op);

	bool operator == (const Polygone& op)const;

	bool operator != (const Polygone& op)const;

	void operator + (const Vecteur2D& op);

	void operator - (int index);

	const Vecteur2D& operator[](int index)const;

	void ajouter(const Vecteur2D& op);

	void supprimer(int index);

	operator string()const;

	void translation(const Vecteur2D& op);

	void homothetie(const Vecteur2D& op, double r);

	void rotation(const Vecteur2D& op, double angle);

	const double getAire()const;

	Polygone* clone() const;

	Polygone& accepte(const VisiteurTransformation& op);

	friend ostream& operator << (ostream& os, const Polygone& op);
};