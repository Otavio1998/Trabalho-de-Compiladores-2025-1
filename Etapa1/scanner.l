%{
/*trabalho de compiladores 2025/1 - etapa 1
Otavio Capelão - 00274737
*/

#include <stdlib>
#include<map.h>
#include<symbols.hpp>
#include<tokens.h>

int running = 1;
int lineNbr = 1;

%}


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

([A-Z|a-z])(_|A-Za-z)   {}

[-,;:\(\)\[\]{}=\+\*/%<>\&\|~]      {return yytext[0]}



%%
