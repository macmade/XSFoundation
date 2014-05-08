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

abstract class XS_Docset_Base
{
    protected $_xml         = NULL;
    protected $_name        = NULL;
    protected $_abstract    = NULL;
    protected $_declaration = NULL;
    protected $_discussion  = NULL;
    protected $_returnValue = NULL;
    protected $_parameters  = NULL;
    protected $_fields      = NULL;
    protected $_constants   = NULL;
    protected $_seeAlso     = NULL;
    
    public abstract function __toString();
    
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
        
        $this->_abstract = ( string )( $this->_xml->abstract->p );
        
        return $this->_abstract;
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
    
    public function getDiscussion()
    {
        if( $this->_discussion !== NULL )
        {
            return $this->_discussion;
        }
        
        $this->_discussion = $this->_xml->desc->p;
        
        return $this->_discussion;
    }
    
    public function getReturnValue()
    {
        if( $this->_returnValue !== NULL )
        {
            return $this->_returnValue;
        }
        
        $this->_returnValue = $this->_xml->result->p;
        
        return $this->_returnValue;
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
    
    public function getSeeAlso()
    {
        $see = NULL;
        
        if( $this->_seeAlso !== NULL )
        {
            return $this->_seeAlso;
        }
        
        if( isset( $this->_xml->attributelists ) )
        {
            foreach( $this->_xml->attributelists->children() as $attr )
            {
                if( isset( $attr->name ) && $attr->name == 'See' && isset( $attr->list ) )
                {
                    $see = $attr->list;
                    
                    break;
                }
            }
        }
        
        $this->_seeAlso = array();
        
        if( $see != NULL )
        {
            foreach( $see->children() as $item )
            {
                $this->_seeAlso[ ( string )( $item->value->hd_link[ 'logicalPath' ] ) ] = ( string )( $item->name );
            }
        }
        
        return $this->_seeAlso;
    }
    
    public function getFields()
    {
        if( $this->_fields !== NULL )
        {
            return $this->_fields;
        }
        
        $this->_fields = array();
        
        if( isset( $this->_xml->fieldlist ) )
        {
            foreach( $this->_xml->fieldlist->children() as $field )
            {
                $this->_fields[ ( string )( $field->name ) ] = ( string )( $field->desc->p );
            }
        }
        
        return $this->_fields;
    }
    
    public function getConstants()
    {
        if( $this->_constants !== NULL )
        {
            return $this->_constants;
        }
        
        $this->_constants = array();
        
        if( isset( $this->_xml->constantlist ) )
        {
            foreach( $this->_xml->constantlist->children() as $constant )
            {
                $this->_constants[ ( string )( $constant->name ) ] = ( string )( $constant->desc->p );
            }
        }
        
        return $this->_constants;
    }
}
