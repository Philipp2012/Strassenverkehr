#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
#define gZeitschritt 0.1
#define epsilon 0.0001

using namespace std;

extern double dGlobaleZeit;

class Fahrzeug
{
public:
	//Konstruktoren
	Fahrzeug();
	Fahrzeug(string);			//Mit Name
	Fahrzeug(string, double);	//Mit Name und MaxGeschwindigkeit
	
	//Copyconstruktor
	Fahrzeug(const Fahrzeug&);

	//Destructor
	virtual ~Fahrzeug();
	
	//Methoden
	virtual void vAusgabe();
	virtual void vAbfertigung();
	virtual double dTanken(double dMenge = 666);
	
	//Überladung von Operatoren
	virtual ostream& ostreamAusgabe(ostream&);
	bool operator <(Fahrzeug&);
	virtual Fahrzeug& operator =(Fahrzeug&);

private:
	static int p_iMaxID;
	void vInitialisierung();

//Attribute zum Vererben	
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
