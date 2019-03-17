#
# PROGRAM:    assign8
# PROGRAMMER: Damler, Lucas
# LOGON ID:   z1761739
# DATE DUE:   25 APR 2017
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign1: assign2.o MainProcess.o SeqProcess.o
	g++ $(CCFLAGS) -o assign2 assign2.o MainProcess.o SeqProcess.o

# Rules to compile source code file to object code
assign1.o: assign2.cpp MainProcess.h
	g++ $(CCFLAGS) -c assign2.cpp

MainProcess.o: MainProcess.cpp MainProcess.h
	g++ $(CCFLAGS) -c MainProcess.cpp

SeqProcess.o: SeqProcess.cpp MainProcess.h
	g++ $(CCFLAGS) -c SeqProcess.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign2
