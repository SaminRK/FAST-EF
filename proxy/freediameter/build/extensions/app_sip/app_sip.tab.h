/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_APP_SIP_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_EXTENSIONS_APP_SIP_APP_SIP_TAB_H_INCLUDED
# define YY_APP_SIP_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_EXTENSIONS_APP_SIP_APP_SIP_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int app_sipdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LEX_ERROR = 258,
    MODE = 259,
    DATASOURCE = 260,
    ASMYSQL_LOGIN = 261,
    ASMYSQL_PASSWORD = 262,
    ASMYSQL_DATABASE = 263,
    ASMYSQL_SERVER = 264,
    ASMYSQL_PORT = 265,
    RTR_PORT = 266,
    PPR_PORT = 267,
    QSTRING = 268,
    INTEGER = 269
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 110 "/home/samin/workspace/research_implementation/proxy/freediameter/src/extensions/app_sip/app_sip.y" /* yacc.c:1909  */

	char 		*string;	/* The string is allocated by strdup in lex.*/
	int		 integer;		/* Store integer values */

#line 74 "/home/samin/workspace/research_implementation/proxy/freediameter/build/extensions/app_sip/app_sip.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int app_sipparse (char * conffile);

#endif /* !YY_APP_SIP_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_EXTENSIONS_APP_SIP_APP_SIP_TAB_H_INCLUDED  */
