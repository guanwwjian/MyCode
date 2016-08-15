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
* 102342parser.h
* C++ header file generated from 102342parser.y.
* 
* Date: 02/16/13
* Time: 21:47:54
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _102342PARSER_H
#define _102342PARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 25 ".\\102342parser.y"

	// place any extra class members here

#line 69 "102342parser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 40 ".\\102342parser.y"


#include "102342TreeNode.h"
#ifndef YYSTYPE
#define YYSTYPE TreeNode
#endif


#line 85 "102342parser.h"
#define INT 257
#define ID 258
#define PROGRAM 259
#define BEG 260
#define END 261
#define CONST 262
#define VAR 263
#define WHILE 264
#define DO 265
#define IF 266
#define THEN 267
#define A 268
#define NE 269
#define BE 270
#define LE 271
#endif
