#pragma once
#include "Forme.h"
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"

class Visiteur
{
public:

	virtual void visite(Segment& op)const = 0;

	virtual void visite(Triangle& op)const = 0;

	virtual void visite(Cercle& op)const = 0;

	virtual void visite(Polygone& op)const = 0;

};