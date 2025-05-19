CXX = g++
CXXFLAGS = -std=c++11 -Wall
target = etapa3

etapa3:  main.o parser.tab.o lex.yy.o symbols.o ast.o
		$(CXX)  main.o parser.tab.o lex.yy.o symbols.o ast.o -o etapa3

%.o: %.cpp
		$(CXX) $(CXXFLAGS) $< -c

lex.yy.cpp: scanner.l
		flex -o lex.yy.cpp scanner.l

parser.tab.cpp parser.tab.hpp: parser.ypp
		bison -d -o parser.tab.cpp parser.ypp

clean: 
		rm etapa3 lex.yy.cpp parser.tab.cpp parser.tab.hpp *.o
