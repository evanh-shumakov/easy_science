--TEST--
sine() Basic test
--EXTENSIONS--
easy_science
--FILE--
<?php

var_dump(sine(0));
var_dump(sine(1));
var_dump(sine(17));
var_dump(sine(45));
var_dump(sine(90));
var_dump(sine(180));
var_dump(sine(700));
var_dump(sine(-6));

try {
    var_dump(sine('string'));
} catch (\TypeError $e) {
    print "wrong type\n";
}

try {
    var_dump(sine());  
} catch (\ArgumentCountError $e) {
    print "wrong argument number\n";
}

?>
--EXPECT--
float(0)
float(0.017452406437284)
float(0.292371704722737)
float(0.707106781186548)
float(1)
float(0)
float(-0.342020143325669)
float(-0.104528463267653)
wrong type
wrong argument number