#include "VisiteurHomothetie.h"

void VisiteurHomothetie::visite(Segment& op)const
{
	Vecteur2D tmpVecteur;

	tmpVecteur = op.getP1();
	op.setP1(tmpVecteur.homothetie(_op, _rapport));

	tmpVecteur = op.getP2();
	op.setP2(tmpVecteur.homothetie(_op, _rapport));

}

void VisiteurHomothetie::visite(Cercle& op)const
{
	Vecteur2D tmpVecteur = op.getCentre();
	op.setCentre(tmpVecteur.homothetie(_op, _rapport));
}

void VisiteurHomothetie::visite(Triangle& op)const
{
	Vecteur2D tmpVecteur;

	tmpVecteur = op.getP1();
	op.setP1(tmpVecteur.homothetie(_op, _rapport));

	tmpVecteur = op.getP2();
	op.setP2(tmpVecteur.homothetie(_op, _rapport));

	tmpVecteur = op.getP3();
	op.setP3(tmpVecteur.homothetie(_op, _rapport));

}

void VisiteurHomothetie::visite(Polygone& op)const
{
	Vecteur2D tmpVecteur;

	for (int i = 0; i < op.getNbPoints(); i++)
	{
		tmpVecteur = op.getPoint(i);
		tmpVecteur.homothetie(_op, _rapport);
		op.setPoint(i, tmpVecteur);
	}
}

void VisiteurHomothetie::visite(Groupe& op)const
{
	for(int i = 0; i < op.getNbForme(); i++)
	{
		op[i].accepte(*this);
	}
}