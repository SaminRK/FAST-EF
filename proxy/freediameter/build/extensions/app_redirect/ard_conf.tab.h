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

#ifndef YY_ARD_CONF_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_EXTENSIONS_APP_REDIRECT_ARD_CONF_TAB_H_INCLUDED
# define YY_ARD_CONF_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_EXTENSIONS_APP_REDIRECT_ARD_CONF_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int ard_confdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_LEX_ERROR = 258,
    TOK_TSTRING = 259,
    TOK_U32VAL = 260,
    TOK_DEFAULT_RCT = 261,
    TOK_TO = 262,
    TOK_DONT_CACHE = 263,
    TOK_ALL_SESSION = 264,
    TOK_ALL_REALM = 265,
    TOK_REALM_AND_APPLICATION = 266,
    TOK_ALL_APPLICATION = 267,
    TOK_ALL_HOST = 268,
    TOK_ALL_USER = 269,
    TOK_FROM_ID = 270,
    TOK_FROM_REALM = 271,
    TOK_APP = 272
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 171 "/home/samin/workspace/research_implementation/proxy/freediameter/src/extensions/app_redirect/ard_conf.y" /* yacc.c:1909  */

	/* returned by lex */
	uint32_t	 u32;	/* Store integer values */
	struct {
		char * str;
		int regex; /* true or false */
	}	 tstring;	/* typed string */

#line 81 "/home/samin/workspace/research_implementation/proxy/freediameter/build/extensions/app_redirect/ard_conf.tab.h" /* yacc.c:1909  */
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



int ard_confparse (char * conffile);

#endif /* !YY_ARD_CONF_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_EXTENSIONS_APP_REDIRECT_ARD_CONF_TAB_H_INCLUDED  */
