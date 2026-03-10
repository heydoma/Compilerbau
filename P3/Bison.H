/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 155 "Bison.H"

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
