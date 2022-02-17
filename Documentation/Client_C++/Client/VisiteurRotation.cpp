#include "VisiteurRotation.h"

void VisiteurRotation::visite(Segment& op)const
{
	Vecteur2D tmpVecteur;

	tmpVecteur = op.getP1();
	op.setP1(tmpVecteur.rotation(_op, _angle));

	tmpVecteur = op.getP2();
	op.setP2(tmpVecteur.rotation(_op, _angle));

}

void VisiteurRotation::visite(Cercle& op)const
{
	Vecteur2D tmpVecteur = op.getCentre();

	op.setCentre(tmpVecteur.rotation(_op, _angle));

}

void VisiteurRotation::visite(Triangle& op)const
{
	Vecteur2D tmpVecteur;

	tmpVecteur = op.getP1();
	op.setP1(tmpVecteur.rotation(_op, _angle));

	tmpVecteur = op.getP2();
	op.setP2(tmpVecteur.rotation(_op, _angle));

	tmpVecteur = op.getP3();
	op.setP3(tmpVecteur.rotation(_op, _angle));

}

void VisiteurRotation::visite(Polygone& op)const
{
	Vecteur2D tmpVecteur;

	for (int i = 0; i < op.getNbPoints(); i++)
	{
		tmpVecteur = op.getPoint(i);
		tmpVecteur.rotation(_op, _angle);
		op.setPoint(i, tmpVecteur);
	}
}

void VisiteurRotation::visite(Groupe& op)const
{
	for (int i = 0; i < op.getNbForme(); i++)
	{
		op[i].accepte(*this);
	}
}
