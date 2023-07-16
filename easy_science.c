/* easy_science extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_easy_science.h"
#include "easy_science_arginfo.h"
#include <math.h>
#include <stdio.h>

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void test1() */
PHP_FUNCTION(test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "easy_science");
}
/* }}} */

/* {{{ string test2( [ string $var ] ) */
PHP_FUNCTION(test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

static double to_radian(double degree)
{
	return degree * (3.141592653589793 / 180.0);
}

static double round_to(double number, int digits_after_decimal_point)
{
	double equalizer = pow(10.0, digits_after_decimal_point);
        return round(number * equalizer) / equalizer;
}

static double round_to_15(double number)
{
	int digits_after_decimal = 15;
	return round_to(number, digits_after_decimal);
}

/* {{{ string sine( [ float $degree ] ) */
PHP_FUNCTION(sine)
{
    double degree;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(degree)
    ZEND_PARSE_PARAMETERS_END();

    double radian = to_radian(degree);

    RETURN_DOUBLE(round_to_15(sin(radian)));
}
/* }}}*/

/* {{{ string cosine( [ float $degree ] ) */
PHP_FUNCTION(cosine)
{
    double degree;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(degree)
    ZEND_PARSE_PARAMETERS_END();

    double radian = to_radian(degree);

    RETURN_DOUBLE(round_to_15(cos(radian)));
}
/* }}}*/

/* {{{ string tangent( [ float $degree ] ) */
PHP_FUNCTION(tangent)
{
    double degree;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(degree)
    ZEND_PARSE_PARAMETERS_END();

    double radian = to_radian(degree);

    RETURN_DOUBLE(round_to_15(tan(radian)));
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(easy_science)
{
#if defined(ZTS) && defined(COMPILE_DL_EASY_SCIENCE)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(easy_science)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "easy_science support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ easy_science_module_entry */
zend_module_entry easy_science_module_entry = {
	STANDARD_MODULE_HEADER,
	"easy_science",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(easy_science),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(easy_science),			/* PHP_MINFO - Module info */
	PHP_EASY_SCIENCE_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_EASY_SCIENCE
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(easy_science)
#endif
