#
# PROGRAM:    assign4
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign7: assign7.o Queue.o
	g++ $(CCFLAGS) -o assign7 assign7.o Queue.o
   
# Rules to compile source code files to object code
assign7.o: assign7.cpp Queue.h
	g++ $(CCFLAGS) -c assign7.cpp
      
Queue.o: Queue.cpp Queue.h
	g++ $(CCFLAGS) -c Queue.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign7
