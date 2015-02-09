#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Exercise
{
	private:
		string name;
		int reps;
		int sets;
		int restTime;
	public:
		Exercise ( string newName , int newReps , int newSets , int newRestTime );
		~Exercise ( );
		void setName ( string newName );
		void setReps ( int newReps );
		void setSets ( int newSets );
		void setRestTime ( int newRestTime );
		string getName ( );
		int getReps ( );
		int getSets ( );
		int getRestTime ( );
};
