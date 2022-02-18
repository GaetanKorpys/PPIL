#include "Polygone.h"
#include "Visiteur.h"

bool Polygone::polygoneValide(const vector<Vecteur2D*>& op)const
{
	for (int i = 0; i < op.size() - 1; i++) {
		for (int j = i + 1; j < op.size(); j++) {
			if (op[i] == op[j])
				return false;
		}
	}
	return true;
}

void Polygone::copie(const vector<Vecteur2D* >& op)
{
	for (int i = 0; i < op.size(); i++)
	{
		_listePoints.push_back(( * op[i]).clone());
	}
}

Polygone::Polygone(const string& couleur) :Forme(couleur){}

Polygone::Polygone(const vector<Vecteur2D*>& op, const string& couleur):Forme(couleur)
{
	copie(op);
}

Polygone::Polygone(const Polygone& op) : Forme(op.getCouleur(), op.getGroupe())
{
	copie(op._listePoints);
}

Polygone::~Polygone()
{
	for (int i = 0; i < _listePoints.size(); ++i) {
		delete _listePoints[i];
	}
}

int Polygone::getNbPoints()const
{
	return _listePoints.size();
}

const Vecteur2D& Polygone::getPoint(int index)const
{
	if (index < 0 || index > _listePoints.size())
	{
		throw Exception("Index incorrect.");
	}
	return *_listePoints[index];
}

const Polygone& Polygone::setPoint(int index, const Vecteur2D& op)
{
	if (index < 0 || index > _listePoints.size())
	{
		throw Exception("Index incorrect.");
	}
	(* _listePoints[index]) = op;
	return *this;
}

const Vecteur2D& Polygone::getCentreGravite()const
{
	Vecteur2D tmp;
	double x = 0;
	double y = 0;

	for(int i =0; i < _listePoints.size(); i++)
	{
		x += _listePoints[i]->getX();
		y += _listePoints[i]->getY();
	}
	tmp.setX(x / _listePoints.size());
	tmp.setY(y / _listePoints.size());
	return tmp;
}

const Polygone& Polygone::operator = (const Polygone& op)
{
	if (this != &op)
	{
		copie(op._listePoints);
		Forme::operator=(op);
	}
	return *this;
}

bool Polygone::operator == (const Polygone& op)const
{
	if(op._listePoints.size() != _listePoints.size() || op.getCouleur() != getCouleur())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < op._listePoints.size(); i++)
		{
			if (op._listePoints[i] != _listePoints[i])
				return false;
		}
		return true;
	}
}

bool Polygone::operator != (const Polygone& op)const
{
	return !(*this == op);
}

void Polygone::operator + (const Vecteur2D& op)
{
	Vecteur2D* tmp = op.clone();
	_listePoints.push_back(tmp);
}

void Polygone::operator - (int index)
{
	if(index < 0 || index > _listePoints.size())
	{
		throw Exception("Index incorrect.");
	}
	_listePoints.erase(_listePoints.begin()+index);
}


const Vecteur2D& Polygone::operator[](int index)const
{
	if (index < 0 || index > _listePoints.size())
	{
		throw Exception("Index incorrect.");
	}
	else
	{
		return ( * _listePoints[index]);
	}
}

void Polygone::ajouter(const Vecteur2D& op)
{
	operator+(op);
}

void Polygone::supprimer(int index)
{
	operator-(index);
}

Polygone::operator string()const
{
	ostringstream os;
	os << "Polygone [ ";

	for(int i = 0; i < _listePoints.size(); i++)
	{
		os << "Points " << i << " : " << *_listePoints[i];
	}
	os << Forme::operator string() << ", " << "Aire : " << getAire() << " ] " << endl;
	return os.str();
}

const double Polygone::getAire()const
{
	if (_listePoints.size() < 3)
		return 0;

	double somme = ( * _listePoints[_listePoints.size() - 1]).determinant(*_listePoints[0]);
	for (int i = 0; i < _listePoints.size() - 1; i++)
		somme += ( * _listePoints[i]).determinant(*_listePoints[i + 1]);
	return 0.5 * fabs(somme);
	
} 

Polygone* Polygone::clone() const
{
	return new Polygone(*this);
}

void Polygone::accepte(const Visiteur& op)
{
	op.visite(*this);
}

ostream& operator << (ostream& os, const Polygone& op)
{
	os << (string)op;
	return os;
}
