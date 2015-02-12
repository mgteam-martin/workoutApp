CC = g++

SRCDIR = src
BUILDDIR = build
TARGET = bin/trainHard

SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS = -c
INC = -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
#	@mkdir -p $(BUILDDIR)
	@mkdir -p $(dir $@)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester


#trainHard: runWorkoutRoulette.o workoutRoulette.o
#	$(CC) runWorkoutRoulette.o workoutRoulette.o -o trainHard

#runWorkoutRoulette.o: runWorkoutRoulette.cpp
#	$(CC) $(CFLAGS) runWorkoutRoulette.cpp

#workoutRoulette.o: workoutRoulette.cpp workoutRoulette.h
#	$(CC) $(CFLAGS) workoutRoulette.cpp

#clean:
#	rm *o trainHard
