/*
 * PROGRAM NAME: Exercise
 * PROGRAM DESCRIPTION: An Exercise class use to build an
 * exercise which includes name, reps, sets, and length
 * of rest time.
 *
 * PROGRAMMER NAME: Martin Mojica
 * Date created: 02/03/2015
 * Last data modified: 02/09/2015
 * 
 * SOURCES: GOOGLE ;)
 */
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Exercise
{
	private:
		string name;	//name of exercise
		int reps;	//number of reps
		int sets;	//number of sets
		int restTime;	//rest time
	public:
		/*
		 * Overloaded Constructor
		 *
		 * @param newName the value of exercise name
		 * @param newReps the value of repititions
		 * @param newSets the value of sets
		 * @param newRestTime the value of rest time
		 */
		Exercise ( string newName , int newReps , int newSets , int newRestTime );
		
		/*
		 * Destructor
		 */
		~Exercise ( );
		
		/*
		 * sets the name of the exercise
		 * @param newName the new value of name
		 */
		void setName ( string newName );
		
		/*
		 * sets the number of reps
		 * @param newReps the new value of reps
		 */
		void setReps ( int newReps );
		
		/*
		 * sets the number of sets
		 * @param newSets the new value of sets
		 */
		void setSets ( int newSets );
		
		/*
		 * sets the length of rest time
		 * @param newRestTime the new value of restTime
		 */
		void setRestTime ( int newRestTime );
		
		/*
		 * gets the name of the exercise
		 * @return the name of the exercise
		 */	
		string getName ( );
		
		/*
		 * gets the number of repititions
		 * @return the number of reps
		 */	
		int getReps ( );
		
		/*
		 * gets the number of sets
		 * @return the number of sets
		 */	
		int getSets ( );
		
		/*
		 * gets the length of rest time
		 * @return the length of restTime
		 */	
		int getRestTime ( );
};
