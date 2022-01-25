/**
* \file Socket.h
* \brief La classe représente une connexion réseau, il s'agit d'un singleton.
* \detail Cela permet de garantir l'unicité de l'instance de la classe.
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