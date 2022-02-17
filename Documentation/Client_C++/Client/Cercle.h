/**
* \file Cercle.h
* \brief Un Cercle est une forme g�om�trique compos�e d'un point centrale et d'un rayon.
* \detail C'est une des 4 formes g�om�triques disponible par d�faut dans le sujet.
*/
#pragma once
#include "Exception.h"
#include "Vecteur2D.h"
#include "Forme.h"


class Cercle :public Forme
{
	Vecteur2D _centre; ///< Le centre du cercle.
	double _rayon; ///< Le rayon du cercle.

public:
	/**
	 * \brief Constructeur.
	 * \param op Vecteur2D Le centre du cercle.
	 * \param rayon double Le rayon du cercle.
	 * \param couleur string La couleur du cercle.
	 */
	Cercle(const Vecteur2D& op, double rayon, const string& couleur = BLACK);

	/**
	 * \brief Constructeur par recopie.
	 * \param op Cercle Une instance du cercle � copier.
	 */
	Cercle(const Cercle& op);

	/**
	 * \brief Destructeur.
	 */
	~Cercle(){}

	/**
	 * \brief Getter du centre du cercle.
	 * \return Vecteur2D
	 */
	const Vecteur2D& getCentre()const { return _centre; }

	/**
	 * \brief Setter du centre du cercle.
	 * \param centre Vecteur2D Le nouveau centre.
	 */
	void setCentre(const Vecteur2D& centre) { _centre = centre; }

	/**
	 * \brief Getter du rayon du cercle.
	 * \return double Le rayon.
	 */
	double getRayon()const { return _rayon; }

	/**
	 * \brief Setter du rayon du cercle.
	 * \param rayon double Le nouveau rayon.
	 */
	void setRayon(double rayon)
	{
		if (rayon <= 0)
		{
			throw Exception("Impossible de construire un cercle avec ce rayon.");
		}
		else
		{
			_rayon = rayon;
		}
	}

	/**
	 * \brief Surcharge de l'op�rateur =.
	 * \detail Affectation par recopie d'un vecteur pass� en param�tre.
	 * \param op Cercle Le cercle � copier.
	 * \return Cercle
	 */
	const Cercle& operator = (const Cercle& op);

	/**
	 * \brief Surcharge de l'op�rateur ==.
	 * \detail Compare l'instance avec le vecteur pass� en param�tre.
	 * \param op Cercle 
	 * \return bool
	 */
	bool operator == (const Cercle& op)const;

	/**
	 * \brief Surcharge de l'op�rateur !=.
	 * \detail V�rifie si l'instance et le vecteur pass� en param�tre sont �gaux.
	 * \param op Cercle
	 * \return bool
	 */
	bool operator != (const Cercle& op)const;

	/**
	 * \brief Surchage de l'op�rateur string.
	 */
	operator string()const;

	/**
	 * \brief Getter de l'aire du cercle.
	 * \return double L'aire du cercle.
	 */
	const double getAire()const;

	/**
	 * \brief Clone l'instance courante du cercle.
	 * \return Cercle* Un pointeur sur une nouvelle instance d'un cercle.
	 * \detail Il s'agit d'une allocation dynamique (new).
	 */
	Cercle* clone() const;

	void accepte(const Visiteur& op);

	/**
	 * \brief Surcharge de l'op�rateur <<.
	 * \detail Modifie l'affichage du flux (g�n�ralement cout).
	 * \param os ostream
	 * \param op Cercle
	 * \return ostream Le flux d'entr�e modifi�.
	 */
	friend ostream& operator << (ostream& os, const Cercle& op);
};
