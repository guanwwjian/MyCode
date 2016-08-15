/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 112 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* 102342parser.cpp
* C++ source file generated from 102342parser.y.
* 
* Date: 02/16/13
* Time: 21:47:54
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\102342parser.y"

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

#line 55 "102342parser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\102342parser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 30 ".\\102342parser.y"

	// place any extra initialisation code here

#line 79 "102342parser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 35 ".\\102342parser.y"

	// place any extra cleanup code here

#line 93 "102342parser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 88 ".\\102342parser.y"

		mesout<<"P->HEAD BODY"<<endl;
	
#line 205 "102342parser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 93 ".\\102342parser.y"

		mesout<<"HEAD->PROGRAM ID"<<endl;
	
#line 220 "102342parser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 98 ".\\102342parser.y"

		mesout<<"BODY->CONSTS VARS STATEMENT"<<endl;
	
#line 235 "102342parser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 103 ".\\102342parser.y"

		mesout<<"CONSTS->CONST CONSTDEFS"<<endl;
	
#line 250 "102342parser.cpp"
			}
		}
		break;
	case 4:
		{
#line 107 ".\\102342parser.y"

		mesout<<"CONSTS->/EMPTY/"<<endl;
	
#line 260 "102342parser.cpp"
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 112 ".\\102342parser.y"

		mesout<<"CONSTDEFS->CONSTDEF ',' CONSTDEFS"<<endl;
	
#line 274 "102342parser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 116 ".\\102342parser.y"

		mesout<<"CONSTDEFS->CONSTDEF"<<endl;
	
#line 289 "102342parser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 121 ".\\102342parser.y"

		mesout<<"CONSTDEF->ID '=' INT"<<endl;
		vt.insertconst(yyattribute(1 - 3).name,yyattribute(3 - 3).val);
	
#line 305 "102342parser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 127 ".\\102342parser.y"

		mesout<<"VARS->VAR VARDEFS"<<endl;
	
#line 320 "102342parser.cpp"
			}
		}
		break;
	case 9:
		{
#line 131 ".\\102342parser.y"

		mesout<<"VARS->/EMPTY/"<<endl;
	
#line 330 "102342parser.cpp"
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 136 ".\\102342parser.y"

		mesout<<"VARDEFS->VARDEF ',' VARDEFS"<<endl;
	
#line 344 "102342parser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 140 ".\\102342parser.y"

		mesout<<"VARDEFS->VARDEF"<<endl;	
	
#line 359 "102342parser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 145 ".\\102342parser.y"

		mesout<<"VARDEF->ID"<<endl;
		vt.insertvar(yyattribute(1 - 1).name);
	
#line 375 "102342parser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 151 ".\\102342parser.y"

		mesout<<"BLOCK->BEG STATEMENTS END"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).n=new List;
		(*(YYSTYPE YYFAR*)yyvalptr).n->add(yyattribute(2 - 3).n);
		//delete $2.n;
	
#line 393 "102342parser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 159 ".\\102342parser.y"

		mesout<<"STATEMENTS->STATEMENT"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).n=new List;
		
	
#line 410 "102342parser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 165 ".\\102342parser.y"

		mesout<<"STATEMENTS->STATEMENT ';' STATEMENTS"<<endl;
		mcm.backpatch(yyattribute(1 - 4).n,yyattribute(3 - 4).q);
		//delete $1.n;
		(*(YYSTYPE YYFAR*)yyvalptr).n=new List;
		(*(YYSTYPE YYFAR*)yyvalptr).n->add(yyattribute(4 - 4).n);
		//delete $4.n
	
#line 430 "102342parser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 175 ".\\102342parser.y"

		mesout<<"STATEMENT->ASSIGN"<<endl;
	
#line 445 "102342parser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 179 ".\\102342parser.y"

		mesout<<"STATEMENT->IFTHENELSE"<<endl;
	
#line 460 "102342parser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 183 ".\\102342parser.y"

		mesout<<"STATEMENT->WHILEDO"<<endl;
	
#line 475 "102342parser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 187 ".\\102342parser.y"

		mesout<<"STATEMENT->BLOCK"<<endl;
	
#line 490 "102342parser.cpp"
			}
		}
		break;
	case 20:
		{
#line 191 ".\\102342parser.y"

		mesout<<"STATEMENT->/EMPTY/"<<endl;
	
#line 500 "102342parser.cpp"
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 196 ".\\102342parser.y"

		mesout<<"ASSIGN->ID := EXPRESSION"<<endl;
		string pl;
		pl=vt.getplace(yyattribute(1 - 3).name);
		if (pl[0]=='[')
		{
			(*(YYSTYPE YYFAR*)yyvalptr).place=pl;
			mcm.emit(":=",yyattribute(3 - 3).place,"#",pl);
			vt.cleartemp();
		}
		else error();
	
#line 523 "102342parser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 210 ".\\102342parser.y"

		mesout<<"EXPRESSION->TERM"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).place=yyattribute(1 - 1).place;
	
#line 539 "102342parser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 215 ".\\102342parser.y"

		mesout<<"EXPRESSION->+ TERM"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).place=yyattribute(2 - 2).place;
	
#line 555 "102342parser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 220 ".\\102342parser.y"

		mesout<<"EXPRESSION->- TERM"<<endl;
		string pl;
		pl=vt.addtemp();
		if (pl!="")
		{
			(*(YYSTYPE YYFAR*)yyvalptr).place=pl;
			mcm.emit("-","0",yyattribute(2 - 2).place,pl);
		}
		else error();
	
#line 578 "102342parser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 232 ".\\102342parser.y"

		mesout<<"EXPRESSION->EXPRESSION + TERM"<<endl;
		string pl;
		pl=vt.addtemp();
		if (pl!="")
		{
			(*(YYSTYPE YYFAR*)yyvalptr).place=pl;
			mcm.emit("+",yyattribute(1 - 3).place,yyattribute(3 - 3).place,pl);
		}
		else error();
		
	
#line 602 "102342parser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 245 ".\\102342parser.y"

		mesout<<"EXPRESSION->EXPRESSION - TERM"<<endl;
		string pl;
		pl=vt.addtemp();
		if (pl!="")
		{
			(*(YYSTYPE YYFAR*)yyvalptr).place=pl;
			mcm.emit("-",yyattribute(1 - 3).place,yyattribute(3 - 3).place,pl);
		}
		else error();
	
#line 625 "102342parser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 258 ".\\102342parser.y"

		mesout<<"TERM->FACTOR"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).place=yyattribute(1 - 1).place;
	
#line 641 "102342parser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 263 ".\\102342parser.y"

		mesout<<"TERM->TERM * FACTOR"<<endl;
		string pl;
		pl=vt.addtemp();
		if (pl!="")
		{
			(*(YYSTYPE YYFAR*)yyvalptr).place=pl;
			mcm.emit("*",yyattribute(1 - 3).place,yyattribute(3 - 3).place,pl);
		}
		else error();
	
#line 664 "102342parser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 275 ".\\102342parser.y"

		mesout<<"TERM->TERM / FACTOR"<<endl;
		string pl;
		pl=vt.addtemp();
		if (pl!="")
		{
			(*(YYSTYPE YYFAR*)yyvalptr).place=pl;
			mcm.emit("/",yyattribute(1 - 3).place,yyattribute(3 - 3).place,pl);
		}
		else error();
	
#line 687 "102342parser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 288 ".\\102342parser.y"

		mesout<<"FACTOR->ID"<<endl;
		string pl=vt.getplace(yyattribute(1 - 1).name);
		if (pl!="")
		{
			(*(YYSTYPE YYFAR*)yyvalptr).place=pl;
		}
		else error();
	
#line 708 "102342parser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 298 ".\\102342parser.y"

		mesout<<"FACTOR->INT"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).place=itostr(yyattribute(1 - 1).val);
	
#line 724 "102342parser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 303 ".\\102342parser.y"

		mesout<<"FACTOR->( EXPRESSION )"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).place=yyattribute(2 - 3).place;
	
#line 740 "102342parser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 327 ".\\102342parser.y"

		mesout<<"IFTHENELSE->IF CONDITION THEN STATEMENT"<<endl;
		mcm.backpatch(yyattribute(2 - 5).t,yyattribute(4 - 5).q);
		//delete $2.t;
		(*(YYSTYPE YYFAR*)yyvalptr).n=new List;
		(*(YYSTYPE YYFAR*)yyvalptr).n->add(yyattribute(2 - 5).f);
		//delete $2.f;
		(*(YYSTYPE YYFAR*)yyvalptr).n->add(yyattribute(5 - 5).n);
		//delete $5.n;
	
#line 762 "102342parser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 339 ".\\102342parser.y"

		mesout<<"WHILEDO->WHILE CONDITION DO STATEMENT"<<endl;
		mcm.backpatch(yyattribute(6 - 6).n,yyattribute(2 - 6).q);
		//delete $6.n;
		mcm.backpatch(yyattribute(3 - 6).t,yyattribute(5 - 6).q);
		//delete $3.t;
		(*(YYSTYPE YYFAR*)yyvalptr).n= new List;
		(*(YYSTYPE YYFAR*)yyvalptr).n=yyattribute(3 - 6).f;
		//delete $3.f;
		mcm.emit("j","#","#",itostr(yyattribute(2 - 6).q));
	
#line 785 "102342parser.cpp"
			}
		}
		break;
	case 35:
		{
#line 352 ".\\102342parser.y"

		mesout<<"M->/EMPTY/"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).q=mcm.nextquad();
	
#line 796 "102342parser.cpp"
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 358 ".\\102342parser.y"

		mesout<<"CONDITION->EXPRESSION OP EXPRESSION"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).t=new List;
		(*(YYSTYPE YYFAR*)yyvalptr).t->add(mcm.nextquad());
		mcm.emit("j"+yyattribute(2 - 3).name,yyattribute(1 - 3).place,yyattribute(3 - 3).place,"#");
		(*(YYSTYPE YYFAR*)yyvalptr).f=new List;
		(*(YYSTYPE YYFAR*)yyvalptr).f->add(mcm.nextquad());
		mcm.emit("j","#","#","#");
		vt.cleartemp();
	
#line 817 "102342parser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 370 ".\\102342parser.y"

		mesout<<"OP-> ="<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).name="=";
	
#line 833 "102342parser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 375 ".\\102342parser.y"

		mesout<<"OP-> <>"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).name="<>";
	
#line 849 "102342parser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 380 ".\\102342parser.y"

		mesout<<"OP-> <"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).name="<";
	
#line 865 "102342parser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 385 ".\\102342parser.y"

		mesout<<"OP-> <="<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).name="<=";
	
#line 881 "102342parser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 390 ".\\102342parser.y"

		mesout<<"OP-> >"<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).name=">";
	
#line 897 "102342parser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 395 ".\\102342parser.y"

		mesout<<"OP-> >="<<endl;
		(*(YYSTYPE YYFAR*)yyvalptr).name=">=";
	
#line 913 "102342parser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "\'(\'", 40 },
		{ "\')\'", 41 },
		{ "\'*\'", 42 },
		{ "\'+\'", 43 },
		{ "\',\'", 44 },
		{ "\'-\'", 45 },
		{ "\'/\'", 47 },
		{ "\';\'", 59 },
		{ "\'<\'", 60 },
		{ "\'=\'", 61 },
		{ "\'>\'", 62 },
		{ "error", 256 },
		{ "INT", 257 },
		{ "ID", 258 },
		{ "PROGRAM", 259 },
		{ "BEG", 260 },
		{ "END", 261 },
		{ "CONST", 262 },
		{ "VAR", 263 },
		{ "WHILE", 264 },
		{ "DO", 265 },
		{ "IF", 266 },
		{ "THEN", 267 },
		{ "A", 268 },
		{ "NE", 269 },
		{ "BE", 270 },
		{ "LE", 271 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: P",
		"P: HEAD BODY",
		"HEAD: PROGRAM ID",
		"BODY: CONSTS VARS STATEMENT",
		"CONSTS: CONST CONSTDEFS \';\'",
		"CONSTS:",
		"CONSTDEFS: CONSTDEF \',\' CONSTDEFS",
		"CONSTDEFS: CONSTDEF",
		"CONSTDEF: ID \'=\' INT",
		"VARS: VAR VARDEFS \';\'",
		"VARS:",
		"VARDEFS: VARDEF \',\' VARDEFS",
		"VARDEFS: VARDEF",
		"VARDEF: ID",
		"BLOCK: BEG STATEMENTS END",
		"STATEMENTS: STATEMENT",
		"STATEMENTS: STATEMENT \';\' M STATEMENTS",
		"STATEMENT: ASSIGN",
		"STATEMENT: IFTHENELSE",
		"STATEMENT: WHILEDO",
		"STATEMENT: BLOCK",
		"STATEMENT:",
		"ASSIGN: ID A EXPRESSION",
		"EXPRESSION: TERM",
		"EXPRESSION: \'+\' TERM",
		"EXPRESSION: \'-\' TERM",
		"EXPRESSION: EXPRESSION \'+\' TERM",
		"EXPRESSION: EXPRESSION \'-\' TERM",
		"TERM: FACTOR",
		"TERM: TERM \'*\' FACTOR",
		"TERM: TERM \'/\' FACTOR",
		"FACTOR: ID",
		"FACTOR: INT",
		"FACTOR: \'(\' EXPRESSION \')\'",
		"IFTHENELSE: IF CONDITION THEN M STATEMENT",
		"WHILEDO: WHILE M CONDITION DO M STATEMENT",
		"M:",
		"CONDITION: EXPRESSION OP EXPRESSION",
		"OP: \'=\'",
		"OP: NE",
		"OP: \'<\'",
		"OP: LE",
		"OP: \'>\'",
		"OP: BE"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 2, 0 },
		{ 2, 2, 1 },
		{ 3, 3, 2 },
		{ 4, 3, 3 },
		{ 4, 0, 4 },
		{ 5, 3, 5 },
		{ 5, 1, 6 },
		{ 6, 3, 7 },
		{ 7, 3, 8 },
		{ 7, 0, 9 },
		{ 8, 3, 10 },
		{ 8, 1, 11 },
		{ 9, 1, 12 },
		{ 10, 3, 13 },
		{ 11, 1, 14 },
		{ 11, 4, 15 },
		{ 12, 1, 16 },
		{ 12, 1, 17 },
		{ 12, 1, 18 },
		{ 12, 1, 19 },
		{ 12, 0, 20 },
		{ 13, 3, 21 },
		{ 14, 1, 22 },
		{ 14, 2, 23 },
		{ 14, 2, 24 },
		{ 14, 3, 25 },
		{ 14, 3, 26 },
		{ 15, 1, 27 },
		{ 15, 3, 28 },
		{ 15, 3, 29 },
		{ 16, 1, 30 },
		{ 16, 1, 31 },
		{ 16, 3, 32 },
		{ 17, 5, 33 },
		{ 18, 6, 34 },
		{ 19, 0, 35 },
		{ 20, 3, 36 },
		{ 21, 1, 37 },
		{ 21, 1, 38 },
		{ 21, 1, 39 },
		{ 21, 1, 40 },
		{ 21, 1, 41 },
		{ 21, 1, 42 }
	};
	yyreduction = reduction;

	yytokenaction_size = 231;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 41, YYAT_ERROR, 0 },
		{ 63, YYAT_SHIFT, 36 },
		{ 75, YYAT_SHIFT, 19 },
		{ 73, YYAT_SHIFT, 19 },
		{ 75, YYAT_SHIFT, 20 },
		{ 73, YYAT_SHIFT, 20 },
		{ 49, YYAT_SHIFT, 66 },
		{ 69, YYAT_SHIFT, 62 },
		{ 75, YYAT_SHIFT, 21 },
		{ 73, YYAT_SHIFT, 21 },
		{ 75, YYAT_SHIFT, 22 },
		{ 73, YYAT_SHIFT, 22 },
		{ 69, YYAT_SHIFT, 63 },
		{ 50, YYAT_SHIFT, 67 },
		{ 44, YYAT_SHIFT, 64 },
		{ 50, YYAT_SHIFT, 53 },
		{ 65, YYAT_SHIFT, 19 },
		{ 50, YYAT_SHIFT, 54 },
		{ 65, YYAT_SHIFT, 20 },
		{ 41, YYAT_SHIFT, 55 },
		{ 41, YYAT_SHIFT, 56 },
		{ 41, YYAT_SHIFT, 57 },
		{ 65, YYAT_SHIFT, 21 },
		{ 20, YYAT_SHIFT, 19 },
		{ 65, YYAT_SHIFT, 22 },
		{ 20, YYAT_SHIFT, 20 },
		{ 12, YYAT_SHIFT, 19 },
		{ 34, YYAT_SHIFT, 48 },
		{ 12, YYAT_SHIFT, 20 },
		{ 20, YYAT_SHIFT, 21 },
		{ 68, YYAT_SHIFT, 62 },
		{ 20, YYAT_SHIFT, 22 },
		{ 12, YYAT_SHIFT, 21 },
		{ 52, YYAT_SHIFT, 62 },
		{ 12, YYAT_SHIFT, 22 },
		{ 68, YYAT_SHIFT, 63 },
		{ 51, YYAT_SHIFT, 62 },
		{ 42, YYAT_SHIFT, 62 },
		{ 52, YYAT_SHIFT, 63 },
		{ 33, YYAT_SHIFT, 47 },
		{ 31, YYAT_SHIFT, 16 },
		{ 51, YYAT_SHIFT, 63 },
		{ 42, YYAT_SHIFT, 63 },
		{ 70, YYAT_SHIFT, 53 },
		{ 61, YYAT_SHIFT, 37 },
		{ 70, YYAT_SHIFT, 54 },
		{ 61, YYAT_SHIFT, 38 },
		{ 46, YYAT_SHIFT, 53 },
		{ 19, YYAT_SHIFT, 32 },
		{ 46, YYAT_SHIFT, 54 },
		{ 18, YYAT_SHIFT, 31 },
		{ 17, YYAT_SHIFT, 30 },
		{ 15, YYAT_SHIFT, 8 },
		{ 13, YYAT_SHIFT, 28 },
		{ 10, YYAT_SHIFT, 15 },
		{ 9, YYAT_SHIFT, 14 },
		{ 8, YYAT_SHIFT, 13 },
		{ 7, YYAT_SHIFT, 11 },
		{ 3, YYAT_SHIFT, 5 },
		{ 2, YYAT_ACCEPT, 0 },
		{ 1, YYAT_SHIFT, 4 },
		{ 0, YYAT_SHIFT, 1 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 63, YYAT_SHIFT, 39 },
		{ 63, YYAT_SHIFT, 40 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 41, YYAT_SHIFT, 58 },
		{ 41, YYAT_SHIFT, 59 },
		{ 41, YYAT_SHIFT, 60 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -198, 1, YYAT_ERROR, 0 },
		{ -198, 1, YYAT_ERROR, 0 },
		{ 59, 1, YYAT_ERROR, 0 },
		{ -204, 1, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_DEFAULT, 15 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ -206, 1, YYAT_REDUCE, 10 },
		{ -5, 1, YYAT_ERROR, 0 },
		{ -4, 1, YYAT_ERROR, 0 },
		{ 10, 1, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_DEFAULT, 31 },
		{ -232, 1, YYAT_REDUCE, 21 },
		{ -204, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -206, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ -8, 1, YYAT_ERROR, 0 },
		{ 6, 1, YYAT_REDUCE, 12 },
		{ -220, 1, YYAT_ERROR, 0 },
		{ -235, 1, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ -218, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ -222, 1, YYAT_ERROR, 0 },
		{ -32, 1, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 61 },
		{ 0, 0, YYAT_DEFAULT, 63 },
		{ 0, 0, YYAT_DEFAULT, 63 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ -41, 1, YYAT_DEFAULT, 50 },
		{ -5, 1, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ -253, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 4, 1, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ -259, 1, YYAT_ERROR, 0 },
		{ -28, 1, YYAT_ERROR, 0 },
		{ -6, 1, YYAT_REDUCE, 24 },
		{ -9, 1, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_DEFAULT, 63 },
		{ 0, 0, YYAT_DEFAULT, 63 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ 0, 0, YYAT_REDUCE, 41 },
		{ 1, 1, YYAT_DEFAULT, 63 },
		{ 0, 0, YYAT_DEFAULT, 63 },
		{ -39, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ -242, 1, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ -12, 1, YYAT_REDUCE, 26 },
		{ -35, 1, YYAT_REDUCE, 27 },
		{ 0, 1, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ -255, 1, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ -256, 1, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 35 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 40;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 75, 23 },
		{ 73, 76 },
		{ 75, 77 },
		{ 75, 24 },
		{ 35, 41 },
		{ 65, 74 },
		{ 65, 34 },
		{ 75, 25 },
		{ 75, 26 },
		{ 66, 75 },
		{ 35, 49 },
		{ 61, 70 },
		{ 61, 42 },
		{ 54, 69 },
		{ 54, 43 },
		{ 31, 45 },
		{ 31, 18 },
		{ 15, 29 },
		{ 15, 10 },
		{ 3, 6 },
		{ 3, 7 },
		{ 0, 2 },
		{ 0, 3 },
		{ 64, 73 },
		{ 63, 72 },
		{ 62, 71 },
		{ 53, 68 },
		{ 48, 65 },
		{ 41, 61 },
		{ 38, 52 },
		{ 37, 51 },
		{ 36, 50 },
		{ 32, 46 },
		{ 22, 44 },
		{ 21, 35 },
		{ 20, 33 },
		{ 12, 27 },
		{ 11, 17 },
		{ 7, 12 },
		{ 5, 9 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 20, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, -1 },
		{ 0, -1 },
		{ 34, 15 },
		{ 0, -1 },
		{ 31, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 29, 31 },
		{ 24, 75 },
		{ 0, -1 },
		{ 0, -1 },
		{ 12, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, 65 },
		{ 15, -1 },
		{ 13, 35 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, -1 },
		{ 18, 61 },
		{ 0, -1 },
		{ 0, -1 },
		{ -10, 61 },
		{ 17, 61 },
		{ 15, 54 },
		{ 14, 54 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 8, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 11, 54 },
		{ -2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -3, 54 },
		{ 9, -1 },
		{ 8, -1 },
		{ 4, -1 },
		{ -6, 75 },
		{ -10, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -11, 75 },
		{ 0, -1 },
		{ -10, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 402 ".\\102342parser.y"


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


