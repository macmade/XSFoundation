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

require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Docset' . DIRECTORY_SEPARATOR . 'Header.class.php';

class XS_Docset
{
    protected $_projectName         = '';
    protected $_projectVersion      = '';
    protected $_copyright           = '';
    protected $_timezone            = '';
    protected $_xmlDir              = '';
    protected $_sourceRootPrefix    = '';
    protected $_classesPrefix       = '';
    protected $_functionsPrefix     = '';
    protected $_typesPrefix         = '';
    protected $_homeFile            = '';
    protected $_parsed              = false;
    protected $_currentFile         = NULL;
    
    protected $_classes             = array();
    protected $_functions           = array();
    protected $_types               = array();
    protected $_headers             = array();
    
    public function __construct( $xmlDir )
    {
        $this->_xmlDir = ( string )$xmlDir;
    }
    
    public function setProjectName( $value )
    {
        $this->_projectName = ( string )$value;
    }
    
    public function setProjectVersion( $value )
    {
        $this->_projectVersion = ( string )$value;
    }
    
    public function setCopyright( $value )
    {
        $this->_copyright = ( string )$value;
    }
    
    public function setTimezone( $value )
    {
        $this->_timezone = ( string )$value;
    }
    
    public function setSourceRootPrefix( $value )
    {
        $this->_sourceRootPrefix = ( string )$value;
    }
    
    public function setClassesPrefix( $value )
    {
        $this->_classesPrefix = ( string )$value;
    }
    
    public function setFunctionsPrefix( $value )
    {
        $this->_functionsPrefix = ( string )$value;
    }
    
    public function setTypesPrefix( $value )
    {
        $this->_typesPrefix = ( string )$value;
    }
    
    public function setHomeFile( $value )
    {
        $this->_homeFile = ( string )$value;
    }
    
    public function getTitle()
    {
        $title = '';
        
        $this->_parse();
        
        if( $this->_currentFile !== NULL )
        {
            $title = $this->_currentFile->getName() . ' - ';
        }
        
        $title .= $this->_projectName . ' API Reference';
        
        return $title;
    }
    
    protected function _parse()
    {
        try
        {
            if( $this->_parsed === true )
            {
                return;
            }
            
            $this->_parsed      = true;
            $this->_classes     = array();
            $this->_functions   = array();
            $this->_types       = array();
            $this->_others      = array();
            $this->_headers     = array();
            
            $dir        = new RecursiveDirectoryIterator( $this->_xmlDir );
            $iterator   = new RecursiveIteratorIterator( $dir, RecursiveIteratorIterator::SELF_FIRST );
            
            foreach( $iterator as $info )
            {
                if( $info->isDir() || $info->getExtension() !== 'xml' )
                {
                    continue;
                }
                
                try
                {
                    $header = new XS_Docset_Header( $info, $this->_sourceRootPrefix );
                    $path   = $header->getPath();
                    
                    if( strpos( $path, $this->_classesPrefix ) === 0 )
                    {
                        $this->_classes[ $header->getName() ] = $header;
                    }
                    else if( strpos( $path, $this->_functionsPrefix ) === 0 )
                    {
                        $this->_functions[ $header->getName() ] = $header;
                    }
                    else if( strpos( $path, $this->_typesPrefix ) === 0 )
                    {
                        $this->_types[ $header->getName() ] = $header;
                    }
                    else
                    {
                        $this->_others[ $header->getName() ] = $header;

                    }
                    
                    ksort( $this->_classes );
                    ksort( $this->_functions );
                    ksort( $this->_types );
                    ksort( $this->_others );
                    
                    $this->_headers[ $header->getID() ] = $header;
                }
                catch( Exception $e )
                {}
            }
            
            if( isset( $_GET[ 'xsdoc-file' ] ) )
            {
                $key = urldecode( $_GET[ 'xsdoc-file' ] );
            
                if( isset( $this->_headers[ $key ] ) )
                {
                    $this->_currentFile = $this->_headers[ $key ];
                }
            }
        }
        catch( Exception $e )
        {}
    }
    
    protected function _headerList( $headers )
    {
        $html = array();
        
        foreach( $headers as $header )
        {
            $html[] = '<li>';
            $html[] = '<a href="?xsdoc-file=' . urlencode( $header->getID() ) . '" title="' . $header->getName() . '">';
            $html[] = $header->getName();
            $html[] = '</a>';
            $html[] = '</li>';
        }
        
        return implode( chr( 10 ), $html );
    }
    
    public function __toString()
    {
        $html = array();
        
        $this->_parse();
        
        if( strlen( $this->_timezone ) )
        {
            date_default_timezone_set( $this->_timezone );
        }
        else
        {
            date_default_timezone_set( 'UTC' );
        }
        
        /* Header */
        $html[] = '<div class="xsdoc-project">';
        $html[] = '<div class="xsdoc-header">';
        $html[] = '<h1>';
        $html[] = '<a href="' . strtok( $_SERVER[ 'REQUEST_URI' ], '?' ) . '">';
        $html[] = $this->_projectName . ': API Reference';
        $html[] = '</a>';
        $html[] = '</h1>';
        $html[] = '</div>';
        
        /* Sub-header */
        $html[] = '<div class="xsdoc-subheader">';
        $html[] = 'Version ' . $this->_projectVersion;
        $html[] = '</div>';
        
        /* Main */
        $html[] = '<div class="xsdoc-main">';
        
        /* Table of contents */
        $html[] = '<div class="xsdoc-toc">';
        
        /* Classes */
        if( count( $this->_classes ) )
        {
            $html[] = '<div class="xsdoc-toc-classes">';
            $html[] = '<h2>Classes</h2>';
            $html[] = '<ul>';
            $html[] = $this->_headerList( $this->_classes );
            $html[] = '</ul>';
            $html[] = '</div>';
        }
        
        /* Functions */
        if( count( $this->_functions ) )
        {
            $html[] = '<div class="xsdoc-toc-classes">';
            $html[] = '<h2>Functions</h2>';
            $html[] = '<ul>';
            $html[] = $this->_headerList( $this->_functions );
            $html[] = '</ul>';
            $html[] = '</div>';
        }
        
        /* Types */
        if( count( $this->_types ) )
        {
            $html[] = '<div class="xsdoc-toc-classes">';
            $html[] = '<h2>Types</h2>';
            $html[] = '<ul>';
            $html[] = $this->_headerList( $this->_types );
            $html[] = '</ul>';
            $html[] = '</div>';
        }
        
        /* Other */
        if( count( $this->_headers ) )
        {
            $html[] = '<div class="xsdoc-toc-classes">';
            $html[] = '<h2>Other headers</h2>';
            $html[] = '<ul>';
            $html[] = $this->_headerList( $this->_others );
            $html[] = '</ul>';
            $html[] = '</div>';
        }
        
        $html[] = '</div>';
        
        /* File content */
        if( $this->_currentFile !== NULL )
        {
            $header = $this->_currentFile;
            $html[] = '<div class="xsdoc-file">';
            
            if( $header->hasPublicMembers() )
            {
                /* Header members */
                $html[] = '<div class="xsdoc-file-toc">';
                $html[] = '<h2>Public members</h2>';
            
                /* Tasks */
                if( count( $header->getFunctions() ) )
                {
                    $html[] = '<div class="xsdoc-file-toc-functions">';
                    $html[] = '<h3>Tasks</h3>';
                    $html[] = '<ul>';
                
                    foreach( $header->getFunctions() as $function )
                    {                        
                        $html[] = '<li>';   
                        $html[] = '<a href="#' . $function->getName() . '" title="' . $function->getName() . '">';
                        $html[] = $function->getName();   
                        $html[] = '</a>';
                        $html[] = '</li>';
                    }
                
                    $html[] = '</ul>';
                    $html[] = '</div>';
                }
            
                /* Types */
                if( count( $header->getTypes() ) )
                {
                    $html[] = '<div class="xsdoc-file-toc-types">';
                    $html[] = '<h3>Types</h3>';
                    $html[] = '<ul>';
                
                    foreach( $header->getTypes() as $type )
                    {                        
                        $html[] = '<li>';   
                        $html[] = '<a href="#' . $type->getName() . '" title="' . $type->getName() . '">';
                        $html[] = $type->getName();   
                        $html[] = '</a>';
                        $html[] = '</li>';
                    }
                
                    $html[] = '</ul>';
                    $html[] = '</div>';
                }
            
                /* Macros */
                if( count( $header->getMacros() ) )
                {
                    $html[] = '<div class="xsdoc-file-toc-macros">';
                    $html[] = '<h3>Macros</h3>';
                    $html[] = '<ul>';
                
                    foreach( $header->getMacros() as $macro )
                    {                        
                        $html[] = '<li>';   
                        $html[] = '<a href="#' . $macro->getName() . '" title="' . $macro->getName() . '">';
                        $html[] = $macro->getName();   
                        $html[] = '</a>';
                        $html[] = '</li>';
                    }
                
                    $html[] = '</ul>';
                    $html[] = '</div>';
                }
            
                $html[] = '</div>';
            }
            
            /* Header content */
            $html[] = '<div class="xsdoc-file-content">';
            $html[] = '<h2>' . $header->getName() . ' Reference</h2>';
            
            /* File details */
            $html[] = '<div class="xsdoc-file-details">';
            
            /* Path */
            $html[] = '<div class="xsdoc-file-detail">';
            $html[] = '<div class="xsdoc-file-detail-name">File</div>';
            $html[] = '<div class="xsdoc-file-detail-content">';
            $html[] = $header->getPath();
            $html[] = '</div>';
            $html[] = '</div>';
            
            /* Attributes */
            if( count( $header->getAttributes() ) )
            {
                foreach( $header->getAttributes() as $key => $value )
                {
                    $html[] = '<div class="xsdoc-file-detail">';
                    $html[] = '<div class="xsdoc-file-detail-name">' . $key . '</div>';
                    $html[] = '<div class="xsdoc-file-detail-content">' . $value . '</div>';
                    $html[] = '</div>';
                }
            }
            
            /* Copyright */
            if( strlen( $header->getCopyright() ) )
            {
                $html[] = '<div class="xsdoc-file-detail">';
                $html[] = '<div class="xsdoc-file-detail-name">Copyright</div>';
                $html[] = '<div class="xsdoc-file-detail-content">';
                $html[] = $header->getCopyright();
                $html[] = '</div>';
                $html[] = '</div>';
            }
            
            /* Date */
            if( strlen( $header->getDate() ) )
            {
                $html[] = '<div class="xsdoc-file-detail">';
                $html[] = '<div class="xsdoc-file-detail-name">Date</div>';
                $html[] = '<div class="xsdoc-file-detail-content">';
                $html[] = $header->getDate();
                $html[] = '</div>';
                $html[] = '</div>';
            }
            
            /* Includes */
            $html[] = '<div class="xsdoc-file-detail">';
            $html[] = '<div class="xsdoc-file-detail-name">Includes</div>';
            $html[] = '<div class="xsdoc-file-detail-content">';
            
            if( count( $header->getIncludeFiles() ) )
            {
                $html[] = '<ul>';
                
                foreach( $header->getIncludeFiles() as $key => $value )
                {
                    if( isset( $this->_headers[ $key ] ) )
                    {
                        $html[] = '<li>';
                        $html[] = '<a href="?xsdoc-file=' . urlencode( $key ) . '" title="' . $value . '">';
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
            
            /* Overview */
            $html[] = '<h3>Overview</h3>';
            $html[] = '<p><strong>' . $header->getAbstract() . '</strong></p>';
            
            if( strlen( $header->getDiscussion() ) )
            {
                $html[] = '<p>' . $header->getDiscussion() . '</p>';
            }
            
            /* Tasks */
            if( count( $header->getFunctions() ) )
            {
                $html[] = '<h3>Tasks</h3>';
                
                foreach( $header->getFunctions() as $function )
                {                        
                    $html[] = '<div class="xsdoc-file-task">';
                    $html[] = '<a name="' . $function->getName() . '"></a>';
                    $html[] = '<h4>' . $function->getName() . '</h4>';
                    
                    /* Abstract */
                    $html[] = '<p>' . $function->getAbstract() . '</p>';
                    
                    /* Declaration */
                    $html[] = '<p class="xsdoc-code-block"><code>' .  $function->getDeclaration() . '</code></p>';
                    
                    /* Discussion */
                    if( strlen( $function->getDiscussion() ) )
                    {
                        $html[] = '<h5>Discussion</h5>';
                        $html[] = '<p>' . $function->getDiscussion() . '</p>';
                    }
                    
                    /* Parameters */
                    if( count( $function->getParameters() ) )
                    {
                        $html[] = '<h5>Parameters</h5>';
                        $html[] = '<ul>';
                        
                        foreach( $function->getParameters() as $key => $value )
                        {
                            $html[] = '<li><span class="xsdoc-code">' . $key . '</span><br />' . $value . '</li>';
                        }
                        
                        $html[] = '</ul>';
                    }
                    
                    /* Return value */
                    if( strlen( $function->getReturnValue() ) )
                    {
                        $html[] = '<h5>Return value</h5>';
                        $html[] = '<p>' . $function->getReturnValue() . '</p>';
                    }
                    
                    /* See also */
                    if( count( $function->getSeeAlso() ) )
                    {
                        $html[] = '<h5>See also</h5>';
                        $html[] = '<ul>';
                        
                        foreach( $function->getSeeAlso() as $key => $value )
                        {
                            $html[] = '<li><a href="#' . $key . '" title="' . $value . '">' . $value . '</a></li>';
                        }
                        
                        $html[] = '</ul>';
                    }
                    
                    $html[] = '</div>';
                }
            }
            
            /* Types */
            if( count( $header->getTypes() ) )
            {
                $html[] = '<h3>Types</h3>';
                
                foreach( $header->getTypes() as $type )
                {                        
                    $html[] = '<div class="xsdoc-file-type">';
                    $html[] = '<a name="' . $type->getName() . '"></a>';
                    $html[] = '<h4>' . $type->getName() . '</h4>';
                    
                    /* Abstract */
                    $html[] = '<p>' . $type->getAbstract() . '</p>';
                    
                    /* Declaration */
                    $html[] = '<p class="xsdoc-code-block"><code>' . $type->getDeclaration() . '</code></p>';
                    
                    /* Discussion */
                    if( strlen( $type->getDiscussion() ) )
                    {
                        $html[] = '<h5>Discussion</h5>';
                        $html[] = '<p>' . $type->getDiscussion() . '</p>';
                    }
                    
                    /* Fields */
                    if( count( $type->getFields() ) )
                    {
                        $html[] = '<h5>Fields</h5>';
                        $html[] = '<ul>';
                        
                        foreach( $type->getFields() as $key => $value )
                        {
                            $html[] = '<li><span class="xsdoc-code">' . $key . '</span><br />' . $value . '</li>';
                        }
                        
                        $html[] = '</ul>';
                    }
                    
                    /* Constants */
                    if( count( $type->getConstants() ) )
                    {
                        $html[] = '<h5>Constants</h5>';
                        $html[] = '<ul>';
                        
                        foreach( $type->getConstants() as $key => $value )
                        {
                            $html[] = '<li><span class="xsdoc-code">' . $key . '</span><br />' . $value . '</li>';
                        }
                        
                        $html[] = '</ul>';
                    }
                    
                    /* Parameters */
                    if( count( $type->getParameters() ) )
                    {
                        $html[] = '<h5>Parameters</h5>';
                        $html[] = '<ul>';
                        
                        foreach( $type->getParameters() as $key => $value )
                        {
                            $html[] = '<li><span class="xsdoc-code">' . $key . '</span><br />' . $value . '</li>';
                        }
                        
                        $html[] = '</ul>';
                    }
                    
                    $html[] = '</div>';
                }
            }
            
            /* Macros */
            if( count( $header->getMacros() ) )
            {
                $html[] = '<h3>Macros</h3>';
                
                foreach( $header->getMacros() as $macro )
                {                        
                    $html[] = '<div class="xsdoc-file-macro">';
                    $html[] = '<a name="' . $macro->getName() . '"></a>';
                    $html[] = '<h4>' . $macro->getName() . '</h4>';
                    
                    /* Abstract */
                    $html[] = '<p>' . $macro->getAbstract() . '</p>';
                    
                    /* Declaration */
                    $html[] = '<p class="xsdoc-code-block"><code>' . $macro->getDeclaration() . '</code></p>';
                    
                    /* Parameters */
                    if( count( $macro->getParameters() ) )
                    {
                        $html[] = '<h5>Parameters</h5>';
                        $html[] = '<ul>';
                        
                        foreach( $macro->getParameters() as $key => $value )
                        {
                            $html[] = '<li><span class="xsdoc-code">' . $key . '</span><br />' . $value . '</li>';
                        }
                        
                        $html[] = '</ul>';
                    }
                    
                    /* Discussion */
                    if( strlen( $macro->getDiscussion() ) )
                    {
                        $html[] = '<h5>Discussion</h5>';
                        $html[] = '<p>' . $macro->getDiscussion() . '</p>';
                    }
                    
                    $html[] = '</div>';
                }
            }
            
            $html[] = '</div>';
            $html[] = '</div>';
        }
        else if( strlen( $this->_homeFile ) )
        {
            $html[] = '<div class="xsdoc-home">';
            $html[] = '<div class="xsdoc-home-content">';
            $html[] = file_get_contents( $this->_homeFile );
            $html[] = '</div>';
            $html[] = '</div>';
        }
        
        /* Footer */
        $html[] = '</div>';
        $html[] = '<div class="xsdoc-footer">';
        $html[] = strftime( $this->_copyright, time() );
        $html[] = '</div>';
        $html[] = '</div>';
        
        return implode( chr( 10 ), $html );
    }
}
