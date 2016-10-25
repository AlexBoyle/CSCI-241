#
# PROGRAM:    assign4
# PROGRAMMER: your name
# LOGON ID:   your z-id
# DATE DUE:   due date of program
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign5: assign5.o VectorN.o
	g++ $(CCFLAGS) -o assign5 assign5.o VectorN.o
   
# Rules to compile source code files to object code
assign5.o: assign5.cpp VectorN.h
	g++ $(CCFLAGS) -c assign5.cpp
      
VectorN.o: VectorN.cpp VectorN.h
	g++ $(CCFLAGS) -c VectorN.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign5
