/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_YACC_H_INCLUDED
# define YY_YY_YACC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MODULE_START = 258,            /* MODULE_START  */
    MODULE_END = 259,              /* MODULE_END  */
    ASSIGN = 260,                  /* ASSIGN  */
    DELIMITER = 261,               /* DELIMITER  */
    CONST = 262,                   /* CONST  */
    TYPE = 263,                    /* TYPE  */
    IDENTIFIER = 264,              /* IDENTIFIER  */
    RELOP = 265,                   /* RELOP  */
    MATHOP = 266,                  /* MATHOP  */
    NUMBER = 267,                  /* NUMBER  */
    BOOLEAN = 268,                 /* BOOLEAN  */
    RETURN = 269,                  /* RETURN  */
    STRING = 270,                  /* STRING  */
    CHAR = 271,                    /* CHAR  */
    NIL = 272,                     /* NIL  */
    ATOM = 273,                    /* ATOM  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    IF_END = 276,                  /* IF_END  */
    FUNC_START = 277,              /* FUNC_START  */
    FUNC_END = 278,                /* FUNC_END  */
    THEN = 279,                    /* THEN  */
    PARAN_OPEN = 280,              /* PARAN_OPEN  */
    PARAN_CLOSE = 281,             /* PARAN_CLOSE  */
    BRACK_OPEN = 282,              /* BRACK_OPEN  */
    BRACK_CLOSE = 283,             /* BRACK_CLOSE  */
    COMMA = 284                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define MODULE_START 258
#define MODULE_END 259
#define ASSIGN 260
#define DELIMITER 261
#define CONST 262
#define TYPE 263
#define IDENTIFIER 264
#define RELOP 265
#define MATHOP 266
#define NUMBER 267
#define BOOLEAN 268
#define RETURN 269
#define STRING 270
#define CHAR 271
#define NIL 272
#define ATOM 273
#define IF 274
#define ELSE 275
#define IF_END 276
#define FUNC_START 277
#define FUNC_END 278
#define THEN 279
#define PARAN_OPEN 280
#define PARAN_CLOSE 281
#define BRACK_OPEN 282
#define BRACK_CLOSE 283
#define COMMA 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 6 "yacc.l"

	int XESQUE;
	char *lexeme;
	MetaValue meta;

#line 130 "yacc.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_H_INCLUDED  */
