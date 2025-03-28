%{
/*trabalho de compiladores 2025/1 - etapa 1
Otavio Capelão - 00274737
*/

#include <stdlib.h>
#include <map>
#include "symbols.hpp"
#include "tokens.h"
#include <algorithm>

extern struct SYMBOL;
extern map<string, SYMBOL> *symbolTable;
extern int insertSymbol(string identifier, string type, map<string, SYMBOL> *symbolTable);
extern void initSymbolTable;

int running = 1;
int lineNbr = 1;
string inverse;

%}

%x COMMENT

%%
byte        {return KW_BYTE;}
char        {return KW_INT;}
real        {return KW_REAL;}

if          {return KW_IF;}
else        {return KW_ELSE;}
do          {return KW_DO;}
while       {return KW_WHILE;}
read        {return KW_PRINT;}
return      {return KW_RETURN;}

(<=)        {return OPERATOR_LE;}
(>=)        {return OPERATOR_GE;}          
(==)        {return OPERATOR_EQ;}
(!=)        {return OPERATOR_DIF;}

[ \t]       
"\n"          {++lineNbr}
"//".*      
"/--"       {begin(COMMENT);}
<COMMENT>"--/"       {begin(initial);}
<COMMENT>"\n"   {++lineNbr}
<COMMENT>.      


([A-Z|a-z])(_|A-Za-z) {insertSymbol(yytext, TK_IDENTIFIER, symbolTable);
                        return TK_IDENTIFIER;}

[0-9]+                {inverse = std::string(yytext);
                        reverse(inverse.begin(), inverse.end());
                        insertSymbol(inverse, LIT_INT, symbolTable);
                        return LIT_INT;}

\"([^\"\\]|\\"|\\n)*\" {insertSymbol(yytext, LIT_STRING, symbolTable);
                        return LIT_STRING;}

\'(\\.|.)\'             {insertSymbol(yytext, LIT_CHAR, symbolTable);
                         return LIT_CHAR;}

[0-9]+/[0-9]+           {insertSymbol(yytext, LIT_REAL, symbolTable);
                        return LIT_REAL}

[-,;:\(\)\[\]{}=\+\*/%<>\&\|~]      {return yytext[0];}



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
    initSymbolTable();
}

