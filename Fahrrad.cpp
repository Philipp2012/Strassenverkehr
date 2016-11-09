#include "Fahrrad.h"



Fahrrad::Fahrrad()
{
}

Fahrrad::Fahrrad(string sName, double dMaxGeschwindigkeit) :Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

Fahrrad::Fahrrad(const Fahrrad& fahrrad) : Fahrzeug(fahrrad)
{
}

Fahrrad::~Fahrrad()
{
}

double Fahrrad::dGeschwindigkeit()
{
	int iAnzahl_20km = (int)(p_dGesamtStrecke / 20);

	double dAktuelleGeschwindigkeit = p_dMaxGeschwindigkeit * pow(0.9, iAnzahl_20km);

	if (dAktuelleGeschwindigkeit < 12)
	{
		dAktuelleGeschwindigkeit = 12;
	}

	return dAktuelleGeschwindigkeit;
}
