#include "FzgVerhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"

//Konstruktor mit Zeiger auf Weg, speichert diesen
FzgVerhalten::FzgVerhalten(Weg* pWeg)
{
	p_pWeg = pWeg;
}

//Destruktor
FzgVerhalten::~FzgVerhalten()
{
}

//Soll die noch übrige Strecke vom Weg zurück geben, tut dies bis jetzt nicht :P
double FzgVerhalten::dStrecke(Fahrzeug* pFzg, double dZeitraum)
{
	if (p_pWeg->dGetLaenge() < (dZeitraum * (pFzg->dGeschwindigkeit())))
	{
		return p_pWeg->dGetLaenge();
	}
	else
	{
		return (dZeitraum * (pFzg->dGeschwindigkeit()));
	}
}
