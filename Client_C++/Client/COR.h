#pragma once
#include "ExpertCercle.h"
#include "ExpertGroupe.h"
#include "ExpertPolygone.h"
#include "ExpertSegment.h"
#include "ExpertTriangle.h"

//La classe qui d�finit l'ordre des des chargeurs
class COR {
private:
	ChargementCOR* _chargeurForme;
	static COR* _instance;

	/**
	* \brief Constructeur par d�faut priv�
	*/
	COR();

	/**
	* \brief Destructeur priv�
	*/
	~COR();

public:


	/**
	*	\brief m�thode pour r�cup�rer l'instance de la classe.
	*	\return COR * l'instance.
	*/
	static COR* getInstance();

	/**
	*	\brief m�thode pour r�cup�rer le chargeur forme.
	*	\return COR * l'instance.
	*/
	Chargement* getChargeurForme();
};