/**
* \file Segment.h
* \brief Un segment est une forme g�om�trique compos� de 2 points ( C'est une droite finie ).
* \detail C'est une des 4 formes g�om�triques disponible par d�faut dans le sujet.
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
	 * \brief V�rifie si un segment est valide.
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
	 * \param op Segment Une instance du segment � copier.
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
	 * \brief Getter du centre de gravit�.
	 * \return Vecteur2D Le centre de gravit�
	 */
	virtual const Vecteur2D& getCentreGravite()const;

	/**
	 * \brief Surcharge de l'op�rateur =.
	 * \detail Compare l'instance avec le vecteur pass� en param�tre.
	 * \param op Segment
	 * \return bool
	 */
	const Segment& operator = (const Segment& op);

	/**
	 * \brief Surcharge de l'op�rateur ==.
	 * \detail Compare l'instance avec le segment pass� en param�tre.
	 * \param op Segment
	 * \return bool
	 */
	bool operator == (const Segment& op)const;

	/**
	 * \brief Surcharge de l'op�rateur !=.
	 * \detail V�rifie si l'instance et le segment pass� en param�tre sont �gaux.
	 * \param op Segment
	 * \return bool
	 */
	bool operator != (const Segment& op)const;

	/**
	 * \brief Surchage de l'op�rateur string.
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
	 * \brief Surcharge de l'op�rateur <<.
	 * \detail Modifie l'affichage du flux (g�n�ralement cout).
	 * \param os ostream
	 * \param op Segment
	 * \return ostream Le flux d'entr�e modifi�.
	 */
	friend ostream& operator << (ostream& os, const Segment& op);
};