/*****************************************************************************
 *
 * Module: count_identifiers
 *
 * Prefix: CI
 *
 * Description:
 *
 * This module implements a traversal, which count the instances of identifiers.
 *
 *****************************************************************************/


#include "count_identifiers.h"
#include "lookup_table.h"

#include "types.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"

#include "str.h"
#include "memory.h"
#include "ctinfo.h"


/*
 * INFO structure
 */

struct INFO {
  lut_t *lookup;
};


/*
 * INFO macros
 */
#define INFO_LOOKUP(n)  ((n)->lookup)


/*
 * INFO functions
 */

static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));
  INFO_LOOKUP(result) = LUTgenerateLut();


  DBUG_RETURN( result);
}

static info *FreeInfo( info *info)
{
  DBUG_ENTER ("FreeInfo");

  info = MEMfree( info);

  DBUG_RETURN( info);
}


/*
 * Traversal functions
 */

node *CIvarlet( node *arg_node, info *arg_info)
{
  char *name;

  DBUG_ENTER("CIvarlet");

  DBUG_PRINT( "CI", ("Renaming variable: %s", VARLET_NAME( arg_node)));

  name = VARLET_NAME( arg_node);
  VARLET_NAME( arg_node) = STRcat( "__", name);
  MEMfree(name);

  DBUG_RETURN( arg_node);
}

node *CIvar( node *arg_node, info *arg_info)
{
  char *name;

  DBUG_ENTER("CIvar");

  DBUG_PRINT( "CI", ("Renaming variable: %s", VAR_NAME( arg_node)));

  name = VAR_NAME( arg_node);
  VAR_NAME( arg_node) = STRcat( "__", name);
  MEMfree(name);

  DBUG_RETURN( arg_node);
}


/*
 * Traversal start function
 */

node *CIdoCountIdentifiers( node *syntaxtree)
{
  DBUG_ENTER("RIdoCountIdentifiers");

  info *arg_info;
  TRAVpush( TR_ci);   // Push traversal "CI" as defined in ast.xml

  arg_info = MakeInfo();
  syntaxtree = TRAVdo( syntaxtree, NULL);   // Initiate ast traversal

  TRAVpop();          // Pop current traversal
  FreeInfo(arg_info);

  DBUG_RETURN( syntaxtree);
}

