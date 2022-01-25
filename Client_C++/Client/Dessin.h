/**
* \brief  Represente l'affichage en java
*/

#pragma once
#include "Forme.h"
#include <WinSock2.h>
#include <string>

using namespace std;


class Dessin
{
	SOCKET _sock;

	SOCKADDR_IN _sockaddr;
public:

	/**
	* \brief Constructeur par defaut.
	* \param ip L'adresse ip pour la connexion.
	* \param port Le port à utiliser.
	*/
	Dessin(string ip = "localhost", int port = 8091);

	/**
	* \brief Dessine la forme
	* \param forme La forme a dessiner
	*/
	virtual void dessiner(const Forme& op);

	/**
	 * \brief Destructeur
	 * \detail Ferme la connexion vers le serveur.
	 */
	~Dessin();

	/**
	* \brief Ouvre une fenetre graphique
	* \param largeur La largeur de la fenêtre
	* \param hauteur La hauteur de la fenêtre
	*/
	void ouvreFenetreGraphique(const int largeur, const int hauteur);


};

