#include "SocketSingleton.h"
#include <sstream>
#include "Exception.h"
#pragma warning(disable:4996)


/* static */ SocketSingleton* SocketSingleton::_instanceUnique = NULL;

SocketSingleton::SocketSingleton()
{
	_port = 8091;
}

SocketSingleton::~SocketSingleton(){}

/* static */ SocketSingleton* SocketSingleton::getInstance()
{
	if (_instanceUnique == NULL)
	{
		_instanceUnique = new SocketSingleton();
	}
		
	return _instanceUnique;
}

bool SocketSingleton::initialiserConnexion() {
	int r;
	string reponse;
	try
	{
		WSADATA wsaData;

		do
		{
			cout << endl;
			cout << "Voulez-vous tester le programme en locale (ou sur 2 machines) ?" << endl;
			cout << "[ y / n ]" << endl;
			cin >> reponse;
		} while (reponse != "y" && reponse != "n");
		if (reponse == "y")
		{
			_ip = "127.0.0.1";
		}
		else
		{
			cout << "Veuillez saisir l'adresse IP du serveur de dessin :" << endl;
			cin >> reponse;
			_ip = reponse;
		}
		// MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2
		r = WSAStartup(MAKEWORD(2, 0), &wsaData);

		/* en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0 */

		if (r) throw Exception("L'initialisation a �chou�.");

		cout << "Initialisation winsock effectuee" << endl;


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

		cout << "SocketSingleton de dessin cree" << endl << endl;

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
			throw Exception("La connexion au serveur de dessin a echoue.");
		}


		cout << "Connexion au serveur de dessin reussie." << endl << endl;
	}
	catch (Exception e) 
	{
		cerr << e << endl;
		return false;
	}
	
}

void SocketSingleton::envoyerRequete(const string& requete) {
	int r;
	string tmp = requete + "\r\n";
	r = send(_sock, tmp.c_str(), tmp.size(), 0);
	if (r == SOCKET_ERROR)
		throw Exception("Echec de l'envoi de la requ�te");
}

bool SocketSingleton::requeteSucces() {
	char t[10];
	recv(_sock, t, 10, 0);
	/*le serveur renvoie '1' si la requete pr�c�dente
	a �t� trait�e*/
	if (t[0] == '1')
		return true;
	return false;
}


void SocketSingleton::fermerConnexion()
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
		cout << endl;
		cout << "Fermeture de la connexion effectuee" << endl;
		_sock = NULL;
	}
	catch (Exception Exception) {
		cerr << Exception << endl;
	}
}

void SocketSingleton::killInstance() {
	if (_instanceUnique != NULL) {
		delete _instanceUnique;
		_instanceUnique = NULL;
	}
}
