#pragma once
#include "ChargementCOR.h"

class ExpertSegment : public ChargementCOR
{
public:
	/**
	* \brief Constructeur � partir d'un pointeur sur l'expert suivant
	* \param suivant Pointeur sur l'expert suivant
	*/
	ExpertSegment(ChargementCOR* suivant);

	/**
	* \brief Retourne le type de la forme que l'expert peut traiter (ici un segment)
	* \return string Type de la forme
	*/
	const string getTypeForme()const;

	/**
	* \brief Extrait les donn�es d'une forme � partir d'une chaine de caract�res
	* \param infoForme Chaine de caract�res correspondant aux donn�es de la forme
	* \return Forme* Un pointeur sur la forme
	*/
	Forme* traiterDemande(const string& infoForme)const;
};