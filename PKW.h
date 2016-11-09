#pragma once
#include "Fahrzeug.h"
class PKW :
	public Fahrzeug
{

public:
	PKW();
	PKW(string, double, double, double dTankvolumen = 55);
	PKW(const PKW&); //Copyconstructor
	~PKW();
	void vAusgabe();
	void vAbfertigung();
	ostream& ostreamAusgabe(ostream&);
	PKW& operator =(PKW&);

private:
	double p_dVerbrauch;	//Verbrauch/100km
	double p_dTankinhalt;	//In Liter
	double p_dTankvolumen;	//Standard 55l

	double dVerbrauch();
	double dTanken(double dMenge = 666);
	double dGeschwindigkeit();
};

