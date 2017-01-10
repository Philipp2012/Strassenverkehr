#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"


Streckenende::Streckenende(Fahrzeug* fFahrzeug, Weg* wWeg):FahrAusnahme(fFahrzeug, wWeg)
{
}


Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	p_pWeg->vAbgabe(p_pFahrzeug);
	p_pWeg->vAnnahme(p_pFahrzeug, 100);	//Fahrzeug wird geparkt, temporäre Lösung
	cout << "Ausnahme: Streckenende, Weg und Fahrzeug: " << p_pWeg->getName() << " " << p_pFahrzeug->getName() << endl;
}