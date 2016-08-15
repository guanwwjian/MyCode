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
* 102342lexer.h
* C++ header file generated from 102342lexer.l.
* 
* Date: 02/14/13
* Time: 20:55:07
* 
* ALex Version: 2.07
****************************************************************************/

#ifndef _102342LEXER_H
#define _102342LEXER_H

#include <yyclex.h>

/////////////////////////////////////////////////////////////////////////////
// mylexer

#ifndef YYEXPLEXER
#define YYEXPLEXER
#endif

class YYEXPLEXER YYFAR mylexer : public _YL yyflexer {
public:
	mylexer();
	virtual ~mylexer();

	// backards compatibility with lex
#ifdef input
	virtual int yyinput();
#endif
#ifdef output
	virtual void yyoutput(int ch);
#endif
#ifdef unput
	virtual void yyunput(int ch);
#endif

protected:
	void yytables();
	virtual int yyaction(int action);

public:
#line 19 ".\\102342lexer.l"

	// place any extra class members here

#line 65 "102342lexer.h"
};

#ifndef YYLEXERNAME
#define YYLEXERNAME mylexer
#endif

#ifndef INITIAL
#define INITIAL 0
#endif

#endif
