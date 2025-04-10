/* baseado no codigo mostrado em aula pelo professor Marcelo Johann
Otavio Capelão - 00274737*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

#ifdef s_type
#define s_type

enum s_type{
    SYMBOL_IDENTIFIER = 1;
    SYMBOL_LIT_INT = 2;
    SYMBOL_LIT_REAL = 3;
    SYMBOL_LIT_CHAR = 4;
    SYMBOL_LIT_STRING = 5;
    SYMBOL_KW_BYTE = 6;
};
#endif

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