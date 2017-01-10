#pragma once
#include "Fahrzeug.h"

/*
Fahrrad Klasse.
Erbt von Fahrzeug
*/
class Fahrrad :
	public Fahrzeug
{

public:
	//Konstruktoren
	Fahrrad();
	Fahrrad(string, double);	//Name, MaxGeschwindigkeit

	//Copyconstructor
	Fahrrad(const Fahrrad&);

	//Destruktor
	~Fahrrad();

private:
	double dGeschwindigkeit();
};

