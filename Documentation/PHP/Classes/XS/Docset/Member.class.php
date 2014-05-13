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

require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Base.class.php';

abstract class XS_Docset_Member extends XS_Docset_Base
{
    public function __toString()
    {
        $html = array();
        
        $html[] = '<div class="xsdoc-file-member">';
        $html[] = '<a name="' . $this->getID() . '"></a>';
        $html[] = '<a name="' . $this->getName() . '"></a>';
        $html[] = '<h4>';
        $html[] = $this->getName();
        
        if( !isset( $_GET[ 'xsdoc-print' ] ) )
        {
            $html[] = '<span class="xsdoc-top"><a href="#xsdoc-top" title="Top">Top</a></span>';
        }
        
        $html[] = '</h4>';
        $html[] = '<p>' . $this->getAbstract() . '</p>';
        $html[] = '<p class="xsdoc-code-block"><code>' .  $this->getDeclaration() . '</code></p>';
        
        if( strlen( $this->getDiscussion() ) )
        {
            $html[] = '<h5>Discussion</h5>';
            $html[] = '<p>' . $this->getDiscussion() . '</p>';
        }
        
        if( count( $this->getParameters() ) )
        {
            $html[] = '<h5>Parameters</h5>';
            $html[] = '<ul>';
            
            foreach( $this->getParameters() as $key => $value )
            {
                $html[] = '<li><span class="xsdoc-code">' . $key . '</span><br />' . $value . '</li>';
            }
            
            $html[] = '</ul>';
        }
        
        if( strlen( $this->getReturnValue() ) )
        {
            $html[] = '<h5>Return value</h5>';
            $html[] = '<p>' . $this->getReturnValue() . '</p>';
        }
        
        if( count( $this->getFields() ) )
        {
            $html[] = '<h5>Fields</h5>';
            $html[] = '<ul>';
            
            foreach( $this->getFields() as $key => $value )
            {
                $html[] = '<li><span class="xsdoc-code">' . $key . '</span><br />' . $value . '</li>';
            }
            
            $html[] = '</ul>';
        }
        
        if( count( $this->getConstants() ) )
        {
            $html[] = '<h5>Constants</h5>';
            $html[] = '<ul>';
            
            foreach( $this->getConstants() as $key => $value )
            {
                $html[] = '<li><span class="xsdoc-code">' . $key . '</span><br />' . $value . '</li>';
            }
            
            $html[] = '</ul>';
        }
        
        if( count( $this->getSeeAlso() ) )
        {
            $html[] = '<h5>See also</h5>';
            $html[] = '<ul>';
            
            foreach( $this->getSeeAlso() as $key => $value )
            {
                $html[] = '<li><a href="#' . $key . '" title="' . $value . '">' . $value . '</a></li>';
            }
            
            $html[] = '</ul>';
        }
        
        $html[] = '</div>';
        
        return implode( chr( 10 ), $html );
    }
}
