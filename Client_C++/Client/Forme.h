/**
* \file Forme.h
* \brief Une forme est caract�ris�e par une couleur et des points.
* \detail Il existe 2 types de formes, les simples (Segment, Triangle ...) et les compos�es.
* \detail Une forme compos�e aussi appel�e Groupe est un ensemble de forme simple et de forme compos�e.
*/

#pragma once
#include "Constante.h"
#include "Vecteur2D.h"
#include <iostream>

using namespace std;

class Visiteur;

class Forme
{
	string _couleur; ///< La couleur de la forme g�om�trique.
	bool _groupe; ///< Si la forme appartient � un groupe.

public :
	/**
	 * \brief Constructeur par d�faut.
	 */
	Forme() 
	{
		_couleur = BLACK;
		_groupe = false;
	}

	/**
	 * \brief Constrcuteur.
	 * \param couleur string La couleur de la forme.
	 */
	Forme(const string& couleur) 
	{ 
		_couleur = couleur; 
		_groupe = false;
	}

	/**
	 * \brief Constructeur par recopie.
	 * \param op Forme Une instance de la forme � copier.
	 */
	Forme(const Forme& op) 
	{
		_couleur = op._couleur; 
		_groupe = op._groupe;
	}

	/**
	 * \brief Destructeur.
	 */
	virtual ~Forme(){}

	/**
	 * \brief Getter de la couleur.
	 * \return string La couleur de la forme.
	 */
	string getCouleur()const { return _couleur; }

	/**
	 * \brief Setter de la couleur.
	 * \param couleur string La nouvelle couleur.
	 */
	void setCouleur(const string& couleur) { _couleur = couleur; }

	/**
	 * \brief Getter de l'appartenance � un groupe.
	 * \return bool
	 */
	bool getGroupe()const { return _groupe; }

	/**
	 * \brief Setter de l'appartenance � un groupe.
	 * \param groupe bool 
	 */
	void setGroupe(bool groupe) { _groupe = groupe; }

	/**
	 * \brief Surcharge de l'op�rateur =.
	 * \detail Affectation par recopie d'une forme pass�e en param�tre.
	 * \param op Forme La forme � copier.
	 * \return Forme
	 */
	virtual const Forme& operator = (const Forme& op);

	/**
	 * \brief Surcharge de l'op�rateur ==.
	 * \detail Compare l'instance avec la forme pass�e en param�tre.
	 * \param op Forme
	 * \return bool
	 */
	virtual bool operator == (const Forme& op)const;

	/**
	 * \brief Surcharge de l'op�rateur !=.
	 * \detail V�rifie si l'instance et la forme pass�e en param�tre sont �gaux.
	 * \param op Forme
	 * \return bool
	 */
	virtual bool operator != (const Forme& op)const;

	/**
	 * \brief Surchage de l'op�rateur string.
	 */
	virtual operator string()const;

	/**
	 * \brief Affiche une forme dans le flux pass� en param�tre.
	 * \detail Par d�faut le flux de sortie est cout.
	 * \param os ostream Le flux de sortie.
	 */
	virtual void affiche(ostream& os = cout)
	{
		os << (*this);
	}

	/**
	 * \brief Getter de l'aire du cercle.
	 * \return double L'aire du cercle.
	 */
	virtual const double getAire() const = 0;

	/**
	 * \brief Clone l'instance courante de la forme.
	 * \return Forme* Un pointeur sur une nouvelle instance d'une forme.
	 * \detail Il s'agit d'une allocation dynamique (new).
	 */
	virtual Forme* clone() const = 0;

	/**
	 * \brief M�thode du DP Visiteur.
	 * \detail Lance la m�thode visite du visiteur pass� en param�tre, celle-ci effectue un traitement sur l'instance en cours.
	 * \param op Visiteur La classe m�re du DP Visiteur
	 */
	virtual void accepte(const Visiteur& op) = 0;

	/**
	 * \brief Surcharge de l'op�rateur <<.
	 * \detail Modifie l'affichage du flux (g�n�ralement cout).
	 * \param os ostream
	 * \param op Forme
	 * \return ostream Le flux d'entr�e modifi�.
	 */
	friend ostream& operator << (ostream& os, const Forme& op)
	{
		os << (string)op;
		return os;
	}
};

