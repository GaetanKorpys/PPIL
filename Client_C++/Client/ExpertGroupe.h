#pragma once
#include "ChargementCOR.h"

class ExpertGroupe : public ChargementCOR
{
public:

	/**
	* \brief Constructeur
	* \param suivant Pointeur sur l'expert suivant
	*/
	ExpertGroupe(ChargementCOR* suivant);

	/**
	* \brief Retourne le type de la forme que l'expert peut traiter (ici un groupe)
	* \return string Type de la forme
	*/
	const string getTypeForme()const;

	/**
	* \brief Extrait les donn�es d'une forme � partir d'une chaine de caract�res
	* \param infoForme Chaine de caract�res correspondant aux donn�es de la forme
	* \return Forme* Un pointeur sur la forme
	*/
	Forme* traiterDemande(const string& infoForme)const;

	/**
	* \brief R�cup�re une forme d'un groupe. La forme est ensuite supprim�e du groupe pour par la suite acc�der aux autre formes de ce m�me groupe
	* \param copier Chaine de caract�re correspondant au groupe
	* \return string Chaine de caract�re correspondant � la forme extraite
	*/
	string getComposant(string& copie)const;
};
