# the compiler: gcc for C program, define as g++ for C++
# Define required macros here
SHELL = /bin/sh

OBJS =  my_bank.o mb_util.o
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAG = -Wall -g
CC = g++
INCLUDE = .
LIBS = -lm

# $@ is the name of the file to be made.
# $? is the names of the changed dependents.
# Below, $@ represents my_bank and $? or $@.cpp picks up all the changed source files.
my_bank:${OBJ}
	${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}
clean:
	-rm -f *.o core *.core

# $< the name of the related file that caused the action.
# $* the prefix shared by target and dependent files.
.cpp.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $<
