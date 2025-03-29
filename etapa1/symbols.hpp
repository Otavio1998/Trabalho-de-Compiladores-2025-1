/* baseado no codigo mostrado em aula pelo professor Marcelo Johann
Otavio Capelão - 00274737*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct SYMBOL{
    string name;
    int type;
};

void InitSymbolTable();

//inserts symbols in the table
int InsertSymbol(string identifier,int type,  map<string, SYMBOL> *symbolTable);

//returns a symbol from the table
string GetSymbol(string identifier, map<string, SYMBOL> *symbolTable);

void printSymbolTable();