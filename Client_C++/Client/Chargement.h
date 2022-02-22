#pragma once
#include "Forme.h"
using namespace std;
class Chargement
{
public:
	virtual Forme* resoudre(const std::string& id, const string& info = "")const = 0;
};
