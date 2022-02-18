/**
* \file Polygone.h
* \brief Un polygone est une forme géométrique composé d'au minimum 3 points.
* \detail C'est une des 4 formes géométriques disponible par défaut dans le sujet.
*/
#pragma once
#include "Exception.h"
#include "Constante.h"
#include "Vecteur2D.h"
#include "Forme.h"
#include <vector>

class Polygone : public Forme
{
	
	vector<Vecteur2D *> _listePoints;///< Vector de pointeur(car clonage) de Vecteur2D.

	/**
	 * \brief Vérifie si un polygone est valide.
	 * \param op vector<Vecteur2D*> Un tableau contenant l'ensemble des points du polygone.
	 * \return bool
	 */
	bool polygoneValide(const vector<Vecteur2D*>& op)const;

	/**
	 * \brief Effectue une copie de chaque point  du polygone.
	 * \detail Chaque point est cloné (new).
	 * \param op vector<Vecteur2D*>
	 */
	void copie(const vector<Vecteur2D*>& op);

public:

	/**
	 * \brief Constructeur
	 * \param couleur String
	 */
	Polygone(const string& couleur = BLACK);

	/**
	 * \brief Constructeur.
	 * \param op vector<Vecteur2D*>
	 * \param couleur string
	 */
	Polygone(const vector<Vecteur2D*>& op, const string& couleur = BLACK);

	/**
	 * \brief Constructeur par recopie.
	 * \param op Polygone
	 */
	Polygone(const Polygone& op);

	/**
	 * \brief Destructeur.
	 */
	~Polygone();

	/**
	 * \brief Retourne le nombre de points du polygone.
	 * \return int
	 */
	int getNbPoints()const;

	/**
	 * \brief Getter du point situé à l'index donné en paramètre.
	 * \param index int L'index du point dans le vector.
	 * \return Vecteur2D
	 */
	const Vecteur2D& getPoint(int index)const;

	/**
	 * \brief Modifie le point situé à l'index donné en paramètre.
	 * \param index int L'index du point dans le vector.
	 * \param op Vecteur2D
	 * \return 
	 */
	const Polygone& setPoint(int index, const Vecteur2D& op);

	/**
	 * \brief Getter du centre de gravité.
	 * \return Vecteur2D Le centre de gravité
	 */
	virtual const Vecteur2D& getCentreGravite()const;

	/**
	 * \brief Surcharge de l'opérateur =.
	 * \detail Affectation par recopie d'un point passé en paramètre.
	 * \param op Polygone Le polygone à copier.
	 * \return Polygone
	 */
	const Polygone& operator = (const Polygone& op);

	/**
	 * \brief Surcharge de l'opérateur ==.
	 * \detail Compare l'instance avec le polygone passé en paramètre.
	 * \param op Polygone
	 * \return bool
	 */
	bool operator == (const Polygone& op)const;

	/**
	 * \brief Surcharge de l'opérateur !=.
	 * \detail Vérifie si l'instance et le polygone passé en paramètre sont égaux.
	 * \param op Polygone
	 * \return bool
	 */
	bool operator != (const Polygone& op)const;

	/**
	 * \brief Surcharge de l'opérateur +.
	 * \detail Ajoute un point au polygone.
	 * \param op Vecteur2D
	 */
	void operator + (const Vecteur2D& op);

	/**
	 * \brief Surcharge de l'opérateur -.
	 * \detail Supprime un point du polygone.
	 * \param index int
	 */
	void operator - (int index);

	/**
	 * \brief Surcharge de l'opérateur [].
	 * \param index int
	 * \return Vecteur2D
	 */
	const Vecteur2D& operator[](int index)const;

	/**
	 * \brief Ajoute un point au polygone.
	 * \param op Vecteur2D
	 */
	void ajouter(const Vecteur2D& op);

	/**
	 * \brief Supprime un point du polygone.
	 * \param index int
	 */
	void supprimer(int index);

	/**
	 * \brief Surchage de l'opérateur string.
	 */
	operator string()const;

	/**
	 * \brief Getter de l'aire du polygone.
	 * \return double L'aire du polygone.
	 */
	const double getAire()const;

	/**
	 * \brief Clone l'instance courante du polygone.
	 * \return Polygone* Un pointeur sur une nouvelle instance d'un polygone.
	 * \detail Il s'agit d'une allocation dynamique (new).
	 */
	Polygone* clone() const;

	void accepte(const Visiteur& op);

	/**
	 * \brief Surcharge de l'opérateur <<.
	 * \detail Modifie l'affichage du flux (généralement cout).
	 * \param os ostream
	 * \param op Segment
	 * \return ostream Le flux d'entrée modifié.
	 */
	friend ostream& operator << (ostream& os, const Polygone& op);
};