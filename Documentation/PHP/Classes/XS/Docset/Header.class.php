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

require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Function.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Type.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Macro.class.php';

class XS_Docset_Header
{
    protected $_file                = '';
    protected $_sourceRootPrefix    = '';
    protected $_xml                 = NULL;
    
    protected $_path                = NULL;
    protected $_name                = NULL;
    protected $_id                  = NULL;
    protected $_abstract            = NULL;
    protected $_includeFiles        = NULL;
    protected $_attributes          = NULL;
    protected $_functions           = NULL;
    protected $_types               = NULL;
    protected $_macros              = NULL;
    
    public function __construct( $file, $sourceRootPrefix = '' )
    {
        $this->_file                = ( string )$file;
        $this->_sourceRootPrefix    = ( string )$sourceRootPrefix;
        $this->_xml                 = simplexml_load_file( $file );
    }
    
    public function getPath()
    {
        if( $this->_path !== NULL )
        {
            return $this->_path;
        }
        
        $path = $this->_xml[ 'headerpath' ];
        $pos  = strpos( $path, $this->_sourceRootPrefix );
        
        if( $pos !== false )
        {
            $path = substr( $path, $pos + 1 );
        }
        
        $this->_path = $path;
        
        return $this->_path;
    }
    
    public function getName()
    {
        if( $this->_name !== NULL )
        {
            return $this->_name;
        }
        
        $info        = pathinfo( $this->_xml[ 'filename' ] ); 
        $this->_name = ( string )( $info[ 'filename' ] );
        
        return $this->_name;
    }
    
    public function getID()
    {
        if( $this->_id !== NULL )
        {
            return $this->_id;
        }
        
        $this->_id = ( string )( $this->_xml[ 'id' ] );
        
        return $this->_id;
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
    
    public function getIncludeFiles()
    {
        if( $this->_includeFiles !== NULL )
        {
            return $this->_includeFiles;
        }
        
        $this->_includeFiles = array();
        
        foreach( $this->_xml->includes->children() as $include )
        {
            $this->_includeFiles[ ( string )( $include->hd_link[ 'logicalPath' ] ) ] = htmlentities( $include->hd_link );
        }
        
        return $this->_includeFiles;
    }
    
    public function getAttributes()
    {
        if( $this->_attributes !== NULL )
        {
            return $this->_attributes;
        }
        
        $this->_attributes = array();
        
        foreach( $this->_xml->attributes->children() as $attribute )
        {
            $this->_attributes[ ( string )( $attribute->name ) ] = $attribute->value;
        }
        
        return $this->_attributes;
    }
    
    public function getFunctions()
    {
        if( $this->_functions !== NULL )
        {
            return $this->_functions;
        }
        
        $this->_functions = array();
        
        if( isset( $this->_xml->functions ) )
        {
            foreach( $this->_xml->functions->children() as $function )
            {
                $this->_functions[] = new XS_Docset_Function( $function );
            }
        }
        
        return $this->_functions;
    }
    
    public function getTypes()
    {
        if( $this->_types !== NULL )
        {
            return $this->_types;
        }
        
        $this->_types = array();
        
        if( isset( $this->_xml->typedefs ) )
        {
            foreach( $this->_xml->typedefs->children() as $typedef )
            {
                $this->_types[] = new XS_Docset_Type( $typedef );
            }
        }
        
        return $this->_types;
    }
    
    public function getMacros()
    {
        if( $this->_macros !== NULL )
        {
            return $this->_macros;
        }
        
        $this->_macros = array();
        
        if( isset( $this->_xml->defines ) )
        {
            foreach( $this->_xml->defines->children() as $macro )
            {
                $this->_macros[] = new XS_Docset_Macro( $macro );
            }
        }
        
        return $this->_macros;
    }
    
    public function hasPublicMembers()
    {
        if
        (
               count( $this->getFunctions() )
            || count( $this->getTypes() )
            || count( $this->getMacros() )
        )
        {
            return true;
        }
        
        return false;
    }
    
    public function __toString()
    {
        return $this->_file;
    }
}
