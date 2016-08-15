%{
/****************************************************************************
102342parser.y
ParserWizard generated YACC file.

Date: 2013Äê1ÔÂ31ÈÕ
****************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <tchar.h>
#include "102342lexer.h"
#include "102342VarTable.h"
#include "102342MidCodeManager.h"
#include "102342globalvs.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

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

// attribute type
%include {

#include "102342TreeNode.h"
#ifndef YYSTYPE
#define YYSTYPE TreeNode
#endif

}

// place any declarations here
%token INT
%token ID
%token PROGRAM
%token BEG
%token END
%token CONST
%token VAR
%token WHILE
%token DO
%token IF
%token THEN
%left '+'
%left '-'
%left '*'
%left '/'
%right A
%left '='
%left NE
%left '>'
%left BE
%left '<'
%left LE
%left '('
%left ')'
%left ';'
%left ','


 
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)
//
 	P:
	HEAD BODY
	{
		mesout<<"P->HEAD BODY"<<endl;
	};
	HEAD:
	PROGRAM ID
	{
		mesout<<"HEAD->PROGRAM ID"<<endl;
	};
	BODY:
	CONSTS VARS STATEMENT
	{
		mesout<<"BODY->CONSTS VARS STATEMENT"<<endl;
	};
	CONSTS:
	CONST CONSTDEFS ';'
	{
		mesout<<"CONSTS->CONST CONSTDEFS"<<endl;
	}|
	//EMPTY
	{
		mesout<<"CONSTS->/EMPTY/"<<endl;
	};
	CONSTDEFS:
	CONSTDEF ',' CONSTDEFS
	{
		mesout<<"CONSTDEFS->CONSTDEF ',' CONSTDEFS"<<endl;
	}|
	CONSTDEF 
	{
		mesout<<"CONSTDEFS->CONSTDEF"<<endl;
	};
	CONSTDEF:
	ID '=' INT
	{
		mesout<<"CONSTDEF->ID '=' INT"<<endl;
		vt.insertconst($1.name,$3.val);
	};
	VARS:
	VAR VARDEFS ';'
	{
		mesout<<"VARS->VAR VARDEFS"<<endl;
	}|
	//EMPTY
	{
		mesout<<"VARS->/EMPTY/"<<endl;
	};
	VARDEFS:
	VARDEF ',' VARDEFS
	{
		mesout<<"VARDEFS->VARDEF ',' VARDEFS"<<endl;
	}|
	VARDEF
	{
		mesout<<"VARDEFS->VARDEF"<<endl;	
	};
	VARDEF:
	ID
	{
		mesout<<"VARDEF->ID"<<endl;
		vt.insertvar($1.name);
	};
	BLOCK:
	BEG STATEMENTS END
	{
		mesout<<"BLOCK->BEG STATEMENTS END"<<endl;
		$$.n=new List;
		$$.n->add($2.n);
		//delete $2.n;
	};
	STATEMENTS:
	STATEMENT
	{
		mesout<<"STATEMENTS->STATEMENT"<<endl;
		$$.n=new List;
		
	}|
	STATEMENT ';' M STATEMENTS
	{
		mesout<<"STATEMENTS->STATEMENT ';' STATEMENTS"<<endl;
		mcm.backpatch($1.n,$3.q);
		//delete $1.n;
		$$.n=new List;
		$$.n->add($4.n);
		//delete $4.n
	};
	STATEMENT:
	ASSIGN
	{
		mesout<<"STATEMENT->ASSIGN"<<endl;
	}|
	IFTHENELSE
	{
		mesout<<"STATEMENT->IFTHENELSE"<<endl;
	}|
	WHILEDO
	{
		mesout<<"STATEMENT->WHILEDO"<<endl;
	}|
	BLOCK
	{
		mesout<<"STATEMENT->BLOCK"<<endl;
	}|
	//EMPTY
	{
		mesout<<"STATEMENT->/EMPTY/"<<endl;
	};
	ASSIGN:
	ID A EXPRESSION
	{
		mesout<<"ASSIGN->ID := EXPRESSION"<<endl;
		string pl;
		pl=vt.getplace($1.name);
		if (pl[0]=='[')
		{
			$$.place=pl;
			mcm.emit(":=",$3.place,"#",pl);
			vt.cleartemp();
		}
		else error();
	};
	EXPRESSION:
	TERM
	{
		mesout<<"EXPRESSION->TERM"<<endl;
		$$.place=$1.place;
	}|
	'+' TERM
	{
		mesout<<"EXPRESSION->+ TERM"<<endl;
		$$.place=$2.place;
	}|
	'-' TERM
	{
		mesout<<"EXPRESSION->- TERM"<<endl;
		string pl;
		pl=vt.addtemp();
		if (pl!="")
		{
			$$.place=pl;
			mcm.emit("-","0",$2.place,pl);
		}
		else error();
	}|
	EXPRESSION '+' TERM
	{
		mesout<<"EXPRESSION->EXPRESSION + TERM"<<endl;
		string pl;
		pl=vt.addtemp();
		if (pl!="")
		{
			$$.place=pl;
			mcm.emit("+",$1.place,$3.place,pl);
		}
		else error();
		
	}|
	EXPRESSION '-' TERM
	{
		mesout<<"EXPRESSION->EXPRESSION - TERM"<<endl;
		string pl;
		pl=vt.addtemp();
		if (pl!="")
		{
			$$.place=pl;
			mcm.emit("-",$1.place,$3.place,pl);
		}
		else error();
	};
	TERM:
	FACTOR
	{
		mesout<<"TERM->FACTOR"<<endl;
		$$.place=$1.place;
	}|
	TERM '*' FACTOR
	{
		mesout<<"TERM->TERM * FACTOR"<<endl;
		string pl;
		pl=vt.addtemp();
		if (pl!="")
		{
			$$.place=pl;
			mcm.emit("*",$1.place,$3.place,pl);
		}
		else error();
	}|
	TERM '/' FACTOR
	{
		mesout<<"TERM->TERM / FACTOR"<<endl;
		string pl;
		pl=vt.addtemp();
		if (pl!="")
		{
			$$.place=pl;
			mcm.emit("/",$1.place,$3.place,pl);
		}
		else error();
	};
	FACTOR:
	ID
	{
		mesout<<"FACTOR->ID"<<endl;
		string pl=vt.getplace($1.name);
		if (pl!="")
		{
			$$.place=pl;
		}
		else error();
	}|
	INT
	{
		mesout<<"FACTOR->INT"<<endl;
		$$.place=itostr($1.val);
	}|
	'(' EXPRESSION ')'
	{
		mesout<<"FACTOR->( EXPRESSION )"<<endl;
		$$.place=$2.place;
	};
	/*ADDSUB:
	'+'
	{
		mesout<<"ADDSUB-> +"<<endl;
	}|
	'-'
	{
		mesout<<"ADDSUB-> -"<<endl;
	};
	MULDIV:
	'*'
	{
		mesout<<"MULDIV-> *"<<endl;
	}|
	'/'
	{
		mesout<<"MULDIV-> /"<<endl;
	};*/
	IFTHENELSE:
	IF CONDITION THEN M STATEMENT
	{
		mesout<<"IFTHENELSE->IF CONDITION THEN STATEMENT"<<endl;
		mcm.backpatch($2.t,$4.q);
		//delete $2.t;
		$$.n=new List;
		$$.n->add($2.f);
		//delete $2.f;
		$$.n->add($5.n);
		//delete $5.n;
	};
	WHILEDO:
	WHILE M CONDITION DO M STATEMENT
	{
		mesout<<"WHILEDO->WHILE CONDITION DO STATEMENT"<<endl;
		mcm.backpatch($6.n,$2.q);
		//delete $6.n;
		mcm.backpatch($3.t,$5.q);
		//delete $3.t;
		$$.n= new List;
		$$.n=$3.f;
		//delete $3.f;
		mcm.emit("j","#","#",itostr($2.q));
	};
	M:
	//EMPTY
	{
		mesout<<"M->/EMPTY/"<<endl;
		$$.q=mcm.nextquad();
	};
	CONDITION:
	EXPRESSION OP EXPRESSION
	{
		mesout<<"CONDITION->EXPRESSION OP EXPRESSION"<<endl;
		$$.t=new List;
		$$.t->add(mcm.nextquad());
		mcm.emit("j"+$2.name,$1.place,$3.place,"#");
		$$.f=new List;
		$$.f->add(mcm.nextquad());
		mcm.emit("j","#","#","#");
		vt.cleartemp();
	};
	OP:
	'='
	{
		mesout<<"OP-> ="<<endl;
		$$.name="=";
	}|
	NE
	{
		mesout<<"OP-> <>"<<endl;
		$$.name="<>";
	}|
	'<'
	{
		mesout<<"OP-> <"<<endl;
		$$.name="<";
	}|
	LE
	{
		mesout<<"OP-> <="<<endl;
		$$.name="<=";
	}|
	'>'
	{
		mesout<<"OP-> >"<<endl;
		$$.name=">";
	}|
	BE
	{
		mesout<<"OP-> >="<<endl;
		$$.name=">=";
	};
	
	

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int _tmain(int argc, _TCHAR* argv[])
{
	
	int n = 1;
	mylexer lexer;
	/* (argc>1)
	{
		ifstream ifile(argv[1]);
		lexer.yyin->rdbuf(ifile.rdbuf());
	}
	if (argc>2)
	{
		ofstream ofile(argv[2]);
		mesout.rdbuf(ofile.rdbuf());
	}*/
	_TCHAR *res=_T("resource.res"),*mid=_T("midcode.mid"),*masm=_T("masmcode.asm"),*mes=_T("message.mes");
	if (argc>1) res=argv[1];
	if (argc>2) masm=argv[2];
	if (argc>3) mid=argv[3];
	if (argc>4) mes=argv[4];
	ifstream ifile(res);
	lexer.yyin->rdbuf(ifile.rdbuf());
	//ofstream ofile(mes);
	//mesout.rdbuf(ofile.rdbuf());
	mesout.open(mes);
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	mcm.fout(mid);
	masmcode(masm);
	mesout.close();
	return n;
}

