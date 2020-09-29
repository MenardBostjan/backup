#include "pch.h"
#include "Actor.h"


Actor::Actor()
{
	life = 0;
	attack = 0;
}

void Actor::setName(string setname)
{
	name = setname;
}

void Actor::setLife(int setlife)
{
	life = setlife;
}

void Actor::setAttack(int setattack)
{
	attack = setattack;
}

void Actor::setDefence(int setdefence)
{
	defence = setdefence;
}

void Actor::setAlive(bool salive) 
{
	alive = salive;
}

string Actor::getName()
{
	return string(name);
}

int Actor::getLife()
{
	return life;
}

int Actor::getAttack()
{
	return attack;
}

int Actor::getDefence()
{
	return defence;
}


bool Actor::getAlive() 
{
	return alive;
}



Actor::~Actor()
{
}
