#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 110 of your 30 day trial period.
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
# 102342lexer.v
# Lex verbose file generated from 102342lexer.l.
# 
# Date: 02/14/13
# Time: 20:55:07
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  "PROGRAM"

    2  "BEGIN"

    3  "END"

    4  "CONST"

    5  "VAR"

    6  "WHILE"

    7  "DO"

    8  "IF"

    9  "THEN"

   10  "+"

   11  "-"

   12  "*"

   13  "/"

   14  ":="

   15  "="

   16  "<>"

   17  ">"

   18  ">="

   19  "<"

   20  "<="

   21  "("

   22  ")"

   23  ";"

   24  ","

   25  [1-9][0-9]*|0

   26  [a-zA-Z][a-zA-Z_0-9]*


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x28               goto 3
	0x29               goto 4
	0x2a               goto 5
	0x2b               goto 6
	0x2c               goto 7
	0x2d               goto 8
	0x2f               goto 9
	0x30               goto 10
	0x31 - 0x39 (9)    goto 11
	0x3a               goto 12
	0x3b               goto 13
	0x3c               goto 14
	0x3d               goto 15
	0x3e               goto 16
	0x41               goto 17
	0x42               goto 18
	0x43               goto 19
	0x44               goto 20
	0x45               goto 21
	0x46 - 0x48 (3)    goto 17
	0x49               goto 22
	0x4a - 0x4f (6)    goto 17
	0x50               goto 23
	0x51 - 0x53 (3)    goto 17
	0x54               goto 24
	0x55               goto 17
	0x56               goto 25
	0x57               goto 26
	0x58 - 0x5a (3)    goto 17
	0x61 - 0x7a (26)   goto 17


state 2
	^INITIAL

	0x28               goto 3
	0x29               goto 4
	0x2a               goto 5
	0x2b               goto 6
	0x2c               goto 7
	0x2d               goto 8
	0x2f               goto 9
	0x30               goto 10
	0x31 - 0x39 (9)    goto 11
	0x3a               goto 12
	0x3b               goto 13
	0x3c               goto 14
	0x3d               goto 15
	0x3e               goto 16
	0x41               goto 17
	0x42               goto 18
	0x43               goto 19
	0x44               goto 20
	0x45               goto 21
	0x46 - 0x48 (3)    goto 17
	0x49               goto 22
	0x4a - 0x4f (6)    goto 17
	0x50               goto 23
	0x51 - 0x53 (3)    goto 17
	0x54               goto 24
	0x55               goto 17
	0x56               goto 25
	0x57               goto 26
	0x58 - 0x5a (3)    goto 17
	0x61 - 0x7a (26)   goto 17


state 3
	match 21


state 4
	match 22


state 5
	match 12


state 6
	match 10


state 7
	match 24


state 8
	match 11


state 9
	match 13


state 10
	match 25


state 11
	0x30 - 0x39 (10)   goto 11

	match 25


state 12
	0x3d               goto 27


state 13
	match 23


state 14
	0x3d               goto 28
	0x3e               goto 29

	match 19


state 15
	match 15


state 16
	0x3d               goto 30

	match 17


state 17
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 18
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x44 (4)    goto 17
	0x45               goto 31
	0x46 - 0x5a (21)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 19
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x4e (14)   goto 17
	0x4f               goto 32
	0x50 - 0x5a (11)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 20
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x4e (14)   goto 17
	0x4f               goto 33
	0x50 - 0x5a (11)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 21
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x4d (13)   goto 17
	0x4e               goto 34
	0x4f - 0x5a (12)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 22
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x45 (5)    goto 17
	0x46               goto 35
	0x47 - 0x5a (20)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 23
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x51 (17)   goto 17
	0x52               goto 36
	0x53 - 0x5a (8)    goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 24
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x47 (7)    goto 17
	0x48               goto 37
	0x49 - 0x5a (18)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 25
	0x30 - 0x39 (10)   goto 17
	0x41               goto 38
	0x42 - 0x5a (25)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 26
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x47 (7)    goto 17
	0x48               goto 39
	0x49 - 0x5a (18)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 27
	match 14


state 28
	match 20


state 29
	match 16


state 30
	match 18


state 31
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x46 (6)    goto 17
	0x47               goto 40
	0x48 - 0x5a (19)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 32
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x4d (13)   goto 17
	0x4e               goto 41
	0x4f - 0x5a (12)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 33
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 7


state 34
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x43 (3)    goto 17
	0x44               goto 42
	0x45 - 0x5a (22)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 35
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 8


state 36
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x4e (14)   goto 17
	0x4f               goto 43
	0x50 - 0x5a (11)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 37
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x44 (4)    goto 17
	0x45               goto 44
	0x46 - 0x5a (21)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 38
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x51 (17)   goto 17
	0x52               goto 45
	0x53 - 0x5a (8)    goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 39
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x48 (8)    goto 17
	0x49               goto 46
	0x4a - 0x5a (17)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 40
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x48 (8)    goto 17
	0x49               goto 47
	0x4a - 0x5a (17)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 41
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x52 (18)   goto 17
	0x53               goto 48
	0x54 - 0x5a (7)    goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 42
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 3


state 43
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x46 (6)    goto 17
	0x47               goto 49
	0x48 - 0x5a (19)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 44
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x4d (13)   goto 17
	0x4e               goto 50
	0x4f - 0x5a (12)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 45
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 5


state 46
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x4b (11)   goto 17
	0x4c               goto 51
	0x4d - 0x5a (14)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 47
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x4d (13)   goto 17
	0x4e               goto 52
	0x4f - 0x5a (12)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 48
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x53 (19)   goto 17
	0x54               goto 53
	0x55 - 0x5a (6)    goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 49
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x51 (17)   goto 17
	0x52               goto 54
	0x53 - 0x5a (8)    goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 50
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 9


state 51
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x44 (4)    goto 17
	0x45               goto 55
	0x46 - 0x5a (21)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 52
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 2


state 53
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 4


state 54
	0x30 - 0x39 (10)   goto 17
	0x41               goto 56
	0x42 - 0x5a (25)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 55
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 6


state 56
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x4c (12)   goto 17
	0x4d               goto 57
	0x4e - 0x5a (13)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 26


state 57
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 1


#############################################################################
# Summary
#############################################################################

1 start state(s)
26 expression(s), 57 state(s)


#############################################################################
# End of File
#############################################################################
