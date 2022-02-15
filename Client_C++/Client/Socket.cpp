#include "Socket.h"
#include <sstream>
#include "Exception.h"
#pragma warning(disable:4996)


/* static */ Socket* Socket::_instanceUnique = NULL;

Socket::Socket()
{
	_ip = "192.168.1.130";
	_port = 8091;
}

Socket::~Socket(){}

/* static */ Socket* Socket::getInstance()
{
	if (_instanceUnique == NULL)
		_instanceUnique = new Socket();
	return _instanceUnique;
}

bool Socket::initialiserConnexion() {
	int r;
	try
	{
		WSADATA wsaData;

		// MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2
		r = WSAStartup(MAKEWORD(2, 0), &wsaData);

		/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */

		if (r) throw Exception("L'initialisation a �chou�.");

		cout << "Initialisation winsock effectu�e" << endl;


		int familleAdresses = AF_INET;         // IPv4
		int typeSocket = SOCK_STREAM;           // mode connect� TCP
		int protocole = IPPROTO_TCP;            // protocole. 

		_sock = socket(familleAdresses, typeSocket, protocole);

		if (_sock == INVALID_SOCKET)
		{
			ostringstream oss;
			oss << "la cr�ation du socket a �chou� : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoy�es par WSAGetLastError() : cf. doc r�f winsock
			throw Exception(oss.str().c_str());
		}

		cout << "Socket de dessin cr��" << endl << endl;

		//Cr�ation du repr�sentant du serveur.

		_sockaddr.sin_family = AF_INET;
		_sockaddr.sin_addr.s_addr = inet_addr(_ip.c_str());   // inet_addr() convertit de l'ASCII en entier
		_sockaddr.sin_port = htons((short)_port);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

		//Connexion du client au serveur.

		r = connect(_sock, (SOCKADDR*)&_sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
																		// Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

		if (r == SOCKET_ERROR)
		{
			cout << WSAGetLastError();
			cout << "ok" << endl;
			throw Exception("La connexion au serveur de dessin a �chou�.");
		}


		cout << "Connexion au serveur de dessin r�ussie." << endl << endl;
	}
	catch (Exception e) 
	{
		cerr << e << endl;
		return false;
	}
	
}

void Socket::envoyerRequete(const string& requete) {
	int r;
	string tmp = requete + "\r\n";
	r = send(_sock, tmp.c_str(), tmp.size(), 0);
	if (r == SOCKET_ERROR)
		throw Exception("Echec de l'envoi de la requ�te");
}

bool Socket::requeteSucces() {
	cout << "OK";
	char t[10];
	recv(_sock, t, 10, 0);
	/*le serveur renvoie '1' si la requete pr�c�dente
	a �t� trait�e*/
	cout << "OK2";
	if (t[0] == '1')
		return true;
	return false;
}


void Socket::fermerConnexion()
{
	try {
		int r;
		r = shutdown(_sock, SD_BOTH);
		if (r == SOCKET_ERROR)
			throw Exception("La coupure de connexion a echoue");
		r = closesocket(_sock);
		if (r)
			throw Exception("La fermeture du socket a echoue");
		WSACleanup();
		cout << "Fermeture de la connexion effectuee" << endl;
		_sock = NULL;
	}
	catch (Exception Exception) {
		cerr << Exception << endl;
	}
}

void Socket::killInstance() {
	if (_instanceUnique != NULL) {
		delete _instanceUnique;
		_instanceUnique = NULL;
	}
}
