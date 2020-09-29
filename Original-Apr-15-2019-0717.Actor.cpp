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

string Actor::getName()
{
	return string(name);
}

int Actor::getLife()
{
	return life;
}

int Actor::setAttack()
{
	return attack;
}

int Actor::setDefence()
{
	return defence;
}



Actor::~Actor()
{
}
