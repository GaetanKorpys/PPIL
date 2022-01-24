/**
* \file Exception.h
* \brief Classe utilisé pour déclarer une exception.
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
	inline Exception(const string& message);

	/**
	* \brief Getter du membre privé _message.
	* \return string 
	*/
	inline const string& getMessage() const;


	/**
	* \brief Surcharge de l'opérateur <<.
	* \detail Modifie l'affichage du flux (généralement cout).
	* \param os ostream
	* \param e Exception
	* \return ostream Flux sortant
	*/
	friend ostream& operator << (ostream& os, const Exception& e);
};

	////////////////////////////////////////////////
	///											 ///
	///		Implémentation des méthodes inline	 ///
	///											 ///
	////////////////////////////////////////////////

inline Exception::Exception(const string& message)
{
	_message = message;
}

inline const string& Exception::getMessage() const
{
	return _message;
}