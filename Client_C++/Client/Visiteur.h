#pragma once
#include "Forme.h"
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"

class Visiteur
{
public:

	/**
	* \brief M�thode virtuelle pure, va �tre appel�e par un segment
	*/
	virtual void visite(Segment& op)const = 0;

	/**
	* \brief M�thode virtuelle pure, va �tre appel�e par un triangle
	*/
	virtual void visite(Triangle& op)const = 0;

	/**
	* \brief M�thode virtuelle pure, va �tre appel�e par un cercle
	*/
	virtual void visite(Cercle& op)const = 0;

	/**
	* \brief M�thode virtuelle pure, va �tre appel�e par un polygone
	*/
	virtual void visite(Polygone& op)const = 0;

	/**
	* \brief M�thode virtuelle pure, va �tre appel�e par un groupe
	*/
	virtual void visite(Groupe& op)const = 0;
};