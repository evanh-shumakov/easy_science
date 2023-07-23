--TEST--
cosine() Basic test
--EXTENSIONS--
easy_science
--FILE--
<?php

var_dump(cosine(0));
var_dump(cosine(1));
var_dump(cosine(17));
var_dump(cosine(45));
var_dump(cosine(90));
var_dump(cosine(180));
var_dump(cosine(700));
var_dump(cosine(-6));

try {
    var_dump(cosine('string'));
} catch (\TypeError $e) {
    print "wrong type\n";
}

try {
    var_dump(cosine());  
} catch (\ArgumentCountError $e) {
    print "wrong argument number\n";
}

?>
--EXPECT--
float(1)
float(0.999847695156391)
float(0.956304755963035)
float(0.707106781186548)
float(0)
float(-1)
float(0.939692620785908)
float(0.994521895368273)
wrong type
wrong argument number