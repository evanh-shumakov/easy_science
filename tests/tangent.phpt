--TEST--
tangent() Basic test
--EXTENSIONS--
easy_science
--FILE--
<?php

var_dump(tangent(0));
var_dump(tangent(1));
var_dump(tangent(17));
var_dump(tangent(45));
var_dump(tangent(90));
var_dump(tangent(180));
var_dump(tangent(700));
var_dump(tangent(-6));

try {
    var_dump(tangent('string'));
} catch (\TypeError $e) {
    print "wrong type\n";
}

try {
    var_dump(tangent());  
} catch (\ArgumentCountError $e) {
    print "wrong argument number\n";
}

?>
--EXPECT--
float(0)
float(0.017455064928218)
float(0.30573068145866)
float(1)
float(16331239353195372)
float(-0)
float(-0.363970234266202)
float(-0.105104235265676)
wrong type
wrong argument number