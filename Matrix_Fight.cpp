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

int ranAttack() {
		return rand() % 50 + 50;
}

int ranDefence() {
	return rand() % 40;
}

int ranLife() {
	return 100;
}

int chooseOne() {
	return rand() % 20;
}

int main()
{
	
	string namelist[20];
	srand(time(NULL));
	int myrandom;

	/*  random rutine
		for (int i = 0; i < 20; i ++){
		myrandom = rand() % 100; // one number out of hundred!
		cout << "Random number: " << myrandom << endl;
	}*/

	fstream mynames("names.txt", ios::in|ios::out);
	string myname;
	vector<string> mynamelist;

	vector<Actor>actor;
	//actor.setname("somename of string");
	if (!mynames.is_open()) { cout << "Faild to open names list!" << endl; }
		else{
			cout << "names ready to be read into vector of strings!" << endl;
			
				while (!mynames.eof()) {
					getline(mynames, myname, '\n');
					mynamelist.push_back(myname);
				};
				cout << endl;
		};

/*
	cout << "Looks like names are set in an vector...lets see: " << endl;

	for (int i = 0; i < mynamelist.size()-10; i++)
		cout << i << "." << mynamelist[i] << endl;
*/

//---------------------------------------------------------------//
	actor.resize(20);
	for (int i = 0; i < mynamelist.size(); i++) {
		actor[i].setName((string)mynamelist[i]);
		actor[i].setLife((int)ranLife());
		actor[i].setAttack((int)ranAttack());
		actor[i].setDefence((int)ranDefence());

	}

	cout << "Now lets see how objects look like:" << endl;
	for (int i = 0; i < actor.size(); i++) {
		cout << i << ". actor name is: "<< actor[i].getName() <<
							 ",  Life: " << actor[i].getLife() <<
							", Attack:" << actor[i].getAttack() <<
							",Defence:"<< actor[i].getDefence() << endl;
	}

	/*choose two random actor*/
	int  firstAct, secondAct;
	int number_remain = 20;
	do { //main loop
		cout << "new loop!" << endl;
		
		
		do {
			
			//loop until someone with life is chosen. 
			cout << "Choose first actor again..." << endl;
			firstAct = chooseOne();
		} while (actor[firstAct].getLife() == 0); cout << "Fist one chosen!" << endl;
		
		
		do { //check if same actor is chosen, or someone with no life.
			secondAct = chooseOne(); cout << "Choose second actor again..." << endl;
		} while ((secondAct == firstAct) || (actor[secondAct].getLife() == 0)); 
				/*	1					0 1
					1					1 1
					0					1 1
					0					0 0  */
		cout << "Second one chosen." << endl;

		cout << "Two actors are chosen are: " << actor[firstAct].getName() << 
		     "("<< actor[firstAct].getLife() <<")" << " and " << actor[secondAct].getName() <<
			 "("<< actor[secondAct].getLife() <<")"<< "." << endl;
		cout << actor[firstAct].getName() << " attack:" << actor[firstAct].getAttack()<< " and defence: " << actor[firstAct].getDefence() << endl;
		cout << actor[secondAct].getName() << " attack:" << actor[secondAct].getAttack() << " and defence: " << actor[secondAct].getDefence() << endl;

	//}// while (getchar() != 'q');
	//fflush(stdin);
	
	/*first attack*/
	int attackpoints;

	//do 
	//{
		attackpoints = actor[firstAct].getAttack() - actor[secondAct].getDefence();
		cout << "Calculated attack poinst of first attacketr: " << attackpoints << endl;
		if (attackpoints < 0) attackpoints = 0; // case defence is stronger than attack you can do no damage. 
												// case attack is stronger difference takes life...until 0 life points.
		cout << "If they were in minus they were reset to zero.." << attackpoints<< endl;
		actor[secondAct].setLife(actor[secondAct].getLife() - attackpoints); // current life points of second actor minus attackpoints
		cout << actor[secondAct].getName() << " has now "
			<< actor[secondAct].getLife() << " life points." << endl;
																			 /*back attack*/
		if (actor[secondAct].getLife() > 0) 
		{										// case the other one is still aliver can return the attack...
			cout << actor[secondAct].getName() << " has some life left and makes revenge attack." << endl;
			attackpoints = actor[secondAct].getAttack() - actor[firstAct].getDefence();
			cout << "Attackpoinst of second actor: " << actor[secondAct].getName() << " " << attackpoints << endl;
			if (attackpoints < 0) attackpoints = 0; // case defence stronger than attack... no damage to life there..shield maybe?
			cout << "attackpoint set to zero if defence of opponent to strong.." << endl;
			actor[firstAct].setLife(actor[firstAct].getLife() - attackpoints);// life minus to first actor
			cout << actor[firstAct].getLife() << " life poits left to " << actor[firstAct].getName() << endl;
			if (actor[firstAct].getLife() <= 0) 
			{
				cout << " in case " << actor[firstAct].getName() << " has minus life points...he must be dead!" << endl;
				actor[firstAct].setLife(0);
				cout << " ...life set to zero!" << endl;
				cout << actor[firstAct].getName() << " is dead." << endl;
			};
		}
		else // case second one died already and cannot return attack
		{
			actor[secondAct].setLife(0);
			cout << actor[secondAct].getName() << " life set to 0! " << endl;
			cout << actor[secondAct].getName() << " just died! " << endl;
		};

		cout << "Next fight ..." << endl;
		getchar(); 
		fflush(stdin);

		//check if there is someone left to fight!
		number_remain = 20; // reset counter to starting point
		for (int i = 0; i < actor.size(); i++)
		{
			if (actor[i].getLife() == 0) number_remain--;
			
		}
		cout << "Looks like there is " << number_remain << " actors left..." << endl;
	} while (number_remain>1); // exit the main loop if there is only one remaining actor 

	cout << "It looks like we have a winner!!!" << endl;
	int winner;
	for (int i = 0; i < actor.size(); i++)
	{
		if (actor[i].getLife() != 0) winner = i;

	}
	cout << "Winner is " << actor[winner].getName() << "!!!" << endl;
	getchar();


		// cout << "From class object actor1: " <<  actor[1].getName() << endl;
		// cout << "From class object actor2: " << actor[2].getName() << endl;
}
