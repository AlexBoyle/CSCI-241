#
# PROGRAM:    assign4
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign6: assign6.o Queue.o
	g++ $(CCFLAGS) -o assign6 assign6.o Queue.o
   
# Rules to compile source code files to object code
assign6.o: assign6.cpp Queue.h
	g++ $(CCFLAGS) -c assign6.cpp
      
Queue.o: Queue.cpp Queue.h
	g++ $(CCFLAGS) -c Queue.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign6
