
/**
 * @file traverse_helper.c
 *
 * Defines the helper function needed by the traversal system
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: traverse_helper.c.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */


#include "traverse_helper.h"
#include "dbug.h"
#include "tree_basic.h"
#include "traverse.h"

#define TRAV( son, info)    if (son != NULL) { son = TRAVdo( son, info); }

node *
TRAVnone (node * arg_node, info * arg_info)
{
  return (arg_node);
}

node *
TRAVerror (node * arg_node, info * arg_info)
{
  DBUG_ASSERT ((FALSE), "Illegal node type found.");

  return (arg_node);
}

node *
TRAVsons (node * arg_node, info * arg_info)
{
  switch (NODE_TYPE (arg_node))
    {
    case N_module:
      TRAV (MODULE_STMTS (arg_node), arg_info);
      break;
    case N_stmts:
      TRAV (STMTS_STMT (arg_node), arg_info);
      TRAV (STMTS_NEXT (arg_node), arg_info);
      break;
    case N_assign:
      TRAV (ASSIGN_LET (arg_node), arg_info);
      TRAV (ASSIGN_EXPR (arg_node), arg_info);
      break;
    case N_binop:
      TRAV (BINOP_LEFT (arg_node), arg_info);
      TRAV (BINOP_RIGHT (arg_node), arg_info);
      break;
    case N_varlet:
      break;
    case N_var:
      break;
    case N_num:
      break;
    case N_float:
      break;
    case N_bool:
      break;
    case N_symboltableentry:
      break;
    case N_error:
      TRAV (ERROR_NEXT (arg_node), arg_info);
      break;
    default:
      DBUG_ASSERT ((FALSE), "Illegal nodetype found!");
      break;
    }

  return (arg_node);
}

int
TRAVnumSons (node * node)
{
  int result = 0;

  DBUG_ENTER ("TRAVnumSons");

  switch (NODE_TYPE (node))
    {
    case N_module:
      result = 1;
      break;
    case N_stmts:
      result = 2;
      break;
    case N_assign:
      result = 2;
      break;
    case N_binop:
      result = 2;
      break;
    case N_varlet:
      result = 0;
      break;
    case N_var:
      result = 0;
      break;
    case N_num:
      result = 0;
      break;
    case N_float:
      result = 0;
      break;
    case N_bool:
      result = 0;
      break;
    case N_symboltableentry:
      result = 0;
      break;
    case N_error:
      result = 1;
      break;
    default:
      DBUG_ASSERT ((FALSE), "Illegal nodetype found!");
      break;
    }

  DBUG_RETURN (result);
}

node *
TRAVgetSon (int no, node * parent)
{
  node *result = NULL;

  DBUG_ENTER ("TRAVgetSon");

  switch (NODE_TYPE (parent))
    {
    case N_module:
      switch (no)
	{
	case 0:
	  result = MODULE_STMTS (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_stmts:
      switch (no)
	{
	case 0:
	  result = STMTS_STMT (parent);
	  break;
	case 1:
	  result = STMTS_NEXT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_assign:
      switch (no)
	{
	case 0:
	  result = ASSIGN_LET (parent);
	  break;
	case 1:
	  result = ASSIGN_EXPR (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_binop:
      switch (no)
	{
	case 0:
	  result = BINOP_LEFT (parent);
	  break;
	case 1:
	  result = BINOP_RIGHT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_varlet:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_var:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_num:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_float:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_bool:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_symboltableentry:
      switch (no)
	{
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    case N_error:
      switch (no)
	{
	case 0:
	  result = ERROR_NEXT (parent);
	  break;
	default:
	  DBUG_ASSERT ((FALSE), "index out of range!");
	  break;
	}
      break;
    default:
      DBUG_ASSERT ((FALSE), "Illegal nodetype found!");
      break;
    }

  DBUG_RETURN (result);
}
