
/**
 * @file attribs.h
 *
 * Defines the AttribUnion and attrib structures.
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: attribs.h.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

#ifndef _SAC_ATTRIBS_H_
#define _SAC_ATTRIBS_H_

#include "types.h"


/******************************************************************************
 * For each node a structure of its attributes is defined, named 
 * ATTRIBS_<nodename>
 *****************************************************************************/
struct ATTRIBS_N_ASSIGN
{
};
struct ATTRIBS_N_BINOP
{
  binop Op;
};
struct ATTRIBS_N_BOOL
{
  bool Value;
};
struct ATTRIBS_N_ERROR
{
  char *message;
  compiler_phase_t anyphase;
};
struct ATTRIBS_N_FLOAT
{
  float Value;
};
struct ATTRIBS_N_MODULE
{
  int Count_all;
  int Count_add;
  int Count_sub;
  int Count_mul;
  int Count_div;
  int Count_mod;
};
struct ATTRIBS_N_NUM
{
  int Value;
};
struct ATTRIBS_N_STMTS
{
};
struct ATTRIBS_N_SYMBOLTABLEENTRY
{
};
struct ATTRIBS_N_VAR
{
  char *Name;
  node *Decl;
};
struct ATTRIBS_N_VARLET
{
  char *Name;
  node *Decl;
};
/*****************************************************************************
 * This union handles all different types of attributes. Its members are
 * called N_nodename.
 ****************************************************************************/
struct ATTRIBUNION
{
  struct ATTRIBS_N_ASSIGN *N_assign;
  struct ATTRIBS_N_BINOP *N_binop;
  struct ATTRIBS_N_BOOL *N_bool;
  struct ATTRIBS_N_ERROR *N_error;
  struct ATTRIBS_N_FLOAT *N_float;
  struct ATTRIBS_N_MODULE *N_module;
  struct ATTRIBS_N_NUM *N_num;
  struct ATTRIBS_N_STMTS *N_stmts;
  struct ATTRIBS_N_SYMBOLTABLEENTRY *N_symboltableentry;
  struct ATTRIBS_N_VAR *N_var;
  struct ATTRIBS_N_VARLET *N_varlet;
};
#endif /* _SAC_ATTRIBS_H_ */
