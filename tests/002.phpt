--TEST--
test1() Basic test
--EXTENSIONS--
easy_science
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension easy_science is loaded and working!
NULL
