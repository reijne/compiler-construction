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





<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
  
  <xsl:import href="common-key-tables.xsl"/>
  <xsl:import href="common-travfun.xsl"/>
  <xsl:import href="common-name-to-nodeenum.xsl"/>

  <xsl:output method="text" indent="no"/>
  <xsl:strip-space elements="*"/>

  <!-- starting template -->
  <xsl:template match="/">
    <xsl:call-template name="travfun-file">
      <xsl:with-param name="file">
        <xsl:value-of select="'sons.h'"/>
      </xsl:with-param>
      <xsl:with-param name="desc">
        <xsl:value-of select="'Defines the NodesUnion and node structures.'"/>
      </xsl:with-param>
      <xsl:with-param name="xslt">
        <xsl:value-of select="'$Id: sons.h.xsl 14593 2006-01-31 17:09:55Z cg $'"/>
      </xsl:with-param>
    </xsl:call-template>
    <xsl:text>
#ifndef _SAC_SONS_H_
#define _SAC_SONS_H_

#include "types.h"

    </xsl:text>
    <xsl:apply-templates select="/definition/syntaxtree" mode="generate-sons-structs"/>
    <xsl:apply-templates select="/definition/syntaxtree" mode="generate-sons-union"/>
    <xsl:text>
#endif /* _SAC_SONS_H_ */
    </xsl:text>
  </xsl:template>

  <xsl:template match="syntaxtree" mode="generate-sons-structs">
     <xsl:text>
/******************************************************************************
 * For each node a structure of its sons is defined, named 
 * SONS_&lt;nodename&gt;
 *****************************************************************************/
     </xsl:text>
     <xsl:apply-templates select="node" mode="generate-sons-structs">
       <xsl:sort select="@name"/>
     </xsl:apply-templates>
  </xsl:template>

  <xsl:template match="node" mode="generate-sons-structs">
    <xsl:value-of select="'struct SONS_N_'"/>
    <xsl:call-template name="uppercase" >
      <xsl:with-param name="string">
        <xsl:value-of select="@name" />
      </xsl:with-param>
    </xsl:call-template>
    <xsl:value-of select="' { '"/>
    <xsl:apply-templates select="sons/son" mode="generate-sons-structs"/>
    <xsl:value-of select="' } ;'"/>
  </xsl:template>

  <xsl:template match="son" mode="generate-sons-structs">
    <xsl:value-of select="'node * '"/>
    <xsl:value-of select="@name"/>
    <xsl:value-of select="'; '"/>
  </xsl:template>

  <xsl:template match="syntaxtree" mode="generate-sons-union">
    <xsl:text>
/*****************************************************************************
 * This union handles all different types of sons. Its members are
 * called N_nodename.
 ****************************************************************************/
    </xsl:text>
    <xsl:value-of select="'struct SONUNION { '"/>
    <xsl:text>
    </xsl:text>
    <xsl:apply-templates select="node" mode="generate-sons-union">
      <xsl:sort select="@name"/>
    </xsl:apply-templates>
    <xsl:value-of select="'} ; '"/>
  </xsl:template>
 
  <!-- generate an entry for each node within the union -->
  <xsl:template match="node" mode="generate-sons-union">
    <xsl:value-of select="'struct SONS_N_'"/>
    <xsl:call-template name="uppercase" >
      <xsl:with-param name="string">
        <xsl:value-of select="@name" />
      </xsl:with-param>
    </xsl:call-template>
    <xsl:value-of select="' *'" />
    <xsl:call-template name="name-to-nodeenum">
      <xsl:with-param name="name">
        <xsl:value-of select="@name" />
      </xsl:with-param>
    </xsl:call-template>
    <xsl:value-of select="'; '"/>
  </xsl:template>
</xsl:stylesheet>
