%{
/****************************************************************************
102342lexer.l
ParserWizard generated Lex file.

Date: 2013Äê1ÔÂ31ÈÕ
****************************************************************************/

#include "102342parser.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

// class definition
{
	// place any extra class members here
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// place any declarations here
INT [1-9][0-9]*|0
ID [a-zA-Z][a-zA-Z_0-9]*

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here
"PROGRAM" {return PROGRAM;}
"BEGIN" {return BEG;}
"END" {return END;}
"CONST" {return CONST;}
"VAR" {return VAR;}
"WHILE" {return WHILE;}
"DO" {return DO;}
"IF" {return IF;}
"THEN" {return THEN;}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
":=" {return A;}
"=" {return '=';}
"<>" {return NE;}
">" {return '>';}
">=" {return BE;}
"<" {return '<';}
"<=" {return LE;}
"(" {return '(';}
")" {return ')';}
";" {return ';';}
"," {return ',';}
{INT} {yylval.val=atoi(yytext);return INT;}
{ID} {yylval.name.assign(yytext);return ID;}


%%
/*lexstart(int argc, char* argv[])
{
if (argc>1)
	{
		FILE *ifile;
		ifile = fopen(argv[1],"r");
		if (!ifile)
		{
			fprintf(stderr,"could not open %s\n",argv[1]);
			exit(1);
		}
		yyin=ifile;
	}
	if (argc>2)
	{
		FILE *ofile;
		ofile = fopen(argv[1],"w");
		if (!ofile)
		{
			fprintf(stderr,"fail to creat %s\n",argv[2]);
			exit(2);
		}
		yyout=ofile;
	}
}
void lexend(int argc, char* argv[])
{

}*/

/////////////////////////////////////////////////////////////////////////////
// programs section

