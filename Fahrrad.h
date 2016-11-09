#pragma once
#include "Fahrzeug.h"
class Fahrrad :
	public Fahrzeug
{

public:
	Fahrrad();
	Fahrrad(string, double);
	Fahrrad(const Fahrrad&); //Copyconstructor
	~Fahrrad();

private:
	double dGeschwindigkeit();
};

