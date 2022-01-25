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

	// MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2
	r = WSAStartup(MAKEWORD(2, 0), &_wsaData);

	/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */

	if (r) throw Exception("L'initialisation a �chou�.");

	cout << "Initialisation winsock effectu�e" << endl;
}

void Socket::fermerConnexion()
{
	WSACleanup();
	cout << "Lib�ration des ressources de la winsock effectu�e" << endl;
}
