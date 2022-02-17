/**
* \file Segment.h
* \brief Un segment est une forme géométrique composé de 2 points ( C'est une droite finie ).
* \detail C'est une des 4 formes géométriques disponible par défaut dans le sujet.
*/

#pragma once
#include "Constante.h"
#include "Exception.h"
#include "Vecteur2D.h"
#include "Forme.h"

using namespace std;

class Segment : public Forme
{
	Vecteur2D _p1; ///< Le 1er point (Vecteur2D) qui compose le segment.
	Vecteur2D _p2; ///< Le 2scd point (Vecteur2D) qui compose le segment.

	/**
	 * \brief Vérifie si un segment est valide.
	 * \param p1 Vecteur2D Le 1er point.
	 * \param p2 Vecteur2D Le 2scd point.
	 * \return bool
	 */
	bool segmentValide(const Vecteur2D& p1, const Vecteur2D& p2)
	{
		if (p1 == p2)
			return false;
		return true;
	}

public:
	/**
	 * \brief Constructeur
	 * \param p1 Vecteur2D
	 * \param p2 Vecteur2D
	 * \param couleur string
	 */
	Segment(const Vecteur2D& p1, const Vecteur2D& p2, const string& couleur = BLACK);

	/**
	 * \brief Constructeur par recopie.
	 * \param op Segment Une instance du segment à copier.
	 */
	Segment(const Segment& op);

	/**
	 * \brief Destructeur.
	 */
	~Segment(){}

	/**
	 * \brief Getter du 1er Point.
	 * \return Vecteur2D
	 */
	const Vecteur2D& getP1()const { return _p1; }

	/**
	 * \brief Setter du 1er point.
	 * \param p1 Vecteur2D
	 */
	void setP1(const Vecteur2D& p1);

	/**
	 * \brief Getter du 2scd point.
	 * \return Vecteur2D
	 */
	const Vecteur2D getP2()const { return _p2; } 

	/**
	 * \brief Setter du 2scd point.
	 * \param p2 Vecteur2D
	 */
	void setP2(const Vecteur2D& p2);

	/**
	 * \brief Getter du centre de gravité.
	 * \return Vecteur2D Le centre de gravité
	 */
	virtual const Vecteur2D& getCentreGravite()const;

	/**
	 * \brief Surcharge de l'opérateur =.
	 * \detail Compare l'instance avec le vecteur passé en paramètre.
	 * \param op Segment
	 * \return bool
	 */
	const Segment& operator = (const Segment& op);

	/**
	 * \brief Surcharge de l'opérateur ==.
	 * \detail Compare l'instance avec le segment passé en paramètre.
	 * \param op Segment
	 * \return bool
	 */
	bool operator == (const Segment& op)const;

	/**
	 * \brief Surcharge de l'opérateur !=.
	 * \detail Vérifie si l'instance et le segment passé en paramètre sont égaux.
	 * \param op Segment
	 * \return bool
	 */
	bool operator != (const Segment& op)const;

	/**
	 * \brief Surchage de l'opérateur string.
	 */
	operator string()const;

	/**
	 * \brief Getter de l'aire du segment.
	 * \return double L'aire du segment.
	 */
	const double getAire()const;

	/**
	 * \brief Clone l'instance courante du segment.
	 * \return Segment* Un pointeur sur une nouvelle instance d'un segment.
	 * \detail Il s'agit d'une allocation dynamique (new).
	 */
	Segment* clone() const;

	void accepte(const Visiteur& op);

	/**
	 * \brief Surcharge de l'opérateur <<.
	 * \detail Modifie l'affichage du flux (généralement cout).
	 * \param os ostream
	 * \param op Segment
	 * \return ostream Le flux d'entrée modifié.
	 */
	friend ostream& operator << (ostream& os, const Segment& op);
};