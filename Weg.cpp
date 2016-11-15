#include "Weg.h"
#include "Fahrzeug.h"


Weg::Weg()
{
}

Weg::Weg(string sName, double dLaenge, Begrenzung eLimit) :AktivesVO(sName)
{
	p_dLaenge = dLaenge;
	p_eLimit = eLimit;
}


Weg::~Weg()
{
}

double Weg::dGetLaenge() const
{
	return p_dLaenge;
}

void Weg::vAbfertigung()
{
	ListFahrzeug::iterator itL;
	itL = p_pFahrzeuge.begin();

	while (p_pFahrzeuge.end() != itL)
	{
		(*itL)->vAbfertigung();
		itL++;
	}
}

void Weg::vAnnahme(Fahrzeug* pFzg)
{
	//To be done
}

ostream& Weg::ostreamAusgabe(ostream& daten)
{
	AktivesVO::ostreamAusgabe(daten) << p_dLaenge;

	return daten;
}
