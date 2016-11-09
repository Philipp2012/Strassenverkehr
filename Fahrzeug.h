#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#define gZeitschritt 0.1

using namespace std;

extern double dGlobaleZeit;

class Fahrzeug
{
public:
	//Konstruktor und Destruktor
	Fahrzeug();
	Fahrzeug(string);
	Fahrzeug(string, double);
	Fahrzeug(const Fahrzeug&); //Copyconstructor
	virtual ~Fahrzeug();
	
	//Methoden
	virtual void vAusgabe();
	virtual void vAbfertigung();
	virtual double dTanken(double dMenge = 666);
	
	virtual ostream& ostreamAusgabe(ostream&);	//Vererbung des Überladens
	bool operator <(Fahrzeug&);
	virtual Fahrzeug& operator =(Fahrzeug&);

private:
	static int p_iMaxID;
	void vInitialisierung();

protected:
	string p_sName;
	int p_iID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;

	virtual double dGeschwindigkeit();
};

ostream& operator << (ostream& daten, Fahrzeug& fahrzeug); 
