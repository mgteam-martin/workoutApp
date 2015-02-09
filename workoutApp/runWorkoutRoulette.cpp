#include "workoutRoulette.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void populateDatabase ( string filename , vector<Exercise>& database );
void print ( Exercise workout );
void clearScreen ( );

int main ( int argc , char** argv )
{
	vector<Exercise> routine;
	vector<Exercise> database;
	string filename = argv [ 1 ];
	
	populateDatabase ( filename , database );	

	int numberOfWorkouts = 1;

	cout << "//////////////////// Workout Roulette ////////////////////" << endl;
	cout << "How many workouts would you like to do today (1-5): ";
	cin >> numberOfWorkouts;
	cout << endl;
	while ( numberOfWorkouts < 0 || numberOfWorkouts > 5 )	//fix incase it was non-numeric
	{
		cout << "Enter a valid number: ";
		cin >> numberOfWorkouts;
	}

	srand ( time(NULL) );	//Initialize random seed
	
	cout << "Building routine...";
	for ( int i = 0; i < numberOfWorkouts; i++ )
	{
		int randomNumber = rand() % database.size ( ) + 0;	//Generate secret number
		cout << randomNumber << endl;
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
