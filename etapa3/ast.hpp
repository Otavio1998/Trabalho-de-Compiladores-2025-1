//Compiladores 2025/1 - Otavio Capelão - 00274737 - etapa3

#ifndef AST_HPP
#define AST_HPP

#include "symbols.hpp"

#define MAX_SONS 4

enum AST_TYPE {
    AST_SYMBOL = 1,
    AST_DCLR,
    AST_DCLRVAR,
    AST_DCLRFUNC,
    AST_DCLRVEC,
    AST_VECVALS,
    AST_ADD,
    AST_SUB,
    AST_MUL,
    AST_DIV,
    AST_GT,
    AST_LE,
    AST_EQ,
    AST_GE,
    AST_LT,
    AST_DIF,
    AST_AND,
    AST_OR,
    AST_NOT,
    AST_CMNDBLCK,
    AST_FUNCALL,
    AST_FUNCARGS,
    AST_CMNDSEQ,
    AST_CMNDATR,
    AST_IF,
    AST_DO,
    AST_WHILE,
    AST_PARAM,
    AST_PRINT,
    AST_READ,
    AST_PRINTARGS,
    AST_INT,
    AST_CHAR,
    AST_REAL,
    AST_BYTE,
    AST_STRING,
    AST_RETURN,

};

struct astnode {
    int type;
    SYMBOL *symbolo;
    struct astnode *son[MAX_SONS];
    
};

astnode *createNode(int type, SYMBOL* symbolo, astnode* s0, astnode* s1, astnode* s2, astnode* s3);

astnode *CreateSymbolNode(SYMBOL* symbolo, astnode* access = NULL);

void printAST(astnode* node, int lv = 0);


#endif