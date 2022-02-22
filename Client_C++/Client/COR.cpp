#include "COR.h"

COR* COR::_instance = NULL;



COR::COR() {
	ChargementCOR* ChargeurCercle, * ChargeurSegment, * ChargeurPolygone, * ChargeurGroupe, * ChargeurTriangle;
	ChargeurCercle = new ExpertCercle(NULL);
	ChargeurSegment = new ExpertSegment(ChargeurCercle);
	ChargeurPolygone = new ExpertPolygone(ChargeurSegment);
	ChargeurGroupe = new ExpertGroupe(ChargeurPolygone);
	ChargeurTriangle = new ExpertTriangle(ChargeurGroupe);
	_chargeurForme = ChargeurTriangle;
}

COR::~COR()
{}

COR* COR::getInstance() {
	if (_instance == NULL)
		_instance = new COR();
	return _instance;
}

Chargement* COR::getChargeurForme() {
	return _chargeurForme;
}