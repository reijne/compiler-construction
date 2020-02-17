/*****************************************************************************
 *
 * Module: count_binops
 *
 * Prefix: CBO
 *
 * Description:
 *
 * This module implements a demo traversal of the abstract syntax tree that 
 * sums up all integer constants and prints the result at the end of the traversal.
 *
 *****************************************************************************/


#include "count_binops.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"

#include "memory.h"
#include "ctinfo.h"

struct INFO {
  int count;
  int count_add;
  int count_sub;
  int count_mul;
  int count_div;
  int count_mod;
};

#define INFO_COUNT(n)  ((n)->count)
#define INFO_COUNT_ADD(n)  ((n)->count_add)
#define INFO_COUNT_SUB(n)  ((n)->count_sub)
#define INFO_COUNT_MUL(n)  ((n)->count_mul)
#define INFO_COUNT_DIV(n)  ((n)->count_div)
#define INFO_COUNT_MOD(n)  ((n)->count_mod)


/* Malloc and init the info struct */
static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));

  INFO_COUNT( result) = 0;
  INFO_COUNT_ADD( result) = 0;
  INFO_COUNT_SUB( result) = 0;
  INFO_COUNT_MUL( result) = 0;
  INFO_COUNT_DIV( result) = 0;
  INFO_COUNT_MOD( result) = 0;

  DBUG_RETURN( result);
}

/* Free the info struct. */
static info *FreeInfo( info *info)
{
  DBUG_ENTER ("FreeInfo");

  info = MEMfree( info);

  DBUG_RETURN( info);
}

/* Binop node, contains a binary operator that need to be counted. */
node *CBObinop (node *arg_node, info *arg_info)
{
  DBUG_ENTER("CBObinop");

  switch (BINOP_OP( arg_node)) {
    case BO_add:
      INFO_COUNT_ADD(arg_info) += 1;
      break;
    case BO_sub:
      INFO_COUNT_SUB(arg_info) += 1;
      break;
    case BO_mul:
      INFO_COUNT_MUL(arg_info) += 1;
      break;
    case BO_div:
      INFO_COUNT_DIV(arg_info) += 1;
      break;
    case BO_mod:
      INFO_COUNT_MOD(arg_info) += 1;
      break;
    default:
      break;
  }

  INFO_COUNT(arg_info) += 1;

  BINOP_LEFT( arg_node) = TRAVdo( BINOP_LEFT( arg_node), arg_info);
  BINOP_RIGHT( arg_node) = TRAVdo( BINOP_RIGHT( arg_node), arg_info);

  DBUG_RETURN(arg_node);
}

/* Root node, starts traversal and stores the found information at the end. */
node *CBOmodule (node *arg_node, info *arg_info)
{
  DBUG_ENTER("CBObinop");

  DBUG_PRINT("MOD", ("Number of binops: %d", INFO_COUNT( arg_info)));

  MODULE_STMTS(arg_node) = TRAVdo( MODULE_STMTS( arg_node), arg_info);
  MODULE_COUNT_ALL(arg_node) = INFO_COUNT( arg_info);

  MODULE_COUNT_ADD(arg_node) = INFO_COUNT_ADD(arg_info);
  MODULE_COUNT_SUB(arg_node) = INFO_COUNT_SUB(arg_info);
  MODULE_COUNT_MUL(arg_node) = INFO_COUNT_MUL(arg_info);
  MODULE_COUNT_DIV(arg_node) = INFO_COUNT_DIV(arg_info);
  MODULE_COUNT_MOD(arg_node) = INFO_COUNT_MOD(arg_info);

  DBUG_RETURN( arg_node);
}

/* Traversal start function. */
node *CBOdoCountBinops( node *syntaxtree)
{
  info *arg_info;

  DBUG_ENTER("CBOdoCountBinops");

  arg_info = MakeInfo();

  TRAVpush(TR_cbo);
  syntaxtree = TRAVdo( syntaxtree, arg_info);
  TRAVpop();
  // CTInote( "Number of binary operators: %d", INFO_COUNT( arg_info));

  arg_info = FreeInfo( arg_info);

  DBUG_RETURN( syntaxtree);
}
