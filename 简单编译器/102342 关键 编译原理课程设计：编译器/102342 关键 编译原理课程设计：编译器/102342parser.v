#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 112 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# 102342parser.v
# YACC verbose file generated from 102342parser.y.
# 
# Date: 02/16/13
# Time: 21:47:54
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : P $end

    1  P : HEAD BODY

    2  HEAD : PROGRAM ID

    3  BODY : CONSTS VARS STATEMENT

    4  CONSTS : CONST CONSTDEFS ';'
    5         |

    6  CONSTDEFS : CONSTDEF ',' CONSTDEFS
    7            | CONSTDEF

    8  CONSTDEF : ID '=' INT

    9  VARS : VAR VARDEFS ';'
   10       |

   11  VARDEFS : VARDEF ',' VARDEFS
   12          | VARDEF

   13  VARDEF : ID

   14  BLOCK : BEG STATEMENTS END

   15  STATEMENTS : STATEMENT
   16             | STATEMENT ';' M STATEMENTS

   17  STATEMENT : ASSIGN
   18            | IFTHENELSE
   19            | WHILEDO
   20            | BLOCK
   21            |

   22  ASSIGN : ID A EXPRESSION

   23  EXPRESSION : TERM
   24             | '+' TERM
   25             | '-' TERM
   26             | EXPRESSION '+' TERM
   27             | EXPRESSION '-' TERM

   28  TERM : FACTOR
   29       | TERM '*' FACTOR
   30       | TERM '/' FACTOR

   31  FACTOR : ID
   32         | INT
   33         | '(' EXPRESSION ')'

   34  IFTHENELSE : IF CONDITION THEN M STATEMENT

   35  WHILEDO : WHILE M CONDITION DO M STATEMENT

   36  M :

   37  CONDITION : EXPRESSION OP EXPRESSION

   38  OP : '='
   39     | NE
   40     | '<'
   41     | LE
   42     | '>'
   43     | BE


##############################################################################
# States
##############################################################################

state 0
	$accept : . P $end

	PROGRAM  shift 1

	P  goto 2
	HEAD  goto 3


state 1
	HEAD : PROGRAM . ID

	ID  shift 4


state 2
	$accept : P . $end  (0)

	$end  accept


state 3
	P : HEAD . BODY
	CONSTS : .  (5)

	CONST  shift 5
	.  reduce 5

	BODY  goto 6
	CONSTS  goto 7


state 4
	HEAD : PROGRAM ID .  (2)

	.  reduce 2


state 5
	CONSTS : CONST . CONSTDEFS ';'

	ID  shift 8

	CONSTDEFS  goto 9
	CONSTDEF  goto 10


state 6
	P : HEAD BODY .  (1)

	.  reduce 1


state 7
	BODY : CONSTS . VARS STATEMENT
	VARS : .  (10)

	VAR  shift 11
	.  reduce 10

	VARS  goto 12


state 8
	CONSTDEF : ID . '=' INT

	'='  shift 13


state 9
	CONSTS : CONST CONSTDEFS . ';'

	';'  shift 14


state 10
	CONSTDEFS : CONSTDEF . ',' CONSTDEFS
	CONSTDEFS : CONSTDEF .  (7)

	','  shift 15
	.  reduce 7


state 11
	VARS : VAR . VARDEFS ';'

	ID  shift 16

	VARDEFS  goto 17
	VARDEF  goto 18


state 12
	BODY : CONSTS VARS . STATEMENT
	STATEMENT : .  (21)

	ID  shift 19
	BEG  shift 20
	WHILE  shift 21
	IF  shift 22
	.  reduce 21

	BLOCK  goto 23
	ASSIGN  goto 24
	IFTHENELSE  goto 25
	WHILEDO  goto 26
	STATEMENT  goto 27


state 13
	CONSTDEF : ID '=' . INT

	INT  shift 28


state 14
	CONSTS : CONST CONSTDEFS ';' .  (4)

	.  reduce 4


state 15
	CONSTDEFS : CONSTDEF ',' . CONSTDEFS

	ID  shift 8

	CONSTDEFS  goto 29
	CONSTDEF  goto 10


state 16
	VARDEF : ID .  (13)

	.  reduce 13


state 17
	VARS : VAR VARDEFS . ';'

	';'  shift 30


state 18
	VARDEFS : VARDEF . ',' VARDEFS
	VARDEFS : VARDEF .  (12)

	','  shift 31
	.  reduce 12


state 19
	ASSIGN : ID . A EXPRESSION

	A  shift 32


state 20
	BLOCK : BEG . STATEMENTS END
	STATEMENT : .  (21)

	ID  shift 19
	BEG  shift 20
	WHILE  shift 21
	IF  shift 22
	.  reduce 21

	BLOCK  goto 23
	STATEMENTS  goto 33
	ASSIGN  goto 24
	IFTHENELSE  goto 25
	WHILEDO  goto 26
	STATEMENT  goto 34


state 21
	WHILEDO : WHILE . M CONDITION DO M STATEMENT
	M : .  (36)

	.  reduce 36

	M  goto 35


state 22
	IFTHENELSE : IF . CONDITION THEN M STATEMENT

	'('  shift 36
	'+'  shift 37
	'-'  shift 38
	INT  shift 39
	ID  shift 40

	EXPRESSION  goto 41
	TERM  goto 42
	FACTOR  goto 43
	CONDITION  goto 44


state 23
	STATEMENT : BLOCK .  (20)

	.  reduce 20


state 24
	STATEMENT : ASSIGN .  (17)

	.  reduce 17


state 25
	STATEMENT : IFTHENELSE .  (18)

	.  reduce 18


state 26
	STATEMENT : WHILEDO .  (19)

	.  reduce 19


state 27
	BODY : CONSTS VARS STATEMENT .  (3)

	.  reduce 3


state 28
	CONSTDEF : ID '=' INT .  (8)

	.  reduce 8


state 29
	CONSTDEFS : CONSTDEF ',' CONSTDEFS .  (6)

	.  reduce 6


state 30
	VARS : VAR VARDEFS ';' .  (9)

	.  reduce 9


state 31
	VARDEFS : VARDEF ',' . VARDEFS

	ID  shift 16

	VARDEFS  goto 45
	VARDEF  goto 18


state 32
	ASSIGN : ID A . EXPRESSION

	'('  shift 36
	'+'  shift 37
	'-'  shift 38
	INT  shift 39
	ID  shift 40

	EXPRESSION  goto 46
	TERM  goto 42
	FACTOR  goto 43


state 33
	BLOCK : BEG STATEMENTS . END

	END  shift 47


state 34
	STATEMENTS : STATEMENT .  (15)
	STATEMENTS : STATEMENT . ';' M STATEMENTS

	';'  shift 48
	.  reduce 15


state 35
	WHILEDO : WHILE M . CONDITION DO M STATEMENT

	'('  shift 36
	'+'  shift 37
	'-'  shift 38
	INT  shift 39
	ID  shift 40

	EXPRESSION  goto 41
	TERM  goto 42
	FACTOR  goto 43
	CONDITION  goto 49


state 36
	FACTOR : '(' . EXPRESSION ')'

	'('  shift 36
	'+'  shift 37
	'-'  shift 38
	INT  shift 39
	ID  shift 40

	EXPRESSION  goto 50
	TERM  goto 42
	FACTOR  goto 43


state 37
	EXPRESSION : '+' . TERM

	'('  shift 36
	INT  shift 39
	ID  shift 40

	TERM  goto 51
	FACTOR  goto 43


state 38
	EXPRESSION : '-' . TERM

	'('  shift 36
	INT  shift 39
	ID  shift 40

	TERM  goto 52
	FACTOR  goto 43


state 39
	FACTOR : INT .  (32)

	.  reduce 32


state 40
	FACTOR : ID .  (31)

	.  reduce 31


state 41
	EXPRESSION : EXPRESSION . '+' TERM
	EXPRESSION : EXPRESSION . '-' TERM
	CONDITION : EXPRESSION . OP EXPRESSION

	'+'  shift 53
	'-'  shift 54
	'<'  shift 55
	'='  shift 56
	'>'  shift 57
	NE  shift 58
	BE  shift 59
	LE  shift 60

	OP  goto 61


state 42
	EXPRESSION : TERM .  (23)
	TERM : TERM . '*' FACTOR
	TERM : TERM . '/' FACTOR

	'*'  shift 62
	'/'  shift 63
	.  reduce 23


state 43
	TERM : FACTOR .  (28)

	.  reduce 28


state 44
	IFTHENELSE : IF CONDITION . THEN M STATEMENT

	THEN  shift 64


state 45
	VARDEFS : VARDEF ',' VARDEFS .  (11)

	.  reduce 11


state 46
	ASSIGN : ID A EXPRESSION .  (22)
	EXPRESSION : EXPRESSION . '+' TERM
	EXPRESSION : EXPRESSION . '-' TERM

	'+'  shift 53
	'-'  shift 54
	.  reduce 22


state 47
	BLOCK : BEG STATEMENTS END .  (14)

	.  reduce 14


state 48
	STATEMENTS : STATEMENT ';' . M STATEMENTS
	M : .  (36)

	.  reduce 36

	M  goto 65


state 49
	WHILEDO : WHILE M CONDITION . DO M STATEMENT

	DO  shift 66


state 50
	EXPRESSION : EXPRESSION . '+' TERM
	EXPRESSION : EXPRESSION . '-' TERM
	FACTOR : '(' EXPRESSION . ')'

	')'  shift 67
	'+'  shift 53
	'-'  shift 54


state 51
	EXPRESSION : '+' TERM .  (24)
	TERM : TERM . '*' FACTOR
	TERM : TERM . '/' FACTOR

	'*'  shift 62
	'/'  shift 63
	.  reduce 24


state 52
	EXPRESSION : '-' TERM .  (25)
	TERM : TERM . '*' FACTOR
	TERM : TERM . '/' FACTOR

	'*'  shift 62
	'/'  shift 63
	.  reduce 25


state 53
	EXPRESSION : EXPRESSION '+' . TERM

	'('  shift 36
	INT  shift 39
	ID  shift 40

	TERM  goto 68
	FACTOR  goto 43


state 54
	EXPRESSION : EXPRESSION '-' . TERM

	'('  shift 36
	INT  shift 39
	ID  shift 40

	TERM  goto 69
	FACTOR  goto 43


state 55
	OP : '<' .  (40)

	.  reduce 40


state 56
	OP : '=' .  (38)

	.  reduce 38


state 57
	OP : '>' .  (42)

	.  reduce 42


state 58
	OP : NE .  (39)

	.  reduce 39


state 59
	OP : BE .  (43)

	.  reduce 43


state 60
	OP : LE .  (41)

	.  reduce 41


state 61
	CONDITION : EXPRESSION OP . EXPRESSION

	'('  shift 36
	'+'  shift 37
	'-'  shift 38
	INT  shift 39
	ID  shift 40

	EXPRESSION  goto 70
	TERM  goto 42
	FACTOR  goto 43


state 62
	TERM : TERM '*' . FACTOR

	'('  shift 36
	INT  shift 39
	ID  shift 40

	FACTOR  goto 71


state 63
	TERM : TERM '/' . FACTOR

	'('  shift 36
	INT  shift 39
	ID  shift 40

	FACTOR  goto 72


state 64
	IFTHENELSE : IF CONDITION THEN . M STATEMENT
	M : .  (36)

	.  reduce 36

	M  goto 73


state 65
	STATEMENTS : STATEMENT ';' M . STATEMENTS
	STATEMENT : .  (21)

	ID  shift 19
	BEG  shift 20
	WHILE  shift 21
	IF  shift 22
	.  reduce 21

	BLOCK  goto 23
	STATEMENTS  goto 74
	ASSIGN  goto 24
	IFTHENELSE  goto 25
	WHILEDO  goto 26
	STATEMENT  goto 34


state 66
	WHILEDO : WHILE M CONDITION DO . M STATEMENT
	M : .  (36)

	.  reduce 36

	M  goto 75


state 67
	FACTOR : '(' EXPRESSION ')' .  (33)

	.  reduce 33


state 68
	EXPRESSION : EXPRESSION '+' TERM .  (26)
	TERM : TERM . '*' FACTOR
	TERM : TERM . '/' FACTOR

	'*'  shift 62
	'/'  shift 63
	.  reduce 26


state 69
	EXPRESSION : EXPRESSION '-' TERM .  (27)
	TERM : TERM . '*' FACTOR
	TERM : TERM . '/' FACTOR

	'*'  shift 62
	'/'  shift 63
	.  reduce 27


state 70
	EXPRESSION : EXPRESSION . '+' TERM
	EXPRESSION : EXPRESSION . '-' TERM
	CONDITION : EXPRESSION OP EXPRESSION .  (37)

	'+'  shift 53
	'-'  shift 54
	.  reduce 37


state 71
	TERM : TERM '*' FACTOR .  (29)

	.  reduce 29


state 72
	TERM : TERM '/' FACTOR .  (30)

	.  reduce 30


state 73
	IFTHENELSE : IF CONDITION THEN M . STATEMENT
	STATEMENT : .  (21)

	ID  shift 19
	BEG  shift 20
	WHILE  shift 21
	IF  shift 22
	.  reduce 21

	BLOCK  goto 23
	ASSIGN  goto 24
	IFTHENELSE  goto 25
	WHILEDO  goto 26
	STATEMENT  goto 76


state 74
	STATEMENTS : STATEMENT ';' M STATEMENTS .  (16)

	.  reduce 16


state 75
	WHILEDO : WHILE M CONDITION DO M . STATEMENT
	STATEMENT : .  (21)

	ID  shift 19
	BEG  shift 20
	WHILE  shift 21
	IF  shift 22
	.  reduce 21

	BLOCK  goto 23
	ASSIGN  goto 24
	IFTHENELSE  goto 25
	WHILEDO  goto 26
	STATEMENT  goto 77


state 76
	IFTHENELSE : IF CONDITION THEN M STATEMENT .  (34)

	.  reduce 34


state 77
	WHILEDO : WHILE M CONDITION DO M STATEMENT .  (35)

	.  reduce 35


##############################################################################
# Summary
##############################################################################

28 token(s), 22 nonterminal(s)
44 grammar rule(s), 78 state(s)


##############################################################################
# End of File
##############################################################################
