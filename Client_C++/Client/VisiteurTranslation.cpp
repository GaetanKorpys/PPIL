#include "VisiteurTranslation.h"

Segment& VisiteurTranslation::visite(const Segment& op)
{
	Segment* tmp = new Segment(op);
}

Cercle& VisiteurTranslation::visite(const Cercle& op)
{
	Vecteur2D tmp = op.getCentre();
	tmp.translation(_op);
}

Triangle& VisiteurTranslation::visite(const Triangle& op)
{
	Vecteur2D tmp;

	tmp = op.getP1();
	tmp.translation(_op);

	tmp = op.getP2();
	tmp.translation(_op);

	tmp = op.getP3();
	tmp.translation(_op);

}

Polygone& VisiteurTranslation::visite(const Polygone& op)
{
	Vecteur2D tmp;
	for (int i = 0; i < op.getNbPoints(); i++)
	{
		tmp = op.getPoint(i);
		tmp.translation(_op);
	}
}
