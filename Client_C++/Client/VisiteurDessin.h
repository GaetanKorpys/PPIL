#pragma once

#include "Visiteur.h"

class VisiteurDessin : public Visiteur
{
	/**
	 * \brief Retourne une requete pour l'ouverture d'une fenetre sous forme de string.
	 * \return string
	 */
	string requeteFenetre()const;

	/**
	* \brief Envoie une requête de dessin d'une forme vers le serveur
	* \param infoForme Données concernant la forme à dessiner
	* \param estMarquee Booléen qui informe si la forme est dans un groupe (true) ou pas (false)
	*/
	void dessiner(const string& infoForme, bool estMarquee)const;


	

public:

	VisiteurDessin();

	/**
	* \brief Envoie une requête de création de la fenêtre vers le serveur
	*/
	void ouvrirFenetre()const;

	/**
	* \brief Initialise une connexion vers le serveur, dessine un segment puis ferme la connexion
	* \param s Pointeur sur le segment à dessiner
	*/
	virtual void visite(Segment& op) const;

	/**
	* \brief Initialise une connexion vers le serveur, dessine un cercle puis ferme la connexion
	* \param s Pointeur sur le cercle à dessiner
	*/
	virtual void visite(Cercle& op) const;

	/**
	* \brief Initialise une connexion vers le serveur, dessine un triangle puis ferme la connexion
	* \param s Pointeur sur le triangle à dessiner
	*/
	virtual void visite(Triangle& op) const;

	/**
	* \brief Initialise une connexion vers le serveur, dessine un polygone puis ferme la connexion
	* \param s Pointeur sur le polygone à dessiner
	*/
	virtual void visite(Polygone& op) const;

	/**
	* \brief Initialise une connexion vers le serveur, dessine un groupe puis ferme la connexion
	* \param s Pointeur sur le groupe à dessiner
	*/
	virtual void visite(Groupe& op) const;

};