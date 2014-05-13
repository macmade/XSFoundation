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
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Function.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Type.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Macro.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Constant.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Class.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR . 'Docset.class.php';

class XS_Docset_Header extends XS_Docset_Member
{
    protected $_file                = '';
    protected $_sourceRootPrefix    = '';
    protected $_xml                 = NULL;
    protected $_docset              = NULL;
    
    protected $_path                = NULL;
    protected $_name                = NULL;
    protected $_id                  = NULL;
    protected $_copyright           = NULL;
    protected $_date                = NULL;
    protected $_abstract            = NULL;
    protected $_discussion          = NULL;
    protected $_includeFiles        = NULL;
    protected $_attributes          = NULL;
    protected $_functions           = NULL;
    protected $_types               = NULL;
    protected $_macros              = NULL;
    protected $_constants           = NULL;
    protected $_classes             = NULL;
    
    public function __construct( XS_Docset $docset, SplFileInfo $file, $sourceRootPrefix = '' )
    {
        $this->_docset              = $docset;
        $this->_file                = ( string )$file;
        $this->_sourceRootPrefix    = ( string )$sourceRootPrefix;
        $this->_xml                 = simplexml_load_file( $file );
    }
    
    public function hasClass()
    {
        return isset( $this->_xml->classes );
    }
    
    public function getPath()
    {
        if( $this->_path !== NULL )
        {
            return $this->_path;
        }
        
        $path = $this->_xml[ 'headerpath' ];
        
        if( $this->_sourceRootPrefix !== NULL && strlen( $this->_sourceRootPrefix ) > 0 )
        {
            $pos  = strpos( $path, $this->_sourceRootPrefix );
        
            if( $pos !== false )
            {
                $path = substr( $path, $pos + 1 );
            }
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
    
    public function getCopyright()
    {
        if( $this->_copyright !== NULL )
        {
            return $this->_copyright;
        }
        
        if( isset( $this->_xml->copyrightinfo ) )
        {
            $this->_copyright = ( string )( $this->_xml->copyrightinfo );
        }
                
        return $this->_copyright;
    }
    
    public function getDate()
    {
        if( $this->_date !== NULL )
        {
            return $this->_date;
        }
        
        if( isset( $this->_xml->timestamp ) )
        {
            $this->_date = ( string )( $this->_xml->timestamp );
        }
                
        return $this->_date;
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
        
        if( isset( $this->_xml->attributes ) )
        {
            foreach( $this->_xml->attributes->children() as $attribute )
            {
                $this->_attributes[ ( string )( $attribute->name ) ] = $attribute->value;
            }
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
    
    public function getConstants()
    {
        if( $this->_constants !== NULL )
        {
            return $this->_constants;
        }
        
        $this->_constants = array();
        
        if( isset( $this->_xml->constants ) )
        {
            foreach( $this->_xml->constants->children() as $constant )
            {
                $this->_constants[] = new XS_Docset_Constant( $constant );
            }
        }
        
        return $this->_constants;
    }
    
    public function getClasses()
    {
        if( $this->_classes !== NULL )
        {
            return $this->_classes;
        }
        
        $this->_classes = array();
        
        if( isset( $this->_xml->classes ) )
        {
            foreach( $this->_xml->classes->children() as $class )
            {
                $this->_classes[] = new XS_Docset_Class( $class );
            }
        }
        
        return $this->_classes;
    }
    
    public function hasPublicMembers()
    {
        if
        (
               count( $this->getClasses() )
            || count( $this->getFunctions() )
            || count( $this->getTypes() )
            || count( $this->getMacros() )
            || count( $this->getConstants() )
        )
        {
            return true;
        }
        
        return false;
    }
    
    public function getFunctionsListHTML()
    {
        $html   = array();
        $html[] = '<ul>';
    
        foreach( $this->getFunctions() as $function )
        {                        
            $html[] = '<li>';   
            $html[] = '<a href="#' . $function->getID() . '" title="' . $function->getName() . '">';
            $html[] = $function->getName();   
            $html[] = '</a>';
            $html[] = '</li>';
        }
    
        $html[] = '</ul>';
        
        return implode( chr( 10 ), $html );
    }
    
    public function getTypesListHTML()
    {
        $html   = array();
        $html[] = '<ul>';
    
        foreach( $this->getTypes() as $type )
        {                        
            $html[] = '<li>';   
            $html[] = '<a href="#' . $type->getID() . '" title="' . $type->getName() . '">';
            $html[] = $type->getName();   
            $html[] = '</a>';
            $html[] = '</li>';
        }
    
        $html[] = '</ul>';
        
        return implode( chr( 10 ), $html );
    }
    
    public function getMacrosListHTML()
    {
        $html   = array();
        $html[] = '<ul>';
    
        foreach( $this->getMacros() as $macro )
        {                        
            $html[] = '<li>';   
            $html[] = '<a href="#' . $macro->getID() . '" title="' . $macro->getName() . '">';
            $html[] = $macro->getName();   
            $html[] = '</a>';
            $html[] = '</li>';
        }
    
        $html[] = '</ul>';
        
        return implode( chr( 10 ), $html );
    }
    
    public function getConstantsListHTML()
    {
        $html   = array();
        $html[] = '<ul>';
    
        foreach( $this->getConstants() as $constant )
        {                        
            $html[] = '<li>';   
            $html[] = '<a href="#' . $constant->getID() . '" title="' . $constant->getName() . '">';
            $html[] = $constant->getName();   
            $html[] = '</a>';
            $html[] = '</li>';
        }
    
        $html[] = '</ul>';
        
        return implode( chr( 10 ), $html );
    }
    
    public function getClassesListHTML()
    {
        $html   = array();
        $html[] = '<ul>';
    
        foreach( $this->getClasses() as $class )
        {                        
            $html[] = '<li>';   
            $html[] = '<a href="#' . $class->getID() . '" title="' . $class->getName() . '">';
            $html[] = $class->getName();   
            $html[] = '</a>';
            $html[] = '</li>';
        }
    
        $html[] = '</ul>';
        
        return implode( chr( 10 ), $html );
    }
    
    protected function _getFileDetailsHTML()
    {
        $html = array();
        
        $html[] = '<div class="xsdoc-file-details">';
        $html[] = '<div class="xsdoc-file-detail">';
        $html[] = '<div class="xsdoc-file-detail-name">File</div>';
        $html[] = '<div class="xsdoc-file-detail-content">';
        $html[] = $this->getPath();
        $html[] = '</div>';
        $html[] = '</div>';
        
        if( count( $this->getAttributes() ) )
        {
            foreach( $this->getAttributes() as $key => $value )
            {
                $html[] = '<div class="xsdoc-file-detail">';
                $html[] = '<div class="xsdoc-file-detail-name">' . $key . '</div>';
                $html[] = '<div class="xsdoc-file-detail-content">' . $value . '</div>';
                $html[] = '</div>';
            }
        }
        
        if( strlen( $this->getCopyright() ) )
        {
            $html[] = '<div class="xsdoc-file-detail">';
            $html[] = '<div class="xsdoc-file-detail-name">Copyright</div>';
            $html[] = '<div class="xsdoc-file-detail-content">';
            $html[] = $this->getCopyright();
            $html[] = '</div>';
            $html[] = '</div>';
        }
        
        if( strlen( $this->getDate() ) )
        {
            $html[] = '<div class="xsdoc-file-detail">';
            $html[] = '<div class="xsdoc-file-detail-name">Date</div>';
            $html[] = '<div class="xsdoc-file-detail-content">';
            $html[] = $this->getDate();
            $html[] = '</div>';
            $html[] = '</div>';
        }
        
        $html[] = '<div class="xsdoc-file-detail">';
        $html[] = '<div class="xsdoc-file-detail-name">Includes</div>';
        $html[] = '<div class="xsdoc-file-detail-content">';
        
        if( count( $this->getIncludeFiles() ) )
        {
            $html[]  = '<ul>';
            $headers = $this->_docset->getHeaders();
            
            foreach( $this->getIncludeFiles() as $key => $value )
            {
                if( isset( $headers[ $key ] ) )
                {
                    $html[] = '<li>';
                    $html[] = '<a href="' . $this->_docset->getHeaderURL( $headers[ $key ] ) . '" title="' . $value . '">';
                    $html[] = $value;
                    $html[] = '</a>';
                    $html[] = '</li>';
                }
                else
                {
                    $html[] = '<li>' . $value . '</li>';
                }
            }
            
            $html[] = '</ul>';
        }
        else
        {
            $html[] = 'None';
        }
        
        $html[] = '</div>';
        $html[] = '</div>';
        $html[] = '</div>';
        
        return implode( chr( 10 ), $html );
    }
    
    public function __toString()
    {
        $html = array();
        
        $html[] = '<div class="xsdoc-file-content">';
        $html[] = '<h2>' . $this->getName() . ' Reference</h2>';
        $html[] = $this->_getFileDetailsHTML();
        $html[] = '<h3>Overview</h3>';
        $html[] = '<p><strong>' . $this->getAbstract() . '</strong></p>';
        
        if( strlen( $this->getDiscussion() ) )
        {
            $html[] = '<p>' . $this->getDiscussion() . '</p>';
        }
        
        if( count( $this->getClasses() ) )
        {
            foreach( $this->getClasses() as $class )
            {
                $html[] = ( string )$class;
            }
        }
        
        if( count( $this->getFunctions() ) )
        {
            $html[] = '<h3>Tasks</h3>';
            
            foreach( $this->getFunctions() as $function )
            {
                $html[] = ( string )$function;
            }
        }
        
        if( count( $this->getTypes() ) )
        {
            $html[] = '<h3>Types</h3>';
            
            foreach( $this->getTypes() as $type )
            {
                $html[] = ( string )$type;
            }
        }
        
        if( count( $this->getMacros() ) )
        {
            $html[] = '<h3>Macros</h3>';
            
            foreach( $this->getMacros() as $macro )
            {
                $html[] = ( string )$macro;
            }
        }
        
        if( count( $this->getConstants() ) )
        {
            $html[] = '<h3>Constants</h3>';
            
            foreach( $this->getConstants() as $constant )
            {
                $html[] = ( string )$constant;
            }
        }
        
        $html[] = '</div>';
        $html[] = '</div>';
        
        return implode( chr( 10 ), $html );
    }
}
