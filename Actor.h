#pragma once
#include <string>
using namespace std;

class Actor
{
public:
	Actor();
	~Actor();
	void setName(string setname);
	void setLife(int setlife);
	void setAttack(int setattack);
	void setDefence(int setdefence);
	void setAlive(bool alive);

	string getName();
	int getLife();
	int getAttack();
	int getDefence();
	bool getAlive();

private:

	string name;
	int life;
	int attack;
	int defence;
	bool alive;
};

