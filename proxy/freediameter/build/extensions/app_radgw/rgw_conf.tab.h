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

#ifndef YY_RGW_CONF_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_EXTENSIONS_APP_RADGW_RGW_CONF_TAB_H_INCLUDED
# define YY_RGW_CONF_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_EXTENSIONS_APP_RADGW_RGW_CONF_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int rgw_confdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    QSTRING = 258,
    INTEGER = 259,
    IP = 260,
    NAS_OR_PXY = 261,
    DISABLED = 262,
    AUTH = 263,
    ACCT = 264,
    PLG_PREFIX = 265,
    AUTH_ENABLE = 266,
    AUTH_PORT = 267,
    AUTH_IP4 = 268,
    AUTH_IP6 = 269,
    ACCT_ENABLE = 270,
    ACCT_PORT = 271,
    ACCT_IP4 = 272,
    ACCT_IP6 = 273,
    LEX_ERROR = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 135 "/home/samin/workspace/research_implementation/proxy/freediameter/src/extensions/app_radgw/rgw_conf.y" /* yacc.c:1909  */

	char 		*string;	/* The string is allocated by strdup in lex.*/
	int		 integer;	/* Store integer values */
	struct sockaddr *ss;		/* sockaddr to free after use (alloc in lex) */

#line 80 "/home/samin/workspace/research_implementation/proxy/freediameter/build/extensions/app_radgw/rgw_conf.tab.h" /* yacc.c:1909  */
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



int rgw_confparse (char * conffile);

#endif /* !YY_RGW_CONF_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_EXTENSIONS_APP_RADGW_RGW_CONF_TAB_H_INCLUDED  */
