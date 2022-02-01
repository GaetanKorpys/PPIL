/**
* \file VisiteurTransformation.h
* \brief L'application offre la possibilit� d'appliquer trois sortes de transformations g�om�triques aux formes : translation, homoth�tie et rotation.
* \detail 
*/
#pragma once
#include "Forme.h"
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"

class VisiteurTransformation
{
public:

	virtual Segment& visite(Segment& op)const = 0;

	virtual Cercle& visite(Cercle& op)const = 0;

	virtual Triangle& visite(Triangle& op)const = 0;

	virtual Polygone& visite(Polygone& op)const = 0;
	
};
