CC = g++
CFLAGS = -c 
LDFLAGS = 

trainHard: runWorkoutRoulette.o workoutRoulette.o
	$(CC) runWorkoutRoulette.o workoutRoulette.o -o trainHard

runWorkoutRoulette.o: runWorkoutRoulette.cpp
	$(CC) $(CFLAGS) runWorkoutRoulette.cpp

workoutRoulette.o: workoutRoulette.cpp workoutRoulette.h
	$(CC) $(CFLAGS) workoutRoulette.cpp

clean:
	rm *o trainHard
