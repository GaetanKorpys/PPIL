#include "Vecteur2D.h"
#include "Exception.h"
#include <math.h>

Vecteur2D::Vecteur2D(const Vecteur2D& op)
{
	_abscisse = op.getX();
	_ordonnee = op.getY();
}

Vecteur2D::operator string() const
{
	ostringstream os;
	os << "(" << _abscisse << ", " << _ordonnee << ")";
	return os.str();
}


ostream& operator << (ostream& os, const Vecteur2D& op)
{
	os << (string)op;
	return os;
}

const Vecteur2D& Vecteur2D::operator =(const Vecteur2D& op)
{
	if (this != &op)
	{
		_abscisse = op.getX();
		_ordonnee = op.getY();
	}
	return *this;
}

bool Vecteur2D::operator ==(const Vecteur2D& op)const
{
	return (_abscisse == op.getX()) && (_ordonnee == op.getY());
}

bool Vecteur2D::operator !=(const Vecteur2D& op)const
{
	return !(*this == op);
}

const Vecteur2D& Vecteur2D::operator +=(const Vecteur2D& op)
{
	*this = *this + op;
	return *this;
}

double Vecteur2D::determinant(const Vecteur2D& op)const
{
	return (op.getY() * _abscisse) - (op.getX() * _ordonnee);
}

void Vecteur2D::translation(const Vecteur2D& op)
{
	*this += op;
}

void Vecteur2D::homothetie(const Vecteur2D& op, double r)
{
	if(r<=0)
	{
		throw Exception("r doit être psoitif.");
	}
	(*this) = r * (*this) + (1 - r) * op;

}

void Vecteur2D::rotation(double angle)
{
	double tempX = _abscisse;
	double tempY = _ordonnee;

	_abscisse = tempX * cos(angle) - tempY * sin(angle);
	_ordonnee = tempX * sin(angle) + tempY * cos(angle);
}