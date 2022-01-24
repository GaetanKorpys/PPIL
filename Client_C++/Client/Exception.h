/**
* \file Exception.h
* \brief Classe utilis� pour d�clarer une exception.
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
	inline Exception(const string& message);

	/**
	* \brief Getter du membre priv� _message.
	* \return string 
	*/
	inline const string& getMessage() const;


	/**
	* \brief Surcharge de l'op�rateur <<.
	* \detail Modifie l'affichage du flux (g�n�ralement cout).
	* \param os ostream
	* \param e Exception
	* \return ostream Flux sortant
	*/
	friend ostream& operator << (ostream& os, const Exception& e);
};

	////////////////////////////////////////////////
	///											 ///
	///		Impl�mentation des m�thodes inline	 ///
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