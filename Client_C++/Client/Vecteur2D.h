/**
* \file Vecteur2D.h
* \brief Un vecteur peut être considéré comme un vecteur ou un point du plan, c'est un couple (x,y) de coordonnées réelles.
*/

#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/**
 * \brief Surcharge de l'opérateur (-).
 * \detail Définition du template. Il permet d'utiliser une variable dont le type n'est pas connu lors de la compilation.
 * \param u T (type générique).
 * \param v T (type générique).
 * \return u + (-v).
 */

template <class T>
const T operator-(const T& u, const T& v) {
	return u + -v;
}

class Vecteur2D
{
	double _abscisse; ///< L'abscisse du vecteur.
	double _ordonnee; ///< L'ordonnée du vecteur.

public:

	/**
	 * \brief Destructeur.
	 */
	inline virtual ~Vecteur2D();

	/**
	 * \brief Constructeur avec un couple de coordonnées (x,y).
	 * \detail Par défaut, les coordonnées sont affectées à 0.
	 * \param x double.
	 * \param y double.
	 */
	inline explicit Vecteur2D(const double& x = 0, const double& y = 0);

	/**
	 * \brief Constructeur par recopie.
	 * \param op Vecteur2D
	 */
	Vecteur2D(const Vecteur2D& op);

	/**
	 * \brief Getter du membre privé _abscisse.
	 * \return double L'abscisse du vecteur.
	 */
	inline double getX()const;

	/**
	 * \brief Setter du membre privé _abscisse.
	 * \param x const double.
	 * \return Vecteur2D Une référence sur l'instance modifiée.
	 */
	inline void setX(const double x);

	/**
	 * \brief Getter du membre privé __ordonnee.
	 * \return double L'ordonné du vecteur.
	 */
	inline double getY()const;

	/**
	 * \brief Setter du membre privé _ordonnee
	 * \param y const double.
	 * \return Vecteur2D Une référence sur l'instance modifiée.
	 */
	inline void setY(const double y);

	/**
	 * \brief Surcharge de l'opérateur addition (+).
	 * \param u const Vecteur2D
	 * \return Vecteur2D Une copie du résultat.
	 */
	inline const Vecteur2D operator + (const Vecteur2D& u) const;

	/**
	 * \brief Surchage de l'opérateur multiplication (*).
	 * \detail Muiltiplication par un réel.
	 * \param a const double. 
	 * \return Vecteur2D Une copie du résultat.
	 */
	inline const Vecteur2D operator * (const double& r) const;

	/**
	 * \brief Surchage de l'opérateur soustraction (-).
	 * \detail Il s'agit ici de l'opposé d'un vecteur.
	 * \return Vecteur2D Une copie du résultat.
	 */
	inline const Vecteur2D operator- () const;

	/**
	 * \brief Surchage de l'opérateur string.
	 * \detail Conversion des coordonnées du vecteur en string. Similaire à la méthode toString().
	 */
	operator string() const;

	/**
	 * \brief Surcharge de l'opérateur d'affectation.
	 * \detail Affectation par recopie d'un vecteur passé en paramètre.
	 * \param op Vecteur2D 
	 * \return Vecteur2D Une référence de l'instance.
	 */
	const Vecteur2D& operator =(const Vecteur2D& op);

	/**
	 * \brief Surchage de l'opérateur d'égalité.
	 * \detail Compare l'instance avec le vecteur passé en paramètre.
	 * \param op Vecteur2D
	 * \return bool
	 */
	bool operator ==(const Vecteur2D& op)const;

	/**
	 * \brief Surchagre de l'opérateur différence.
	 * \detail Vérifie si l'instance et le vecteur passé en paramètre sont égaux.
	 * \param op Vecteur2D
	 * \return bool
	 */
	bool operator !=(const Vecteur2D& op)const;

	/**
	 * \brief Surcharge de l'opérateur +=.
	 * \detail Modification de l'instance via le vecteur passé en paramètre : instance = instance + op.
	 * \param op Vecteur2D
	 * \return Vecteur2D Une référence de l'instance modifiée.
	 */
	const Vecteur2D& operator +=(const Vecteur2D& op);

	/**
	 * \brief Surcharge de l'opérateur <<.
	 * \detail Modifie l'affichage du flux (généralement cout).
	 * \param os ostream
	 * \param u const Vecteur2D
	 * \return ostream Le flux d'entrée modifié.
	 */
	friend ostream& operator << (ostream& os, const Vecteur2D& op);

	Vecteur2D* clone()const
	{
		return new Vecteur2D(*this);
	}

	void affiche(ostream& os = cout)
	{
		os << (*this) << endl;
	}

	///////////////////////////////////////
	///									///
	///			Méthodes métier			///
	///									///
	///////////////////////////////////////


	/**
	* \brief Calcul du determinant.
	* \param op Vecteur2D
	* \return double
	*/
	double determinant(const Vecteur2D& op)const;

	/**
	 * \brief Opération de translation.
	 * \detail Similaire à l'opéarteur +=.
	 * \param op Vecteur2D
	 * \return void
	 */
	Vecteur2D& translation(const Vecteur2D& op);

	/**
	 * \brief Opération d'homothétie : transformation géométrique par agrandissement ou réduction
	 * \detail Une homothétie est définie par un point invariant (Vecteur2D) et par un rapport d'homothétie (double).
	 * \param op Vecteur2D
	 * \param r double
	 * \return void
	 */
	Vecteur2D& homothetie(const Vecteur2D& op, double r);

	/**
	 * \brief Opération de rotation.
	 * \detail Une rotation est définie par un point invariant (le centre de la rotation) et par un angle signé donné en radians.
	 * \param angle double
	 * \return void
	 */
	Vecteur2D& rotation(const Vecteur2D& op, double angle);

};

	////////////////////////////////////////////////
	///											 ///
	///		Implémentation des méthodes inline	 ///
	///											 ///
	////////////////////////////////////////////////



inline Vecteur2D::~Vecteur2D(){}

inline double Vecteur2D::getX() const
{
	return _abscisse;
}

inline void Vecteur2D::setX(double x)
{
	_abscisse = x;
}

inline double Vecteur2D::getY() const
{
	return _ordonnee;
}

inline void Vecteur2D::setY(double y)
{
	_abscisse = y;
}

inline const Vecteur2D operator *(const double& a, const Vecteur2D& u)
{
	return u * a;
}

inline Vecteur2D::Vecteur2D(const double& x, const double& y) : _abscisse(x), _ordonnee(y) {}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D& u) const
{
	return Vecteur2D(_abscisse + u._abscisse, _ordonnee + u._ordonnee);
}

inline const Vecteur2D Vecteur2D::operator * (const double& a) const
{
	return Vecteur2D(_abscisse * a, _ordonnee * a);
}

inline const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-_abscisse, -_ordonnee);
}

