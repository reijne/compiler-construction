
/**
 * @file check.c
 *
 * Functions needed by check.
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: check.c.xsl 14618 2006-02-28 16:08:17Z                                jhb $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

/**
 * @defgroup check Check tree Functions
 *
 * Functions needed by check traversal.
 *
 * @{
 */


#include "check.h"
#include "globals.h"
#include "tree_basic.h"
#include "traverse.h"
#include "dbug.h"
#include "print.h"
#include "check_lib.h"
#include "free.h"
#include "str.h"
#include "memory.h"

/*****************************************************************************
 *
 * @fn node *CHKdoTreeCheck( node *syntax_tree)
 *
 ****************************************************************************/
node *
CHKdoTreeCheck (node * syntax_tree)
{
  DBUG_ENTER ("CHKdoTreeCheck");

  DBUG_PRINT ("CHK", ("Starting the check mechanism"));

  TRAVpush (TR_chk);
  syntax_tree = TRAVdo (syntax_tree, NULL);
  TRAVpop ();

  DBUG_PRINT ("CHK", ("Checkmechanism complete"));

  DBUG_RETURN (syntax_tree);
}

static bool
isExpr (node * arg_node)
{
  bool res = ((NODE_TYPE (arg_node) == N_binop) ||
	      (NODE_TYPE (arg_node) == N_bool) ||
	      (NODE_TYPE (arg_node) == N_float) ||
	      (NODE_TYPE (arg_node) == N_num) ||
	      (NODE_TYPE (arg_node) == N_var));
  return (res);
}

static bool
isStmt (node * arg_node)
{
  bool res = ((NODE_TYPE (arg_node) == N_assign));
  return (res);
}

void
isDummy ()
{
  isExpr (NULL);
  isStmt (NULL);
}

/** <!--******************************************************************-->
 *
 * @fn CHKassign
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node Assign node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKassign (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKassign");

/*
 * Son check: ASSIGN_EXPR 
 */
  if ((FALSE) || (TRUE))
    {
      CHKexistSon (ASSIGN_EXPR (arg_node), arg_node,
		   "mandatory son ASSIGN_EXPR is NULL");
      if (ASSIGN_EXPR (arg_node) != NULL)
	{
	  if (!((FALSE) || (isExpr (ASSIGN_EXPR (arg_node)))))
	    {
	      CHKcorrectTypeInsertError (arg_node,
					 "ASSIGN_EXPR hasnt the right type."
					 " It should be: " "Nodeset: Expr");
	    }
	}
    }
  else
    {
      CHKnotExist (ASSIGN_EXPR (arg_node), arg_node,
		   "attribute ASSIGN_EXPR must be NULL");
    }

/*
 * Son check: ASSIGN_LET 
 */
  if ((FALSE) || (TRUE))
    {
      if (ASSIGN_LET (arg_node) != NULL)
	{
	  if (!((FALSE) || (NODE_TYPE (ASSIGN_LET (arg_node)) == N_varlet)))
	    {
	      CHKcorrectTypeInsertError (arg_node,
					 "ASSIGN_LET hasnt the right type."
					 " It should be: " "N_varlet");
	    }
	}
    }
  else
    {
      CHKnotExist (ASSIGN_LET (arg_node), arg_node,
		   "attribute ASSIGN_LET must be NULL");
    }

/*
 * trav functions: to get all sons
 */
  if (ASSIGN_EXPR (arg_node) != NULL)
    {
      ASSIGN_EXPR (arg_node) = TRAVdo (ASSIGN_EXPR (arg_node), arg_info);
    }

/*
 * trav functions: to get all sons
 */
  if (ASSIGN_LET (arg_node) != NULL)
    {
      ASSIGN_LET (arg_node) = TRAVdo (ASSIGN_LET (arg_node), arg_info);
    }
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKbinop
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node BinOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKbinop (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKbinop");

/*
 * Son check: BINOP_LEFT 
 */
  if ((FALSE) || (TRUE))
    {
      CHKexistSon (BINOP_LEFT (arg_node), arg_node,
		   "mandatory son BINOP_LEFT is NULL");
      if (BINOP_LEFT (arg_node) != NULL)
	{
	  if (!((FALSE) || (isExpr (BINOP_LEFT (arg_node)))))
	    {
	      CHKcorrectTypeInsertError (arg_node,
					 "BINOP_LEFT hasnt the right type."
					 " It should be: " "Nodeset: Expr");
	    }
	}
    }
  else
    {
      CHKnotExist (BINOP_LEFT (arg_node), arg_node,
		   "attribute BINOP_LEFT must be NULL");
    }

/*
 * Son check: BINOP_RIGHT 
 */
  if ((FALSE) || (TRUE))
    {
      CHKexistSon (BINOP_RIGHT (arg_node), arg_node,
		   "mandatory son BINOP_RIGHT is NULL");
      if (BINOP_RIGHT (arg_node) != NULL)
	{
	  if (!((FALSE) || (isExpr (BINOP_RIGHT (arg_node)))))
	    {
	      CHKcorrectTypeInsertError (arg_node,
					 "BINOP_RIGHT hasnt the right type."
					 " It should be: " "Nodeset: Expr");
	    }
	}
    }
  else
    {
      CHKnotExist (BINOP_RIGHT (arg_node), arg_node,
		   "attribute BINOP_RIGHT must be NULL");
    }

/*
 * trav functions: to get all sons
 */
  if (BINOP_LEFT (arg_node) != NULL)
    {
      BINOP_LEFT (arg_node) = TRAVdo (BINOP_LEFT (arg_node), arg_info);
    }

/*
 * trav functions: to get all sons
 */
  if (BINOP_RIGHT (arg_node) != NULL)
    {
      BINOP_RIGHT (arg_node) = TRAVdo (BINOP_RIGHT (arg_node), arg_info);
    }
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKbool
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node Bool node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKbool (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKbool");
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKerror
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node Error node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKerror (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKerror");

/*
 * Son check: ERROR_NEXT 
 */
  if ((FALSE) || (TRUE))
    {
      if (ERROR_NEXT (arg_node) != NULL)
	{
	  if (!((FALSE) || (NODE_TYPE (ERROR_NEXT (arg_node)) == N_error)))
	    {
	      CHKcorrectTypeInsertError (arg_node,
					 "ERROR_NEXT hasnt the right type."
					 " It should be: " "N_error");
	    }
	}
    }
  else
    {
      CHKnotExist (ERROR_NEXT (arg_node), arg_node,
		   "attribute ERROR_NEXT must be NULL");
    }

/*
 * Attribute check: ERROR_MESSAGE
 */
  if ((FALSE) || (TRUE))
    {
      CHKexistAttribute (ERROR_MESSAGE (arg_node), arg_node,
			 "mandatory attribute ERROR_MESSAGE is NULL");
    }
  else
    {
      CHKnotExist (ERROR_MESSAGE (arg_node), arg_node,
		   "attribute ERROR_MESSAGE must be NULL");
    }

/*
 * trav functions: to get all sons
 */
  if (ERROR_NEXT (arg_node) != NULL)
    {
      ERROR_NEXT (arg_node) = TRAVdo (ERROR_NEXT (arg_node), arg_info);
    }
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKfloat
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node Float node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKfloat (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKfloat");
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKmodule
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node Module node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKmodule (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKmodule");

/*
 * Son check: MODULE_STMTS 
 */
  if ((FALSE) || (TRUE))
    {
      CHKexistSon (MODULE_STMTS (arg_node), arg_node,
		   "mandatory son MODULE_STMTS is NULL");
      if (MODULE_STMTS (arg_node) != NULL)
	{
	  if (!((FALSE) || (NODE_TYPE (MODULE_STMTS (arg_node)) == N_stmts)))
	    {
	      CHKcorrectTypeInsertError (arg_node,
					 "MODULE_STMTS hasnt the right type."
					 " It should be: " "N_stmts");
	    }
	}
    }
  else
    {
      CHKnotExist (MODULE_STMTS (arg_node), arg_node,
		   "attribute MODULE_STMTS must be NULL");
    }

/*
 * trav functions: to get all sons
 */
  if (MODULE_STMTS (arg_node) != NULL)
    {
      MODULE_STMTS (arg_node) = TRAVdo (MODULE_STMTS (arg_node), arg_info);
    }
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKnum
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node Num node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKnum (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKnum");
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKstmts
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node Stmts node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKstmts (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKstmts");

/*
 * Son check: STMTS_NEXT 
 */
  if ((FALSE) || (TRUE))
    {
      if (STMTS_NEXT (arg_node) != NULL)
	{
	  if (!((FALSE) || (NODE_TYPE (STMTS_NEXT (arg_node)) == N_stmts)))
	    {
	      CHKcorrectTypeInsertError (arg_node,
					 "STMTS_NEXT hasnt the right type."
					 " It should be: " "N_stmts");
	    }
	}
    }
  else
    {
      CHKnotExist (STMTS_NEXT (arg_node), arg_node,
		   "attribute STMTS_NEXT must be NULL");
    }

/*
 * Son check: STMTS_STMT 
 */
  if ((FALSE) || (TRUE))
    {
      CHKexistSon (STMTS_STMT (arg_node), arg_node,
		   "mandatory son STMTS_STMT is NULL");
      if (STMTS_STMT (arg_node) != NULL)
	{
	  if (!((FALSE) || (isStmt (STMTS_STMT (arg_node)))))
	    {
	      CHKcorrectTypeInsertError (arg_node,
					 "STMTS_STMT hasnt the right type."
					 " It should be: " "Nodeset: Stmt");
	    }
	}
    }
  else
    {
      CHKnotExist (STMTS_STMT (arg_node), arg_node,
		   "attribute STMTS_STMT must be NULL");
    }

/*
 * trav functions: to get all sons
 */
  if (STMTS_NEXT (arg_node) != NULL)
    {
      STMTS_NEXT (arg_node) = TRAVdo (STMTS_NEXT (arg_node), arg_info);
    }

/*
 * trav functions: to get all sons
 */
  if (STMTS_STMT (arg_node) != NULL)
    {
      STMTS_STMT (arg_node) = TRAVdo (STMTS_STMT (arg_node), arg_info);
    }
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKsymboltableentry
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node SymbolTableEntry node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKsymboltableentry (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKsymboltableentry");
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKvar
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node Var node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKvar (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKvar");

/*
 * Attribute check: VAR_DECL
 */
  if ((FALSE) || (TRUE))
    {
    }
  else
    {
      CHKnotExist (VAR_DECL (arg_node), arg_node,
		   "attribute VAR_DECL must be NULL");
    }

/*
 * Attribute check: VAR_NAME
 */
  if ((FALSE) || (TRUE))
    {
      CHKexistAttribute (VAR_NAME (arg_node), arg_node,
			 "mandatory attribute VAR_NAME is NULL");
    }
  else
    {
      CHKnotExist (VAR_NAME (arg_node), arg_node,
		   "attribute VAR_NAME must be NULL");
    }
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn CHKvarlet
 *
 * @brief Check the node and its sons/attributes
 *
 * @param arg_node VarLet node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
CHKvarlet (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("CHKvarlet");

/*
 * Attribute check: VARLET_DECL
 */
  if ((FALSE) || (TRUE))
    {
    }
  else
    {
      CHKnotExist (VARLET_DECL (arg_node), arg_node,
		   "attribute VARLET_DECL must be NULL");
    }

/*
 * Attribute check: VARLET_NAME
 */
  if ((FALSE) || (TRUE))
    {
      CHKexistAttribute (VARLET_NAME (arg_node), arg_node,
			 "mandatory attribute VARLET_NAME is NULL");
    }
  else
    {
      CHKnotExist (VARLET_NAME (arg_node), arg_node,
		   "attribute VARLET_NAME must be NULL");
    }
  DBUG_RETURN (arg_node);
}

typedef enum
{ CHK_binop_op,
  CHK_bool_value,
  CHK_error_message,
  CHK_float_value,
  CHK_module_count_all,
  CHK_num_value,
  CHK_var_name,
  CHK_varlet_name
} attr_list;