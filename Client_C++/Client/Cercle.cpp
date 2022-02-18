#include "Cercle.h"
#include "Constante.h"
#include "Visiteur.h"

Cercle::Cercle(const Vecteur2D& centre, double rayon, const string& couleur) : Forme(couleur)
{
	if (rayon <= 0)
	{
		throw Exception("Impossible de construire un cercle avec ce rayon.");
	}
	else
	{
		_centre = centre;
		_rayon = rayon;
	}
}

Cercle::Cercle(const Cercle& op) : Forme(op.getCouleur(), op.getGroupe())
{
	if (op._rayon <= 0)
	{
		throw Exception("Impossible de construire un cercle avec ce rayon.");
	}
	else
	{
		_centre = op._centre;
		_rayon = op._rayon;
	}
}

const Cercle& Cercle::operator = (const Cercle& op)
{
	if (this != &op)
	{
		_centre = op._centre;
		_rayon = op._rayon;
		Forme::operator=(op);
	}
	return *this;
}

bool Cercle::operator == (const Cercle& op)const
{
	return (_centre == op._centre) && (_rayon == op._rayon) && Forme::operator==(op);
}

bool Cercle::operator != (const Cercle& op)const
{
	return !(*this == op);
}

Cercle::operator string()const
{
	ostringstream os;
	os << "Cercle [ "
		<< "Centre : " << _centre << ", "
		<< "Rayon: " << _rayon << ", "
		<< Forme::operator string() << ", "
		<< "Aire : " << getAire()
		<< " ] " << endl;
	return os.str();
}

const double Cercle::getAire()const
{
	return _rayon * _rayon * PI;
}

Cercle* Cercle::clone() const
{
	return new Cercle(*this);
}


void Cercle::accepte(const Visiteur& op)
{
	op.visite(*this);
}

ostream& operator << (ostream& os, const Cercle& op)
{
	os << (string)op;
	return os;
}
