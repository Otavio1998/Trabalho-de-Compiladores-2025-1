CXX = g++
CXXFLAGS = -std=c++11 -Wall
target = etapa2

etapa2:  main.o parser.tab.o lex.yy.o symbols.o 
		$(CXX)  main.o parser.tab.o lex.yy.o symbols.o  -o etapa2

%.o: %.cpp
		$(CXX) $(CXXFLAGS) $< -c

lex.yy.cpp: scanner.l
		flex -o lex.yy.cpp scanner.l

parser.tab.cpp: parser.ypp
		bison -d parser.ypp -d

clean: 
		rm etapa2 lex.yy.cpp parser.tab.cpp parser.tab.hpp*.o