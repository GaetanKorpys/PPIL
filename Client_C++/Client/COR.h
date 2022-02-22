#pragma once
#include "ExpertCercle.h"
#include "ExpertGroupe.h"
#include "ExpertPolygone.h"
#include "ExpertSegment.h"
#include "ExpertTriangle.h"

//La classe qui définit l'ordre des des chargeurs
class COR {
private:
	ChargementCOR* _chargeurForme;
	static COR* _instance;

	/**
	* \brief Constructeur par défaut privé
	*/
	COR();

	/**
	* \brief Destructeur privé
	*/
	~COR();

public:


	/**
	*	\brief méthode pour récupérer l'instance de la classe.
	*	\return COR * l'instance.
	*/
	static COR* getInstance();

	/**
	*	\brief méthode pour récupérer le chargeur forme.
	*	\return COR * l'instance.
	*/
	Chargement* getChargeurForme();
};