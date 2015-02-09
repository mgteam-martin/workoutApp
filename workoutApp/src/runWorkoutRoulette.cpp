/*
 * PROGRAM NAME: trainHard
 * PROGRAM DESCRIPTION: A full featured workout application. It will have
 * many features such as roulette workout, workout log, 1rm calculation
 * and so much more.
 *
 * PROGRAMMER NAME: Martin Mojica
 * Date created: 02/03/2015
 * Last data modified: 02/09/2015
 * 
 * SOURCES: GOOGLE ;)
 */
#include "workoutRoulette.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * Populates the database with the information from workoutList file
 * @param filename is the workoutList file
 * @param database is vector that holds our full list of exercises
 */
void populateDatabase ( string filename , vector<Exercise>& database );

/*
 * Prints the exercise information
 * @param workout is the exercise to print out
 */
void print ( Exercise workout );

/*
 * Clears the screen
 */
void clearScreen ( );

int main ( int argc , char** argv )
{
	vector<Exercise> routine;	//holds the actual workout routine to be used
	vector<Exercise> database;	//holds all the workouts
	string filename = argv [ 1 ];	//workoutList file
	
	populateDatabase ( filename , database );	

	int numberOfWorkouts = 1;

	cout << "//////////////////// Workout Roulette ////////////////////" << endl;
	cout << "How many workouts would you like to do today (1-5): ";
	cin >> numberOfWorkouts;
	cout << endl;
	while ( numberOfWorkouts < 0 || numberOfWorkouts > 5 )	//FIX: incase it was non-numeric
	{
		cout << "Enter a valid number: ";
		cin >> numberOfWorkouts;
	}

	srand ( time ( NULL ) );	//Initialize random seed
	
	cout << "Building routine...";
	for ( int i = 0; i < numberOfWorkouts; i++ )
	{
		int randomNumber = rand() % database.size ( ) + 0;	//Generate secret number
		cout << randomNumber << endl;				//FIX: Check to make sure exercise is not already in routine
		routine.push_back ( database [ randomNumber ] ); 
	}

	cout << "Get ready to do " << numberOfWorkouts << " workouts" << endl;

	for ( int i = 0; i < routine.size ( ); i++ )
	{
		print ( routine [ i ] );	
	}


	return 0;
}

void populateDatabase ( string filename , vector<Exercise>& database )
{
	ifstream fin ( filename.c_str ( ) );
	istringstream iss;
	string buffer = "";

	string exerciseName = "";
	string strReps;
	string strSets;
	string strRestTime;

	int numberOfReps;
	int numberOfSets;
	int intervalRestTime;

	if ( fin.good ( ) )
	{
	
		while ( getline ( fin , buffer ) )
		{
			exerciseName = buffer.substr ( 0 , buffer.find ( ',' ) - 1 );
			buffer.erase ( 0 , buffer.find ( ',' ) + 1 );
			
			strReps = buffer.substr ( 0 , buffer.find ( ',' ) - 1 );
			buffer.erase ( 0 , buffer.find ( ',' ) + 1 );
			
			strSets = buffer.substr ( 0 , buffer.find ( ',' ) - 1 );
			buffer.erase ( 0 , buffer.find ( ',' ) + 1 );
		
			strRestTime = buffer;

			iss.str ( strReps );
			iss >> numberOfReps;
			iss.clear ( );
		
			iss.str ( strSets );
			iss >> numberOfSets;
			iss.clear ( );
		
			iss.str ( strRestTime );
			iss >> intervalRestTime;
			iss.clear ( );

			Exercise  workout ( exerciseName , numberOfReps , numberOfSets , intervalRestTime );
		
			database.push_back ( workout );
		}
	}
}

void print ( Exercise workout )
{
         cout << "Exercise: " << workout.getName ( ) << endl;
         cout << "Reps ( Max ): " << workout.getReps ( ) << endl;
         cout << "Sets: " << workout.getSets ( ) << endl;
         cout << "Rest Time ( mins ): " << workout.getRestTime ( ) << endl;
}

void clearScreen ( )
{
	#ifdef WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
