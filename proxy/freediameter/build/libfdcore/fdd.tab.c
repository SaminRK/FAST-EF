/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         fddparse
#define yylex           fddlex
#define yyerror         fdderror
#define yydebug         fdddebug
#define yynerrs         fddnerrs


/* Copy the first part of user declarations.  */
#line 54 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:339  */

#include "fdcore-internal.h"
#include "fdd.tab.h"	/* bug : bison does not define the YYLTYPE before including this bloc, so... */

/* The Lex parser prototype */
int fddlex(YYSTYPE *lvalp, YYLTYPE *llocp);

/* Function to report error */
void yyerror (YYLTYPE *ploc, struct fd_config * conf, char const *s)
{
	if (ploc->first_line != ploc->last_line) {
		TRACE_ERROR("%s:%d.%d-%d.%d : %s", conf->cnf_file, ploc->first_line, ploc->first_column, ploc->last_line, ploc->last_column, s);
	} else if (ploc->first_column != ploc->last_column) {
		TRACE_ERROR("%s:%d.%d-%d : %s", conf->cnf_file, ploc->first_line, ploc->first_column, ploc->last_column, s);
	} else {
		TRACE_ERROR("%s:%d.%d : %s", conf->cnf_file, ploc->first_line, ploc->first_column, s);
	}
}

int got_peer_noip = 0;
int got_peer_noipv6 = 0;
int got_peer_notcp = 0;
int got_peer_nosctp = 0;

struct peer_info fddpi;


#line 100 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "fdd.tab.h".  */
#ifndef YY_FDD_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_LIBFDCORE_FDD_TAB_H_INCLUDED
# define YY_FDD_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_LIBFDCORE_FDD_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int fdddebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LEX_ERROR = 258,
    QSTRING = 259,
    INTEGER = 260,
    IDENTITY = 261,
    REALM = 262,
    PORT = 263,
    SECPORT = 264,
    SEC3436 = 265,
    NOIP = 266,
    NOIP6 = 267,
    NOTCP = 268,
    NOSCTP = 269,
    PREFERTCP = 270,
    OLDTLS = 271,
    NOTLS = 272,
    SCTPSTREAMS = 273,
    APPSERVTHREADS = 274,
    LISTENON = 275,
    THRPERSRV = 276,
    TCTIMER = 277,
    TWTIMER = 278,
    NORELAY = 279,
    LOADEXT = 280,
    CONNPEER = 281,
    CONNTO = 282,
    TLS_CRED = 283,
    TLS_CA = 284,
    TLS_CRL = 285,
    TLS_PRIO = 286,
    TLS_DH_BITS = 287,
    TLS_DH_FILE = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 83 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:355  */

	char 		 *string;	/* The string is allocated by strdup in lex.*/
	int		  integer;	/* Store integer values */

#line 179 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:355  */
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



int fddparse (struct fd_config * conf);

#endif /* !YY_FDD_HOME_SAMIN_WORKSPACE_RESEARCH_IMPLEMENTATION_PROXY_FREEDIAMETER_BUILD_LIBFDCORE_FDD_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 209 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    35,
       2,    34,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   164,
     165,   168,   174,   180,   188,   196,   204,   212,   220,   228,
     243,   251,   257,   265,   275,   285,   304,   319,   325,   331,
     386,   389,   395,   395,   418,   419,   422,   423,   432,   441,
     454,   463,   467,   471,   475,   479,   483,   489,   493,   497,
     501,   524,   555,   595,   635,   649,   653
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEX_ERROR", "QSTRING", "INTEGER",
  "IDENTITY", "REALM", "PORT", "SECPORT", "SEC3436", "NOIP", "NOIP6",
  "NOTCP", "NOSCTP", "PREFERTCP", "OLDTLS", "NOTLS", "SCTPSTREAMS",
  "APPSERVTHREADS", "LISTENON", "THRPERSRV", "TCTIMER", "TWTIMER",
  "NORELAY", "LOADEXT", "CONNPEER", "CONNTO", "TLS_CRED", "TLS_CA",
  "TLS_CRL", "TLS_PRIO", "TLS_DH_BITS", "TLS_DH_FILE", "'='", "';'", "':'",
  "'{'", "'}'", "','", "$accept", "conffile", "errors", "identity",
  "realm", "tctimer", "twtimer", "port", "secport", "sec3436",
  "sctpstreams", "listenon", "thrpersrv", "norelay", "appservthreads",
  "noip", "noip6", "notcp", "nosctp", "prefertcp", "oldtls", "loadext",
  "extconf", "connpeer", "$@1", "peerinfo", "peerparams", "tls_cred",
  "tls_ca", "tls_crl", "tls_prio", "tls_dh", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    61,    59,    58,   123,   125,    44
};
# endif

#define YYPACT_NINF -33

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-33)))

#define YYTABLE_NINF -53

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -33,     0,   -33,   -33,   -33,   -32,   -30,   -29,   -17,    -7,
       1,    10,    11,    12,    13,    16,    18,    19,    21,    22,
      23,    25,    26,    28,    29,    30,    32,    33,    34,    35,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,    44,   -33,   -33,   -33,   -33,   -33,    56,    67,    68,
      69,    70,   -33,   -33,   -33,   -33,   -33,   -33,    71,    72,
      74,    75,    76,    77,   -33,    79,    80,    81,    82,    83,
      84,    86,    38,    53,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    43,    52,    73,    78,    85,    87,
      88,    98,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,    99,    89,   100,   -33,   -33,   -33,   -33,
     -33,    90,   -33,   -33,    91,   -33,    93,   -33,    27,   -33,
      95,    96,    97,   101,   102,   103,   104,   105,   106,   107,
     109,   110,   111,   112,   -33,   108,   113,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   114,   116,   121,   127,   115,
     117,   118,   119,   120,   122,   -33,   -33,   -33,   -33,   -33,
     -33
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    30,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     0,    23,    24,    25,    26,    27,     0,     0,     0,
       0,     0,    43,    44,    45,    46,    47,    48,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    35,    36,    37,    38,    42,    39,
      40,    33,    34,     0,     0,     0,    72,    73,    74,    75,
      76,    54,    51,    49,     0,    56,     0,    71,     0,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,    64,    57,    58,
      59,    60,    61,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    66,    67,    68,    70,
      69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,   114,    50,    51,   126,   128,    52,    53,    54,
      55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,     3,    57,     4,    58,    59,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    60,    16,    17,
      18,    19,    20,    21,    22,    23,   -52,    61,    24,    25,
      26,    27,    28,    29,   130,   131,    62,   132,   133,   134,
     135,   136,   137,   138,   139,    63,    64,    65,    66,   140,
     141,    67,    68,    69,   142,    70,    71,    72,   143,    73,
      83,    74,    75,    76,    77,   144,    78,    79,    80,    81,
      82,    84,   101,    85,    86,    87,    88,    89,    90,   113,
      91,    92,    93,    94,    95,    96,    97,    98,   102,    99,
     100,   115,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   121,   122,   124,     0,     0,     0,   116,     0,
       0,     0,   159,   117,     0,     0,     0,     0,   160,   161,
     118,   162,   119,   120,   123,   163,   127,   125,   129,   145,
     146,   164,   147,     0,     0,     0,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,     0,
     165,     0,   166,   167,   168,   169,     0,   170
};

static const yytype_int8 yycheck[] =
{
       0,     1,    34,     3,    34,    34,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    34,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    34,    28,    29,
      30,    31,    32,    33,     7,     8,    35,    10,    11,    12,
      13,    14,    15,    16,    17,    35,    35,    35,    35,    22,
      23,    35,    34,    34,    27,    34,    34,    34,    31,    34,
       4,    35,    34,    34,    34,    38,    34,    34,    34,    34,
      26,     4,    34,     5,     5,     5,     5,     5,     4,    36,
       5,     5,     5,     4,     4,     4,     4,     4,    35,     5,
       4,    39,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,     4,     4,     4,    -1,    -1,    -1,    35,    -1,
      -1,    -1,     4,    35,    -1,    -1,    -1,    -1,     5,     5,
      35,     5,    35,    35,    35,     4,    35,    37,    35,    34,
      34,     4,    35,    -1,    -1,    -1,    35,    35,    35,    35,
      35,    35,    35,    34,    34,    34,    34,    -1,    -1,    -1,
      35,    -1,    35,    35,    35,    35,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,     0,     1,     3,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    18,    19,    20,    21,
      22,    23,    24,    25,    28,    29,    30,    31,    32,    33,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      63,    64,    67,    68,    69,    70,    71,    34,    34,    34,
      34,    34,    35,    35,    35,    35,    35,    35,    34,    34,
      34,    34,    34,    34,    35,    34,    34,    34,    34,    34,
      34,    34,    26,     4,     4,     5,     5,     5,     5,     5,
       4,     5,     5,     5,     4,     4,     4,     4,     4,     5,
       4,    34,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,    35,    36,    62,    39,    35,    35,    35,    35,
      35,     4,     4,    35,     4,    37,    65,    35,    66,    35,
       7,     8,    10,    11,    12,    13,    14,    15,    16,    17,
      22,    23,    27,    31,    38,    34,    34,    35,    35,    35,
      35,    35,    35,    35,    35,    34,    34,    34,    34,     4,
       5,     5,     5,     4,     4,    35,    35,    35,    35,    35,
      35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    42,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    62,    64,    63,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    68,    69,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     2,     4,     2,     2,     2,     2,     2,     2,     5,
       0,     2,     0,     6,     0,     3,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     5,     5,     5,     5,
       5,     6,     4,     4,     4,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, conf, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, conf); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct fd_config * conf)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (conf);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct fd_config * conf)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, conf);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, struct fd_config * conf)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , conf);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, conf); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, struct fd_config * conf)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (conf);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (struct fd_config * conf)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 28:
#line 157 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				yyerror(&yylloc, conf, "An error occurred while parsing the configuration file");
				return EINVAL;
			}
#line 1504 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 169 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				conf->cnf_diamid = (yyvsp[-1].string);
			}
#line 1512 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 175 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				conf->cnf_diamrlm = (yyvsp[-1].string);
			}
#line 1520 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 181 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				CHECK_PARAMS_DO( ((yyvsp[-1].integer) > 0),
					{ yyerror (&yylloc, conf, "Invalid value"); YYERROR; } );
				conf->cnf_timer_tc = (unsigned int)(yyvsp[-1].integer);
			}
#line 1530 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 189 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				CHECK_PARAMS_DO( ((yyvsp[-1].integer) > 5),
					{ yyerror (&yylloc, conf, "Invalid value"); YYERROR; } );
				conf->cnf_timer_tw = (unsigned int)(yyvsp[-1].integer);
			}
#line 1540 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 197 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				CHECK_PARAMS_DO( ((yyvsp[-1].integer) >= 0) && ((yyvsp[-1].integer) < 1<<16),
					{ yyerror (&yylloc, conf, "Invalid value"); YYERROR; } );
				conf->cnf_port = (uint16_t)(yyvsp[-1].integer);
			}
#line 1550 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 205 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				CHECK_PARAMS_DO( ((yyvsp[-1].integer) >= 0) && ((yyvsp[-1].integer) < 1<<16),
					{ yyerror (&yylloc, conf, "Invalid value"); YYERROR; } );
				conf->cnf_port_tls = (uint16_t)(yyvsp[-1].integer);
			}
#line 1560 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 213 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				CHECK_PARAMS_DO( ((yyvsp[-1].integer) >= 0) && ((yyvsp[-1].integer) < 1<<16),
					{ yyerror (&yylloc, conf, "Invalid value"); YYERROR; } );
				conf->cnf_port_3436 = (uint16_t)(yyvsp[-1].integer);
			}
#line 1570 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 221 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				CHECK_PARAMS_DO( ((yyvsp[-1].integer) > 0) && ((yyvsp[-1].integer) < 1<<16),
					{ yyerror (&yylloc, conf, "Invalid value"); YYERROR; } );
				conf->cnf_sctp_str = (uint16_t)(yyvsp[-1].integer);
			}
#line 1580 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 229 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				struct addrinfo hints, *ai;
				int ret;
				
				memset(&hints, 0, sizeof(hints));
				hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;
				ret = getaddrinfo((yyvsp[-1].string), NULL, &hints, &ai);
				if (ret) { yyerror (&yylloc, conf, gai_strerror(ret)); YYERROR; }
				CHECK_FCT_DO( fd_ep_add_merge( &conf->cnf_endpoints, ai->ai_addr, ai->ai_addrlen, EP_FL_CONF ), YYERROR );
				freeaddrinfo(ai);
				free((yyvsp[-1].string));
			}
#line 1597 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 244 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				CHECK_PARAMS_DO( ((yyvsp[-1].integer) > 0),
					{ yyerror (&yylloc, conf, "Invalid value"); YYERROR; } );
				conf->cnf_thr_srv = (yyvsp[-1].integer);
			}
#line 1607 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 252 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				conf->cnf_flags.no_fwd = 1;
			}
#line 1615 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 258 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				CHECK_PARAMS_DO( ((yyvsp[-1].integer) > 0) && ((yyvsp[-1].integer) < 256),
					{ yyerror (&yylloc, conf, "Invalid value"); YYERROR; } );
				conf->cnf_dispthr = (uint16_t)(yyvsp[-1].integer);
			}
#line 1625 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 266 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				if (got_peer_noipv6) { 
					yyerror (&yylloc, conf, "No_IP conflicts with a ConnectPeer directive No_IPv6."); 
					YYERROR; 
				}
				conf->cnf_flags.no_ip4 = 1;
			}
#line 1637 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 276 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				if (got_peer_noip) { 
					yyerror (&yylloc, conf, "No_IP conflicts with a ConnectPeer directive No_IP."); 
					YYERROR; 
				}
				conf->cnf_flags.no_ip6 = 1;
			}
#line 1649 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 286 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				#ifdef DISABLE_SCTP
				yyerror (&yylloc, conf, "No_TCP cannot be specified for daemon compiled with DISABLE_SCTP option."); 
				YYERROR; 
				#endif
				if (conf->cnf_flags.no_sctp)
				{
					yyerror (&yylloc, conf, "No_TCP conflicts with No_SCTP directive." ); 
					YYERROR; 
				}
				if (got_peer_nosctp) { 
					yyerror (&yylloc, conf, "No_TCP conflicts with a ConnectPeer directive No_SCTP."); 
					YYERROR; 
				}
				conf->cnf_flags.no_tcp = 1;
			}
#line 1670 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 305 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				if (conf->cnf_flags.no_tcp)
				{
					yyerror (&yylloc, conf, "No_SCTP conflicts with No_TCP directive." ); 
					YYERROR; 
				}
				if (got_peer_notcp) { 
					yyerror (&yylloc, conf, "No_SCTP conflicts with a ConnectPeer directive No_TCP.");
					YYERROR;
				}
				conf->cnf_flags.no_sctp = 1;
			}
#line 1687 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 320 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				conf->cnf_flags.pr_tcp = 1;
			}
#line 1695 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 326 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				conf->cnf_flags.tls_alg = 1;
			}
#line 1703 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 332 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				char * fname;
				char * cfname;
				FILE * fd;
				
				/* Try and open the extension file */
				fname = (yyvsp[-2].string);
				fd = fopen(fname, "r");
				if ((fd == NULL) && (*fname != '/')) {
					char * bkp = fname;
					CHECK_MALLOC_DO( fname = malloc( strlen(bkp) + strlen(DEFAULT_EXTENSIONS_PATH) + 2 ),
						{ yyerror (&yylloc, conf, "Not enough memory"); YYERROR; } );
					sprintf(fname, DEFAULT_EXTENSIONS_PATH "/%s", bkp);
					fd = fopen(fname, "r");
					if (fd == NULL) {
						free(fname);
						fname = bkp;
					} else {
						free(bkp);
					}
				}
				if (fd != NULL) {
					fclose(fd);
				} /* otherwise, LD_LIBRARY_PATH will be tested by dl_open. 
				This should not give any security issue, otherwise we can add an "else fail" here. */
				
				/* Try and open the configuration file (optional) */
				cfname = (yyvsp[-1].string);
				if (cfname) {
					fd = fopen(cfname, "r");
					if ((fd == NULL) && (*cfname != '/')) {
						char * test;
						CHECK_MALLOC_DO( test = malloc( strlen(cfname) + strlen(DEFAULT_CONF_PATH) + 2 ),
							{ yyerror (&yylloc, conf, "Not enough memory"); YYERROR; } );
						sprintf(test, DEFAULT_CONF_PATH "/%s", cfname);
						fd = fopen(test, "r");
						if (fd) {
							free(cfname);
							cfname=test;
						} else {
							/* This is not an error, we allow an extension to wait for something else than a real conf file. */
							free(test);
						}
					}
					if (fd)
						fclose(fd);
				}
				
				CHECK_FCT_DO( fd_ext_add( fname, cfname ),
					{ yyerror (&yylloc, conf, "Error adding extension"); YYERROR; } );
			}
#line 1759 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 386 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				(yyval.string) = NULL;
			}
#line 1767 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 390 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				(yyval.string) = (yyvsp[0].string);
			}
#line 1775 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 395 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				memset(&fddpi, 0, sizeof(fddpi));
				fddpi.config.pic_flags.persist = PI_PRST_ALWAYS;
				fd_list_init( &fddpi.pi_endpoints, NULL );
			}
#line 1785 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 401 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				fddpi.pi_diamid = (yyvsp[-2].string);
				CHECK_FCT_DO( fd_peer_add ( &fddpi, conf->cnf_file, NULL, NULL ),
					{ yyerror (&yylloc, conf, "Error adding ConnectPeer information"); YYERROR; } );
					
				/* Now destroy any content in the structure */
				free(fddpi.pi_diamid);
				free(fddpi.config.pic_realm);
				free(fddpi.config.pic_priority);
				while (!FD_IS_LIST_EMPTY(&fddpi.pi_endpoints)) {
					struct fd_list * li = fddpi.pi_endpoints.next;
					fd_list_unlink(li);
					free(li);
				}
			}
#line 1805 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 424 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				if ((conf->cnf_flags.no_ip6) || (fddpi.config.pic_flags.pro3 == PI_P3_IP)) { 
					yyerror (&yylloc, conf, "No_IP conflicts with a No_IPv6 directive.");
					YYERROR;
				}
				got_peer_noip++;
				fddpi.config.pic_flags.pro3 = PI_P3_IPv6;
			}
#line 1818 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 433 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				if ((conf->cnf_flags.no_ip4) || (fddpi.config.pic_flags.pro3 == PI_P3_IPv6)) { 
					yyerror (&yylloc, conf, "No_IPv6 conflicts with a No_IP directive.");
					YYERROR;
				}
				got_peer_noipv6++;
				fddpi.config.pic_flags.pro3 = PI_P3_IP;
			}
#line 1831 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 442 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				#ifdef DISABLE_SCTP
					yyerror (&yylloc, conf, "No_TCP cannot be specified in daemon compiled with DISABLE_SCTP option.");
					YYERROR;
				#endif
				if ((conf->cnf_flags.no_sctp) || (fddpi.config.pic_flags.pro4 == PI_P4_TCP)) { 
					yyerror (&yylloc, conf, "No_TCP conflicts with a No_SCTP directive.");
					YYERROR;
				}
				got_peer_notcp++;
				fddpi.config.pic_flags.pro4 = PI_P4_SCTP;
			}
#line 1848 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 455 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				if ((conf->cnf_flags.no_tcp) || (fddpi.config.pic_flags.pro4 == PI_P4_SCTP)) { 
					yyerror (&yylloc, conf, "No_SCTP conflicts with a No_TCP directive.");
					YYERROR;
				}
				got_peer_nosctp++;
				fddpi.config.pic_flags.pro4 = PI_P4_TCP;
			}
#line 1861 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 464 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				fddpi.config.pic_flags.alg = PI_ALGPREF_TCP;
			}
#line 1869 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 468 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				fddpi.config.pic_flags.sec |= PI_SEC_TLS_OLD;
			}
#line 1877 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 472 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				fddpi.config.pic_flags.sec |= PI_SEC_NONE;
			}
#line 1885 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 476 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				fddpi.config.pic_flags.sctpsec |= PI_SCTPSEC_3436;
			}
#line 1893 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 480 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				fddpi.config.pic_realm = (yyvsp[-1].string);
			}
#line 1901 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 484 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				CHECK_PARAMS_DO( ((yyvsp[-1].integer) > 0) && ((yyvsp[-1].integer) < 1<<16),
					{ yyerror (&yylloc, conf, "Invalid port value"); YYERROR; } );
				fddpi.config.pic_port = (uint16_t)(yyvsp[-1].integer);
			}
#line 1911 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 490 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				fddpi.config.pic_tctimer = (yyvsp[-1].integer);
			}
#line 1919 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 494 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				fddpi.config.pic_twtimer = (yyvsp[-1].integer);
			}
#line 1927 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 498 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				fddpi.config.pic_priority = (yyvsp[-1].string);
			}
#line 1935 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 502 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				struct addrinfo hints, *ai;
				int ret;
				int disc = 0;
				
				memset(&hints, 0, sizeof(hints));
				hints.ai_flags = AI_ADDRCONFIG | AI_NUMERICHOST;
				ret = getaddrinfo((yyvsp[-1].string), NULL, &hints, &ai);
				if (ret == EAI_NONAME) {
					/* The name was maybe not numeric, try again */
					disc = EP_FL_DISC;
					hints.ai_flags &= ~ AI_NUMERICHOST;
					ret = getaddrinfo((yyvsp[-1].string), NULL, &hints, &ai);
				}
				if (ret) { yyerror (&yylloc, conf, gai_strerror(ret)); YYERROR; }
				
				CHECK_FCT_DO( fd_ep_add_merge( &fddpi.pi_endpoints, ai->ai_addr, ai->ai_addrlen, EP_FL_CONF | (disc ?: EP_ACCEPTALL) ), YYERROR );
				free((yyvsp[-1].string));
				freeaddrinfo(ai);
			}
#line 1960 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 525 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				FILE * fd;
				fd = fopen((yyvsp[-3].string), "r");
				if (fd == NULL) {
					int ret = errno;
					TRACE_ERROR("Unable to open certificate file %s for reading: %s", (yyvsp[-3].string), strerror(ret));
					yyerror (&yylloc, conf, "Error on file name"); 
					YYERROR;
				}
				fclose(fd);
				fd = fopen((yyvsp[-1].string), "r");
				if (fd == NULL) {
					int ret = errno;
					TRACE_ERROR("Unable to open private key file %s for reading: %s", (yyvsp[-1].string), strerror(ret));
					yyerror (&yylloc, conf, "Error on file name"); 
					YYERROR;
				}
				fclose(fd);
				conf->cnf_sec_data.cert_file = (yyvsp[-3].string);
				conf->cnf_sec_data.key_file = (yyvsp[-1].string);
				
				CHECK_GNUTLS_DO( gnutls_certificate_set_x509_key_file( 
							conf->cnf_sec_data.credentials,
							conf->cnf_sec_data.cert_file,
							conf->cnf_sec_data.key_file,
							GNUTLS_X509_FMT_PEM),
						{ yyerror (&yylloc, conf, "Error opening certificate or private key file."); YYERROR; } );
			}
#line 1993 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 556 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				FILE * fd;
				fd = fopen((yyvsp[-1].string), "rb");
				if (fd == NULL) {
					int ret = errno;
					TRACE_ERROR("Unable to open CA file %s for reading: %s", (yyvsp[-1].string), strerror(ret));
					yyerror (&yylloc, conf, "Error on file name"); 
					YYERROR;
				}
				#ifdef GNUTLS_VERSION_300
				{
					/* We import these CA in the trust list */
					gnutls_x509_crt_t * calist;
					unsigned int cacount;
					gnutls_datum_t cafile;
					
					CHECK_FCT_DO( fd_conf_stream_to_gnutls_datum(fd, &cafile), 
							{ yyerror (&yylloc, conf, "Error reading CA file."); YYERROR; } );
							
					CHECK_GNUTLS_DO( gnutls_x509_crt_list_import2(&calist, &cacount, &cafile, GNUTLS_X509_FMT_PEM, 
										GNUTLS_X509_CRT_LIST_FAIL_IF_UNSORTED),
							{ yyerror (&yylloc, conf, "Error importing CA file."); YYERROR; } );
					free(cafile.data);
					
					CHECK_GNUTLS_DO( gnutls_x509_trust_list_add_cas (fd_g_config->cnf_sec_data.trustlist, calist, cacount, 0),
							{ yyerror (&yylloc, conf, "Error saving CA in trust list."); YYERROR; } );
				}
				#endif /* GNUTLS_VERSION_300 */
				fclose(fd);
				conf->cnf_sec_data.ca_file = (yyvsp[-1].string);
				CHECK_GNUTLS_DO( conf->cnf_sec_data.ca_file_nr += gnutls_certificate_set_x509_trust_file( 
							conf->cnf_sec_data.credentials,
							conf->cnf_sec_data.ca_file,
							GNUTLS_X509_FMT_PEM),
						{ yyerror (&yylloc, conf, "Error setting CA parameters."); YYERROR; } );
						
			}
#line 2035 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 596 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				FILE * fd;
				fd = fopen((yyvsp[-1].string), "rb");
				if (fd == NULL) {
					int ret = errno;
					TRACE_ERROR("Unable to open CRL file %s for reading: %s", (yyvsp[-1].string), strerror(ret));
					yyerror (&yylloc, conf, "Error on file name"); 
					YYERROR;
				}
				#ifdef GNUTLS_VERSION_300
				{
					/* We import these CRL in the trust list */
					gnutls_x509_crl_t * crllist;
					unsigned int crlcount;
					gnutls_datum_t crlfile;
					
					CHECK_FCT_DO( fd_conf_stream_to_gnutls_datum(fd, &crlfile), 
							{ yyerror (&yylloc, conf, "Error reading CRL file."); YYERROR; } );
							
					CHECK_GNUTLS_DO( gnutls_x509_crl_list_import2(&crllist, &crlcount, &crlfile, GNUTLS_X509_FMT_PEM, 0),
							{ yyerror (&yylloc, conf, "Error importing CRL file."); YYERROR; } );
					free(crlfile.data);
					
					CHECK_GNUTLS_DO( gnutls_x509_trust_list_add_crls (fd_g_config->cnf_sec_data.trustlist, crllist, crlcount, 
									GNUTLS_TL_VERIFY_CRL,
									0),
							{ yyerror (&yylloc, conf, "Error importing CRL in trust list."); YYERROR; } );
				}
				#endif /* GNUTLS_VERSION_300 */
				fclose(fd);
				conf->cnf_sec_data.crl_file = (yyvsp[-1].string);
				CHECK_GNUTLS_DO( gnutls_certificate_set_x509_crl_file( 
							conf->cnf_sec_data.credentials,
							conf->cnf_sec_data.crl_file,
							GNUTLS_X509_FMT_PEM),
						{ yyerror (&yylloc, conf, "Error setting CRL parameters."); YYERROR; } );
			}
#line 2077 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 636 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				const char * err_pos = NULL;
				conf->cnf_sec_data.prio_string = (yyvsp[-1].string);
				CHECK_GNUTLS_DO( gnutls_priority_init( 
							&conf->cnf_sec_data.prio_cache,
							conf->cnf_sec_data.prio_string,
							&err_pos),
						{ yyerror (&yylloc, conf, "Error setting Priority parameter.");
						  TRACE_ERROR("Error at position : %s", err_pos);
						  YYERROR; } );
			}
#line 2093 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 650 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				conf->cnf_sec_data.dh_bits = (yyvsp[-1].integer);
			}
#line 2101 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 654 "/home/samin/workspace/research_implementation/proxy/freediameter/src/libfdcore/fdd.y" /* yacc.c:1646  */
    {
				FILE * fd;
				free(conf->cnf_sec_data.dh_file);
				conf->cnf_sec_data.dh_file = (yyvsp[-1].string);
				fd = fopen((yyvsp[-1].string), "r");
				if (fd == NULL) {
					int ret = errno;
					TRACE_ERROR("Unable to open DH file %s for reading: %s", (yyvsp[-1].string), strerror(ret));
					yyerror (&yylloc, conf, "Error on file name"); 
					YYERROR;
				}
				fclose(fd);
			}
#line 2119 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
    break;


#line 2123 "/home/samin/workspace/research_implementation/proxy/freediameter/build/libfdcore/fdd.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, conf, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, conf, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, conf);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, conf);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, conf, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, conf);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, conf);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
