
/**
 * @file node_basic.h
 *
 * Functions to allocate node structures
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: node_basic.h.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

#ifndef _SAC_NODE_BASIC_H_
#define _SAC_NODE_BASIC_H_

#include "types.h"


#define _SAC_AST_VERSION_ "0.9"


/*****************************************************************************
 * macros and functions for N_program
 *****************************************************************************/

#define PROGRAM_DECLARATIONS( n) ((n)->sons.N_program->Declarations)
extern node *TBmakeProgram (node * Declarations);

/*****************************************************************************
 * macros and functions for N_declarations
 *****************************************************************************/

#define DECLARATIONS_DECLARATION( n) ((n)->sons.N_declarations->Declaration)
#define DECLARATIONS_DECLARATIONS( n) ((n)->sons.N_declarations->Declarations)
extern node *TBmakeDeclarations (node * Declaration, node * Declarations);

/*****************************************************************************
 * macros and functions for N_module
 *****************************************************************************/

#define MODULE_STMTS( n) ((n)->sons.N_module->Stmts)
#define MODULE_COUNT_ALL( n) ((n)->attribs.N_module->Count_all)
#define MODULE_COUNT_ADD( n) ((n)->attribs.N_module->Count_add)
#define MODULE_COUNT_SUB( n) ((n)->attribs.N_module->Count_sub)
#define MODULE_COUNT_MUL( n) ((n)->attribs.N_module->Count_mul)
#define MODULE_COUNT_DIV( n) ((n)->attribs.N_module->Count_div)
#define MODULE_COUNT_MOD( n) ((n)->attribs.N_module->Count_mod)
extern node *TBmakeModule (int Count_all, int Count_add, int Count_sub,
			   int Count_mul, int Count_div, int Count_mod,
			   node * Stmts);

/*****************************************************************************
 * macros and functions for N_fundec
 *****************************************************************************/

#define FUNDEC_KEYWORD( n) ((n)->sons.N_fundec->Keyword)
#define FUNDEC_FUNHEADER( n) ((n)->sons.N_fundec->FunHeader)
#define FUNDEC_SEMICOLON( n) ((n)->sons.N_fundec->Semicolon)
extern node *TBmakeFundec (node * Keyword, node * FunHeader,
			   node * Semicolon);

/*****************************************************************************
 * macros and functions for N_extern
 *****************************************************************************/

extern node *TBmakeExtern ();

/*****************************************************************************
 * macros and functions for N_semicolon
 *****************************************************************************/

extern node *TBmakeSemicolon ();

/*****************************************************************************
 * macros and functions for N_fundef
 *****************************************************************************/

#define FUNDEF_KEYWORD( n) ((n)->sons.N_fundef->Keyword)
#define FUNDEF_FUNHEADER( n) ((n)->sons.N_fundef->FunHeader)
#define FUNDEF_FUNBODYBLOCK( n) ((n)->sons.N_fundef->FunBodyBlock)
extern node *TBmakeFundef (node * Keyword, node * FunHeader,
			   node * FunBodyBlock);

/*****************************************************************************
 * macros and functions for N_funbodyblock
 *****************************************************************************/

#define FUNBODYBLOCK_L_CURLY_BRACKET( n) ((n)->sons.N_funbodyblock->L_curly_bracket)
#define FUNBODYBLOCK_FUNBODY( n) ((n)->sons.N_funbodyblock->FunBody)
#define FUNBODYBLOCK_R_CURLY_BRACKET( n) ((n)->sons.N_funbodyblock->R_curly_bracket)
extern node *TBmakeFunbodyblock (node * L_curly_bracket, node * FunBody,
				 node * R_curly_bracket);

/*****************************************************************************
 * macros and functions for N_l_curly_bracket
 *****************************************************************************/

extern node *TBmakeL_curly_bracket ();

/*****************************************************************************
 * macros and functions for N_r_curly_bracket
 *****************************************************************************/

extern node *TBmakeR_curly_bracket ();

/*****************************************************************************
 * macros and functions for N_l_bracket
 *****************************************************************************/

extern node *TBmakeL_bracket ();

/*****************************************************************************
 * macros and functions for N_r_bracket
 *****************************************************************************/

extern node *TBmakeR_bracket ();

/*****************************************************************************
 * macros and functions for N_comma
 *****************************************************************************/

extern node *TBmakeComma ();

/*****************************************************************************
 * macros and functions for N_funheader
 *****************************************************************************/

#define FUNHEADER_RETTYPE( n) ((n)->sons.N_funheader->RetType)
#define FUNHEADER_ID( n) ((n)->sons.N_funheader->Id)
#define FUNHEADER_L_BRACKET( n) ((n)->sons.N_funheader->L_bracket)
#define FUNHEADER_PARAMS( n) ((n)->sons.N_funheader->Params)
#define FUNHEADER_R_BRACKET( n) ((n)->sons.N_funheader->R_bracket)
extern node *TBmakeFunheader (node * RetType, node * Id, node * L_bracket,
			      node * Params, node * R_bracket);

/*****************************************************************************
 * macros and functions for N_params
 *****************************************************************************/

#define PARAMS_PARAM( n) ((n)->sons.N_params->Param)
#define PARAMS_COMMA( n) ((n)->sons.N_params->Comma)
#define PARAMS_PARAMS( n) ((n)->sons.N_params->Params)
extern node *TBmakeParams (node * Param, node * Comma, node * Params);

/*****************************************************************************
 * macros and functions for N_param
 *****************************************************************************/

#define PARAM_RETTYPE( n) ((n)->sons.N_param->RetType)
#define PARAM_ID( n) ((n)->sons.N_param->Id)
extern node *TBmakeParam (node * RetType, node * Id);

/*****************************************************************************
 * macros and functions for N_id
 *****************************************************************************/

#define ID_ID( n) ((n)->attribs.N_id->Id)
extern node *TBmakeId (char *Id);

/*****************************************************************************
 * macros and functions for N_globaldec
 *****************************************************************************/

#define GLOBALDEC_EXTERN( n) ((n)->sons.N_globaldec->Extern)
#define GLOBALDEC_TYPE( n) ((n)->sons.N_globaldec->Type)
#define GLOBALDEC_ID( n) ((n)->sons.N_globaldec->Id)
#define GLOBALDEC_SEMICOLON( n) ((n)->sons.N_globaldec->Semicolon)
extern node *TBmakeGlobaldec (node * Extern, node * Type, node * Id,
			      node * Semicolon);

/*****************************************************************************
 * macros and functions for N_globaldef
 *****************************************************************************/

#define GLOBALDEF_EXPORT( n) ((n)->sons.N_globaldef->Export)
#define GLOBALDEF_TYPE( n) ((n)->sons.N_globaldef->Type)
#define GLOBALDEF_ID( n) ((n)->sons.N_globaldef->Id)
#define GLOBALDEF_EXPR( n) ((n)->sons.N_globaldef->Expr)
#define GLOBALDEF_SEMICOLON( n) ((n)->sons.N_globaldef->Semicolon)
extern node *TBmakeGlobaldef (node * Export, node * Type, node * Id,
			      node * Expr, node * Semicolon);

/*****************************************************************************
 * macros and functions for N_stmts
 *****************************************************************************/

#define STMTS_STMT( n) ((n)->sons.N_stmts->Stmt)
#define STMTS_NEXT( n) ((n)->sons.N_stmts->Next)
extern node *TBmakeStmts (node * Stmt, node * Next);

/*****************************************************************************
 * macros and functions for N_assign
 *****************************************************************************/

#define ASSIGN_LET( n) ((n)->sons.N_assign->Let)
#define ASSIGN_EXPR( n) ((n)->sons.N_assign->Expr)
extern node *TBmakeAssign (node * Let, node * Expr);

/*****************************************************************************
 * macros and functions for N_binop
 *****************************************************************************/

#define BINOP_LEFT( n) ((n)->sons.N_binop->Left)
#define BINOP_RIGHT( n) ((n)->sons.N_binop->Right)
#define BINOP_OP( n) ((n)->attribs.N_binop->Op)
extern node *TBmakeBinop (binop Op, node * Left, node * Right);

/*****************************************************************************
 * macros and functions for N_monop
 *****************************************************************************/

#define MONOP_RIGHT( n) ((n)->sons.N_monop->Right)
#define MONOP_OP( n) ((n)->attribs.N_monop->Op)
extern node *TBmakeMonop (monop Op, node * Right);

/*****************************************************************************
 * macros and functions for N_varlet
 *****************************************************************************/

#define VARLET_NAME( n) ((n)->attribs.N_varlet->Name)
#define VARLET_DECL( n) ((n)->attribs.N_varlet->Decl)
extern node *TBmakeVarlet (char *Name);

/*****************************************************************************
 * macros and functions for N_var
 *****************************************************************************/

#define VAR_NAME( n) ((n)->attribs.N_var->Name)
#define VAR_DECL( n) ((n)->attribs.N_var->Decl)
extern node *TBmakeVar (char *Name);

/*****************************************************************************
 * macros and functions for N_num
 *****************************************************************************/

#define NUM_VALUE( n) ((n)->attribs.N_num->Value)
extern node *TBmakeNum (int Value);

/*****************************************************************************
 * macros and functions for N_float
 *****************************************************************************/

#define FLOAT_VALUE( n) ((n)->attribs.N_float->Value)
extern node *TBmakeFloat (float Value);

/*****************************************************************************
 * macros and functions for N_bool
 *****************************************************************************/

#define BOOL_VALUE( n) ((n)->attribs.N_bool->Value)
extern node *TBmakeBool (bool Value);

/*****************************************************************************
 * macros and functions for N_symboltableentry
 *****************************************************************************/

extern node *TBmakeSymboltableentry ();

/*****************************************************************************
 * macros and functions for N_error
 *****************************************************************************/

#define ERROR_NEXT( n) ((n)->sons.N_error->Next)
#define ERROR_MESSAGE( n) ((n)->attribs.N_error->message)
#define ERROR_ANYPHASE( n) ((n)->attribs.N_error->anyphase)
extern node *TBmakeError (char *message, compiler_phase_t anyphase,
			  node * Next);

#endif /* _SAC_NODE_BASIC_H_ */
