#include "Groupe.h"

void Groupe::copie(const vector<Forme *>& op)
{
	for (int i = 0; i < op.size(); i++)
	{
		_listeFormes.push_back(op[i]->clone());
	}
}

Groupe::Groupe(const Groupe& op):Forme(op.getCouleur())
{
	copie(op._listeFormes);
}

Groupe::~Groupe()
{
	for (std::vector<Forme *>::iterator it = _listeFormes.begin(); it != _listeFormes.end(); it++)
		delete *it;
}

int Groupe::getNbForme()const
{
	return _listeFormes.size();
}

const Forme& Groupe::getForme(int index)const
{
	return *_listeFormes[index];
}

const Groupe& Groupe::operator = (const Groupe& op)
{
	if (this != &op)
	{
		copie(op._listeFormes);
		Forme::operator=(op);
	}
	return *this;
}

bool Groupe::operator == (const Groupe& op)const
{
	if (op._listeFormes.size() != _listeFormes.size() || op.getCouleur() != getCouleur())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < op._listeFormes.size(); i++)
		{
			if (op._listeFormes[i] != _listeFormes[i])
				return false;
		}
		return true;
	}
}

bool Groupe::operator != (const Groupe& op)const
{
	return !(*this == op);
}

void Groupe::operator + (const Forme& op)
{
	if(op.getGroupe())
	{
		throw Exception("La forme appartient déjà à un groupe.");
	}
	Forme* tmp = op.clone();
	tmp->setCouleur(getCouleur());
	tmp->setGroupe(true);
	_listeFormes.push_back(tmp);
}

void Groupe::operator - (int index)
{
	if (index < 0 || index > _listeFormes.size())
	{
		throw Exception("Index incorrect.");
	}
	_listeFormes.erase(_listeFormes.begin() + index);
}

const Forme& Groupe::operator[](int index)const
{
	if (index < 0 || index > _listeFormes.size())
	{
		throw Exception("Index incorrect.");
	}
	else
	{
		return *_listeFormes[index];
	}
}

void Groupe::ajouter(const Forme& op)
{
	operator+(op);
}

void Groupe::supprimer(int index)
{
	operator-(index);
}

Groupe::operator string()const
{
	ostringstream os;
	os << "Groupe [ ";

	for (int i = 0; i < _listeFormes.size(); i++)
	{
		os << "Forme " << i << " : " << *_listeFormes[i];
	}
	os << Forme::operator string() << ", " << "Aire : " << getAire() << " ] " << endl << endl;
	return os.str();
}

void Groupe::translation(const Vecteur2D& op)
{
	for (int i = 0; i < _listeFormes.size(); i++)
		_listeFormes[i]->translation(op);
}

void Groupe::homothetie(const Vecteur2D& op, double r)
{
	for (int i = 0; i < _listeFormes.size(); i++)
		_listeFormes[i]->homothetie(op, r);
}

void Groupe::rotation(const Vecteur2D& op, double angle)
{
	for(int i = 0; i < _listeFormes.size(); i++)
		_listeFormes[i]->rotation(op, angle);
}

const double Groupe::getAire()const
{
	double aire = 0;
	for(int i = 0; i < _listeFormes.size(); i++)
	{
		aire += _listeFormes[i]->getAire();
	}
	return aire;
}

Groupe* Groupe::clone() const
{
	return new Groupe(*this);
}

ostream& operator << (ostream& os, const Groupe& op)
{
	os << (string)op;
	return os;
}