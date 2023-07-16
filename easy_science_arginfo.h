/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 87b64006970e45daa6e0c6879228e3f5c4081f68 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test1, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_test2, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, str, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_sine, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, degree, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_cosine arginfo_sine

#define arginfo_tangent arginfo_sine


ZEND_FUNCTION(test1);
ZEND_FUNCTION(test2);
ZEND_FUNCTION(sine);
ZEND_FUNCTION(cosine);
ZEND_FUNCTION(tangent);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(test1, arginfo_test1)
	ZEND_FE(test2, arginfo_test2)
	ZEND_FE(sine, arginfo_sine)
	ZEND_FE(cosine, arginfo_cosine)
	ZEND_FE(tangent, arginfo_tangent)
	ZEND_FE_END
};
