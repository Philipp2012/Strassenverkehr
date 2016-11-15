#pragma once
#include "Weg.h"

class FzgVerhalten
{
public:
	//Konstruktor und Destruktor
	FzgVerhalten(Weg* pWeg);
	~FzgVerhalten();

private:
	Weg* p_pWeg;

	double dStrecke(Fahrzeug*, double Zeitraum);
};

