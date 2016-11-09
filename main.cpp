#include "PKW.h"
#include "Fahrrad.h"
#include <vector>

//Uhr initialisieren (global)
double dGlobaleZeit = 0.0;

/*
Funktion zum testen der Fahrzeug-Klasse.
Erstellt Fahrzeuge, ruft die Ausgabe-Funktion auf und löscht alle Fahrzeuge wieder
*/
void vAufgabe_1()
{
	//Statisch erzeugte Objekte
	Fahrzeug tAuto1;
	Fahrzeug tAuto2("PKW", 40.0);

	//Dynamisch erzeugte Objekte
	Fahrzeug* pAuto3;
	Fahrzeug* pAuto4;
	
	//Nutzer nach Fahrzeugnamen fragen
	string sAutoname;
	cout << "Geben sie einen Fahrzeugnamen ein:" << endl;
	cin >> sAutoname;
	pAuto3 = new Fahrzeug();
	pAuto4 = new Fahrzeug(sAutoname, 30.0);

	//Ausgabe der Fahrzeuge und Daten
	cout << endl << "ID  Name   :  MaxKmh   GesamtStrecke      " << endl;
	cout << setw(42) << setfill('+') << " " << endl;
	
	for (double d = 0; d <= 2.1; d += 0.1)
	{
		dGlobaleZeit = d;
		
		tAuto1.vAbfertigung();
		tAuto2.vAbfertigung();
		pAuto3->vAbfertigung();
		pAuto4->vAbfertigung();

		cout << "Nach " << dGlobaleZeit << "h:" << endl;
		tAuto1.vAusgabe();
		cout << endl;
		tAuto2.vAusgabe();
		cout << endl;
		pAuto3->vAusgabe();
		cout << endl;
		pAuto4->vAusgabe();
		cout << endl << endl;
	}

	getchar();

	//Löschen der dynamischen Objekte
	delete pAuto4;	
	delete pAuto3;
}

/*
-!-War eine Idee, aber man müsste halt die einzelnen Objekte oder Pointer übergeben-!-
Rahmenfunktion für die Memberfunktion vAusgabe in Fahrzeug.h zur Ausgabe der Fahrzeuge und Daten

void vHauptausgabe()
{

}
*/

void vAufgabe_1_deb()
{
	Fahrzeug* pFeld[4] = { new Fahrzeug("Rot", 40.0), new Fahrzeug("Blau", 25.0),
							new Fahrzeug("Gruen", 30.0), new Fahrzeug("Gelb", 10.0) };

	for (int i = 0; i <= 3; i++)
	{
		pFeld[i]->vAusgabe();
		cout << endl;
	}

	pFeld[2] = 0;

	for (int i = 0; i <= 3; i++)
	{
		pFeld[i]->vAusgabe();
		cout << endl;
	}

}

void vAufgabe_2()
{
	int iAnzahlPKW, iAnzahlFahrrad;
	
	//Anzahl PKWs und Fahrräder einlesen
	cout << "Wie viele PKWs moechten Sie erstellen?" << endl;
	cin >> iAnzahlPKW;
	cout << "Wie viele Fahrraeder moechten sie erstellen?" << endl;
	cin >> iAnzahlFahrrad;

	//Vektor erstellen
	vector<Fahrzeug*> vecFahrzeuge;

	//PKWs erstellen und in Vektor schieben
	for (int i = 0; i < iAnzahlPKW; i++)
	{
		PKW* tempPKW = new PKW("PKW" + to_string(i+1), 50, 20);
		vecFahrzeuge.push_back(tempPKW);
	}

	//Fahrräder erstellen und in Vektor schieben
	for (int i = 0; i < iAnzahlFahrrad; i++)
	{
		Fahrrad* tempFR = new Fahrrad("Fahrrad" + to_string(i + 1), 25);
		vecFahrzeuge.push_back(tempFR);
	}

	//Tabellenkopf
	cout << endl << "ID  Name   :  MaxKmh  AktKmh   GesamtStrecke  GesamtVerbrauch  AktTankinhalt " << endl;
	cout << setw(62) << setfill('+') << " " << endl;
	
	//Fahrzeuge abfertigen und ausgeben
	for (double d = 0.0; d < 8; d += 0.1)
	{
		dGlobaleZeit = d;
		cout << "Nach " << dGlobaleZeit << "h:" << endl;

		for (int i = 0; i < vecFahrzeuge.size(); i++)
		{
			vecFahrzeuge[i]->vAbfertigung();

			//Nach 3h tanken
			if (fabs(dGlobaleZeit-3) < 0.001)
			{
				vecFahrzeuge[i]->dTanken(666);
			}

			//vecFahrzeuge[i]->vAusgabe();
			cout << *vecFahrzeuge[i];
			cout << endl;
		}
		cout << endl;
	}
}

void vAufgabe_3()
{
	PKW* tempPKW1 = new PKW("PKW 1" , 50, 20);
	PKW* tempPKW2 = new PKW("PKW 2", 50, 20);
	PKW tempPKW3("PKW 3", 50, 20);
	

		tempPKW3 = *tempPKW2;

	cout << *tempPKW1 << endl << *tempPKW2 << endl << tempPKW3 << endl;
	getchar();
}

int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	vAufgabe_3();
	getchar();
	return 0;
}

