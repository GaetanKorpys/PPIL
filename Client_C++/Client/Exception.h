/**
* \file Exception.h
* \brief Classe utilisée pour déclarer une exception.
*/

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exception
{
	string _message;  ///< Le message de l'excption à lever.
public:

	/**
	* \brief Constructeur avec une chaine de caractère.
	* \param string message
	*/
	Exception(const string& message)
	{
		_message = message;
	}

	/**
	* \brief Getter du membre privé _message.
	* \return string 
	*/
	const string& getMessage() const
	{
		return _message;
	}


	/**
	* \brief Surcharge de l'opérateur <<.
	* \detail Modifie l'affichage du flux (généralement cout).
	* \param os ostream
	* \param e Exception
	* \return ostream Flux sortant
	*/
	friend ostream& operator << (ostream& os, const Exception& e);
};