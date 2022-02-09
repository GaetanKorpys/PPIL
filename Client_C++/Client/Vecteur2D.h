/**
* \file Vecteur2D.h
* \brief Un vecteur peut �tre consid�r� comme un vecteur ou un point du plan, c'est un couple (x,y) de coordonn�es r�elles.
*/

#pragma once
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

/**
 * \brief Surcharge de l'op�rateur (-).
 * \detail D�finition du template. Il permet d'utiliser une variable dont le type n'est pas connu lors de la compilation.
 * \param u T (type g�n�rique).
 * \param v T (type g�n�rique).
 * \return u + (-v).
 */

template <class T>
const T operator-(const T& u, const T& v) {
	return u + -v;
}

class Vecteur2D
{
	double _abscisse; ///< L'abscisse du vecteur.
	double _ordonnee; ///< L'ordonn�e du vecteur.

public:

	/**
	 * \brief Destructeur.
	 */
	inline virtual ~Vecteur2D();

	/**
	 * \brief Constructeur avec un couple de coordonn�es (x,y).
	 * \detail Par d�faut, les coordonn�es sont affect�es � 0.
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
	 * \brief Getter du membre priv� _abscisse.
	 * \return double L'abscisse du vecteur.
	 */
	inline double getX()const;

	/**
	 * \brief Setter du membre priv� _abscisse.
	 * \param x const double.
	 * \return Vecteur2D Une r�f�rence sur l'instance modifi�e.
	 */
	inline void setX(const double x);

	/**
	 * \brief Getter du membre priv� __ordonnee.
	 * \return double L'ordonn� du vecteur.
	 */
	inline double getY()const;

	/**
	 * \brief Setter du membre priv� _ordonnee
	 * \param y const double.
	 * \return Vecteur2D Une r�f�rence sur l'instance modifi�e.
	 */
	inline void setY(const double y);

	/**
	 * \brief Surcharge de l'op�rateur addition (+).
	 * \param u const Vecteur2D
	 * \return Vecteur2D Une copie du r�sultat.
	 */
	inline const Vecteur2D operator + (const Vecteur2D& u) const;

	/**
	 * \brief Surchage de l'op�rateur multiplication (*).
	 * \detail Muiltiplication par un r�el.
	 * \param a const double. 
	 * \return Vecteur2D Une copie du r�sultat.
	 */
	inline const Vecteur2D operator * (const double& r) const;

	/**
	 * \brief Surchage de l'op�rateur soustraction (-).
	 * \detail Il s'agit ici de l'oppos� d'un vecteur.
	 * \return Vecteur2D Une copie du r�sultat.
	 */
	inline const Vecteur2D operator- () const;

	/**
	 * \brief Surchage de l'op�rateur string.
	 * \detail Conversion des coordonn�es du vecteur en string. Similaire � la m�thode toString().
	 */
	operator string() const;

	/**
	 * \brief Surcharge de l'op�rateur d'affectation.
	 * \detail Affectation par recopie d'un vecteur pass� en param�tre.
	 * \param op Vecteur2D 
	 * \return Vecteur2D Une r�f�rence de l'instance.
	 */
	const Vecteur2D& operator =(const Vecteur2D& op);

	/**
	 * \brief Surchage de l'op�rateur d'�galit�.
	 * \detail Compare l'instance avec le vecteur pass� en param�tre.
	 * \param op Vecteur2D
	 * \return bool
	 */
	bool operator ==(const Vecteur2D& op)const;

	/**
	 * \brief Surchagre de l'op�rateur diff�rence.
	 * \detail V�rifie si l'instance et le vecteur pass� en param�tre sont �gaux.
	 * \param op Vecteur2D
	 * \return bool
	 */
	bool operator !=(const Vecteur2D& op)const;

	/**
	 * \brief Surcharge de l'op�rateur +=.
	 * \detail Modification de l'instance via le vecteur pass� en param�tre : instance = instance + op.
	 * \param op Vecteur2D
	 * \return Vecteur2D Une r�f�rence de l'instance modifi�e.
	 */
	const Vecteur2D& operator +=(const Vecteur2D& op);

	/**
	 * \brief Surcharge de l'op�rateur <<.
	 * \detail Modifie l'affichage du flux (g�n�ralement cout).
	 * \param os ostream
	 * \param u const Vecteur2D
	 * \return ostream Le flux d'entr�e modifi�.
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
	///			M�thodes m�tier			///
	///									///
	///////////////////////////////////////


	/**
	* \brief Calcul du determinant.
	* \param op Vecteur2D
	* \return double
	*/
	double determinant(const Vecteur2D& op)const;

	/**
	 * \brief Op�ration de translation.
	 * \detail Similaire � l'op�arteur +=.
	 * \param op Vecteur2D
	 * \return void
	 */
	Vecteur2D& translation(const Vecteur2D& op);

	/**
	 * \brief Op�ration d'homoth�tie : transformation g�om�trique par agrandissement ou r�duction
	 * \detail Une homoth�tie est d�finie par un point invariant (Vecteur2D) et par un rapport d'homoth�tie (double).
	 * \param op Vecteur2D
	 * \param r double
	 * \return void
	 */
	Vecteur2D& homothetie(const Vecteur2D& op, double r);

	/**
	 * \brief Op�ration de rotation.
	 * \detail Une rotation est d�finie par un point invariant (le centre de la rotation) et par un angle sign� donn� en radians.
	 * \param angle double
	 * \return void
	 */
	Vecteur2D& rotation(const Vecteur2D& op, double angle);

};

	////////////////////////////////////////////////
	///											 ///
	///		Impl�mentation des m�thodes inline	 ///
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

