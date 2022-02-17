/**
* \file Groupe.h
* \brief Un groupe est un ensemble de forme g�om�trique.
*/

#pragma once
#include "Forme.h"
#include "Exception.h"
#include <vector>

class Groupe :public Forme
{
	vector<Forme *> _listeFormes;///< Vector de pointeur(car clonage) de Forme.

	/**
	 * \brief Effectue une copie de chaque forme du polygone.
	 * \detail Chaque forme est clon�e (new).
	 * \param op vector<Forme*>
	 */
	void copie(const vector<Forme *>& op);

public:
	/**
	 * \brief Constructeur
	 * \param couleur string 
	 */
	Groupe(const string& couleur = BLACK);

	/**
	 * \brief Constructeur par recopie.
	 * \param op Groupe
	 */
	Groupe(const Groupe& op);

	/**
	 * \brief Destructeur.
	 */
	~Groupe();

	/**
	 * \brief Retourne le nombre de forme du groupe.
	 * \return int
	 */
	int getNbForme()const;

	/**
	 * \brief Getter de la forme situ� � l'index donn� en param�tre.
	 * \param index int L'index du point dans le vector.
	 * \return Forme
	 */
	const Forme& getForme(int index)const;

	/**
	 * \brief Surcharge de l'op�rateur =.
	 * \detail Affectation par recopie d'une forme pass�e en param�tre.
	 * \param op Groupe Le groupe � copier.
	 * \return Groupe
	 */
	const Groupe& operator = (const Groupe& op);

	/**
	 * \brief Surcharge de l'op�rateur ==.
	 * \detail Compare l'instance avec le groupe pass� en param�tre.
	 * \param op Groupe
	 * \return bool
	 */
	bool operator == (const Groupe& op)const;

	/**
	 * \brief Surcharge de l'op�rateur !=.
	 * \detail V�rifie si l'instance et le groupe pass� en param�tre sont �gaux.
	 * \param op Groupe
	 * \return bool
	 */
	bool operator != (const Groupe& op)const;

	/**
	 * \brief Surcharge de l'op�rateur +.
	 * \detail Ajoute une forme au groupe.
	 * \param op Forme
	 */
	void operator + (const Forme& op);

	/**
	 * \brief Surcharge de l'op�rateur -.
	 * \detail Supprime une forme du groupe.
	 * \param index int
	 */
	void operator - (int index);

	/**
	 * \brief Surcharge de l'op�rateur [].
	 * \param index int
	 * \return Forme
	 */
	Forme& operator[](int index)const;

	/**
	 * \brief Ajoute une forme au groupe.
	 * \param op Forme
	 */
	void ajouter(const Forme& op);

	/**
	 * \brief Supprime une forme du groupe.
	 * \param index int
	 */
	void supprimer(int index);

	/**
	 * \brief Surchage de l'op�rateur string.
	 */
	operator string()const;

	/**
	 * \brief Getter de l'aire du groupe.
	 * \return double L'aire du groupe.
	 */
	const double getAire()const;

	/**
	 * \brief Clone l'instance courante du groupe.
	 * \return Groupe* Un pointeur sur une nouvelle instance d'un groupe.
	 * \detail Il s'agit d'une allocation dynamique (new).
	 */
	Groupe* clone() const;

	void accepte(const Visiteur& op);

	/**
	 * \brief Surcharge de l'op�rateur <<.
	 * \detail Modifie l'affichage du flux (g�n�ralement cout).
	 * \param os ostream
	 * \param op Segment
	 * \return ostream Le flux d'entr�e modifi�.
	 */
	friend ostream& operator << (ostream& os, const Groupe& op);
};