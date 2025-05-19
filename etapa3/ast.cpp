//compiladores 2025/1 - Otavio Capelão - 00274737 - etapa3

#include "ast.hpp"

const char* AST_TP[] = {
    "AST_SYMBOL",
    "AST_DCLR",
    "AST_DCLRVAR",
    "AST_DCLRFUNC",
    "AST_DCLRVEC",
    "AST_VECVALS",
    "AST_ADD",
    "AST_SUB",
    "AST_MUL",
    "AST_DIV",
    "AST_GT",
    "AST_LE",
    "AST_EQ",
    "AST_GE",
    "AST_LT",
    "AST_DIF",
    "AST_AND",
    "AST_OR",
    "AST_NOT",
    "AST_CMNDBLCK",
    "AST_FUNCALL",
    "AST_FUNCARGS",
    "AST_CMNDSEQ",
    "AST_CMNDATR",
    "AST_IF",
    "AST_DO",
    "AST_WHILE",
    "AST_PARAM",
    "AST_PRINT",
    "AST_READ",
    "AST_PRINTARGS",
    "AST_INT",
    "AST_CHAR",
    "AST_REAL",
    "AST_BYTE",
    "AST_STRING", 
    "AST_RETURN"
};

astnode *createNode(int type, SYMBOL* symbolo, astnode *s0, astnode *s1, astnode *s2, astnode *s3) {
    astnode *node = (astnode *)malloc(sizeof(astnode));
    node->type = type;
    node->symbolo = symbolo;
    node->son[0] = s0;
    node->son[1] = s1;
    node->son[2] = s2;
    node->son[3] = s3;
    return node;
}

astnode *CreateSymbolNode(SYMBOL* symbolo, astnode* access) {
    return createNode(AST_SYMBOL, symbolo, access, NULL, NULL, NULL);
}

void printAST(astnode *node, int level) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    if(node->type){
        printf("%s", AST_TP[node->type -1]);
    } else {
        printf("NULL");
    }

    if(node->symbolo) {
        printf(", %s", node->symbolo->name);
    }
    else if(node->type == AST_SYMBOL) {
        printf(" NULL");
    }

    for(int i = 0; i< MAX_SONS;i++){
        printAST(node->son[i], level +1);
    }

}
