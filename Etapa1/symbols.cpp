#include "symbols.hpp"

map<string, SYMBOL> *symbolTable = new map<string, SYMBOL>();

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

int InsertSymbol(string identifier,string type, map<string, SYMBOL> *symbolTable){
    
    if((GetSymbol(identifier, symbolTable)) == ""){
        SYMBOL s;
        s.name = identifier;
        s.type = type;
        (*symbolTable)[identifier] = s;
        return 1;
    }
    return 0;
    
}

void printSymbolTable(){
    for(const auto &pair : *symbolTable){
        printf("Name: %s Type: %s\n", pair.second.name, pair.second.type);
    }
}