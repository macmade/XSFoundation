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
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Docset' . DIRECTORY_SEPARATOR . 'Base.class.php';
require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Docset' . DIRECTORY_SEPARATOR . 'Header.class.php';

class XS_Docset extends XS_Docset_Base
{
    protected $_projectName         = '';
    protected $_projectVersion      = '';
    protected $_companyName         = '';
    protected $_companyURL          = '';
    protected $_copyright           = '';
    protected $_timezone            = '';
    protected $_xmlDir              = '';
    protected $_sourceRootPrefix    = '';
    protected $_classesPrefix       = '';
    protected $_functionsPrefix     = '';
    protected $_typesPrefix         = '';
    protected $_homeFile            = '';
    protected $_parsed              = false;
    protected $_currentHeader       = NULL;
    
    protected $_classes             = array();
    protected $_functions           = array();
    protected $_types               = array();
    protected $_headers             = array();
    protected $_pages               = array();
    
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
    
    public function setCompanyName( $value )
    {
        $this->_companyName = ( string )$value;
    }
    
    public function setCompanyURL( $value )
    {
        $this->_companyURL = ( string )$value;
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
    
    public function addPage( $page, $title )
    {
        $this->_pages[ $title ] = $page;
    }
    
    public function getHeaders()
    {
        $this->_parse();
        
        return $this->_headers;
    }
    
    public function getTitle()
    {
        $title = '';
        
        $this->_parse();
        
        if( $this->_currentHeader !== NULL )
        {
            $title = $this->_currentHeader->getName() . ' - ';
        }
        else if( isset( $_GET[ 'xsdoc-page' ] ) && isset( $this->_pages[ urldecode( $_GET[ 'xsdoc-page' ] ) ] ) )
        {
            $title = urldecode( $_GET[ 'xsdoc-page' ] ) . ' - ';
        }
        
        $title .= $this->_projectName . ' API Reference';
        
        return $title;
    }
    
    public function getHomeURL()
    {
        return strtok( $_SERVER[ 'REQUEST_URI' ], '?' );
    }
    
    public function getHeaderURL( XS_Docset_Header $header )
    {
        $url = $this->getHomeURL();
        
        if( $header !== NULL )
        {
            $url .= '?xsdoc-header=' . urlencode( $header->getID() );
        }
        
        return $url;
    }
    
    public function getSearchURL()
    {
        return $this->getHomeURL() . '?xsdoc-search=1';
    }
    
    public function getPrintURL()
    {
        if( isset( $_GET[ 'xsdoc-search' ] ) )
        {
            return $this->getSearchURL();
        }
        else if( isset( $_GET[ 'xsdoc-page' ] ) && isset( $this->_pages[ urldecode( $_GET[ 'xsdoc-page' ] ) ] ) )
        {
            return $this->getHomeURL() . '?xsdoc-page=' . $_GET[ 'xsdoc-page' ] . '&xsdoc-print=1';
        }
        else if( $this->_currentHeader !== NULL )
        {
            return $this->getHeaderURL( $this->_currentHeader ) . '&xsdoc-print=1';
        }
        else
        {
            return $this->getHomeURL() . '?xsdoc-print=1';
        }
    }
    
    public function getPageURL( $page )
    {
        $url = $this->getHomeURL();
        
        if( isset( $this->_pages[ $page ] ) )
        {
            $url .= '?xsdoc-page=' . urlencode( $page );
        }
        
        return $url;
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
                    $header = new XS_Docset_Header( $this, $info, $this->_sourceRootPrefix );
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
            
            if( isset( $_GET[ 'xsdoc-header' ] ) )
            {
                $key = urldecode( $_GET[ 'xsdoc-header' ] );
            
                if( isset( $this->_headers[ $key ] ) )
                {
                    $this->_currentHeader = $this->_headers[ $key ];
                }
            }
        }
        catch( Exception $e )
        {}
    }
    
    protected function _getHeaderListHTML( $headers )
    {
        $html = array();
        
        foreach( $headers as $header )
        {
            $html[] = '<li>';
            $html[] = '<a href="' . $this->getHeaderURL( $header ) . '" title="' . $header->getName() . '">';
            $html[] = $header->getName();
            $html[] = '</a>';
            $html[] = '</li>';
        }
        
        return implode( chr( 10 ), $html );
    }
    
    protected function _getPagesListHTML()
    {
        $html = array();
        
        if( strlen( $this->_homeFile ) )
        {
            $html[] = '<li>';
            $html[] = '<a href="' . $this->getHomeURL() . '" title="Start page">Start page</a>';
            $html[] = '</li>';
        }
        
        foreach( $this->_pages as $key => $value )
        {
            $html[] = '<li>';
            $html[] = '<a href="' . $this->getPageURL( $key ) . '" title="' . $key . '">' . $key . '</a>';
            $html[] = '</li>';
        }
        
        return implode( chr( 10 ), $html );
    }
    
    protected function _getSearchResults( $q )
    {
        $res     = array();
        $temp    = array();
        $headers = array_values( $this->_headers );
        
        $this->_parse();
        
        if( strlen( $q ) == 0 )
        {
            return array();
        }
        
        if( strlen( $this->_homeFile ) )
        {
            $doc = strtolower( preg_replace( '/<[^>]+>/', ' ', file_get_contents( $this->_homeFile ) ) );
            $i   = substr_count( $doc, strtolower( $q ) );
            
            if( $i > 0 )
            {
                if( !isset( $temp[ $i ] ) )
                {
                    $temp[ $i ] = array();
                }
                
                $temp[ $i ][] = '';
            }
        }
        
        foreach( $this->_pages as $key => $value )
        {
            $doc = strtolower( preg_replace( '/<[^>]+>/', ' ', file_get_contents( $value ) ) );
            $i   = substr_count( $doc, strtolower( $q ) );
            
            if( $i > 0 )
            {
                if( !isset( $temp[ $i ] ) )
                {
                    $temp[ $i ] = array();
                }
                
                $temp[ $i ][] = $key;
            }
        }
        
        foreach( $this->_headers as $header )
        {
            $doc = strtolower( preg_replace( '/<[^>]+>/', ' ', ( string )$header ) );
            $i   = substr_count( $doc, strtolower( $q ) );
            
            if( $i === 0 )
            {
                continue;
            }
            
            if( !isset( $temp[ $i ] ) )
            {
                $temp[ $i ] = array();
            }
            
            $temp[ $i ][] = $header;
        }
        
        krsort( $temp );
        
        foreach( $temp as $t )
        {
            foreach( $t as $header )
            {
                $res[] = $header;
            }
        }
        
        return $res;
    }
    
    public function _getSearchHTML()
    {
        $html = array();
        $q    = ( isset( $_POST[ 'xsdoc-q' ] ) ) ? $_POST[ 'xsdoc-q' ] : '';
        
        $html[] = '<div class="xsdoc-search">';
        $html[] = '<div class="xsdoc-search-content">';
        $html[] = '<h2>Search ' . $this->_projectName . '</h2>';
        $html[] = '<form action="' . $this->getSearchURL() . '" method="post">';
        $html[] = '<div class="xsdoc-search-form">';
        $html[] = '<div class="xsdoc-search-term">';
        $html[] = '<input type="text" size="50" name="xsdoc-q" value="' . $q . '" />';
        $html[] = '</div>';
        $html[] = '<div class="xsdoc-search-submit">';
        $html[] = '<input type="submit" value="Search" />';
        $html[] = '</div>';
        $html[] = '</div>';
        $html[] = '</form>';
        
        if( strlen( $q ) )
        {            
            $html[] = '<div class="xsdoc-search-results">';
            $html[] = '<h3>Search results</h3>';
            
            $res = $this->_getSearchResults( $q );
            
            if( count( $res ) === 0 )
            {
                $html[] = '<p class="xsdoc-search-results-none">The specified term was not found.</p>';
            }
            else
            {
                foreach( $res as $value )
                {
                    if( $value instanceof XS_Docset_Header )
                    {
                        $header      = $value;
                        $abstract    = $header->getAbstract();
                        $discussion  = $header->getDiscussion();
                    
                        if( strlen( $discussion ) > 200 )
                        {
                            $discussion = substr( $discussion, 0, 200 ) . ' [...]';
                        }
                        
                        $description = $abstract . '<br />' . $discussion;
                        
                        $html[] = '<div class="xsdoc-search-result">';
                        $html[] = '<h4><a href="' . $this->getHeaderURL( $header ) . '">' . $header->getName() . '</a></h4>';
                        $html[] = '<h5><a href="' . $this->getHeaderURL( $header ) . '">' . $header->getPath() . '</a></h5>';
                        $html[] = '<p><a href="' . $this->getHeaderURL( $header ) . '">' . $description . '</a></p>';
                        $html[] = '</div>';
                    }
                    else
                    {
                        $html[] = '<div class="xsdoc-search-result">';
                        
                        if( strlen( $value ) )
                        {
                            $html[] = '<h4><a href="' . $this->getPageURL( $value ) . '">' . $value . '</a></h4>';
                        }
                        else
                        {
                            $html[] = '<h4><a href="' . $this->getHomeURL() . '">Start page</a></h4>';
                        }
                        
                        $html[] = '<h5></h5>';
                        $html[] = '<p></p>';
                        $html[] = '</div>';
                    }
                }
            }
            
            $html[] = '</div>';
        }
        
        $html[] = '</div>';
        $html[] = '</div>';
        
        return implode( chr( 10 ), $html );
    }
    
    public function __toString()
    {
        $html   = array();
        $search = ( isset( $_GET[ 'xsdoc-search' ] ) ) ? true : false;
        $print  = ( isset( $_GET[ 'xsdoc-print'  ] ) ) ? true : false;
        
        $this->_parse();
        
        if( strlen( $this->_timezone ) )
        {
            date_default_timezone_set( $this->_timezone );
        }
        else
        {
            date_default_timezone_set( 'UTC' );
        }
        
        $html[] = '<a name="xsdoc-top"></a>';
        
        if( $print === false )
        {
            $html[] = '<div class="xsdoc-project">';
            $html[] = '<div class="xsdoc-header">';
            $html[] = '<h1>';
            $html[] = '<span class="xsdoc-header-project">';
            $html[] = '<a href="' . $this->getHomeURL() . '">';
            $html[] = $this->_projectName . ': API Reference';
            $html[] = '</a>';
            $html[] = '</span>';
        
            if( strlen( $this->_companyName ) )
            {
                $html[] = '<span class="xsdoc-header-company">';
                $html[] = '<a href="' . $this->_companyURL . '">';
                $html[] = '[ ' . $this->_companyName . ' ]';
                $html[] = '</a>';
                $html[] = '</span>';;
            }
        
            $html[] = '</h1>';
            $html[] = '<div class="xsdoc-header-buttons">';
            $html[] = '<div class="xsdoc-header-button">';
            $html[] = '<a href="' . $this->getPrintURL() . '" title="Print">';
            $html[] = '<img src="../CSS/Resources/print.png" alt="" width="20" height="20" />';
            $html[] = '</a>';
            $html[] = '</div>';
            $html[] = '<div class="xsdoc-header-button">';
            $html[] = '<a href="' . $this->getSearchURL() . '" title="Print">';
            $html[] = '<img src="../CSS/Resources/search.png" alt="" width="20" height="20" />';
            $html[] = '</a>';
            $html[] = '</div>';
            $html[] = '</div>';
            $html[] = '</div>';
            $html[] = '<div class="xsdoc-subheader">';
            $html[] = 'Version ' . $this->_projectVersion;
            $html[] = '</div>';
            $html[] = '<div class="xsdoc-main">';
            $html[] = '<div class="xsdoc-toc">';
        
            if( strlen( $this->_homeFile ) || count( $this->_pages ) )
            {
                $html[] = '<div class="xsdoc-toc-general">';
                $html[] = '<h2>General</h2>';
                $html[] = '<ul>';
                $html[] = $this->_getPagesListHTML();
                $html[] = '</ul>';
                $html[] = '</div>';
            }
        
            if( count( $this->_classes ) )
            {
                $html[] = '<div class="xsdoc-toc-classes">';
                $html[] = '<h2>Classes</h2>';
                $html[] = '<ul>';
                $html[] = $this->_getHeaderListHTML( $this->_classes );
                $html[] = '</ul>';
                $html[] = '</div>';
            }
        
            if( count( $this->_functions ) )
            {
                $html[] = '<div class="xsdoc-toc-classes">';
                $html[] = '<h2>Functions</h2>';
                $html[] = '<ul>';
                $html[] = $this->_getHeaderListHTML( $this->_functions );
                $html[] = '</ul>';
                $html[] = '</div>';
            }
        
            if( count( $this->_types ) )
            {
                $html[] = '<div class="xsdoc-toc-classes">';
                $html[] = '<h2>Types</h2>';
                $html[] = '<ul>';
                $html[] = $this->_getHeaderListHTML( $this->_types );
                $html[] = '</ul>';
                $html[] = '</div>';
            }
        
            if( count( $this->_headers ) )
            {
                $html[] = '<div class="xsdoc-toc-classes">';
                
                
                if
                (
                       count( $this->_classes )
                    || count( $this->_functions )
                    || count( $this->_types )
                )
                {
                    $html[] = '<h2>Other headers</h2>';
                }
                else
                {
                    $html[] = '<h2>Headers</h2>';
                }
                
                $html[] = '<ul>';
                $html[] = $this->_getHeaderListHTML( $this->_others );
                $html[] = '</ul>';
                $html[] = '</div>';
            }
        
            $html[] = '</div>';
        }
        
        if( $search === true )
        {
            $html[] = $this->_getSearchHTML();
        }
        else if( $this->_currentHeader !== NULL )
        {
            $header = $this->_currentHeader;
            $html[] = '<div class="xsdoc-file">';
            
            if( $header->hasPublicMembers() && $print === false )
            {
                $html[] = '<div class="xsdoc-file-toc">';
                $html[] = '<h2>Public members</h2>';
                
                if( count( $header->getFunctions() ) )
                {
                    $html[] = '<div class="xsdoc-file-toc-functions">';
                    $html[] = '<h3>Tasks</h3>';
                    $html[] = $header->getFunctionsListHTML();
                    $html[] = '</div>';
                }
                
                if( count( $header->getTypes() ) )
                {
                    $html[] = '<div class="xsdoc-file-toc-types">';
                    $html[] = '<h3>Types</h3>';
                    $html[] = $header->getTypesListHTML();
                    $html[] = '</div>';
                }
                
                if( count( $header->getMacros() ) )
                {
                    $html[] = '<div class="xsdoc-file-toc-macros">';
                    $html[] = '<h3>Macros</h3>';
                    $html[] = $header->getMacrosListHTML();
                    $html[] = '</div>';
                }
            
                $html[] = '</div>';
            }
            
            $html[] = ( string )$header;
        }
        else
        {
            $page = '';
            
            if( isset( $_GET[ 'xsdoc-page' ] ) )
            {
                $pageTitle = urldecode( $_GET[ 'xsdoc-page' ] );
                
                if( isset( $this->_pages[ $pageTitle ] ) )
                {
                    $page = $this->_pages[ $pageTitle ];
                }
            }
            
            if( strlen( $page ) )
            {
                $html[] = '<div class="xsdoc-page">';
                $html[] = '<div class="xsdoc-page-content">';
                
                ob_start();
                
                include( $page );
                
                $html[] = ob_get_contents();
                
                ob_end_clean();
                
                $html[] = '</div>';
                $html[] = '</div>';
            }
            else if( strlen( $this->_homeFile ) )
            {
                $html[] = '<div class="xsdoc-home">';
                $html[] = '<div class="xsdoc-home-content">';
                
                ob_start();
                
                include( $this->_homeFile );
                
                $html[] = ob_get_contents();
                
                ob_end_clean();
                
                $html[] = '</div>';
                $html[] = '</div>';
            }
        }
        
        if( $print === false )
        {
            $html[] = '</div>';
            $html[] = '<div class="xsdoc-footer">';
            $html[] = strftime( $this->_copyright, time() );
            $html[] = '</div>';
            $html[] = '</div>';
        }
        
        return implode( chr( 10 ), $html );
    }
}
