<?php

require_once dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'PHP' . DIRECTORY_SEPARATOR . 'Classes' . DIRECTORY_SEPARATOR . 'XS' . DIRECTORY_SEPARATOR . 'Docset.class.php';

$DOC = new XS_Docset( dirname( __FILE__ ) . DIRECTORY_SEPARATOR . 'XML' );

$DOC->setProjectName( 'XSFoundation' );
$DOC->setProjectVersion( '2.0.0-0' );
$DOC->setCopyright( 'XS-Labs &copy; %Y - All Rights Reserved' );
$DOC->setTimezone( 'Europe/Zurich' );
$DOC->setCompanyName( 'XS-Labs' );
$DOC->setCompanyURL( 'http://www.xs-labs.com/' );
$DOC->setSourceRootPrefix( '/XSFoundation/include/' );
$DOC->setClassesPrefix( 'XSFoundation/include/XS/Classes/' );
$DOC->setFunctionsPrefix( 'XSFoundation/include/XS/Functions/' );
$DOC->setTypesPrefix( 'XSFoundation/include/XS/XSTypes/' );
$DOC->setHomeFile( 'Pages/Home.inc.php' );
$DOC->addPage( 'Pages/Build.inc.php', 'Building XSFoundation' );
$DOC->addPage( 'Pages/Memory.inc.php', 'Memory management' );
$DOC->addPage( 'Pages/Classes.inc.php', 'Class definition' );

?>
<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//ENhttp://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
    <meta http-equiv="content-type" content="text/html; charset=utf-8" />
    <title><?php print $DOC->getTitle(); ?></title>
    <link rel="schema.dc" href="http://purl.org/metadata/dublin_core_elements" />
    <link href="CSS/XSDoc.css" type="text/css" rel="stylesheet" media="all" charset="utf-8" />
    <meta http-equiv="content-language" content="en" />
    <meta name="DC.Language" scheme="NISOZ39.50" content="en" />
    <meta name="rating" content="General" />
    <meta name="robots" content="all" />
    <meta name="generator" content="XSDocgen" />
</head>
<body>
<?php

print $DOC;

?>
</body>
</html>
