/**
* \file Socket.h
* \brief La classe repr�sente une connexion r�seau, il s'agit d'un singleton.
* \detail Cela permet de garantir l'unicit� de l'instance de la classe.
*/
#pragma once
#include <WinSock2.h>
#include <string>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

class Socket 
{

	static Socket* _instanceUnique; ///< Instance unique static de la classe.

	SOCKET _sock;

	SOCKADDR_IN _sockaddr;

	string _ip; ///< L'adresse ip pour connecter le client et le serveur.

	int _port; ///< Le port pour connecter le client et le serveur.

	/**
	 * \brief Constructeur priv� car la classe est un singleton.
	 */
	Socket();

	/**
	 * \brief Destructeur priv�.
	 */
	~Socket();

public:
	/**
	* \brief Retourne une instance unique
	* \details Va cr�er l'instance si celle-ci n'existe pas ou bien juste la retourner dans le cas contraire
	* \return SingletonConnexion* Pointeur sur l'instance unique
	*/
	static Socket* getInstance();

	/**
	* \brief Initialise la connexion vers le serveur
	* \return bool Bool�en vrai si la connexion est r�ussie, faux sinon
	*/
	bool initialiserConnexion();

	/**
	* \brief Envoie une requ�te au serveur
	* \param str La chaine de caract�re � envoyer au serveur
	*/
	void envoyerRequete(const string& requte);

	/**
	* \brief Teste si une requ�te a �t� trait�e par le serveur
	* \return bool Bool�en vrai si la requ�te a �t� trait�e, faux sinon
	*/
	bool requeteSucces(); 

	/**
	* \brief Ferme la connexion vers le serveur
	*/
	void fermerConnexion();

	/**
	* \brief Ferme l'instance unique en cours
	*/
	void killInstance();
};