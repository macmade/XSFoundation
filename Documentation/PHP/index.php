<?php

require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'Classes' . DIRECTORY_SEPARATOR . 'XS' . DIRECTORY_SEPARATOR . 'Docset.class.php';

$DOC = new XS_Docset( dirname( __FILE__ ) . DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR . 'XML' );

$DOC->setProjectName( 'XSFoundation' );
$DOC->setProjectVersion( '2.0.0-0' );
$DOC->setCompanyName( 'XS-Labs' );
$DOC->setCompanyURL( 'http://www.xs-labs.com/' );
$DOC->setCopyright( 'XS-Labs &copy; %Y - All Rights Reserved' );
$DOC->setTimezone( 'Europe/Zurich' );
$DOC->setSourceRootPrefix( '/XSFoundation/include/' );
$DOC->setClassesPrefix( 'XSFoundation/include/XS/Classes/' );
$DOC->setFunctionsPrefix( 'XSFoundation/include/XS/Functions/' );
$DOC->setTypesPrefix( 'XSFoundation/include/XS/XSTypes/' );
$DOC->setHomeFile( 'Pages' . DIRECTORY_SEPARATOR . 'home.inc.php' );
$DOC->addPage( 'Pages' . DIRECTORY_SEPARATOR . 'build.inc.php', 'Building XSFoundation' );
$DOC->addPage( 'Pages' . DIRECTORY_SEPARATOR . 'memory.inc.php', 'Memory management' );
$DOC->addPage( 'Pages' . DIRECTORY_SEPARATOR . 'class.inc.php', 'Custom class creation' );

?>
<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
    <!--
    
    ##################################################
    #                                                #
    #       Blood Sweat & Code (& Rock'N'Roll)       #
    #      Thanx for looking at the source code      #
    #                                                #
    #                 XS-Labs © 2014                 #
    #                                                #
    ##################################################
    
    -->
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <title><?php print $DOC->getTitle(); ?></title>
    <link rel="schema.dc" href="http://purl.org/metadata/dublin_core_elements" />
    <link href="../CSS/XSDoc.css" type="text/css" rel="stylesheet" media="all" charset="utf-8" />
    <meta http-equiv="content-language" content="en" />
    <meta name="DC.Language" scheme="NISOZ39.50" content="en" />
    <meta name="author" content="XS-Labs" />
    <meta name="DC.Creator" content="XS-Labs" />
    <meta name="copyright" content="XS-Labs &copy; 2014 - All rights reseverd" />
    <meta name="DC.Rights" content="XS-Labs &copy; 2014 - All rights reseverd" />
    <meta name="rating" content="General" />
    <meta name="robots" content="all" />
    <meta name="generator" content="BBEdit 10.5" />
</head>
<body>
<?php

print $DOC;

?>
</body>
</html>
