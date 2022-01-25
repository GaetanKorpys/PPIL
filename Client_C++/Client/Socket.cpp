#include "Socket.h"
#include "Exception.h"

/* static */ Socket* Socket::_instanceUnique = NULL;

Socket::Socket(){}

Socket::~Socket(){}

/* static */ Socket* Socket::getInstance()
{
	if (_instanceUnique == NULL)
		_instanceUnique = new Socket();
	return _instanceUnique;
}

bool Socket::initialiserConnexion() {
	int r;

	// MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2
	r = WSAStartup(MAKEWORD(2, 0), &_wsaData);

	/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */

	if (r) throw Exception("L'initialisation a échoué.");

	cout << "Initialisation winsock effectuée" << endl;
}

void Socket::fermerConnexion()
{
	WSACleanup();
	cout << "Libération des ressources de la winsock effectuée" << endl;
}
