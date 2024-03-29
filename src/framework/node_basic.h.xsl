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


<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
version="1.0">

<xsl:import href="common-key-tables.xsl"/>
<xsl:import href="common-accessor-macros.xsl"/>
<xsl:import href="common-make-head.xsl"/>
<xsl:import href="common-travfun.xsl"/>
<xsl:import href="common-name-to-nodeenum.xsl"/>

<xsl:output method="text" indent="no"/>
<xsl:strip-space elements="*"/>

<!-- This stylesheet generates a node_basic.h file defining all the macros
     to the different attributes and the MakeXXX functions for nodes       -->

<xsl:template match="/">
  <xsl:call-template name="travfun-file">
    <xsl:with-param name="file">
      <xsl:value-of select="'node_basic.h'"/>
    </xsl:with-param>
    <xsl:with-param name="desc">
      <xsl:value-of select="'Functions to allocate node structures'"/>
    </xsl:with-param>
    <xsl:with-param name="xslt">
      <xsl:value-of select="'$Id: node_basic.h.xsl 14593 2006-01-31 17:09:55Z cg $'"/>
    </xsl:with-param>
  </xsl:call-template>
  <xsl:text>
#ifndef _SAC_NODE_BASIC_H_
#define _SAC_NODE_BASIC_H_

#include "types.h"

  </xsl:text>
  <xsl:apply-templates select="/definition/@version"/>
  <xsl:apply-templates select="//syntaxtree/node"/>
  <xsl:text>

    #endif /* _SAC_NODE_BASIC_H_ */
  </xsl:text>
</xsl:template>

<xsl:template match="@version">
  <xsl:call-template name="newline"/>
  <xsl:value-of select="'#define _SAC_AST_VERSION_ &quot;'"/>
  <xsl:value-of select="." />
  <xsl:value-of select="'&quot;'"/>
  <xsl:call-template name="newline"/>
</xsl:template>

<xsl:template match="node">
  <xsl:text>

/*****************************************************************************
 * macros and functions for </xsl:text>
  <xsl:call-template name="name-to-nodeenum" >
    <xsl:with-param name="name" >
      <xsl:value-of select="@name"/>
    </xsl:with-param>
  </xsl:call-template><xsl:text>
 *****************************************************************************/

  </xsl:text>
  <xsl:apply-templates select="sons/son" mode="accessor-macros"/>
  <xsl:apply-templates select="attributes/attribute" mode="accessor-macros"/>
  <xsl:apply-templates select="flags" mode="accessor-macros"/>
  <xsl:apply-templates select="." mode="make-head"/>
</xsl:template>

<xsl:template match="node" mode="make-head">
  <xsl:value-of select="'extern '"/>
  <xsl:apply-imports/>
  <xsl:value-of select="';'"/>
</xsl:template>

</xsl:stylesheet>
