#pragma once
#include "Visiteur.h"

class VisiteurTranslation : public Visiteur
{

	Vecteur2D _op;

public:
	/**
	 * \brief Constructeur
	 * \param op Vecteur2D
	 */
	VisiteurTranslation(const Vecteur2D& op)
	{
		_op = op;
	}


	/**
	* \brief Translation d'un segment
	* \param op Segment
	*/
	virtual void visite(Segment& op)const;

	/**
	* \brief Translation d'un cercle
	* \param op Cercle
	*/
	virtual void visite(Cercle& op)const;

	/**
	* \brief Translation d'un triangle
	* \param op Triangle
	*/
	virtual void visite(Triangle& op)const;

	/**
	* \brief Translation d'un polygone
	* \param op Polygone
	*/
	virtual void visite(Polygone& op)const;

	/**
	* \brief Translation d'un groupe
	* \param op Groupe
	*/
	virtual void visite(Groupe& op)const;

};