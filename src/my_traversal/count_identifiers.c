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

struct INFO {
  lut_t *lookup;
  int total;
};

struct COUNT {
  char *name;
  int counter;
};

#define INFO_LOOKUP(n)  ((n)->lookup)
#define INFO_TOTAL(n)  ((n)->total)
#define COUNT_NAME(n)  ((n)->name)
#define COUNT_COUNTER(n)  ((n)->counter)

/* Malloc and init the info struct. */
static info *MakeInfo(void)
{
  info *result;

  DBUG_ENTER( "MakeInfo");

  result = (info *)MEMmalloc(sizeof(info));
  INFO_LOOKUP(result) = LUTgenerateLut();
  INFO_TOTAL(result) = 0;

  DBUG_RETURN( result);
}

/* Malloc and init a count struct. */
static count *MakeCount(char *name, int counter)
{
  count *result;

  DBUG_ENTER( "MakeCount");

  result = (count *)MEMmalloc(sizeof(count *));
  COUNT_NAME(result) = name;
  COUNT_COUNTER(result) = counter;

  DBUG_RETURN( result);
}

/* Free the count struct. */
static info *FreeInfo( info *info)
{
  DBUG_ENTER ("FreeInfo");
  info = MEMfree( info);
  DBUG_RETURN( info);
}

/* Free the count struct. */
static count *FreeCount( count *c)
{
  count *counter = (count *)c;
  DBUG_ENTER ("FreeCount");
  counter = MEMfree(counter);
  DBUG_RETURN(counter);
}

/* Print the found count for the indentifier, then free it. */
static void *finish_count(void* c) {
  DBUG_ENTER("FinishCount");
  count *counter = (count *) c;
  CTInote("%s : %d", COUNT_NAME(counter), COUNT_COUNTER(counter));
  c = FreeCount(c);
  DBUG_RETURN(counter);
}

/* Update the counter in the lut. */
static void update_counter(info *arg_info, char* name) {
  DBUG_PRINT("CI", ("updatecounter"));
  lut_t *lookup = INFO_LOOKUP(arg_info);
  void **counter = LUTsearchInLutS(lookup, name);
  INFO_TOTAL(arg_info)++;
  count *c;
  if (!counter) {
    c = MakeCount(name, 1);
    DBUG_PRINT("CI", ("counter none: %d", COUNT_COUNTER(c)));
  }
  else {
    c = (count *) (*counter);
    COUNT_COUNTER(c)++;
    DBUG_PRINT("CI", ("counter set: %d", COUNT_COUNTER(c)));
  }
  LUTupdateLutS(lookup, name, c, NULL);
}

/* Varlet node, contains identifier, insert or update said identifier in lut. */
node *CIvarlet( node *arg_node, info *arg_info)
{
  DBUG_ENTER("CIvarlet");
  DBUG_PRINT( "CI", ("Counting varlet: %s", VARLET_NAME(arg_node)));

  char *name = VARLET_NAME(arg_node);
  update_counter(arg_info, name);
  DBUG_PRINT("CI", ("VARLETDONE"));

  DBUG_RETURN( arg_node);
}

/* Var node, contains an identifier, insert or update said identifier in lut. */
node *CIvar( node *arg_node, info *arg_info)
{

  DBUG_ENTER("CIvar");
  DBUG_PRINT( "CI", ("Counting var: %s", VAR_NAME( arg_node)));

  char *name = VAR_NAME(arg_node);
  update_counter(arg_info, name);
  DBUG_PRINT("CI", ("VARDONE"));

  DBUG_RETURN( arg_node);
}

/* Root node, start traversal then print the found values and free the structs at the end. */
extern node *CImodule (node *arg_node, info *arg_info) {
  DBUG_ENTER("CImodule");
  
  DBUG_PRINT("CI", ("start traverse"));
  MODULE_STMTS(arg_node) = TRAVdo(MODULE_STMTS(arg_node), arg_info);
  DBUG_PRINT("CI", ("end traverse"));

  CTInote("\n\nTotal indentifier counter: %d", INFO_TOTAL(arg_info));
  LUTmapLutS(INFO_LOOKUP(arg_info), *finish_count);

  DBUG_PRINT("CI", ("end of module"));
  DBUG_RETURN(arg_node);
}

/* Traversal start function. */
node *CIdoCountIdentifiers( node *syntaxtree)
{
  DBUG_ENTER("CIdoCountIdentifiers");

  TRAVpush( TR_ci);   // Push traversal "CI" as defined in ast.xml

  info *arg_info = MakeInfo();
  syntaxtree = TRAVdo( syntaxtree, arg_info);   // Initiate ast traversal
  TRAVpop();          // Pop current traversal
  FreeInfo(arg_info);

  DBUG_RETURN( syntaxtree);
}

