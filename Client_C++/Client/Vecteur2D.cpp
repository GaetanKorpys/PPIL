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

inline const Vecteur2D operator *(const double& a, const Vecteur2D& u)
{
	return u * a;
}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D& u) const
{
	return Vecteur2D(_abscisse + u._abscisse, _ordonnee + u._ordonnee);
}

inline const Vecteur2D Vecteur2D::operator * (const double& a) const
{
	return Vecteur2D(_abscisse * a, _ordonnee * a);
}

inline const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-_abscisse, -_ordonnee);
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

Vecteur2D& Vecteur2D::translation(const Vecteur2D& op)
{
	*this += op;
	return *this;
}

Vecteur2D& Vecteur2D::homothetie(const Vecteur2D& op, double r)
{
	if(r<=0)
	{
		throw Exception("r doit être psoitif.");
	}
	(*this) = r * (*this) + (1 - r) * op;
	return *this;
}

Vecteur2D& Vecteur2D::rotation(const Vecteur2D& op, double angle)
{
	double deltaX = _abscisse - op._abscisse, deltaY = _ordonnee - op._ordonnee;
	_abscisse = deltaX * cos(angle) - deltaY * sin(angle) + op._abscisse;
	_ordonnee = deltaX * sin(angle) + deltaY * cos(angle) + op._ordonnee;

	return *this;
}