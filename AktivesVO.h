#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <list>
#define gZeitschritt 0.5
#define epsilon 0.0001

using namespace std;

class AktivesVO
{
public:
	AktivesVO();
	AktivesVO(string);
	~AktivesVO();


	//gemeinsam genutzte Methoden von Fahrzeug und Weg
	virtual void vAbfertigung()=0;

	//Überladung der Operatoren
	virtual ostream& ostreamAusgabe(ostream&);
	//bool operator <(AktivesVO&);
	//virtual AktivesVO& operator =(AktivesVO&);

private:
	static int p_iMaxID;
	void vInitialisierung();

protected:
	int p_iID;
	string p_sName;
	double p_dZeit;
};

ostream& operator << (ostream& daten, AktivesVO& fahrzeug);