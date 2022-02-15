#pragma once
#include "Visiteur.h"

class VisiteurRotation : public Visiteur
{

	Vecteur2D _op;
	double _angle;

public:
	/**
	 * \brief Constructeur
	 * \param op Vecteur2D
	 * \param angle double
	 */
	VisiteurRotation(const Vecteur2D& op, double angle)
	{
		if (angle < 0)
			throw Exception("Impossible de construre une Rotation avec un angle < 0.");
		_op = op;
		_angle = angle;
	}

	/**
	 * \brief Rotation d'un segment
	 * \param op Segment
	 */
	virtual void visite(Segment& op)const;

	/**
	 * \brief Rotation d'un cercle
	 * \param op Cercle
	 */
	virtual void visite(Cercle& op)const;

	/**
	 * \brief Rotation d'un triangle
	 * \param op Triangle
	 */
	virtual void visite(Triangle& op)const;

	/**
	 * \brief Rotation d'un polygone
	 * \param op Polygone
	 */
	virtual void visite(Polygone& op)const;

	/**
	 * \brief Rotation d'un groupe
	 * \param op Groupe
	 */
	virtual void visite(Groupe& op)const;
};