#pragma once
#include "Visiteur.h"

class VisiteurHomothetie : public Visiteur
{

	Vecteur2D _op;
	double _rapport;

public:
	/**
	 * \brief Constructeur
	 * \param op Vecteur2D
	 * \param r double
	 */
	VisiteurHomothetie(const Vecteur2D& op, double r)
	{
		if (r < 0)
			throw Exception("Impossible de construire une Homothétie avec un rapport < 0.");
		_op = op;
		_rapport = r;
	}

	/**
	 * \brief Homothétie d'un segment
	 * \param op Segment
	 */
	virtual void visite(Segment& op)const;

	/**
	 * \brief Homothétie d'un triangle
	 * \param op Triangle
	 */
	virtual void visite(Triangle& op)const;

	/**
	 * \brief Homothétie d'un cercle
	 * \param op Cercle
	 */
	virtual void visite(Cercle& op)const;

	/**
	 * \brief Homothétie d'un polygone
	 * \param op Polygone
	 */
	virtual void visite(Polygone& op)const;

	/**
	 * \brief Homothétie d'un groupe
	 * \param op Groupe
	 */
	virtual void visite(Groupe& op)const;

};
