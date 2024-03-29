<?xml version="1.0"?>

<!--
****************************************************************************
* 
* SAC Compiler Construction Framework
* 
****************************************************************************
* 
* SAC COPYRIGHT NOTICE, LICENSE, AND DISCLAIMER
* 
* (c) Copyright 1994 - 2011 by
* 
*   SAC Development Team
*   SAC Research Foundation
* 
*   http://www.sac-home.org
*   email:info@sac-home.org
* 
*   All rights reserved
* 
****************************************************************************
* 
* The SAC compiler construction framework, all accompanying 
* software and documentation (in the following named this software)
* is developed by the SAC Development Team (in the following named
* the developer) which reserves all rights on this software.
* 
* Permission to use this software is hereby granted free of charge
* exclusively for the duration and purpose of the course 
*   "Compilers and Operating Systems" 
* of the MSc programme Grid Computing at the University of Amsterdam.
* Redistribution of the software or any parts thereof as well as any
* alteration  of the software or any parts thereof other than those 
* required to use the compiler construction framework for the purpose
* of the above mentioned course are not permitted.
* 
* The developer disclaims all warranties with regard to this software,
* including all implied warranties of merchantability and fitness.  In no
* event shall the developer be liable for any special, indirect or
* consequential damages or any damages whatsoever resulting from loss of
* use, data, or profits, whether in an action of contract, negligence, or
* other tortuous action, arising out of or in connection with the use or
* performance of this software. The entire risk as to the quality and
* performance of this software is with you. Should this software prove
* defective, you assume the cost of all servicing, repair, or correction.
* 
****************************************************************************
 -->

<!--  $Id: check.h.xsl 15657 2007-11-13 13:57:30Z cg $  -->

<!-- This stylesheet generates a check.h file implementing all functions needed to check a node -->

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
version="1.0">

<xsl:output method="text" indent="no"/>
<xsl:strip-space elements="*"/>

 <xsl:variable name="newline">
<xsl:text>
</xsl:text>
 </xsl:variable>

<xsl:template match="/">

 <xsl:text>
/**
 * @file check.h
 *
 * Functions to check node structures
 * 
 * THIS FILE HAS BEEN GENERATED USING 
 * $Id: check.h.xsl 15657 2007-11-13 13:57:30Z cg $.
 * DO NOT EDIT THIS FILE. EDIT THE AST SPEC IN ast.xml INSTEAD!
 *
 * ALL CHANGES MADE TO THIS FILE WILL BE OVERWRITTEN!
 *
 */

#ifndef _SAC_CHECK_H_
#define _SAC_CHECK_H_

#include "types.h"

extern node *CHKdoTreeCheck  ( node *syntax_tree);

</xsl:text> 
<xsl:value-of select="$newline"/>

  <xsl:apply-templates select="//syntaxtree/node">
    <xsl:sort select="@name"/>
  </xsl:apply-templates>


  <xsl:apply-templates select="//nodesets/nodeset">
    <xsl:sort select="@name"/>
  </xsl:apply-templates>

<xsl:text>

#endif /* _SAC_CHECK_H_ */
</xsl:text>

</xsl:template>

<xsl:template match="node">

<xsl:value-of select="'extern node *CHK'"/>
  <xsl:value-of select="translate(@name, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ','abcdefghijklmnopqrstuvwxyz')"/>
  <xsl:value-of select="'( node *arg_node, info *arg_info)'"/>
  <xsl:value-of select="';'"/>
  <xsl:value-of select="$newline"/>
</xsl:template>

</xsl:stylesheet>