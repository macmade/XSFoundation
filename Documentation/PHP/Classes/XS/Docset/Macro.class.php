<?php

/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2014 Jean-David Gadina - www-xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/* $Id$ */

class XS_Docset_Macro
{
    protected $_xml = NULL;
    
    protected $_name        = NULL;
    protected $_abstract    = NULL;
    protected $_discussion  = NULL;
    protected $_declaration = NULL;
    protected $_parameters  = NULL;
    
    public function __construct( SimpleXMLElement $xml )
    {
        $this->_xml = $xml;
    }
    
    public function getName()
    {
        if( $this->_name !== NULL )
        {
            return $this->_name;
        }
        
        $this->_name = ( string )( $this->_xml->name );
        
        return $this->_name;
    }
    
    public function getAbstract()
    {
        if( $this->_abstract !== NULL )
        {
            return $this->_abstract;
        }
        
        if( isset( $this->_xml->abstract->p ) )
        {
            $this->_abstract = ( string )( $this->_xml->abstract->p );
        }
        
        return $this->_abstract;
    }
    
    public function getDiscussion()
    {
        if( $this->_discussion !== NULL )
        {
            return $this->_discussion;
        }
        
        if( isset( $this->_xml->desc->p ) )
        {
            $this->_discussion = ( string )( $this->_xml->desc->p );
        }
        
        return $this->_discussion;
    }
    
    public function getDeclaration()
    {
        if( $this->_declaration !== NULL )
        {
            return $this->_declaration;
        }
        
        $this->_declaration = strip_tags( $this->_xml->declaration->asXML() );
        $this->_declaration = preg_replace( '!/\*.*?\*/!s', '', $this->_declaration );
        $this->_declaration = preg_replace( '/\n\s*\n/', chr( 10 ), $this->_declaration );
        
        return $this->_declaration;
    }
    
    public function getParameters()
    {
        if( $this->_parameters !== NULL )
        {
            return $this->_parameters;
        }
        
        $this->_parameters = array();
        
        if( isset( $this->_xml->parameterlist ) )
        {
            foreach( $this->_xml->parameterlist->children() as $param )
            {
                $this->_parameters[ ( string )( $param->name ) ] = ( string )( $param->desc->p );
            }
        }
        
        return $this->_parameters;
    }
}
