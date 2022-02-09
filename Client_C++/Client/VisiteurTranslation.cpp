#include "VisiteurTranslation.h"

void VisiteurTranslation::visite(Segment& op)const
{
	Vecteur2D tmpVecteur;

	tmpVecteur = op.getP1();
	op.setP1(tmpVecteur.translation(_op));

	tmpVecteur = op.getP2();
	op.setP2(tmpVecteur.translation(_op));

}

void VisiteurTranslation::visite(Cercle& op)const
{
	Vecteur2D tmpVecteur = op.getCentre();
	op.setCentre(tmpVecteur.translation(_op));

}

void VisiteurTranslation::visite(Triangle& op)const
{
	Vecteur2D tmpVecteur;

	tmpVecteur = op.getP1();
	op.setP1(tmpVecteur.translation(_op));

	tmpVecteur = op.getP2();
	op.setP2(tmpVecteur.translation(_op));

	tmpVecteur = op.getP3();
	op.setP3(tmpVecteur.translation(_op));

}

void VisiteurTranslation::visite(Polygone& op)const
{
	Vecteur2D tmpVecteur;

	for (int i = 0; i < op.getNbPoints(); i++)
	{
		tmpVecteur = op.getPoint(i);
		tmpVecteur.translation(_op);
		op.setPoint(i, tmpVecteur);
	}
 
}

void VisiteurTranslation::visite(Groupe& op)const
{
	for (int i = 0; i < op.getNbForme(); i++)
	{
		op[i].accepte(*this);
	}
}