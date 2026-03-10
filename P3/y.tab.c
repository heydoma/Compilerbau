/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         cpp_parse
#define yylex           cpp_lex
#define yyerror         cpp_error
#define yydebug         cpp_debug
#define yynerrs         cpp_nerrs

/* First part of user prologue.  */
#line 20 "CPP2.y"

/* Begin C preamble code */

#include <algorithm> /* for std::reverse */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Absyn.H"

#define YYMAXDEPTH 10000000

/* The type yyscan_t is defined by flex, but we need it in the parser already. */
#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE cpp__scan_string(const char *str, yyscan_t scanner);
extern void cpp__delete_buffer(YY_BUFFER_STATE buf, yyscan_t scanner);

extern void cpp_lex_destroy(yyscan_t scanner);
extern char* cpp_get_text(yyscan_t scanner);

extern yyscan_t cpp__initialize_lexer(FILE * inp);

/* End C preamble code */

#line 104 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_CPP_BISON_H_INCLUDED
# define YY_CPP_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int cpp_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _ERROR_ = 258,
    _BANGEQ = 259,
    _DAMP = 260,
    _LPAREN = 261,
    _RPAREN = 262,
    _STAR = 263,
    _PLUS = 264,
    _DPLUS = 265,
    _MINUS = 266,
    _DMINUS = 267,
    _DOT = 268,
    _SLASH = 269,
    _COLON = 270,
    _SEMI = 271,
    _LT = 272,
    _LDARROW = 273,
    _SYMB_12 = 274,
    _EQ = 275,
    _DEQ = 276,
    _GT = 277,
    _GTEQ = 278,
    _QUESTION = 279,
    _KW_bool = 280,
    _KW_do = 281,
    _KW_else = 282,
    _KW_false = 283,
    _KW_for = 284,
    _KW_if = 285,
    _KW_int = 286,
    _KW_return = 287,
    _KW_struct = 288,
    _KW_true = 289,
    _KW_void = 290,
    _KW_while = 291,
    _LBRACE = 292,
    _DBAR = 293,
    _RBRACE = 294,
    _INTEGER_ = 295,
    _IDENT_ = 296
  };
#endif
/* Tokens.  */
#define _ERROR_ 258
#define _BANGEQ 259
#define _DAMP 260
#define _LPAREN 261
#define _RPAREN 262
#define _STAR 263
#define _PLUS 264
#define _DPLUS 265
#define _MINUS 266
#define _DMINUS 267
#define _DOT 268
#define _SLASH 269
#define _COLON 270
#define _SEMI 271
#define _LT 272
#define _LDARROW 273
#define _SYMB_12 274
#define _EQ 275
#define _DEQ 276
#define _GT 277
#define _GTEQ 278
#define _QUESTION 279
#define _KW_bool 280
#define _KW_do 281
#define _KW_else 282
#define _KW_false 283
#define _KW_for 284
#define _KW_if 285
#define _KW_int 286
#define _KW_return 287
#define _KW_struct 288
#define _KW_true 289
#define _KW_void 290
#define _KW_while 291
#define _LBRACE 292
#define _DBAR 293
#define _RBRACE 294
#define _INTEGER_ 295
#define _IDENT_ 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "CPP2.y"

  int    _int;
  char   _char;
  double _double;
  char*  _string;
  Program* program_;
  Def* def_;
  ListDef* listdef_;
  Field* field_;
  ListField* listfield_;
  Stm* stm_;
  ListStm* liststm_;
  Exp* exp_;
  Type* type_;

#line 254 "y.tab.c"

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



int cpp_parse (yyscan_t scanner, YYSTYPE *result);

#endif /* !YY_CPP_BISON_H_INCLUDED  */

/* Second part of user prologue.  */
#line 66 "CPP2.y"

void yyerror(YYLTYPE *loc, yyscan_t scanner, YYSTYPE *result, const char *msg)
{
  fprintf(stderr, "error: %d,%d: %s at %s\n",
    loc->first_line, loc->first_column, msg, cpp_get_text(scanner));
}

int yyparse(yyscan_t scanner, YYSTYPE *result);

extern int yylex(YYSTYPE *lvalp, YYLTYPE *llocp, yyscan_t scanner);

#line 295 "y.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   171

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   147,   147,   149,   150,   151,   153,   154,   156,   158,
     159,   161,   162,   163,   164,   165,   166,   167,   168,   170,
     171,   173,   174,   175,   176,   177,   179,   180,   181,   182,
     183,   185,   186,   187,   188,   189,   191,   192,   193,   195,
     196,   197,   199,   200,   202,   203,   204,   205,   206,   208,
     209,   210,   212,   213,   215,   216,   218,   219,   220,   222,
     224,   226,   228,   230,   232,   233,   234,   235
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "_BANGEQ", "_DAMP", "_LPAREN",
  "_RPAREN", "_STAR", "_PLUS", "_DPLUS", "_MINUS", "_DMINUS", "_DOT",
  "_SLASH", "_COLON", "_SEMI", "_LT", "_LDARROW", "_SYMB_12", "_EQ",
  "_DEQ", "_GT", "_GTEQ", "_QUESTION", "_KW_bool", "_KW_do", "_KW_else",
  "_KW_false", "_KW_for", "_KW_if", "_KW_int", "_KW_return", "_KW_struct",
  "_KW_true", "_KW_void", "_KW_while", "_LBRACE", "_DBAR", "_RBRACE",
  "_INTEGER_", "_IDENT_", "$accept", "Program", "Def", "ListDef", "Field",
  "ListField", "Stm", "ListStm", "Exp15", "Exp14", "Exp13", "Exp12",
  "Exp11", "Exp10", "Exp9", "Exp8", "Exp4", "Exp3", "Exp2", "Exp", "Exp1",
  "Exp5", "Exp6", "Exp7", "Type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -79,    11,    -2,   -79,   -79,   -79,   -24,   -79,   -79,   -79,
     -19,   -10,    -1,    86,   -79,    42,    14,    20,    36,    86,
     -79,   -79,   104,   104,   104,   104,   104,   130,   -79,    61,
      63,     9,   -79,    65,   -79,   -79,   -79,    68,   -79,   -79,
      22,   -79,     2,    19,    64,    37,     3,    77,   -12,   -79,
      69,   -79,   -79,   -79,   -79,   -79,    79,   -79,   -79,   -79,
     -79,    48,   104,   104,   -79,    71,   104,    94,    85,   -79,
     -79,    52,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   -79,   -79,    88,
      80,    90,   -79,    92,   -79,   -79,   -79,   -79,   -79,     2,
       2,    19,    64,    64,    64,    64,    37,    37,   -79,   -79,
      93,    77,   104,   104,   130,   130,   104,   100,    96,    82,
     -79,   -79,   102,   104,   130,   -79,   112,   -79,   130,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     2,     1,    64,    65,     0,    66,    67,     7,
       0,     0,     3,     0,    19,     0,     0,     0,     0,     9,
       5,     8,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,    21,     0,    19,     4,    23,    24,    20,    30,
      35,    38,    41,    43,    48,    51,    63,    55,    58,    60,
       0,    59,    53,    61,    62,    10,     0,    33,    31,    34,
      32,     0,     0,     0,    13,     0,     0,     0,     0,    28,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    25,     0,
       0,     0,    12,     0,    17,    26,    27,    36,    37,    39,
      40,    42,    44,    46,    45,    47,    50,    49,    52,    56,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    57,     0,     0,     0,    15,     0,    18,     0,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   -79,   -79,    76,   -26,    91,   -79,   -79,
     -21,   -61,    53,     1,   -25,   -79,    51,   -79,   -78,   -22,
     -79,    60,   -79,   -79,   144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     9,     2,    15,    16,    38,    18,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    61,    57,    58,    59,    60,   109,    81,    84,    65,
      72,     3,    85,    99,   100,    22,    73,    11,    23,    24,
      25,    26,    12,     4,    82,    64,    86,    13,    74,     5,
      75,     6,    69,     7,    70,    71,    14,    28,   121,     8,
      90,    91,    22,    32,    93,    23,    24,    25,    26,    36,
      37,    97,    98,    20,    77,    78,   106,   107,    19,    79,
      80,    21,    27,   110,    28,    29,    30,    62,    31,    63,
      32,    66,    33,    34,    68,    35,    36,    37,   102,   103,
     104,   105,    83,    76,    89,    87,    88,    92,   119,   120,
     117,   118,    95,    96,   112,    55,   113,   114,   127,   115,
      22,   126,   129,    23,    24,    25,    26,   122,   116,   124,
      22,     4,   123,    23,    24,    25,    26,     5,   125,   128,
      27,     7,    28,    29,    30,    67,    31,     8,    32,   101,
      33,    34,    28,    94,    36,    37,    22,   111,    32,    23,
      24,    25,    26,   108,    36,    37,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,    28,    29,
      30,     0,    31,     0,    32,     0,    33,    34,     0,     0,
      36,    37
};

static const yytype_int16 yycheck[] =
{
      22,    27,    23,    24,    25,    26,    84,     4,    20,    31,
       8,     0,    24,    74,    75,     6,    14,    41,     9,    10,
      11,    12,    41,    25,    21,    16,    38,    37,     9,    31,
      11,    33,    10,    35,    12,    13,    37,    28,   116,    41,
      62,    63,     6,    34,    66,     9,    10,    11,    12,    40,
      41,    72,    73,    39,    17,    18,    81,    82,    16,    22,
      23,    41,    26,    85,    28,    29,    30,     6,    32,     6,
      34,     6,    36,    37,     6,    39,    40,    41,    77,    78,
      79,    80,     5,    19,    36,    16,     7,    16,   114,   115,
     112,   113,     7,    41,     6,    19,    16,     7,   124,     7,
       6,   123,   128,     9,    10,    11,    12,     7,    15,    27,
       6,    25,    16,     9,    10,    11,    12,    31,    16,     7,
      26,    35,    28,    29,    30,    34,    32,    41,    34,    76,
      36,    37,    28,    39,    40,    41,     6,    86,    34,     9,
      10,    11,    12,    83,    40,    41,     2,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,
      30,    -1,    32,    -1,    34,    -1,    36,    37,    -1,    -1,
      40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    45,     0,    25,    31,    33,    35,    41,    44,
      66,    41,    41,    37,    37,    46,    47,    66,    49,    16,
      39,    41,     6,     9,    10,    11,    12,    26,    28,    29,
      30,    32,    34,    36,    37,    39,    40,    41,    48,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    47,    61,    52,    52,    52,
      52,    48,     6,     6,    16,    61,     6,    49,     6,    10,
      12,    13,     8,    14,     9,    11,    19,    17,    18,    22,
      23,     4,    21,     5,    20,    24,    38,    16,     7,    36,
      61,    61,    16,    61,    39,     7,    41,    52,    52,    53,
      53,    54,    55,    55,    55,    55,    56,    56,    63,    60,
      61,    58,     6,    16,     7,     7,    15,    61,    61,    48,
      48,    60,     7,    16,    27,    16,    61,    48,     7,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    45,    45,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    50,    50,    50,    50,    50,    51,    51,    51,    51,
      51,    52,    52,    52,    52,    52,    53,    53,    53,    54,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    57,
      57,    57,    58,    58,    59,    59,    60,    60,    60,    61,
      62,    63,    64,    65,    66,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     5,     5,     0,     2,     2,     2,
       3,     2,     3,     2,     5,     7,     9,     3,     7,     0,
       2,     1,     1,     1,     1,     3,     3,     3,     2,     2,
       1,     2,     2,     2,     2,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (&yylloc, scanner, result, YY_("syntax error: cannot back up")); \
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
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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
                  Type, Value, Location, scanner, result); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, YYSTYPE *result)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (result);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner, YYSTYPE *result)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, scanner, result);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, yyscan_t scanner, YYSTYPE *result)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , scanner, result);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, scanner, result); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner, YYSTYPE *result)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);
  YYUSE (result);
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
yyparse (yyscan_t scanner, YYSTYPE *result)
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

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

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

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 147 "CPP2.y"
                  { (yyval.program_) = new PDefs((yyvsp[0].listdef_)); result->program_ = (yyval.program_); }
#line 1659 "y.tab.c"
    break;

  case 3:
#line 149 "CPP2.y"
                   { (yyval.def_) = new DVar((yyvsp[-1].type_), (yyvsp[0]._string)); result->def_ = (yyval.def_); }
#line 1665 "y.tab.c"
    break;

  case 4:
#line 150 "CPP2.y"
                                         { (yyval.def_) = new DFun((yyvsp[-4].type_), (yyvsp[-3]._string), (yyvsp[-1].liststm_)); result->def_ = (yyval.def_); }
#line 1671 "y.tab.c"
    break;

  case 5:
#line 151 "CPP2.y"
                                                 { std::reverse((yyvsp[-1].listfield_)->begin(),(yyvsp[-1].listfield_)->end()) ;(yyval.def_) = new DStruct((yyvsp[-3]._string), (yyvsp[-1].listfield_)); result->def_ = (yyval.def_); }
#line 1677 "y.tab.c"
    break;

  case 6:
#line 153 "CPP2.y"
                      { (yyval.listdef_) = new ListDef(); result->listdef_ = (yyval.listdef_); }
#line 1683 "y.tab.c"
    break;

  case 7:
#line 154 "CPP2.y"
                { (yyvsp[-1].listdef_)->push_back((yyvsp[0].def_)); (yyval.listdef_) = (yyvsp[-1].listdef_); result->listdef_ = (yyval.listdef_); }
#line 1689 "y.tab.c"
    break;

  case 8:
#line 156 "CPP2.y"
                     { (yyval.field_) = new FDecl((yyvsp[-1].type_), (yyvsp[0]._string)); result->field_ = (yyval.field_); }
#line 1695 "y.tab.c"
    break;

  case 9:
#line 158 "CPP2.y"
                        { (yyval.listfield_) = new ListField(); (yyval.listfield_)->push_back((yyvsp[-1].field_)); result->listfield_ = (yyval.listfield_); }
#line 1701 "y.tab.c"
    break;

  case 10:
#line 159 "CPP2.y"
                          { (yyvsp[0].listfield_)->push_back((yyvsp[-2].field_)); (yyval.listfield_) = (yyvsp[0].listfield_); result->listfield_ = (yyval.listfield_); }
#line 1707 "y.tab.c"
    break;

  case 11:
#line 161 "CPP2.y"
                { (yyval.stm_) = new SExp((yyvsp[-1].exp_)); result->stm_ = (yyval.stm_); }
#line 1713 "y.tab.c"
    break;

  case 12:
#line 162 "CPP2.y"
                         { (yyval.stm_) = new SReturn((yyvsp[-1].exp_)); result->stm_ = (yyval.stm_); }
#line 1719 "y.tab.c"
    break;

  case 13:
#line 163 "CPP2.y"
                     { (yyval.stm_) = new SReturnV(); result->stm_ = (yyval.stm_); }
#line 1725 "y.tab.c"
    break;

  case 14:
#line 164 "CPP2.y"
                                      { (yyval.stm_) = new SWhile((yyvsp[-2].exp_), (yyvsp[0].stm_)); result->stm_ = (yyval.stm_); }
#line 1731 "y.tab.c"
    break;

  case 15:
#line 165 "CPP2.y"
                                                   { (yyval.stm_) = new SDoWhile((yyvsp[-5].stm_), (yyvsp[-2].exp_)); result->stm_ = (yyval.stm_); }
#line 1737 "y.tab.c"
    break;

  case 16:
#line 166 "CPP2.y"
                                                        { (yyval.stm_) = new SFor((yyvsp[-6].exp_), (yyvsp[-4].exp_), (yyvsp[-2].exp_), (yyvsp[0].stm_)); result->stm_ = (yyval.stm_); }
#line 1743 "y.tab.c"
    break;

  case 17:
#line 167 "CPP2.y"
                            { (yyval.stm_) = new SBlock((yyvsp[-1].liststm_)); result->stm_ = (yyval.stm_); }
#line 1749 "y.tab.c"
    break;

  case 18:
#line 168 "CPP2.y"
                                                { (yyval.stm_) = new SIfElse((yyvsp[-4].exp_), (yyvsp[-2].stm_), (yyvsp[0].stm_)); result->stm_ = (yyval.stm_); }
#line 1755 "y.tab.c"
    break;

  case 19:
#line 170 "CPP2.y"
                      { (yyval.liststm_) = new ListStm(); result->liststm_ = (yyval.liststm_); }
#line 1761 "y.tab.c"
    break;

  case 20:
#line 171 "CPP2.y"
                { (yyvsp[-1].liststm_)->push_back((yyvsp[0].stm_)); (yyval.liststm_) = (yyvsp[-1].liststm_); result->liststm_ = (yyval.liststm_); }
#line 1767 "y.tab.c"
    break;

  case 21:
#line 173 "CPP2.y"
                 { (yyval.exp_) = new ETrue(); result->exp_ = (yyval.exp_); }
#line 1773 "y.tab.c"
    break;

  case 22:
#line 174 "CPP2.y"
              { (yyval.exp_) = new EFalse(); result->exp_ = (yyval.exp_); }
#line 1779 "y.tab.c"
    break;

  case 23:
#line 175 "CPP2.y"
              { (yyval.exp_) = new EInt((yyvsp[0]._int)); result->exp_ = (yyval.exp_); }
#line 1785 "y.tab.c"
    break;

  case 24:
#line 176 "CPP2.y"
            { (yyval.exp_) = new EIdent((yyvsp[0]._string)); result->exp_ = (yyval.exp_); }
#line 1791 "y.tab.c"
    break;

  case 25:
#line 177 "CPP2.y"
                        { (yyval.exp_) = (yyvsp[-1].exp_); result->exp_ = (yyval.exp_); }
#line 1797 "y.tab.c"
    break;

  case 26:
#line 179 "CPP2.y"
                                { (yyval.exp_) = new EApp((yyvsp[-2]._string)); result->exp_ = (yyval.exp_); }
#line 1803 "y.tab.c"
    break;

  case 27:
#line 180 "CPP2.y"
                       { (yyval.exp_) = new EProj((yyvsp[-2].exp_), (yyvsp[0]._string)); result->exp_ = (yyval.exp_); }
#line 1809 "y.tab.c"
    break;

  case 28:
#line 181 "CPP2.y"
                 { (yyval.exp_) = new EPIncr((yyvsp[-1].exp_)); result->exp_ = (yyval.exp_); }
#line 1815 "y.tab.c"
    break;

  case 29:
#line 182 "CPP2.y"
                  { (yyval.exp_) = new EPDecr((yyvsp[-1].exp_)); result->exp_ = (yyval.exp_); }
#line 1821 "y.tab.c"
    break;

  case 30:
#line 183 "CPP2.y"
          { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 1827 "y.tab.c"
    break;

  case 31:
#line 185 "CPP2.y"
                     { (yyval.exp_) = new EIncr((yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1833 "y.tab.c"
    break;

  case 32:
#line 186 "CPP2.y"
                  { (yyval.exp_) = new EDecr((yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1839 "y.tab.c"
    break;

  case 33:
#line 187 "CPP2.y"
                { (yyval.exp_) = new EUPlus((yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1845 "y.tab.c"
    break;

  case 34:
#line 188 "CPP2.y"
                 { (yyval.exp_) = new EUMinus((yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1851 "y.tab.c"
    break;

  case 35:
#line 189 "CPP2.y"
          { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 1857 "y.tab.c"
    break;

  case 36:
#line 191 "CPP2.y"
                          { (yyval.exp_) = new ETimes((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1863 "y.tab.c"
    break;

  case 37:
#line 192 "CPP2.y"
                       { (yyval.exp_) = new EDiv((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1869 "y.tab.c"
    break;

  case 38:
#line 193 "CPP2.y"
          { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 1875 "y.tab.c"
    break;

  case 39:
#line 195 "CPP2.y"
                          { (yyval.exp_) = new EPlus((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1881 "y.tab.c"
    break;

  case 40:
#line 196 "CPP2.y"
                       { (yyval.exp_) = new EMinus((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1887 "y.tab.c"
    break;

  case 41:
#line 197 "CPP2.y"
          { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 1893 "y.tab.c"
    break;

  case 42:
#line 199 "CPP2.y"
                             { (yyval.exp_) = new ETwc((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1899 "y.tab.c"
    break;

  case 43:
#line 200 "CPP2.y"
          { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 1905 "y.tab.c"
    break;

  case 44:
#line 202 "CPP2.y"
                      { (yyval.exp_) = new ELt((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1911 "y.tab.c"
    break;

  case 45:
#line 203 "CPP2.y"
                   { (yyval.exp_) = new EGt((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1917 "y.tab.c"
    break;

  case 46:
#line 204 "CPP2.y"
                        { (yyval.exp_) = new ELtEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1923 "y.tab.c"
    break;

  case 47:
#line 205 "CPP2.y"
                     { (yyval.exp_) = new EGtEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1929 "y.tab.c"
    break;

  case 48:
#line 206 "CPP2.y"
          { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 1935 "y.tab.c"
    break;

  case 49:
#line 208 "CPP2.y"
                      { (yyval.exp_) = new EEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1941 "y.tab.c"
    break;

  case 50:
#line 209 "CPP2.y"
                      { (yyval.exp_) = new ENEq((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1947 "y.tab.c"
    break;

  case 51:
#line 210 "CPP2.y"
         { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 1953 "y.tab.c"
    break;

  case 52:
#line 212 "CPP2.y"
                       { (yyval.exp_) = new EAnd((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1959 "y.tab.c"
    break;

  case 53:
#line 213 "CPP2.y"
         { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 1965 "y.tab.c"
    break;

  case 54:
#line 215 "CPP2.y"
                       { (yyval.exp_) = new EOr((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1971 "y.tab.c"
    break;

  case 55:
#line 216 "CPP2.y"
         { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 1977 "y.tab.c"
    break;

  case 56:
#line 218 "CPP2.y"
                     { (yyval.exp_) = new EAss((yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1983 "y.tab.c"
    break;

  case 57:
#line 219 "CPP2.y"
                                   { (yyval.exp_) = new ECond((yyvsp[-4].exp_), (yyvsp[-2].exp_), (yyvsp[0].exp_)); result->exp_ = (yyval.exp_); }
#line 1989 "y.tab.c"
    break;

  case 58:
#line 220 "CPP2.y"
         { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 1995 "y.tab.c"
    break;

  case 59:
#line 222 "CPP2.y"
           { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 2001 "y.tab.c"
    break;

  case 60:
#line 224 "CPP2.y"
            { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 2007 "y.tab.c"
    break;

  case 61:
#line 226 "CPP2.y"
            { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 2013 "y.tab.c"
    break;

  case 62:
#line 228 "CPP2.y"
            { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 2019 "y.tab.c"
    break;

  case 63:
#line 230 "CPP2.y"
            { (yyval.exp_) = (yyvsp[0].exp_); result->exp_ = (yyval.exp_); }
#line 2025 "y.tab.c"
    break;

  case 64:
#line 232 "CPP2.y"
                { (yyval.type_) = new Type_bool(); result->type_ = (yyval.type_); }
#line 2031 "y.tab.c"
    break;

  case 65:
#line 233 "CPP2.y"
            { (yyval.type_) = new Type_int(); result->type_ = (yyval.type_); }
#line 2037 "y.tab.c"
    break;

  case 66:
#line 234 "CPP2.y"
             { (yyval.type_) = new Type_void(); result->type_ = (yyval.type_); }
#line 2043 "y.tab.c"
    break;

  case 67:
#line 235 "CPP2.y"
            { (yyval.type_) = new TypeIdent((yyvsp[0]._string)); result->type_ = (yyval.type_); }
#line 2049 "y.tab.c"
    break;


#line 2053 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
      yyerror (&yylloc, scanner, result, YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (&yylloc, scanner, result, yymsgp);
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
                      yytoken, &yylval, &yylloc, scanner, result);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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
                  yystos[yystate], yyvsp, yylsp, scanner, result);
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
  yyerror (&yylloc, scanner, result, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner, result);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp, scanner, result);
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
#line 238 "CPP2.y"



/* Entrypoint: parse Program* from file. */
Program* pProgram(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.program_;
  }
}

/* Entrypoint: parse Program* from string. */
Program* psProgram(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.program_;
  }
}

/* Entrypoint: parse Def* from file. */
Def* pDef(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.def_;
  }
}

/* Entrypoint: parse Def* from string. */
Def* psDef(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.def_;
  }
}

/* Entrypoint: parse ListDef* from file. */
ListDef* pListDef(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.listdef_;
  }
}

/* Entrypoint: parse ListDef* from string. */
ListDef* psListDef(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.listdef_;
  }
}

/* Entrypoint: parse Field* from file. */
Field* pField(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.field_;
  }
}

/* Entrypoint: parse Field* from string. */
Field* psField(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.field_;
  }
}

/* Entrypoint: parse ListField* from file. */
ListField* pListField(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listfield_->begin(), result.listfield_->end());
    return result.listfield_;
  }
}

/* Entrypoint: parse ListField* from string. */
ListField* psListField(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
std::reverse(result.listfield_->begin(), result.listfield_->end());
    return result.listfield_;
  }
}

/* Entrypoint: parse Stm* from file. */
Stm* pStm(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.stm_;
  }
}

/* Entrypoint: parse Stm* from string. */
Stm* psStm(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.stm_;
  }
}

/* Entrypoint: parse ListStm* from file. */
ListStm* pListStm(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.liststm_;
  }
}

/* Entrypoint: parse ListStm* from string. */
ListStm* psListStm(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.liststm_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp15(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp15(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp14(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp14(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp13(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp13(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp12(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp12(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp11(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp11(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp10(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp10(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp9(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp9(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp8(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp8(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp4(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp4(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp3(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp3(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp2(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp2(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp1(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp1(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp5(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp5(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp6(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp6(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from file. */
Exp* pExp7(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Exp* from string. */
Exp* psExp7(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.exp_;
  }
}

/* Entrypoint: parse Type* from file. */
Type* pType(FILE *inp)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(inp);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  int error = yyparse(scanner, &result);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}

/* Entrypoint: parse Type* from string. */
Type* psType(const char *str)
{
  YYSTYPE result;
  yyscan_t scanner = cpp__initialize_lexer(0);
  if (!scanner) {
    fprintf(stderr, "Failed to initialize lexer.\n");
    return 0;
  }
  YY_BUFFER_STATE buf = cpp__scan_string(str, scanner);
  int error = yyparse(scanner, &result);
  cpp__delete_buffer(buf, scanner);
  cpp_lex_destroy(scanner);
  if (error)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return result.type_;
  }
}



