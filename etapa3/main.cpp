//Trabalho de compiladores 2025/1 - etapa 1
// Baseado no codigo do professor Marcelo Johann mostrado em aula
// Otávio Capelão - 00274737
#include <iostream>
#include <map>
#include "ast.hpp"

using namespace std;

int isRunning();
void initMe();
int getLineNumber();

int yylex();
int yyparse(astnode* parsetreee);
extern char *yytext;
extern FILE *yyin;

void printSymbolTable();

int main(int argc, char **argv){
    if(argc < 3){
        fprintf(stderr, "Call: ./Etapa3 filename\n");
        exit(1);
    }

    if((yyin = fopen(argv[1], "r")) == 0){
        fprintf(stderr, "could not open file %s \n", argv[1]);
        exit(1);
    }

    if((yyin = fopen(argv[2], "w")) == 0){
        fprintf(stderr, "could not open file %s \n", argv[2]);
        exit(1);
    }

    initMe();

    astnode parsetree;

    int err = yyparse(&parsetree);

    if(err != 0){
        printf("parse error \n");
        exit(1);
    }
    else {
        printAST(&parsetree);
    }

    //printSymbolTable();
    //printf("numero de linhas: %d\n", getLineNumber());

    exit(0);

}