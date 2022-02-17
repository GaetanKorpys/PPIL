#pragma once
#include "Visiteur.h"

class VisiteurTxt : public Visiteur
{
	const static string _chemin; ///< Le chemin pour enregister les formes

	static int _id; ///< L'identifiant de chaque forme enregistrée.

	/**
	* \brief Ecriture d'une ligne dans un fichier
	* \param ligne Chaine de caractère à écrire dans le fichier
	* \param chemin Chemin du fichier dans lequel on veut écrire la ligne
	*/
	void sauvgarde(const string& ligne, const string& chemin)const;

public:

	/**
	* \brief Sauvegarde un segment dans un fichier
	* \param op Segment
	*/
	virtual void visite(Segment& op) const;

	/**
	* \brief Sauvegarde un triangle dans un fichier
	* \param op Triangle
	*/
	virtual void visite(Triangle& op) const;

	/**
	* \brief Sauvegarde un cercle dans un fichier
	* \param op Cercle
	*/
	virtual void visite(Cercle& op) const;


	/**
	* \brief Sauvegarde un polygone dans un fichier
	* \param op Polygone
	*/
	virtual void visite(Polygone& op) const;

	/**
	* \brief Sauvegarde un groupe dans un fichier
	* \param op Groupe
	*/
	virtual void visite(Groupe& op)const;
};