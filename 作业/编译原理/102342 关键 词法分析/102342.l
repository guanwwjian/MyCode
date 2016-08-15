%{
   #include "stdio.h"
   #include "stdlib.h"
   
%}
INT [1-9][0-9]*|0
ID [a-zA-Z][a-zA-Z_0-9]*
%%
DIM {printf("$DIM:%s ",yytext);}
IF {printf("$IF:%s ",yytext);}
DO {printf("$DO:%s ",yytext);}
STOP {printf("$STOP:%s ",yytext);}
END {printf("$END:%s ",yytext);}
{ID} {printf("$ID:%s ",yytext);}
{INT} {printf("$INT:%d ",atoi(yytext));}
"=" {printf("$ASSIGN:%s ",yytext);}
"+" {printf("$PLUS:%s ",yytext);}
"-" {printf("$MINUS:%s ",yytext);}
"*" {printf("$STAR:%s ",yytext);}
"/" {printf("$DIVIDE:%s ",yytext);}
"**" {printf("$POWER:%s ",yytext);}
"," {printf("$COMMA:%s ",yytext);}
"(" {printf("$LPAR:%s ",yytext);}
")" {printf("$RPAR:%s ",yytext);}
%%

int main()
{
  yylex();
}
int yywrap()

{
    return 1;
}

