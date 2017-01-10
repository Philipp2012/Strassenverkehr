#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include <vector>
#include "SimuClient.h"
#include <stdlib.h>
#include "LazyListe.h"


//Uhr initialisieren (global)
double dGlobaleZeit = 0.0;

void vWegTabellenkopf()
{
	cout << setw(4) << resetiosflags(ios::right) << setiosflags(ios::left) << setfill(' ')
		<< "ID" << setw(9) << setfill(' ') << "Name" << "Laenge  Fahrzeuge" << endl;
}

void vAufgabe_4()
{
	Weg* WegTest = new Weg("Weg1", 133, Innerorts);
	PKW* BMW = new PKW("BMW", 10, 5);
	PKW* Audi = new PKW("Audi", 200, 5);
	PKW* Parki = new PKW("Parki", 50, 5);

	WegTest->vAnnahme(BMW);
	WegTest->vAnnahme(Audi);
	WegTest->vAnnahme(Parki, 3.0);

	vWegTabellenkopf();
	cout << *WegTest << endl;

	//Tabellenkopf
	cout << endl << "ID  Name     :  MaxKmh  AktKmh   GesamtStrecke AbschnittStrecke GesamtVerbrauch  AktTankinhalt " << endl;
	cout << setw(80) << setfill('+') << " " << endl;

	while (dGlobaleZeit < 4)
	{
		WegTest->vAbfertigung();
		
		cout << "Nach " << dGlobaleZeit << "h:" << endl;
		cout << *BMW << endl << *Audi << endl << *Parki << endl << endl;
		cout << *WegTest << endl;

		dGlobaleZeit += gZeitschritt;
	}
	getchar();
}


void vAufgabe_5()
{
	Weg* WegHin = new Weg("A", 500, Autobahn);
	Weg* WegRueck = new Weg("B", 500, Autobahn);

	PKW* Audi = new PKW("Audi", 200, 5);
	PKW* Parki = new PKW("Parki", 50, 5, 60, 250);

	WegHin->vAnnahme(Audi);
	WegRueck->vAnnahme(Parki, 1.0);

	int Koordinaten[4] = { 700, 250, 100, 250 };
	
	bInitialisiereGrafik(800, 500);

	bZeichneStrasse("A", "B", 500, 2, Koordinaten);
	bZeichnePKW("Audi", "A", 0.0, 200, 50);
	bZeichnePKW("Parki", "B", 0.5, 0, 60);

	while (dGlobaleZeit < 4)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "Nach " << dGlobaleZeit << "h" << endl;
		WegHin->vAbfertigung();
		WegRueck->vAbfertigung();

		dGlobaleZeit += gZeitschritt;
		vSleep(500);
	}
}

void vAufgabe_6a()
{
	LazyListe<int> Liste;
	LazyListe<int>::iterator itL;

	//Initialisieren der Liste mti Random Integers
	for (int i = 0; i < 20; i++)
	{
		int zahl = rand() % 10 + 1;
		Liste.push_back(zahl);
	}
	
	//Aktualisieren der Liste
	Liste.vAktualisieren();
	
	cout << "Liste wurde Initialisiert:" << endl;
	
	//Erste Ausgabe der Liste
	itL = Liste.begin();
	while (itL != Liste.end())
	{
		cout << *itL << endl;
		itL++;
	}

	cout << endl << "Löschen der Elemente >5" << endl;

	//Löschen der Elemente >5
	itL = Liste.begin();
	while (itL != Liste.end())
	{
		if (*itL > 5)
		{
			Liste.erase(itL);
		}
		itL++;
	}
	
	cout << "Die Liste ohne Aktualisierung:" << endl;

	//Ausgabe der Liste ohne Aktualisierung
	itL = Liste.begin();
	while (itL != Liste.end())
	{
		cout << *itL << endl;
		itL++;
	}

	Liste.vAktualisieren();

	cout << endl << "Die Liste mit Aktualisierung:" << endl;

	//Ausgabe der Liste mit Aktualisierung
	itL = Liste.begin();
	while (itL != Liste.end())
	{
		cout << *itL << endl;
		itL++;
	}

}

void vAufgabe_7()
{
	Weg* WegHin = new Weg("Hin", 500);
	Weg* WegRueck = new Weg("Rueck", 500);

	PKW* PKW1 = new PKW("PKW1", 200, 5);
	PKW* PKW2 = new PKW("PKW2", 50, 5, 60, 250);
	Fahrrad* Fahrrad1 = new Fahrrad("Fahrrad", 30);

	WegHin->vAnnahme(PKW1, 1.8);
	WegHin->vAnnahme(Fahrrad1, 1.0);

	int Koordinaten[4] = { 700, 250, 100, 250 };

	bInitialisiereGrafik(800, 500);

	bZeichneStrasse("Hin", "Rueck", 500, 2, Koordinaten);
	bZeichnePKW("PKW1", "Hin", 0.0, 200, 50);
	bZeichnePKW("PKW2", "Rück" , 0.5, 0, 60);

	while (dGlobaleZeit < 8)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "Nach " << dGlobaleZeit << "h" << endl;
		WegHin->vAbfertigung();
		WegRueck->vAbfertigung();

		if (fabs(dGlobaleZeit - 2) < gZeitschritt)
		{
			WegHin->vAnnahme(PKW2, 3.0);
		}

		dGlobaleZeit += gZeitschritt;
		vSleep(500);

	}
}

int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
	//vAufgabe_4();
	//vAufgabe_5();
	vAufgabe_6a();
	return 0;
}

