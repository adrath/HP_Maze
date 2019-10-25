###
### @Author - Alexander Drath
### @Date - 7/24/18
### @Description: The makefile for the final project

# Project Name
#
PROJ = Final_Project_Drath_Alexander

# Program Name
#
PROG = Harry_Potter

# Compiler
#
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time
#

# Valgrind Options
#
VOPT = --tool=memcheck
VOPT += --leak-check=full
VOPT += --show-leak-kinds=all
VOPT += --track-origins=yes

# The object files to be used in the program
#
OBJS = HarryPotterMain.o Menu.o HarryPotter.o Space.o FluffySpace.o DevilSnareSpace.o FlyingKeysSpace.o ChessGameSpace.o TrollSpace.o PotionChallengeSpace.o MirrorOfErisedSpace.o

# The source files for the program
#
SRCS = HarryPotterMain.cpp Menu.cpp HarryPotter.cpp Space.cpp FluffySpace.cpp DevilSnareSpace.cpp FlyingKeysSpace.cpp ChessGameSpace.cpp TrollSpace.cpp PotionChallengeSpace.cpp MirrorOfErisedSpace.cpp

# The header files for the program
#
HEADERS = Menu.hpp HarryPotter.hpp Space.hpp FluffySpace.hpp DevilSnareSpace.hpp FlyingKeysSpace.hpp ChessGameSpace.hpp TrollSpace.hpp PotionChallengeSpace.hpp MirrorOfErisedSpace.hpp

# Output binary
#
BIN = ${PROJ}.bin

# Compiling the object files using the compilers
#
Harry_Potter: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${PROG} 

# Making the object files for the program 
#
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

# Debug the program
#
debug: ${PROG}
	@valgrind ${VOPT} ./${PROG}

${BIN}: ${OBJ} ${HEADERS}
	@echo "CC $@"
	@${CXX} ${CFLAGS} $^ -o $@

# Default Behavior:
# 	1. Remove everything to start from scratch
# 	2. Compile the binary
# 	3. Run it through valgrind for quicker debugging
#
default: clean ${BIN} debug

# Cleaning the object files and program made by the makefile
#
clean:
	rm *o *zip ${PROG}

# Make a zip file of all of the source files, header files and the makefile
#
zip:
	zip ${PROJ} .zip *.cpp *.hpp makefile
