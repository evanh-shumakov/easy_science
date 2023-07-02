/* easy_science extension for PHP */

#ifndef PHP_EASY_SCIENCE_H
# define PHP_EASY_SCIENCE_H

extern zend_module_entry easy_science_module_entry;
# define phpext_easy_science_ptr &easy_science_module_entry

# define PHP_EASY_SCIENCE_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_EASY_SCIENCE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_EASY_SCIENCE_H */
