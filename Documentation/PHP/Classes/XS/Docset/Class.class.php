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

require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Member.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Method.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Property.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'InstanceVariable.class.php';

class XS_Docset_Class extends XS_Docset_Member
{
    protected $_methods             = NULL;
    protected $_properties          = NULL;
    protected $_instanceVariables   = NULL;
    
    public function __construct( SimpleXMLElement $xml )
    {
        parent::__construct( $xml );
    }
    
    public function getMethods()
    {
        if( $this->_methods !== NULL )
        {
            return $this->_methods;
        }
        
        $this->_methods = array();
        
        if( isset( $this->_xml->methods ) )
        {
            foreach( $this->_xml->methods->children() as $method )
            {
                $this->_methods[] = new XS_Docset_Method( $this, $method );
            }
        }
        
        return $this->_methods;
    }
    
    public function getProperties()
    {
        if( $this->_properties !== NULL )
        {
            return $this->_properties;
        }
        
        $this->_properties = array();
        
        if( isset( $this->_xml->properties ) )
        {
            foreach( $this->_xml->properties->children() as $method )
            {
                $this->_properties[] = new XS_Docset_Property( $this, $method );
            }
        }
        
        return $this->_properties;
    }
    
    public function getInstanceVariables()
    {
        if( $this->_instanceVariables !== NULL )
        {
            return $this->_instanceVariables;
        }
        
        $this->_instanceVariables = array();
        
        if( isset( $this->_xml->globals ) )
        {
            foreach( $this->_xml->globals->children() as $var )
            {
                $this->_instanceVariables[] = new XS_Docset_InstanceVariable( $this, $var );
            }
        }
        
        return $this->_instanceVariables;
    }
    
    public function __toString()
    {
        $html = array();
        
        $html[] = '<a name="' . $this->getID() . '"></a>';
        $html[] = '<a name="' . $this->getName() . '"></a>';
        $html[] = '<h3>Class ' . $this->getName() . '</h3>';
        $html[] = '<div class="xsdoc-class-members">';
        
        if( count( $this->getMethods() ) )
        {
            $html[] = '<h4>Tasks</h4>';
            $html[] = '<ul>';
            
            foreach( $this->getMethods() as $method )
            {
                $html[] = '<li>';
                $html[] = '<a href="#' . $method->getID() . '">';
                $html[] = $method->getName();
                $html[] = '</a>';
                $html[] = '</li>';
            }
            
            $html[] = '</ul>';
        }
        
        if( count( $this->getProperties() ) )
        {
            $html[] = '<h4>Properties</h4>';
            $html[] = '<ul>';
            
            foreach( $this->getProperties() as $property )
            {
                $html[] = '<li>';
                $html[] = '<a href="#' . $property->getID() . '">';
                $html[] = $property->getName();
                $html[] = '</a>';
                $html[] = '</li>';
            }
            
            $html[] = '</ul>';
        }
        
        if( count( $this->getInstanceVariables() ) )
        {
            $html[] = '<h4>Instance variables</h4>';
            $html[] = '<ul>';
            
            foreach( $this->getInstanceVariables() as $var )
            {
                $html[] = '<li>';
                $html[] = '<a href="#' . $var->getID() . '">';
                $html[] = $var->getName();
                $html[] = '</a>';
                $html[] = '</li>';
            }
            
            $html[] = '</ul>';
        }
        
        $html[] = '</div>';
        
        foreach( $this->getMethods() as $method )
        {
            $html[] = ( string )$method;
        }
                    
        foreach( $this->getProperties() as $property )
        {
            $html[] = ( string )$property;
        }
                    
        foreach( $this->getInstanceVariables() as $var )
        {
            $html[] = ( string )$var;
        }
        
        return implode( chr( 10 ), $html );
    }
}
