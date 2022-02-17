#include "Triangle.h"

#include "Visiteur.h"

Triangle::Triangle(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3, const string& couleur) :Forme(couleur)
{
	if (triangleValide(p1, p2, p3))
	{
		_p1 = p1;
		_p2 = p2;
		_p3 = p3;
	}
	else {
		throw Exception("Impossible de construire le triangle avec ces points.");
	}
}

Triangle::Triangle(const Triangle& op): Forme(op.getCouleur())
{
	_p1 = op._p1;
	_p2 = op._p2;
	_p3 = op._p3;
}

void Triangle::setP1(const Vecteur2D& op)
{
	if (triangleValide(op, _p2, _p3))
	{
		_p1 = op;
	}
	else
	{ 
		throw Exception("Le point P1 n'est pas valide."); 
	}
	
}

void Triangle::setP2(const Vecteur2D& op)
{
	if (triangleValide(_p1, op, _p3))
	{
		_p2 = op;
	}
	else
	{
		throw Exception("Le point P2 n'est pas valide.");
	}
}

void Triangle::setP3(const Vecteur2D& op)
{
	if (triangleValide(_p1, _p2, op))
	{
		_p3 = op;
	}
	else 
	{
		throw Exception("Le point P3 n'est pas valide.");
	}
}

const Vecteur2D& Triangle::getCentreGravite()const
{
	Vecteur2D tmp;
	tmp.setX((getP1().getX() + getP2().getX() + getP3().getX()) / 3);
	tmp.setY((getP1().getY() + getP2().getY() + getP3().getY()) / 3);
	return tmp;
}

const Triangle& Triangle::operator = (const Triangle& op)
{
	if (this != &op)
	{
		_p1 = op._p1;
		_p2 = op._p2;
		_p3 = op._p3;
		Forme::operator=(op);
	}
	return *this;
}

bool Triangle::operator == (const Triangle& op)const
{
	return (_p1 == op._p1) && (_p2 == op._p2) && (_p3 == op._p3) && Forme::operator==(op);
}

bool Triangle::operator != (const Triangle& op)const
{
	return !(*this == op);
}

Triangle::operator string()const
{
	ostringstream os;
	os << "Triangle [ "
		<< "Point 1 : " << _p1 << ", "
		<< "Point 2 : " << _p2 << ", "
		<< "Point 3 : " << _p3 << ", "
		<< Forme::operator string() << ", "
		<< "Aire : " << getAire()
		<< " ] " << endl;
	return os.str();
}

const double Triangle::getAire()const
{
	double tmp = _p1.determinant(_p2);
	tmp += _p2.determinant(_p3);
	tmp += _p3.determinant(_p1);
	return 0.5 * fabs(tmp);
}

Triangle* Triangle::clone() const
{
	return new Triangle(*this);
}

void Triangle::accepte(const Visiteur& op)
{
	op.visite(*this);
}

ostream& operator << (ostream& os, const Triangle& op)
{
	os << (string)op;
	return os;
}