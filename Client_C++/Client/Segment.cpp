#include "Segment.h"

#include "Visiteur.h"

Segment::Segment(const Vecteur2D& p1, const Vecteur2D& p2,const string& couleur ):Forme(couleur)
{
	if (segmentValide(p1, p2))
	{
		_p1 = p1;
		_p2 = p2;
	}
	else
	{
		throw Exception("Impossible de construire le segment avec ces 2 points.");
	}
}

Segment::Segment(const Segment& op) :Forme(op.getCouleur())
{
	_p1 = op._p1;
	_p2 = op._p2;
}

void Segment::setP1(const Vecteur2D& p1)
{
	if (segmentValide(p1, _p2))
	{
		_p1 = p1;
	}
	else
	{
		throw Exception("Le point P1 n'est pas valide.");
	}
}

void Segment::setP2(const Vecteur2D& p2)
{
	if (segmentValide(_p1, p2))
	{
		_p2 = p2;
	}
	else
	{
		throw Exception("Le point P2 n'est pas valide.");
	}
}

const Segment& Segment::operator = (const Segment& op)
{
	if (this != &op)
	{
		_p1 = op._p1;
		_p2 = op._p2;
		Forme::operator=(op);
	}
	return *this;
}

bool Segment::operator == (const Segment& op)const
{
	return (_p1 == op._p1) && (_p2 == op._p2) && Forme::operator==(op);
}

bool Segment::operator != (const Segment& op)const
{
	return !(*this == op);
}

Segment::operator string()const
{
	ostringstream os;
	os << "Segment [ "
		<< "Point 1 : " << _p1 << ", "
		<< "Point 2 : " << _p2 << ", "
		<< Forme::operator string() << ", "
		<< "Aire : " << getAire()
		<< " ] " << endl << endl;
	return os.str();
}

const double Segment::getAire()const
{
	return 0;
}

Segment* Segment::clone() const
{
	return new Segment(*this);
}

void Segment::accepte(const Visiteur& op)
{
	op.visite(*this);
}

ostream& operator << (ostream& os, const Segment& op)
{
	os << (string)op;
	return os;
}


