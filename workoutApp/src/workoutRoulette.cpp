#include "workoutRoulette.h"

Exercise::Exercise ( string newName , int newReps , int newSets , int newRestTime )
: name ( newName ) , reps ( newReps ) , sets ( newSets ) , restTime ( newRestTime )
{
}

Exercise::~Exercise ( )
{
}

void Exercise::setName ( string newName )
{
	name = newName;
}

void Exercise::setReps ( int newReps )
{
	reps = newReps;
}

void Exercise::setSets ( int newSets )
{
	sets = newSets;
}

void Exercise::setRestTime ( int newRestTime )
{
	restTime = newRestTime;
}

string Exercise::getName ( )
{
	return name;
}

int Exercise::getReps ( )
{
	return reps;
}

int Exercise::getSets ( )
{
	return sets;
}

int Exercise::getRestTime ( )
{
	return restTime;
}
