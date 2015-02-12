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

void menu ( vector<Exercise>& routine , vector<Exercise> database );

void createCustom ( vector<Exercise>& routine , vector<Exercise> database );

void roulette ( vector<Exercise>& routine , vector<Exercise> database );

void previousWorkout ( );

void viewLogs ( );

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

int randomizer ( int min , int max );

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

	menu ( routine , database );

	return 0;
}

void menu ( vector<Exercise>& routine , vector<Exercise> database )
{
	clearScreen ( );
	int selection;

	cout << "*********************** Train Hard ************************" << endl;
	cout << "*                                                         *" << endl;
	cout << "*                                                         *" << endl;
	cout << "*        [0] Create Custom Routine                        *" << endl;
	cout << "*        [1] Workout Roulette                             *" << endl;
	cout << "*        [2] Continue Previous Routine                    *" << endl;
	cout << "*        [3] View Logs                                    *" << endl;
	cout << "*        [4] Quit                                         *" << endl;
	cout << "***********************************************************" << endl;
	cout << "Make a selection: ";
	cin >> selection;
	
	switch ( selection )
	{
		case 0:
			//create custom routine
			createCustom ( routine , database );
			break;
		case 1:
			//workout roulette
			roulette ( routine , database );
			break;
		case 2:
			//continue previous routine
			previousWorkout ( );
			break;
		case 3:
			//view logs
			viewLogs ( );
			break;
		case 4:
			//quit
			break;
		default:
			//default case
			break;
	}
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

void createCustom ( vector<Exercise>& routine , vector<Exercise> database )
{
}

void roulette ( vector<Exercise>& routine , vector<Exercise> database )
{
	int numberOfWorkouts = 1;
	int max = database.size ( ) - 1;
	int min = 0;
	char trainingType;
	vector <int> used;
	int randomNumber;
	bool alreadyUsed = false;

	cout << "Would you like to do Strength Training (4 Workouts) or Circuit Training (10 Workouts): ";	//FIX: use s and c ONLY
	cin >> trainingType;
	if ( trainingType == 's' )
		numberOfWorkouts = 4;
	else 
		numberOfWorkouts = 10;

	srand ( time ( NULL ) );	//Initialize random seed
	
	clearScreen ( );
	
	cout << "Building routine..." << endl;
	
	for ( int i = 0; i < numberOfWorkouts; i++ )
	{

		if ( used.size ( ) > 0 )
		{
			do { 
				alreadyUsed = false;
				randomNumber = randomizer ( min , max );
				cout << randomNumber << endl;
				for ( int j = 0; j < used.size ( ); j++ )
					if ( used [ j ] == randomNumber )
						alreadyUsed = true;
			} while ( alreadyUsed == true );
		}
		else
			randomNumber = randomizer ( min , max );
	
		used.push_back ( randomNumber );
		routine.push_back ( database [ randomNumber ] ); 
	}

	cout << "Get ready to do " << numberOfWorkouts << " workouts" << endl;

	for ( int i = 0; i < routine.size ( ); i++ )
	{
		print ( routine [ i ] );	
	}

}

void previousWorkout ( )
{

}

void viewLogs ( )
{

}

void print ( Exercise workout )
{
         cout << "Exercise: " << workout.getName ( ) << endl;
         cout << "Reps ( Max ): " << workout.getReps ( ) << endl;
         cout << "Sets: " << workout.getSets ( ) << endl;
         cout << "Rest Time ( mins ): " << workout.getRestTime ( ) << endl;
}

int randomizer ( int min , int max )
{
	int randomNumber = rand ( ) % max + min;
	return randomNumber;
}

void clearScreen ( )
{
	#ifdef WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
