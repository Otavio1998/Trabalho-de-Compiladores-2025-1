// trabalho de compiladores 2025/1 Professor Marcelo Johann
// Otávio Capelão - 00274737
#include "symbols.hpp"

map<string, SYMBOL> *symbolTable = new map<string, SYMBOL>();
using namespace std;

void InitSymbolTable(){
    (*symbolTable).clear();
}

string GetSymbol(string identifier, map<string, SYMBOL> *symbolTable){
    if((*symbolTable).find(identifier) != (*symbolTable).end()){
        return ((*symbolTable)[identifier].name);
    }
    else{
        return "";
    }
       
}

int InsertSymbol(string identifier,int type, map<string, SYMBOL> *symbolTable){
    
    if((GetSymbol(identifier, symbolTable)) == ""){
        SYMBOL s;
        s.name = identifier;
        if (type == IDENTIFIER)
        {
            s.type = s_type::SYMBOL_IDENTIFIER;
        } 
        //s.type = type;
        (*symbolTable)[identifier] = s;
        return 1;
    }
    return 0;
    
}

int GetType(int type){

}

void printSymbolTable(){
    for(const auto &pair : *symbolTable){
        printf("Name: %s Type: %d\n", pair.second.name.c_str(), pair.second.type);
    }
}