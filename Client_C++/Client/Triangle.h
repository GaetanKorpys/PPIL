/**
* \file Triangle.h
* \brief Un triangle est une forme géométrique composé de 3 points.
* \detail C'est une des 4 formes géométriques disponible par défaut dans le sujet.
*/
#pragma once
#include "Exception.h"
#include "Vecteur2D.h"
#include "Forme.h"


using namespace std;

class Triangle : public Forme
{
	Vecteur2D _p1; ///< Le 1er point (Vecteur2D) qui compose le triangle.
	Vecteur2D _p2; ///< Le 2scd point (Vecteur2D) qui compose le triangle.
	Vecteur2D _p3; ///< Le 3ème point (Vecteur2D) qui compose le triangle.

	/**
	 * \brief Vérifie si un triangle est valide.
	 * \param p1 Vecteur2D Le 1er point.
	 * \param p2 Vecteur2D Le 2scd point.
	 * \return bool
	 */
	bool triangleValide(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3)
	{
		if( (p1 == p2) || (p1 == p3) || (p2 == p3) )
			return false;
		return true;
	}

public:
	/**
	 * \brief Constructeur
	 * \param p1 Vecteur2D
	 * \param p2 Vecteur2D
	 * \param p3 Vecteur2D
	 * \param couleur string
	 */
	Triangle(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3, const string& couleur = BLACK);

	/**
	 * \brief Constructeur par recopie.
	 * \param op Segment Une instance du triangle à copier.
	 */
	Triangle(const Triangle& op);

	/**
	 * \brief Destructeur.
	 */
	~Triangle(){}

	/**
	 * \brief Getter du 1er Point.
	 * \return Vecteur2D
	 */
	const Vecteur2D& getP1()const
	{
		return _p1;
	}

	/**
	 * \brief Setter du 1er point.
	 * \param op Vecteur2D
	 */
	void setP1(const Vecteur2D& op);

	/**
	 * \brief Getter du 2scd Point.
	 * \return Vecteur2D
	 */
	const Vecteur2D& getP2()const
	{
		return _p2;
	}

	/**
	 * \brief Setter du 2scd point.
	 * \param op Vecteur2D
	 */
	void setP2(const Vecteur2D& op);

	/**
	 * \brief Getter du 3eme Point.
	 * \return Vecteur2D
	 */
	const Vecteur2D& getP3()const
	{
		return _p3;
	}

	/**
	 * \brief Setter du 3eme point.
	 * \param op Vecteur2D
	 */
	void setP3(const Vecteur2D& op);

	/**
	 * \brief Surcharge de l'opérateur d'affectation.
	 * \detail Affectation par recopie d'un triangle passé en paramètre.
	 * \param op Triangle
	 * \return Triangle Une référence de l'instance.
	 */
	const Triangle& operator = (const Triangle& op);

	/**
	 * \brief Surcharge de l'opérateur ==.
	 * \detail Compare l'instance avec le triangle passé en paramètre.
	 * \param op Triangle
	 * \return bool
	 */
	bool operator == (const Triangle& op)const;

	/**
	 * \brief Surcharge de l'opérateur !=.
	 * \detail Vérifie si l'instance et le triangle passé en paramètre sont égaux.
	 * \param op Triangle
	 * \return bool
	 */
	bool operator != (const Triangle& op)const;

	/**
	 * \brief Surchage de l'opérateur string.
	 */
	operator string()const;

	/**
	 * \brief Getter de l'aire du triangle.
	 * \return double L'aire du triangle.
	 */
	const double getAire()const;

	/**
	 * \brief Clone l'instance courante du triangle.
	 * \return Triangle* Un pointeur sur une nouvelle instance d'un triangle.
	 * \detail Il s'agit d'une allocation dynamique (new).
	 */
	Triangle* clone() const;

	void accepte(const Visiteur& op);

	/**
	 * \brief Surcharge de l'opérateur <<.
	 * \detail Modifie l'affichage du flux (généralement cout).
	 * \param os ostream
	 * \param op Triangle
	 * \return ostream Le flux d'entrée modifié.
	 */
	friend ostream& operator << (ostream& os, const Triangle& op);
};
