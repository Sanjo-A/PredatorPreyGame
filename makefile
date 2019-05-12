 #***************************************************************************
 #*  Name: makefile
 #* Author: Group 24
 #* Date: 5/11/19
 #* Description: This is a make file that turns source files into object files
 #then links them into a final executable called main.  This code was taken
 #from the makefile lecture .txt file from CS 162 Oregon State University
 #class and CS162 Piazza.
 #****************************************************************************
CXX = g++
 CXXFLAGS = -std=c++0x
 CXXFLAGS += -Wall
 CXXFLAGS += -pedantic-errors
 CXXFLAGS += -g
 #CXXFLAGS += -O3
 LDFLAGS = -lboost_date_time
 
 OBJS = main.o Ant.o Critter.o Doodlebug.o Edge.o Game.o RNG.o Menu.o  

 SRCS = main.cpp Ant.cpp Critter.cpp Doodlebug.cpp Edge.cpp Game.cpp RNG.cpp Menu.cpp
 
HEADERS = Ant.hpp Critter.hpp Doodlebug.hpp Edge.hpp Game.hpp RNG.hpp Menu.hpp
 
main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o main
 
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
 
clean:
	rm *.o main
