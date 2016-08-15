/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 110 of your 30 day trial period.
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
* 102342lexer.cpp
* C++ source file generated from 102342lexer.l.
* 
* Date: 02/14/13
* Time: 20:55:07
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\102342lexer.l"

/****************************************************************************
102342lexer.l
ParserWizard generated Lex file.

Date: 2013Äê1ÔÂ31ÈÕ
****************************************************************************/

#include "102342parser.h"

#line 49 "102342lexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\102342lexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 24 ".\\102342lexer.l"

	// place any extra initialisation code here

#line 73 "102342lexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 29 ".\\102342lexer.l"

	// place any extra cleanup code here

#line 85 "102342lexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 42 ".\\102342lexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 156 "102342lexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 48 ".\\102342lexer.l"
return PROGRAM;
#line 163 "102342lexer.cpp"
		}
		break;
	case 2:
		{
#line 49 ".\\102342lexer.l"
return BEG;
#line 170 "102342lexer.cpp"
		}
		break;
	case 3:
		{
#line 50 ".\\102342lexer.l"
return END;
#line 177 "102342lexer.cpp"
		}
		break;
	case 4:
		{
#line 51 ".\\102342lexer.l"
return CONST;
#line 184 "102342lexer.cpp"
		}
		break;
	case 5:
		{
#line 52 ".\\102342lexer.l"
return VAR;
#line 191 "102342lexer.cpp"
		}
		break;
	case 6:
		{
#line 53 ".\\102342lexer.l"
return WHILE;
#line 198 "102342lexer.cpp"
		}
		break;
	case 7:
		{
#line 54 ".\\102342lexer.l"
return DO;
#line 205 "102342lexer.cpp"
		}
		break;
	case 8:
		{
#line 55 ".\\102342lexer.l"
return IF;
#line 212 "102342lexer.cpp"
		}
		break;
	case 9:
		{
#line 56 ".\\102342lexer.l"
return THEN;
#line 219 "102342lexer.cpp"
		}
		break;
	case 10:
		{
#line 57 ".\\102342lexer.l"
return '+';
#line 226 "102342lexer.cpp"
		}
		break;
	case 11:
		{
#line 58 ".\\102342lexer.l"
return '-';
#line 233 "102342lexer.cpp"
		}
		break;
	case 12:
		{
#line 59 ".\\102342lexer.l"
return '*';
#line 240 "102342lexer.cpp"
		}
		break;
	case 13:
		{
#line 60 ".\\102342lexer.l"
return '/';
#line 247 "102342lexer.cpp"
		}
		break;
	case 14:
		{
#line 61 ".\\102342lexer.l"
return A;
#line 254 "102342lexer.cpp"
		}
		break;
	case 15:
		{
#line 62 ".\\102342lexer.l"
return '=';
#line 261 "102342lexer.cpp"
		}
		break;
	case 16:
		{
#line 63 ".\\102342lexer.l"
return NE;
#line 268 "102342lexer.cpp"
		}
		break;
	case 17:
		{
#line 64 ".\\102342lexer.l"
return '>';
#line 275 "102342lexer.cpp"
		}
		break;
	case 18:
		{
#line 65 ".\\102342lexer.l"
return BE;
#line 282 "102342lexer.cpp"
		}
		break;
	case 19:
		{
#line 66 ".\\102342lexer.l"
return '<';
#line 289 "102342lexer.cpp"
		}
		break;
	case 20:
		{
#line 67 ".\\102342lexer.l"
return LE;
#line 296 "102342lexer.cpp"
		}
		break;
	case 21:
		{
#line 68 ".\\102342lexer.l"
return '(';
#line 303 "102342lexer.cpp"
		}
		break;
	case 22:
		{
#line 69 ".\\102342lexer.l"
return ')';
#line 310 "102342lexer.cpp"
		}
		break;
	case 23:
		{
#line 70 ".\\102342lexer.l"
return ';';
#line 317 "102342lexer.cpp"
		}
		break;
	case 24:
		{
#line 71 ".\\102342lexer.l"
return ',';
#line 324 "102342lexer.cpp"
		}
		break;
	case 25:
		{
#line 72 ".\\102342lexer.l"
yylval.val=atoi(yytext);return INT;
#line 331 "102342lexer.cpp"
		}
		break;
	case 26:
		{
#line 73 ".\\102342lexer.l"
yylval.name.assign(yytext);return ID;
#line 338 "102342lexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 142;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 28, 14 },
		{ 29, 14 },
		{ 30, 16 },
		{ 31, 18 },
		{ 32, 19 },
		{ 33, 20 },
		{ 34, 21 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 35, 22 },
		{ 36, 23 },
		{ 37, 24 },
		{ 38, 25 },
		{ 17, 57 },
		{ 39, 26 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 17, 57 },
		{ 3, 1 },
		{ 4, 1 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 8, 1 },
		{ 40, 31 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 41, 32 },
		{ 42, 34 },
		{ 43, 36 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 44, 37 },
		{ 45, 38 },
		{ 46, 39 },
		{ 22, 1 },
		{ 47, 40 },
		{ 48, 41 },
		{ 49, 43 },
		{ 50, 44 },
		{ 51, 46 },
		{ 52, 47 },
		{ 23, 1 },
		{ 53, 48 },
		{ 54, 49 },
		{ 55, 51 },
		{ 24, 1 },
		{ 56, 54 },
		{ 25, 1 },
		{ 26, 1 },
		{ 57, 56 },
		{ 27, 12 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 1 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 },
		{ 11, 11 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 57, 36, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 21 },
		{ 0, 0, 22 },
		{ 0, 0, 12 },
		{ 0, 0, 10 },
		{ 0, 0, 24 },
		{ 0, 0, 11 },
		{ 0, 0, 13 },
		{ 0, 0, 25 },
		{ 0, 84, 25 },
		{ 0, 64, 0 },
		{ 0, 0, 23 },
		{ 0, -50, 19 },
		{ 0, 0, 15 },
		{ 0, -48, 17 },
		{ 57, 0, 26 },
		{ 57, -55, 26 },
		{ 57, -64, 26 },
		{ 57, -63, 26 },
		{ 57, -61, 26 },
		{ 57, -26, 26 },
		{ 57, -37, 26 },
		{ 57, -26, 26 },
		{ 57, -18, 26 },
		{ 57, -23, 26 },
		{ 0, 0, 14 },
		{ 0, 0, 20 },
		{ 0, 0, 16 },
		{ 0, 0, 18 },
		{ 57, 11, 26 },
		{ 57, 21, 26 },
		{ 57, 0, 7 },
		{ 57, 32, 26 },
		{ 57, 0, 8 },
		{ 57, 22, 26 },
		{ 57, 37, 26 },
		{ 57, 25, 26 },
		{ 57, 35, 26 },
		{ 57, 37, 26 },
		{ 57, 28, 26 },
		{ 57, 0, 3 },
		{ 57, 41, 26 },
		{ 57, 35, 26 },
		{ 57, 0, 5 },
		{ 57, 38, 26 },
		{ 57, 37, 26 },
		{ 57, 33, 26 },
		{ 57, 36, 26 },
		{ 57, 0, 9 },
		{ 57, 50, 26 },
		{ 57, 0, 2 },
		{ 57, 0, 4 },
		{ 57, 56, 26 },
		{ 57, 0, 6 },
		{ 57, 47, 26 },
		{ 0, -47, 1 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 76 ".\\102342lexer.l"

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


