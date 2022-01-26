#include <winsock2.h>
#include <string>
#include <sstream>
#include "Exception.h"
#include "Socket.h"
#include "Dessin.h"
#pragma warning(disable:4996) 

using namespace std;


Dessin::Dessin(string ip, int port) {
	if (_sock != NULL) {
		throw Exception("Initialisation d�j� effectu�e.");
	}

	//Inisialisation du socket unique.
	Socket::getInstance();


	//Structure contenant les donn�es de la librairie winsock � initialiser.
	int r;

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
	_sockaddr.sin_addr.s_addr = inet_addr(ip.c_str());   // inet_addr() convertit de l'ASCII en entier
	_sockaddr.sin_port = htons((short)port);                 //htons() assure que le port est bien inscrit dans le format du r�seau (little-endian ou big-endian)

	//Connexion du client au serveur.

	r = connect(_sock, (SOCKADDR*)&_sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'�chec.
																	// Le code d'erreur peut �tre obtenu par un appel � WSAGetLastError()

	if (r == SOCKET_ERROR)
		throw Exception("La connexion au serveur de dessin a �chou�.");

	cout << "Connexion au serveur de dessin r�ussie." << endl << endl;
}



void Dessin::ouvreFenetreGraphique(const int largeur, const int hauteur)
{
	ostringstream oss;

	oss << "OuvrirFenetre" << ", " << largeur << ", " << hauteur << "\r\n";

	string requete = oss.str();

	//Envoi de la requete au serveur.
	int r = send(_sock, requete.c_str(), requete.length(), 0);

	if (r == SOCKET_ERROR)
		throw Exception("Echec de l'envoi de la requ�te d'ouverture de fen�tre graphique.");

	cout << "Requ�te d'ouverture de fen�tre graphique envoy�e." << endl;
}

void Dessin::dessiner(const Forme& forme)
{
	string requete = forme;
	requete += "\n";

	//Envoi de la requete au serveur.
	int r = send(_sock, requete.c_str(), requete.length(), 0);

	if (r == SOCKET_ERROR)
		throw Exception("Echec de l'envoi de la requ�te d'ouverture de fen�tre graphique.");

	cout << "Requ�te de forme envoyee : " + requete << endl;
}

Dessin::~Dessin()
{
	int r = shutdown(_sock, SD_BOTH);						
													

	if (r == SOCKET_ERROR)
		throw Exception("La coupure de connexion a �chou�.");


	r = closesocket(_sock);                        
	if (r) throw Exception("La fermeture du socket a �chou�");

	cout << "Arr�t normal du client" << endl << endl;
}