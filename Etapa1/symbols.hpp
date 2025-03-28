/* baseado no codigo mostrado em aula pelo professor Marcelo Johann*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, SYMBOL> *symbolTable;

struct SYMBOL{
    string name;
    string type;
};

void InitSymbolTable();

//inserts symbols in the table
int InsertSymbol(string identifier,string type,  map<string, SYMBOL> *symbolTable);

//returns a symbol from the table
string GetSymbol(string identifier, map<string, SYMBOL> *symbolTable);

void printSymbolTable();