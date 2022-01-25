#include "Forme.h"

const Forme& Forme::operator = (const Forme& op)
{
	if (&op != this) {
		_couleur = op._couleur;
		_groupe = op._groupe;
	}
	return *this;
}

bool Forme::operator == (const Forme& op)const
{
	return (_couleur == op._couleur) && (_groupe == op._groupe);
}

bool Forme::operator != (const Forme& op)const
{
	return !(*this == op);
}

Forme::operator string()const
{
	string tmp = "Oui";
	if (!getGroupe())
		tmp = "Non";

	ostringstream oss;
	oss << "Couleur = " << _couleur << ", "
		<< "Groupe = " << tmp;
	return oss.str();
}


