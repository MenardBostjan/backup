// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.

// Matrix_Fight.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include "Actor.h"
#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	Actor actor[2];
	string namelist[20];
	srand(time(NULL));
	int myrandom;

	/*  random rutine
		for (int i = 0; i < 20; i ++){
		myrandom = rand() % 100; // one number out of hundred!
		cout << "Random number: " << myrandom << endl;
	}*/

	ifstream mynames("names.txt", ios::in);
	string myname;
	vector<string> mynamelist;

	vector<Actor>actor;
	//actor.setname("somename of string");
	if (!mynames.is_open()) { cout << "Faild to open names list!" << endl; }
		else{
			cout << "names ready to be read into array of strings!" << endl;
			
				while (!mynames.eof()) {
					getline(mynames, myname, '\n');
				//	cout << myname << " ";
					mynamelist.push_back(myname);
				};
				cout << endl;
		};

	for (int i = 0; i < mynamelist.size() - 1; i++)
		actor[i].setName(mynamelist[i]);

	cout << "Looks like names are set in an array...lets see: " << endl;
	
	for (int i = 0; i < mynamelist.size()-1; i++)
		cout << i+1 << "." << mynamelist[i] << endl;
/*
	string mytestlist[10];
	for (int i = 0; i < 19; i++)
		mytestlist[i] = i + "!";

	cout << " Print the result:";
	for (int i = 0; i < 19; i++)
		cout << mytestlist[i] << endl;*/

		//cout << "From class object actor1: " <<  actor[1].getName() << endl;
		//cout << "From class object actor2: " << actor[2].getName() << endl;
}
