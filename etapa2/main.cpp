//Trabalho de compiladores 2025/1 - etapa 1
// Baseado no codigo do professor Marcelo Johann mostrado em aula
// Otávio Capelão - 00274737
#include <iostream>
#include <map>

using namespace std;

int isRunning();
void initMe();
int getLineNumber();

int yylex();
int yyparse();
extern char *yytext;
extern FILE *yyin;

void printSymbolTable();

int main(int argc, char **argv){
    if(argc < 2){
        fprintf(stderr, "Call: ./Etapa2 filename\n");
        exit(1);
    }

    if((yyin = fopen(argv[1], "r")) == 0){
        fprintf(stderr, "could not open file %s \n", argv[1]);
        exit(1);
    }

    initMe();

    yyparse();

    printSymbolTable();
    printf("numero de linhas: %d\n", getLineNumber());

    exit(0);

}