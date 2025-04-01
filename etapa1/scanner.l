%{
/*trabalho de compiladores 2025/1 - etapa 1
Otavio Capelão - 00274737
*/

#include <stdlib.h>
#include <map>
#include "symbols.hpp"
#include "tokens.h"
#include <algorithm>

extern struct SYMBOL symbol;
extern map<string, SYMBOL> *symbolTable;
extern int insertSymbol(string identifier, int type, map<string, SYMBOL> *symbolTable);
extern void initSymbolTable();

int running = 1;
int lineNbr = 1;
string inverse;

%}

%x COMMENT

%option nounput

%%
byte        {return KW_BYTE;}
int         {return KW_INT;}
real        {return KW_REAL;}

if          {return KW_IF;}
else        {return KW_ELSE;}
do          {return KW_DO;}
while       {return KW_WHILE;}
read        {return KW_READ;}
print       {return KW_PRINT;}
return      {return KW_RETURN;}

(<=)        {return OPERATOR_LE;}
(>=)        {return OPERATOR_GE;}          
(==)        {return OPERATOR_EQ;}
(!=)        {return OPERATOR_DIF;}

           
"//".*      
"/--"       {BEGIN(COMMENT);}
<COMMENT>"--/"       {BEGIN(INITIAL);}
<COMMENT>"\n"   {++lineNbr;}
<COMMENT>.      


[a-zA-Z_][_a-zA-Z0-9]* {InsertSymbol(yytext, TK_IDENTIFIER, symbolTable);
                        return TK_IDENTIFIER;}

[0-9]+\/[0-9]+           {InsertSymbol(yytext, LIT_REAL, symbolTable);
                        return LIT_REAL;}

[0-9]+                {inverse = std::string(yytext);
                        reverse(inverse.begin(), inverse.end());
                        InsertSymbol(inverse, LIT_INT, symbolTable);
                        return LIT_INT;}


\"([^\"\\]|\\.)*\"      {InsertSymbol(yytext, LIT_STRING, symbolTable);
                        return LIT_STRING;}

\'(\\.|.)\'             {InsertSymbol(yytext, LIT_CHAR, symbolTable);
                         return LIT_CHAR;}



[-,;:\(\)\[\]{}=\+\*/%<>\&\|~]      {return yytext[0];}


[ \t]+       
"\n"          {++lineNbr;}
.                       {return TOKEN_ERROR;}



%%

int yywrap(){
    running = 0;
    return 1;
}

int isRunning(){
    return running;
}

int getLineNumber(){
    return lineNbr;
}

void initMe(){
    InitSymbolTable();
}

