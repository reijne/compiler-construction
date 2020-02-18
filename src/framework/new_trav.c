
/**
 * @file eval.c
 *
 * Functions needed for compiling
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: free_node.c.xsl 14593 2006-01-31 17:09:55Z cg $.
 * DO NOT EDIT THIS FILE AS MIGHT BE CHANGED IN A LATER VERSION.
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

/**
 * @defgroup comp Compilation functions.
 *
 * Functions needed for compiling.
 *
 * @{
 */


#include "eval.h"
#include "traverse.h"
#include "dbug.h"


/** <!--******************************************************************-->
 *
 * @fn EVALassign
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Assign node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALassign (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALassign");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALbinop
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node BinOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALbinop (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALbinop");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALbool
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Bool node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALbool (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALbool");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALcomma
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Comma node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALcomma (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALcomma");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALdeclarations
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Declarations node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALdeclarations (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALdeclarations");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALerror
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Error node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALerror (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALerror");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALextern
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Extern node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALextern (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALextern");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALfloat
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Float node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALfloat (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALfloat");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALfunbodyblock
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunBodyBlock node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALfunbodyblock (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALfunbodyblock");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALfundec
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunDec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALfundec (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALfundec");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALfundef
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunDef node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALfundef (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALfundef");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALfunheader
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node FunHeader node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALfunheader (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALfunheader");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALglobaldec
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node GlobalDec node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALglobaldec (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALglobaldec");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALglobaldef
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node GlobalDef node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALglobaldef (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALglobaldef");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALid
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Id node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALid (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALid");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALl_bracket
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node L_bracket node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALl_bracket (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALl_bracket");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALl_curly_bracket
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node L_curly_bracket node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALl_curly_bracket (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALl_curly_bracket");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALmodule
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Module node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALmodule (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALmodule");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALmonop
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node MonOp node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALmonop (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALmonop");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALnum
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Num node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALnum (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALnum");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALparam
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Param node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALparam (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALparam");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALparams
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Params node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALparams (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALparams");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALprogram
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Program node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALprogram (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALprogram");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALr_bracket
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node R_bracket node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALr_bracket (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALr_bracket");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALr_curly_bracket
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node R_curly_bracket node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALr_curly_bracket (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALr_curly_bracket");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALsemicolon
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Semicolon node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALsemicolon (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALsemicolon");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALstmts
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Stmts node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALstmts (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALstmts");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALsymboltableentry
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node SymbolTableEntry node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALsymboltableentry (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALsymboltableentry");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALvar
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node Var node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALvar (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALvar");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/** <!--******************************************************************-->
 *
 * @fn EVALvarlet
 *
 * @brief Frees the node and its sons/attributes
 *
 * @param arg_node VarLet node to process
 * @param arg_info pointer to info structure
 *
 * @return processed node
 *
 ***************************************************************************/
node *
EVALvarlet (node * arg_node, info * arg_info)
{
  DBUG_ENTER ("EVALvarlet");
  arg_node = TRAVcont (arg_node, arg_info);
  DBUG_RETURN (arg_node);
}

/**
 * @}
 */