/**
* \file Socket.h
* \brief La classe repr�sente une connexion r�seau, il s'agit d'un singleton.
* \detail Cela permet de garantir l'unicit� de l'instance de la classe.
*/
#pragma once
#include <WinSock2.h>
#include <string>

using namespace std;

class Socket 
{

	static Socket* _instanceUnique;

	WSADATA _wsaData;

	Socket();

	~Socket();

public:

	static Socket* getInstance();

	bool initialiserConnexion();

	void fermerConnexion();
};