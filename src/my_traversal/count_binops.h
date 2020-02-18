#ifndef _COUNT_BINOPS_H_
#define _COUNT_BINOPS_H_

#include "types.h"

extern node *CBObinop (node *arg_node, info *arg_info);
extern node *CBOmodule (node *arg_node, info *arg_info);
extern node *CBOdoCountBinops ( node *syntaxtree);

#endif