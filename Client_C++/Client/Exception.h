/**
* \file Exception.h
* \brief Classe utilis�e pour d�clarer une exception.
*/

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exception
{
	string _message;  ///< Le message de l'excption � lever.
public:

	/**
	* \brief Constructeur avec une chaine de caract�re.
	* \param string message
	*/
	Exception(const string& message)
	{
		_message = message;
	}

	/**
	* \brief Getter du membre priv� _message.
	* \return string 
	*/
	const string& getMessage() const
	{
		return _message;
	}


	/**
	* \brief Surcharge de l'op�rateur <<.
	* \detail Modifie l'affichage du flux (g�n�ralement cout).
	* \param os ostream
	* \param e Exception
	* \return ostream Flux sortant
	*/
	friend ostream& operator << (ostream& os, const Exception& e);
};